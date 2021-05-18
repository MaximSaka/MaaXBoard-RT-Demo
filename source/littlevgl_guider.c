/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "demo_common.h"
#include "network_demo.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

portSTACK_TYPE *lvgl_task_stack = NULL;
TaskHandle_t lvgl_task_task_handler;

portSTACK_TYPE *network_task_stack = NULL;
TaskHandle_t network_task_task_handler;

/*******************************************************************************
 * Code
 ******************************************************************************/

void vApplicationTickHook_lvgl(void);

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
//pf     BOARD_MIPIPanelTouch_I2C_Init();    //disable until new touch driver is added
    BOARD_InitDebugConsole();

	/* Init input switch GPIO. */
    EnableIRQ(BOARD_USER_BUTTON_IRQ);

    setInputSignal(false);

    os_setup_tick_function(vApplicationTickHook_lvgl);

    // Init gui task

    stat = xTaskCreate(
        lvgl_task, 
        "lvgl", 
        configMINIMAL_STACK_SIZE + 800, 
        lvgl_task_stack, 
        tskIDLE_PRIORITY + 2, 
        &lvgl_task_task_handler);
    assert(pdPASS == stat);

    // Init network task

    stat = xTaskCreate(
        network_task, 
        "network", 
        configMINIMAL_STACK_SIZE + 800, 
        network_task_stack, 
        tskIDLE_PRIORITY + 2, 
        &network_task_task_handler);
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
