/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "FreeRTOS.h"
#include "queue.h"
#include "event_groups.h"
#include "fsl_lpuart_freertos.h"

#include "fsl_debug_console.h"
#include "littlevgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"

#include "fsl_soc_src.h"

#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "globals.h"
#include "demo_common.h"
#include "audio_demo.h"
#include "lvgl_demo.h"
#include "network_demo.h"
#include "usb_peripherals.h"
#include "UART_CLI.h"
#include "ether_if.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define WIFI_EN		1

#ifdef WIFI_EN
	#define ETH_100MB_EN	1
#endif

portSTACK_TYPE *lvgl_task_stack = NULL;
TaskHandle_t lvgl_task_task_handler;

portSTACK_TYPE *wifi_task_stack = NULL;
TaskHandle_t wifi_task_task_handler;

portSTACK_TYPE *console_task_stack = NULL;
TaskHandle_t console_task_task_handler;

volatile uint32_t cmdEnable = 0;

/* Freertos queue */
static QueueHandle_t hid_devices_queue = NULL;
static QueueHandle_t wifi_commands_queue = NULL;
static QueueHandle_t wifi_response_queue = NULL;

uint8_t shared_buff[2048];

/******* UART handle definition ***************/
static lpuart_rtos_handle_t uart_rtos_handle;
static struct _lpuart_handle tuart_handle;
static uint8_t background_buffer[32];
//uint8_t recv_buffer[4];

lpuart_rtos_config_t lpuart_config = {
	.base		 = DEMO_LPUART,
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer,
    .buffer_size = sizeof(background_buffer),
};

/******* USB HID device definition ***************/
static usb_host_handle g_HostHandle;
/*! @brief USB host mouse instance global variable */
static usb_host_mouse_instance_t g_HostHidMouse;
/*! @brief USB host keyboard instance global variable */
static usb_host_keyboard_instance_t g_HostHidKeyboard;
static custom_usb_host_mouse_instance_t t_usb_host_mouse;
static custom_usb_host_keyboard_instance_t t_usb_host_keyboard;
static custom_usb_log_instance_t t_usb_log;
static custom_wifi_instance_t t_wifi_cmd;
static custom_console_instance_t t_console;

static EventGroupHandle_t event_group_demo;

/* counter used for freeRTOS tasks runtime analysis */
static uint32_t perfCounter = 0;

/*******************************************************************************
 * Function Prototypes
 ******************************************************************************/
static void uart_init();

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief S1 button switch interrupt service ISR
 */
void BOARD_USER_BUTTON_IRQ_HANDLER(void)
{
    /* clear the interrupt status */
    GPIO_PortClearInterruptFlags(BOARD_USER_BUTTON_GPIO, 1U << BOARD_USER_BUTTON_GPIO_PIN);

    setInputSignal(true);

    SDK_ISR_EXIT_BARRIER;
}

/*!
 * @brief PIT1 Timer interrupt service ISR
 */
void PIT1_IRQHANDLER(void)
{
	PIT_ClearStatusFlags(PIT1_PERIPHERAL, PIT1_CHANNEL_0, kPIT_TimerFlag);
	perfCounter++;
	//__DSB();
}

void AppConfigureTimerForRuntimeStats(void) {
	pit_config_t config;

	PIT_GetDefaultConfig(&config);
	config.enableRunInDebug = false;
	PIT_Init(PIT1_PERIPHERAL, &config);
	PIT_SetTimerPeriod(PIT1_PERIPHERAL, PIT1_CHANNEL_0, PIT1_CHANNEL_0_TICKS);
	PIT_EnableInterrupts(PIT1_PERIPHERAL, PIT1_CHANNEL_0, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT1_IRQN);
	PIT_StartTimer(PIT1_PERIPHERAL, PIT1_CHANNEL_0);
}

uint32_t AppGetRuntimeCounterValueFromISR(void) {
	return perfCounter;
}

/*!
 * @brief Main function
 */
