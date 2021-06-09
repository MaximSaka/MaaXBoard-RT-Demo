/*
 * audio_test.c
 *
 *  Created on: Jun 7, 2021
 *      Author: gulziibayar
 */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_pdm.h"
#include "fsl_debug_console.h"
#include "lvgl_demo.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_PDM PDM
#define DEMO_PDM_CLK_FREQ 24576000
#define DEMO_PDM_FIFO_WATERMARK (FSL_FEATURE_PDM_FIFO_DEPTH - 1U)
#define DEMO_PDM_QUALITY_MODE kPDM_QualityModeHigh
#define DEMO_PDM_CIC_OVERSAMPLE_RATE (0U)
#define DEMO_PDM_ENABLE_CHANNEL_LEFT (0U)
#define DEMO_PDM_ENABLE_CHANNEL_RIGHT (1U)
#define DEMO_AUDIO_SAMPLE_RATE (16000)

#define SAMPLE_COUNT (256)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void BOARD_InitDebugConsole(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
SDK_ALIGN(static uint32_t txBuff[SAMPLE_COUNT], 4);
static volatile bool s_lowFreqFlag          = false;
static volatile bool s_fifoErrorFlag        = false;
static volatile uint32_t s_readIndex        = 0U;
static const pdm_config_t pdmConfig         = {
    .enableDoze        = false,
    .fifoWatermark     = DEMO_PDM_FIFO_WATERMARK,
    .qualityMode       = DEMO_PDM_QUALITY_MODE,
    .cicOverSampleRate = DEMO_PDM_CIC_OVERSAMPLE_RATE,
};
static pdm_channel_config_t channelConfig = {
    .cutOffFreq = kPDM_DcRemoverCutOff152Hz,
    .gain       = kPDM_DfOutputGain7,
};

static SemaphoreHandle_t xBinarySemaphore = NULL;
/*******************************************************************************
 * Code
 ******************************************************************************/
/*
 * AUDIO PLL setting: Frequency = Fref * (DIV_SELECT + NUM / DENOM) / (2^POST)
 *                              = 24 * (32 + 77/100)  / 2
 *                              = 393.24MHZ
 */
const clock_audio_pll_config_t audioPllConfig1 = {
    .loopDivider = 32,  /* PLL loop divider. Valid range for DIV_SELECT divider value: 27~54. */
    .postDivider = 1,   /* Divider after the PLL, should only be 0, 1, 2, 3, 4, 5 */
    .numerator   = 77,  /* 30 bit numerator of fractional loop divider. */
    .denominator = 100, /* 30 bit denominator of fractional loop divider */
};

static void pdm_error_irqHandler(void)
{
    uint32_t status = 0U;
    if (PDM_GetStatus(DEMO_PDM) & PDM_STAT_LOWFREQF_MASK)
    {
        PDM_ClearStatus(DEMO_PDM, PDM_STAT_LOWFREQF_MASK);
        s_lowFreqFlag = true;
    }

    status = PDM_GetFifoStatus(DEMO_PDM);
    if (status != 0U)
    {
        PDM_ClearFIFOStatus(DEMO_PDM, status);
        s_fifoErrorFlag = true;
    }
#if defined(FSL_FEATURE_PDM_HAS_RANGE_CTRL) && FSL_FEATURE_PDM_HAS_RANGE_CTRL
    status = PDM_GetRangeStatus(DEMO_PDM);
    if (status != 0U)
    {
        PDM_ClearRangeStatus(DEMO_PDM, status);
    }
#else
    status = PDM_GetOutputStatus(DEMO_PDM);
    if (status != 0U)
    {
        PDM_ClearOutputStatus(DEMO_PDM, status);
    }
#endif
}

#if !(defined FSL_FEATURE_PDM_HAS_NO_INDEPENDENT_ERROR_IRQ && FSL_FEATURE_PDM_HAS_NO_INDEPENDENT_ERROR_IRQ)
void PDM_ERROR_IRQHandler(void)
{
    pdm_error_irqHandler();
    __DSB();
}
#endif

void PDM_EVENT_IRQHandler(void)
{
    uint32_t i = 0U, status = PDM_GetStatus(DEMO_PDM);
    /* receive data */
    //    PDM channels are read one after another.
    //    E.g: ch1 , ch2, ch1, ch2. if all channels enabled.
    //    E.g ch1, ch2, ch3, ch4, ch1,
    for (i = 0U; i < DEMO_PDM_FIFO_WATERMARK; i++)
    {
    	for (int ch = 0; ch < 2; ch++)	// hardcoded channel value. ch
    	{
    		if (s_readIndex < SAMPLE_COUNT)
			{
				txBuff[s_readIndex] = PDM_ReadData(DEMO_PDM, ch);
				s_readIndex++;
			}
    	}
    }
    /* handle PDM error status */
#if (defined FSL_FEATURE_PDM_HAS_NO_INDEPENDENT_ERROR_IRQ && FSL_FEATURE_PDM_HAS_NO_INDEPENDENT_ERROR_IRQ)
    pdm_error_irqHandler();
#endif

    PDM_ClearStatus(DEMO_PDM, status);
    if (s_readIndex >= SAMPLE_COUNT)
    {
    	//buffer is SAMPLE_COUNT=128 long. once full, process it.
    	s_readIndex = 0;
        BaseType_t xHigherPriorityTaskWoken, xResult;
		/* The xHigherPriorityTaskWoken parameter must be initialized to pdFALSE as
		it will get set to pdTRUE inside the interrupt safe API function if a
		context switch is required. */
		xHigherPriorityTaskWoken = pdFALSE;
		/* 'Give' the semaphore to unblock the task, passing in the address of
		xHigherPriorityTaskWoken as the interrupt safe API function's
		pxHigherPriorityTaskWoken parameter. */
		xResult = xSemaphoreGiveFromISR( xBinarySemaphore, &xHigherPriorityTaskWoken);
    }
    __DSB();
}

