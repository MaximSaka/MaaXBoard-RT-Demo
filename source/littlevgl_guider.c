/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "demo_common.h"
#include "lvgl_demo.h"
#include "network_demo.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

portSTACK_TYPE *lvgl_task_stack = NULL;
TaskHandle_t lvgl_task_task_handler;

portSTACK_TYPE *wifi_task_stack = NULL;
TaskHandle_t wifi_task_task_handler;

portSTACK_TYPE *console_task_stack = NULL;
TaskHandle_t console_task_task_handler;

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

	/* Init input switch GPIO. */
    EnableIRQ(BOARD_USER_BUTTON_IRQ);

    setInputSignal(false);

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

    stat = xTaskCreate(
        wifi_task, 
        "wifi", 
        configMINIMAL_STACK_SIZE + 800, 
        wifi_task_stack, 
        tskIDLE_PRIORITY + 4,
        &wifi_task_task_handler);
    assert(pdPASS == stat);

   // Create console task

   stat = xTaskCreate(
       console_task,
       "console",
       configMINIMAL_STACK_SIZE + 800,
       console_task_stack,
       tskIDLE_PRIORITY + 2,
       &console_task_task_handler);
   assert(pdPASS == stat);

    // Init scheduler

    vTaskStartScheduler();

    for (;;)
    {
    } /* should never get here */
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