int main(void)
{
    BaseType_t stat;

    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_BootClockRUN();

    /*
     * Reset the displaymix, otherwise during debugging, the
     * debugger may not reset the display, then the behavior
     * is not right.
     */
    SRC_AssertSliceSoftwareReset(SRC, kSRC_DisplaySlice);

    BOARD_InitPins();
    BOARD_InitMipiPanelPins();
    BOARD_MIPIPanelTouch_I2C_Init();
    BOARD_InitDebugConsole();
    //enable lpi2c3
    BOARD_RTOS_I2C_Init(3);
    BOARD_RTOS_I2C_Init(6);
    // configure uart for Maaxboard RT
    uart_init();
	/* Init input switch GPIO. */
    EnableIRQ(BOARD_USER_BUTTON_IRQ);

    setInputSignal(false);

    /* Freertos Queue for usb mouse and keyboards */
	hid_devices_queue = xQueueCreate(10, sizeof(struct hid_device*));
	/* Enable queue view in MCUX IDE FreeRTOS TAD plugin. */
	if (hid_devices_queue != NULL)
	{
		vQueueAddToRegistry(hid_devices_queue, "usbQ");
	}

	wifi_commands_queue = xQueueCreate(10, sizeof(struct t_user_wifi_command));
	if (wifi_commands_queue != NULL)
	{
		vQueueAddToRegistry(wifi_commands_queue, "wifiQ");
	}

	wifi_response_queue = xQueueCreate(1, sizeof(uint8_t));
	/* Enable queue view in MCUX IDE FreeRTOS TAD plugin. */
	if (wifi_response_queue != NULL)
	{
		vQueueAddToRegistry(wifi_response_queue, "wResQ");
	}
	event_group_demo = xEventGroupCreate();

	PRINTF("Debug Session");
	SDK_DelayAtLeastUs(1000000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

	/******** Freertos task declarations ********/
    os_setup_tick_function(vApplicationTickHook_lvgl);

   // Create lvgl task

   stat = xTaskCreate(
       lvgl_task,
       "lvgl",
       configMINIMAL_STACK_SIZE + 800,
       lvgl_task_stack,
       tskIDLE_PRIORITY + 3,
       &lvgl_task_task_handler);
   assert(pdPASS == stat);

    // Create wifi task
#ifdef WIFI_EN
	t_wifi_cmd.cmd_queue = &wifi_commands_queue;
	t_wifi_cmd.event_group_wifi = &event_group_demo;
	t_wifi_cmd.wifi_resQ = &wifi_response_queue;
    stat = xTaskCreate(
        wifi_task,
        "wifi",
        configMINIMAL_STACK_SIZE + 800,
		&t_wifi_cmd,
        tskIDLE_PRIORITY + 4,
        &wifi_task_task_handler);
    assert(pdPASS == stat);
#endif
    /* usb host, freertos task initialization */
	USB_HostApplicationInit(&g_HostHandle);
	if (xTaskCreate(USB_HostTask, "usb host task", 2000L / sizeof(portSTACK_TYPE), g_HostHandle, 4, NULL) != pdPASS)
	{
		PRINTF("Failed to create USB host task\r\n");
		while (1);
	}

	/* handle USB mouse input */
	t_usb_host_mouse.hid_queue = &hid_devices_queue;
	t_usb_host_mouse.host_hid_mouse = &g_HostHidMouse;
	if (xTaskCreate(USB_HostApplicationMouseTask, "mouse task", 2000L / sizeof(portSTACK_TYPE), &t_usb_host_mouse, 3,
					NULL) != pdPASS)
	{
		PRINTF("Failed to create mouse task\r\n");
		while (1);
	}

	/* handle USB keyboard input */
	t_usb_host_keyboard.hid_queue = &hid_devices_queue;
	t_usb_host_keyboard.host_hid_keyboard = &g_HostHidKeyboard;
	if (xTaskCreate(USB_HostApplicationKeyboardTask, "keyboard task", 2000L / sizeof(portSTACK_TYPE),
					&t_usb_host_keyboard, 3, NULL) != pdPASS)
	{
		PRINTF("Failed to create keyboard task\r\n");
		while (1);
	}

    /* launch HID input logging task */
	t_usb_log.hid_queue = &hid_devices_queue;
	t_usb_log.uart_handle = &uart_rtos_handle;
	#if defined(ENABLED_LOG_TASK)
	if (xTaskCreate(USB_logTask, "USB_log", configMINIMAL_STACK_SIZE + 166, &t_usb_log, 2, NULL) != pdPASS)
	{
		PRINTF("Failed to create log task\r\n");
		while (1);
	}
	#endif

    /* launch demo console task */
    t_console.cmd_queue = &wifi_commands_queue;
    t_console.wifi_resQ = &wifi_response_queue;
    t_console.uart_handle = &uart_rtos_handle;
    t_console.event_group_wifi = &event_group_demo;
	if (xTaskCreate(console_task, "Console_task", configMINIMAL_STACK_SIZE + 200, &t_console, 3, NULL) != pdPASS)
	{
		PRINTF("Failed to create console task\r\n");
		while (1);
	}

	/* Note: when ethernet task starts, it hangs the program until network cable is connected.
	 	 if network interface is not connected, must comment below task */
	/*
	 * Note:
	 * order of wifi, ethernet initialization is
	 * 1. wifi
	 * 2. ethernet_100mb
	 * 3. ethernet_1g
	 * Reason is: There is one lwip thread is used. Inside wifi tcpip_init() is called.
	 * 			  ethernet_100mb, ethernet_1g assumes tcpip_init() is called.
	 * Freertos eventgroup (event_group_demo) is used for ensuring the correct order of execution.
	 *
	 * when ethernet task starts, it hangs the program until network cable is connected.
	 * so if network interface is not used, must comment below task.
	 *  */

	// dual_eth_configuration() must be called before starting ethernet tasks.
#ifdef ETH_100MB_EN
	dual_eth_configuration();
	// eth100 task
	if (xTaskCreate(eth_100m_task, "eth_100m", configMINIMAL_STACK_SIZE + 200, &event_group_demo, 3, NULL) != pdPASS)
	{
		PRINTF("Failed to create console task\r\n");
		while (1);
	}
	// eth1G task
	if (xTaskCreate(eth_1g_task, "eth_1g", configMINIMAL_STACK_SIZE + 200, &event_group_demo, 3, NULL) != pdPASS)
	{
		PRINTF("Failed to create console task\r\n");
		while (1);
	}
#endif

	// audio task init
    if (xTaskCreate(audio_task_init, "av_task", configMINIMAL_STACK_SIZE + 200, NULL, 3, NULL) != pdPASS)
	{
		PRINTF("Failed to create console task\r\n");
		while (1);
	}

    // Init scheduler

    vTaskStartScheduler();

    for (;;)
    {
    } /* should never get here */
}

static void uart_init()
{
	NVIC_SetPriority(DEMO_LPUART_IRQn, 5);
	lpuart_config.srcclk = DEMO_LPUART_CLK_FREQ;
	LPUART_RTOS_Init(&uart_rtos_handle, &tuart_handle, &lpuart_config);
}

/*!
 * @brief Malloc failed hook.
 */
void vApplicationMallocFailedHook(void)
{
    for (;;)
        ;
}

/*!
 * @brief Stack overflow hook.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, signed char *pcTaskName)
{
    (void)pcTaskName;
    (void)xTask;

    for (;;)
        ;
}
