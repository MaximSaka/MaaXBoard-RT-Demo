/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "FreeRTOS.h"
#include "task.h"

#include "fsl_debug_console.h"
#include "littlevgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"

#include "fsl_soc_src.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile bool g_InputSignal = false;                // S1 button switch page signal
volatile uint8_t g_current_action = 1;              // action index

static volatile bool s_lvgl_initialized = false;
lv_ui guider_ui;

/*******************************************************************************
 * Functions
 ******************************************************************************/
/*!
 * @brief Opens the help screen
 */
void openHelpScreen()
{
    lv_obj_clean(lv_scr_act());
    setup_scr_screen(&guider_ui);
    lv_scr_load(guider_ui.screen);
}

/*!
 * @brief Toggles the red button
 */
void toggleRedButton(bool state)
{
    if (state)
    {
        lv_obj_set_state(guider_ui.welcome_screen_redbtn0, LV_STATE_CHECKED|LV_STATE_PRESSED);
        lv_event_send(guider_ui.welcome_screen_redbtn0, LV_EVENT_PRESSED, NULL);
    }
    else
    {
        lv_obj_set_state(guider_ui.welcome_screen_redbtn0, LV_STATE_DEFAULT);
        lv_event_send(guider_ui.welcome_screen_redbtn0, LV_EVENT_RELEASED, NULL);
    }
}

/*!
 * @brief Toggles the green button
 */
void toggleGreenButton(bool state)
{
    if (state)
    {
        lv_obj_set_state(guider_ui.welcome_screen_greenbtn0, LV_STATE_CHECKED|LV_STATE_PRESSED);
        lv_event_send(guider_ui.welcome_screen_greenbtn0, LV_EVENT_PRESSED, NULL);
    }
    else
    {
        lv_obj_set_state(guider_ui.welcome_screen_greenbtn0, LV_STATE_DEFAULT);
        lv_event_send(guider_ui.welcome_screen_greenbtn0, LV_EVENT_RELEASED, NULL);
    }
}

/*!
 * @brief Toggles the blue button
 */
void toggleBlueButton(bool state)
{
    if (state)
    {
        lv_obj_set_state(guider_ui.welcome_screen_bluebtn0, LV_STATE_CHECKED|LV_STATE_PRESSED);
        lv_event_send(guider_ui.welcome_screen_bluebtn0, LV_EVENT_PRESSED, NULL);
    }
    else
    {
        lv_obj_set_state(guider_ui.welcome_screen_bluebtn0, LV_STATE_DEFAULT);
        lv_event_send(guider_ui.welcome_screen_bluebtn0, LV_EVENT_RELEASED, NULL);
    }
}

/*!
 * @brief Toggles the user button image
 */
void toggleUserButton(bool state)
{
    if (state)
    {
		lv_label_set_text(guider_ui.welcome_screen_userlabel0, "User button toggled");
    }
    else
    {
		lv_label_set_text(guider_ui.welcome_screen_userlabel0, "User button untoggled");
    }
    
    lv_obj_set_hidden(guider_ui.welcome_screen_usruntglimg0, state);
    lv_obj_set_hidden(guider_ui.welcome_screen_usrtglimg0, !state);
}

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void AppTask(void *param)
{
    lv_port_pre_init();
    lv_init();
    lv_port_disp_init();
//pf lv_port_indev_init();    //disable until new touch driver is added

    s_lvgl_initialized = true;
    g_current_action = 1;

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    
    // set the user button initial state
    toggleUserButton(false);

    for (;;)
    {
        if (g_InputSignal)
        {
            switch (g_current_action)
            {
                case 1:
                    toggleRedButton(true);
                    toggleUserButton(true);

                    g_current_action++;
                    break;

                case 2:
                    toggleGreenButton(true);
                    toggleUserButton(false);

                    g_current_action++;
                    break;

                case 3:
                    toggleBlueButton(true);
                    toggleUserButton(true);

                    g_current_action++;
                    break;

                case 4:
                    toggleRedButton(false);
                    toggleUserButton(false);

                    g_current_action++;
                    break;

                case 5:
                    toggleGreenButton(false);
                    toggleUserButton(true);

                    g_current_action++;
                    break;

                case 6:
                    toggleBlueButton(false);
                    toggleUserButton(false);

                    g_current_action++;
                    break;

                case 7:
                    // openHelpScreen();

                    g_current_action = 1;
                    break;
            }

            g_InputSignal = false;
        }

        GPIO_PinWrite(BOARD_USER_LED_GPIO,      BOARD_USER_LED_GPIO_PIN,      get_green_led() ? 1U : 0U);
        GPIO_PinWrite(BOARD_USER_LED_RED_GPIO,  BOARD_USER_LED_RED_GPIO_PIN,  get_red_led()   ? 1U : 0U);
        GPIO_PinWrite(BOARD_USER_LED_BLUE_GPIO, BOARD_USER_LED_BLUE_GPIO_PIN, get_blue_led()  ? 1U : 0U);

        lv_task_handler();
        vTaskDelay(5);
    }
}

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

    g_InputSignal = true;

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

    BOARD_InitLpuartPins();
    BOARD_InitMipiPanelPins();
//pf     BOARD_MIPIPanelTouch_I2C_Init();    //disable until new touch driver is added
    BOARD_InitDebugConsole();

	/* Init input switch GPIO. */
    EnableIRQ(BOARD_USER_BUTTON_IRQ);

    g_InputSignal = false;

    stat = xTaskCreate(AppTask, "littlevgl", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 2, NULL);

    if (pdPASS != stat)
    {
        PRINTF("Failed to create littlevgl task");
        while (1)
            ;
    }

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
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
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
