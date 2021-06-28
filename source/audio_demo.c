/*
 * audio_demo_new.c
 *
 *  Created on: Jun 14, 2021
 *      Author: gulziibayar
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

#include "board.h"
#include "fsl_pdm.h"
#include "fsl_sai.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"

#include "fsl_codec_common.h"
#include "fsl_sgtl5000.h"
#include "fsl_codec_adapter.h"

#include "lvgl_demo.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_PDM                      PDM
#define DEMO_SAI                      SAI2
#define DEMO_SAI_CLK_FREQ             24576000
#define DEMO_SAI_CHANNEL              0
#define DEMO_SAI_MASTER_SLAVE         kSAI_Master
#define DEMO_SAI_TX_SYNC_MODE         kSAI_ModeAsync
#define DEMO_SAI_CLOCK_SOURCE         (kSAI_BclkSourceMclkDiv)
#define DEMO_PDM_CLK_FREQ             24576000
#define DEMO_PDM_FIFO_WATERMARK       (7)
#define DEMO_PDM_QUALITY_MODE         kPDM_QualityModeHigh
#define DEMO_PDM_CIC_OVERSAMPLE_RATE  (0U)
#define DEMO_PDM_ENABLE_CHANNEL_0  (0U)
#define DEMO_PDM_ENABLE_CHANNEL_1  (1U)
#define DEMO_PDM_ENABLE_CHANNEL_2  (2U)
#define DEMO_PDM_ENABLE_CHANNEL_3  (3U)
#if 1 // 1:use U11 U2 0:use U1 U10
#define DEMO_PDM_ENABLE_CHANNEL_LEFT DEMO_PDM_ENABLE_CHANNEL_0
#define DEMO_PDM_ENABLE_CHANNEL_RIGHT DEMO_PDM_ENABLE_CHANNEL_1
#else
#define DEMO_PDM_ENABLE_CHANNEL_LEFT DEMO_PDM_ENABLE_CHANNEL_2
#define DEMO_PDM_ENABLE_CHANNEL_RIGHT DEMO_PDM_ENABLE_CHANNEL_3
#endif

#define DEMO_PDM_SAMPLE_CLOCK_RATE    (16000U) /* 16Khz */
/* demo audio sample rate */
#define DEMO_AUDIO_SAMPLE_RATE (kSAI_SampleRate16KHz)
/* demo audio master clock */
#define DEMO_AUDIO_MASTER_CLOCK DEMO_SAI_CLK_FREQ
/* demo audio data channel */
#define DEMO_AUDIO_DATA_CHANNEL (2U)
/* demo audio bit width */
#define DEMO_AUDIO_BIT_WIDTH kSAI_WordWidth32bits
#define BOARD_MasterClockConfig()
#define BUFFER_SIZE   (DEMO_PDM_FIFO_WATERMARK * FSL_FEATURE_PDM_FIFO_WIDTH * 2U)
#define BUFFER_NUMBER (256U)
#ifndef DEMO_CODEC_VOLUME
#define DEMO_CODEC_VOLUME 100U
#endif
#define BUFF_TIMES	8

#define CH1_EN	(1<<0)
#define CH2_EN	(1<<1)
#define CH3_EN	(1<<2)
#define CH4_EN	(1<<3)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void saiCallback(I2S_Type *base, sai_handle_t *handle, status_t status, void *userData);
/*******************************************************************************
 * Variables
 ******************************************************************************/
static sai_transfer_t xfer;
static sai_transceiver_t config;

sai_handle_t s_saiTxHandle         = {0};
static volatile bool isSaiFinished = false;
SDK_ALIGN(static uint8_t pdmBuff[BUFFER_SIZE*2], 4);
SDK_ALIGN(static uint8_t txBuff[BUFFER_SIZE * BUFFER_NUMBER], 4);
static volatile bool s_dataReadFinishedFlag = false;
static volatile uint32_t s_buffCnt         = 0U;
static volatile uint32_t s_readIndex        = 0U;
static volatile uint32_t s_writeIndex       = 0U;

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