static int32_t map_range(int32_t in_val, int32_t in_start, int32_t in_end, int32_t out_start, int32_t out_end)
{
	int32_t output;
	output = out_start + (int32_t)(((float)(out_end - out_start) /(float)(in_end - in_start)) * (float)(in_val - in_start));
	return output;
}

static void audio_task(void *pvParameters)
{
    int32_t channel_0;
    int32_t channel_1;
    int32_t channel_2;
    int32_t channel_3;
    int32_t mapped_ch0;
    int32_t mapped_ch1;
    int cnt = 0;
    while(1)
    {
    	if (xSemaphoreTake( xBinarySemaphore, portMAX_DELAY ) == pdTRUE)
    	{
    		cnt++;
    		if (cnt > 2)
    		{
    			cnt = 0;
    			channel_0 = (int32_t)((txBuff[0]&(0x000000FF) << 24) | (txBuff[0]&(0x0000FF00) << 8) | (txBuff[0]&(0x00FF0000) >> 8))>>8;
    			channel_1 = (int32_t)((txBuff[1]&(0x000000FF) << 24) | (txBuff[1]&(0x0000FF00) << 8) | (txBuff[1]&(0x00FF0000) >> 8))>>8;
//    			channel_2 = (int32_t)((txBuff[2]&(0x000000FF) << 24) | (txBuff[2]&(0x0000FF00) << 8) | (txBuff[2]&(0x00FF0000) >> 8))>>8;
//    			channel_3 = (int32_t)((txBuff[3]&(0x000000FF) << 24) | (txBuff[3]&(0x0000FF00) << 8) | (txBuff[3]&(0x00FF0000) >> 8))>>8;
    			mapped_ch0 = map_range(channel_0>>8, -32768, 32767, 0, 100);
    			mapped_ch1 = map_range(channel_1>>8, -32768, 32767, 0, 100);
    			addMicData(1, mapped_ch0);
        		//PRINTF("%d %d %d %d\n", mapped_ch0, mapped_ch1, 0>>8, 0>>8);
    		}

    	}
    }

    PRINTF("Task destroyed\r\n");
    vTaskSuspend(NULL);
}



void audio_task_init()
{
	uint32_t i = 0U, j = 0U;
	BOARD_InitPins_Pdm();
	CLOCK_SetRootClockMux(kCLOCK_Root_Bus_Lpsr, 0);
	CLOCK_InitAudioPll(&audioPllConfig1);

	/* 24.576m mic root clock */
	CLOCK_SetRootClockMux(kCLOCK_Root_Mic, 6);
	CLOCK_SetRootClockDiv(kCLOCK_Root_Mic, 16);

	PRINTF("PDM interrupt example started!\n\r");

	memset(txBuff, 0U, sizeof(txBuff));

	/* Set up pdm */
	PDM_Init(DEMO_PDM, &pdmConfig);

	PDM_SetChannelConfig(DEMO_PDM, DEMO_PDM_ENABLE_CHANNEL_LEFT, &channelConfig);
	PDM_SetChannelConfig(DEMO_PDM, DEMO_PDM_ENABLE_CHANNEL_RIGHT, &channelConfig);
	//    PDM_SetChannelConfig(DEMO_PDM, 2, &channelConfig);
	//    PDM_SetChannelConfig(DEMO_PDM, 3, &channelConfig);

	if (PDM_SetSampleRateConfig(DEMO_PDM, DEMO_PDM_CLK_FREQ, DEMO_AUDIO_SAMPLE_RATE) != kStatus_Success)
	{
		PRINTF("PDM configure sample rate failed.\r\n");
		return -1;
	}

	//	NVIC priority is necessary for FREERTOS tasks. It should be higher than other tasks.
	//  If not defined, interrupt will have default 0 priority(lowest in Freertos)
	NVIC_SetPriority(PDM_EVENT_IRQn, 5);
	PDM_EnableInterrupts(DEMO_PDM, kPDM_ErrorInterruptEnable | kPDM_FIFOInterruptEnable);

	EnableIRQ(PDM_EVENT_IRQn);

#if !(defined FSL_FEATURE_PDM_HAS_NO_INDEPENDENT_ERROR_IRQ && FSL_FEATURE_PDM_HAS_NO_INDEPENDENT_ERROR_IRQ)
    EnableIRQ(PDM_ERROR_IRQn);
#endif
    PDM_Enable(DEMO_PDM, true);

    xBinarySemaphore = xSemaphoreCreateBinary();
    if (xBinarySemaphore==NULL)
    {
    	PRINTF("Binary semaphore not created\r\n");
    }

    if (xTaskCreate(audio_task, "av_task", configMINIMAL_STACK_SIZE + 200, NULL, 3, NULL) != pdPASS)
	{
		PRINTF("Failed to create console task\r\n");
		while (1);
	}

}