/* codec config */
sgtl_config_t sgtlConfig = {
	.i2cConfig        = {.codecI2CInstance = BOARD_CODEC_I2C_INSTANCE, .codecI2CSourceClock = BOARD_CODEC_I2C_CLOCK_FREQ},
	.route            = kSGTL_RoutePlaybackandRecord,
	.bus              = kSGTL_BusI2S,
	.slaveAddress     = SGTL5000_I2C_ADDR,
	.format           = {
			.mclk_HZ       = 4096000U,
			.sampleRate    = 16000U,
			.bitWidth      = 16U
	},
	.master_slave     = false,
};

codec_config_t boardCodecConfig = {.codecDevType = kCODEC_SGTL5000, .codecDevConfig = &sgtlConfig};
codec_handle_t codecHandle;

static volatile bool s_channel0Enabled = true;
static volatile bool s_channel1Enabled = true;
static volatile bool s_channel2Enabled = false;
static volatile bool s_channel3Enabled = false;

static uint8_t s_channels = 0;

static uint8_t audio_jack[2] = {1,2};
static int32_t channel_0;
static int32_t channel_1;
static int32_t channel_2;
static int32_t channel_3;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*
 * AUDIO PLL setting: Frequency = Fref * (DIV_SELECT + NUM / DENOM)
 *                              = 24 * (32 + 77/100)
 *                              = 786.48 MHz
 */
const clock_audio_pll_config_t audioPllConfig = {
    .loopDivider = 32,  /* PLL loop divider. Valid range for DIV_SELECT divider value: 27~54. */
    .postDivider = 1,   /* Divider after the PLL, should only be 1, 2, 4, 8, 16. */
    .numerator   = 77,  /* 30 bit numerator of fractional loop divider. */
    .denominator = 100, /* 30 bit denominator of fractional loop divider */
};

/*!
 * @brief Enable or Disable SAI clk
 */
void BOARD_EnableSaiMclkOutput(bool enable)
{
    if (enable)
    {
        IOMUXC_GPR->GPR1 |= IOMUXC_GPR_GPR1_SAI2_MCLK_DIR_MASK;
    }
    else
    {
        IOMUXC_GPR->GPR1 &= (~IOMUXC_GPR_GPR1_SAI2_MCLK_DIR_MASK);
    }
}

/*!
 * @brief SAI call back when data transfer complete
 */
static void saiCallback(I2S_Type *base, sai_handle_t *handle, status_t status, void *userData)
{
    if (kStatus_SAI_TxError == status)
    {
        /* Handle the error. */
    }
    else
    {
    	isSaiFinished = true;
    }
}
static void pdm_error_irqHandler(void)
{
    uint32_t status = 0U;
    if (PDM_GetStatus(DEMO_PDM) & PDM_STAT_LOWFREQF_MASK)
    {
        PDM_ClearStatus(DEMO_PDM, PDM_STAT_LOWFREQF_MASK);
    }

    status = PDM_GetFifoStatus(DEMO_PDM);
    if (status != 0U)
    {
        PDM_ClearFIFOStatus(DEMO_PDM, status);
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

/*!
 * @brief Among the all 4 channels data, only select only up to 2 selected channels to audio output
 * @params - src_buff - source buffer which stores all 4 mic values in following order. mic1, mic2, mic3, mic4, mic1...
 * 						4*7 samples are stored
 * 			 dest_buff - destination buffer which stores the enabled 2 mic values. E.g mic1, mic2, mic1, mic2...
 * audio_jack[0], audio_jack[1] holds the selected mic values.
 */
static void four_two_conv(uint8_t *src_buff, uint8_t *dest_buff)
{
    memset(dest_buff, 0x00, BUFFER_SIZE);
    int offset = 0;

    // otherwise only up to 2 mic will be outputted to audio jack
    uint8_t mic_mask = 0x01;
    uint8_t count_enabled_mic = 0;
    for (int i=0; i<2; i++)
    {
        if (audio_jack[i])
        {
            offset = 0;
            for (int j=0; j<BUFFER_SIZE/2/4; j++)
            {
                memcpy(dest_buff+j*8+i*4, src_buff+(audio_jack[i]-1)*4+offset, 4);
                offset = offset + 16;		// ch1(4) + ch2(4) + ch3(4) + ch4(4)
                                            // next sample is 16 bytes away
            }
            count_enabled_mic++;
        }
    }
}

/*!
 * @brief 4 microphone data are sample at 16khz. Interrupt is triggered when fifo level is 7.
 */
void PDM_EVENT_IRQHandler(void)
{
    uint32_t status = PDM_GetStatus(DEMO_PDM);
    /* handle PDM error status */
#if (defined FSL_FEATURE_PDM_HAS_NO_INDEPENDENT_ERROR_IRQ && FSL_FEATURE_PDM_HAS_NO_INDEPENDENT_ERROR_IRQ)
    pdm_error_irqHandler();
#endif
    /* receive data */
    if ((1U << DEMO_PDM_ENABLE_CHANNEL_LEFT) & status)
    {
        PDM_ReadFifo(DEMO_PDM, DEMO_PDM_ENABLE_CHANNEL_LEFT, 4, &pdmBuff[0],
                      DEMO_PDM_FIFO_WATERMARK, FSL_FEATURE_PDM_FIFO_WIDTH);
        if ((s_readIndex >= s_writeIndex) || (s_readIndex <= (s_writeIndex - 1U)))
        {
        	channel_0 = (int32_t)((pdmBuff[3]<<24)|(pdmBuff[2]<<16) | (pdmBuff[1]<<8))>>8;
			channel_1 = (int32_t)((pdmBuff[3+4]<<24)|(pdmBuff[2+4]<<16) | (pdmBuff[1+4]<<8))>>8;
			channel_2 = (int32_t)((pdmBuff[3+8]<<24)|(pdmBuff[2+8]<<16) | (pdmBuff[1+8]<<8))>>8;
			channel_3 = (int32_t)((pdmBuff[3+12]<<24)|(pdmBuff[2+12]<<16) | (pdmBuff[1+12]<<8))>>8;

			/* Only forward enabled mic to audio buffer */
        	four_two_conv(pdmBuff, &txBuff[s_readIndex * BUFF_TIMES * BUFFER_SIZE + s_buffCnt * BUFFER_SIZE]);
        	s_buffCnt += 1U;
        	if (s_buffCnt == BUFF_TIMES)	/* audio buffer is ready */
        	{
        		s_buffCnt = 0;
        		s_readIndex += 1U;
				if (s_readIndex >= BUFFER_NUMBER/BUFF_TIMES)
				{
					s_readIndex = 0U;
				}
				s_dataReadFinishedFlag = true;
        	}
        }
    }
    /* Clear PDM status */
    PDM_ClearStatus(DEMO_PDM, status);
    __DSB();
}

/*!
 * @brief maps the range to given range.
 */
static int32_t map_range(int32_t in_val, int32_t in_start, int32_t in_end, int32_t out_start, int32_t out_end)
{
	int32_t output;
	output = out_start + (int32_t)(((float)(out_end - out_start) /(float)(in_end - in_start)) * (float)(in_val - in_start));
	return output;
}

/*!
 * @brief disables all the channels.
 */
void disableAllMicChannels()
{
	s_channel0Enabled = false;
	s_channel1Enabled = false;
	s_channel2Enabled = false;
	s_channel3Enabled = false;
	audio_jack[0] = 0;
	audio_jack[1] = 0;
}

/*!
 * @brief returns the enabled channels. 0 -> empty, 1-4 enabled channels
 */
uint8_t * getEnabledChannels()
{
	return &audio_jack[0];
}

/*!
 * @brief enables audio mic channels from console
 */
void enableAudioMicChannels(uint8_t ch, uint8_t val)
{
	if (ch>=0 && ch<2)
	{
		if (val>=0 && val<=4)
		{
			audio_jack[ch] = val;
			switch(val)
			{
				case 1:
					s_channel0Enabled = true;
					break;
				case 2:
					s_channel1Enabled = true;
					break;
				case 3:
					s_channel2Enabled = true;
					break;
				case 4:
					s_channel3Enabled = true;
					break;
			}
		}
	}
}

/*!
 * @brief enables mic channels from gui
 */
void enableMicChannel(int id, bool state)
{
    switch (id)
    {
    case 0:
        s_channel0Enabled = state;
        break;
    case 1:
        s_channel1Enabled = state;
        break;
    case 2:
        s_channel2Enabled = state;
        break;
    case 3:
        s_channel3Enabled = state;
        break;
    default:
        PRINTF("Invalid mic channel: %d\r\n", id);
        break;
    }

    if ((id>=0 && id<4))
    {
    	if (state == false)
    	{
    		for (int i=0; i<2; i++)
    		{
    			if (audio_jack[i]==(id+1))
    			{
    				audio_jack[i] = 0;
    				break;
    			}
    		}
    	}
    	else
    	{
    		for (int i=0; i<2; i++)
    		{
    			if (audio_jack[i]==id+1)
    			{
    				//already enabled
    				return;
    			}
    		}


    		for (int i=0; i<2; i++)
    		{
    			if (audio_jack[i]==0)
    			{
    				audio_jack[i] = id+1;
    				break;
    			}
    		}
    	}
    }
}

/*!
* @brief returns the RTOS_i2c5_handle for i2c scan
*/
void * getRtosI2cHandle()
{
	return ((sgtl_handle_t *)(codecHandle.codecDevHandle))->i2cHandle;
}

/*!
 * @brief main body freertos audio_task
 */
void audio_task_init()
{
	BOARD_InitPins_Sai();
	BOARD_InitPins_Pdm();

	CLOCK_InitAudioPll(&audioPllConfig);

	CLOCK_SetRootClockMux(kCLOCK_Root_Lpi2c5, 1);
	/* audio pll  */
	CLOCK_SetRootClockMux(kCLOCK_Root_Sai1, 4);
	CLOCK_SetRootClockDiv(kCLOCK_Root_Sai1, 16);
	/* 0SC400M */
	/* 24.576m mic root clock */
	CLOCK_SetRootClockMux(kCLOCK_Root_Mic, 6);
	CLOCK_SetRootClockDiv(kCLOCK_Root_Mic, 16);

	BOARD_EnableSaiMclkOutput(true);
	NVIC_SetPriority(LPI2C5_IRQn, 5);
	PRINTF("PDM SAI interrupt transfer example started!\n\r");

	memset(txBuff, 0U, sizeof(txBuff));

	/* SAI init */
	SAI_Init(DEMO_SAI);
	SAI_TransferTxCreateHandle(DEMO_SAI, &s_saiTxHandle, saiCallback, NULL);
	/* I2S mode configurations */
	SAI_GetClassicI2SConfig(&config, DEMO_AUDIO_BIT_WIDTH, kSAI_Stereo, 1U << DEMO_SAI_CHANNEL);

	config.syncMode    = DEMO_SAI_TX_SYNC_MODE;
	config.masterSlave = DEMO_SAI_MASTER_SLAVE;
	SAI_TransferTxSetConfig(DEMO_SAI, &s_saiTxHandle, &config);

	/* set bit clock divider */
	SAI_TxSetBitClockRate(DEMO_SAI, DEMO_AUDIO_MASTER_CLOCK, DEMO_AUDIO_SAMPLE_RATE, DEMO_AUDIO_BIT_WIDTH,
						  DEMO_AUDIO_DATA_CHANNEL);

	/* Use default setting to init codec */
	if (CODEC_Init(&codecHandle, &boardCodecConfig) != kStatus_Success)
	{
		assert(false);
	}

	/* Set up pdm */
	/* Set up pdm */
	PDM_Init(DEMO_PDM, &pdmConfig);
	PDM_SetChannelConfig(DEMO_PDM, DEMO_PDM_ENABLE_CHANNEL_0, &channelConfig);
	PDM_SetChannelConfig(DEMO_PDM, DEMO_PDM_ENABLE_CHANNEL_1, &channelConfig);
	PDM_SetChannelConfig(DEMO_PDM, DEMO_PDM_ENABLE_CHANNEL_2, &channelConfig);
	PDM_SetChannelConfig(DEMO_PDM, DEMO_PDM_ENABLE_CHANNEL_3, &channelConfig);
	if (PDM_SetSampleRateConfig(DEMO_PDM, DEMO_PDM_CLK_FREQ, DEMO_AUDIO_SAMPLE_RATE) != kStatus_Success)
	{
		PRINTF("PDM configure sample rate failed.\r\n");
		assert(false);
	}
	PDM_Reset(DEMO_PDM);

    // setting NVIC priority is important for Freertos
    NVIC_SetPriority(PDM_EVENT_IRQn, 5);
	PDM_EnableInterrupts(DEMO_PDM, kPDM_ErrorInterruptEnable | kPDM_FIFOInterruptEnable);
	EnableIRQ(PDM_EVENT_IRQn);
	PDM_Enable(DEMO_PDM, true);

    int32_t mapped_ch0;
	int32_t mapped_ch1;
	int32_t mapped_ch2;
	int32_t mapped_ch3;
	int cnt = 0;

	while(1)
	{
		if (s_readIndex != s_writeIndex)
		{
			/*  xfer structure */
			xfer.data     = (uint8_t *)(&txBuff[s_writeIndex * BUFF_TIMES * BUFFER_SIZE]);
			xfer.dataSize = BUFF_TIMES * BUFFER_SIZE;
			if (SAI_TransferSendNonBlocking(DEMO_SAI, &s_saiTxHandle, &xfer) != kStatus_SAI_QueueFull)
			{
				if ((s_writeIndex += 1U) >= BUFFER_NUMBER/BUFF_TIMES)
				{
					s_writeIndex = 0U;
				}
				cnt++;
				if (cnt<4)
				{
					cnt = 0;
					if (s_channel0Enabled)
					{
						/* map the integer value to 0-100 range for plotting on GUI */
						mapped_ch0 = map_range(channel_0>>8, -32768, 32767, 0, 100);
						/* send the mic value to GUI graph*/
						addMicData(1, mapped_ch0);
					}

					if (s_channel1Enabled)
					{
						/* map the integer value to 0-100 range for plotting on GUI */
						mapped_ch1 = map_range(channel_1>>8, -32768, 32767, 0, 100);
						/* send the mic value to GUI graph*/
						addMicData(2, mapped_ch1);
					}

					if (s_channel2Enabled)
					{
						/* map the integer value to 0-100 range for plotting on GUI */
						mapped_ch2 = map_range(channel_2>>8, -32768, 32767, 0, 100);
						/* send the mic value to GUI graph*/
						addMicData(3, mapped_ch2);
					}

					if (s_channel3Enabled)
					{
						/* map the integer value to 0-100 range for plotting on GUI */
						mapped_ch3 = map_range(channel_3>>8, -32768, 32767, 0, 100);
						/* send the mic value to GUI graph*/
						addMicData(4, mapped_ch3);
					}
				}
			}
		}
		vTaskDelay(3);
	}

	PRINTF("Task destroyed\r\n");
	vTaskSuspend(NULL);
}

