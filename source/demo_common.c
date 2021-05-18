
#include "gui_guider.h"
#include "littlevgl_support.h"
#include "lvgl.h"
#include "events_init.h"

#include "demo_common.h"
#include "network_demo.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

typedef enum _activePage
{
    PAGE_HELP       = 0,
    PAGE_WELCOME    = 1,
    PAGE_NETWORK    = 2,
} activePage;

/*******************************************************************************
 * Variables
 ******************************************************************************/

static volatile uint8_t s_current_action = 1;        // action index
static volatile bool s_input_signal = false;         // S1 button switch page signal
static volatile bool s_lvgl_initialized = false;
static volatile activePage s_active_page = PAGE_WELCOME;

lv_ui guider_ui;

/*******************************************************************************
 * Functions
 ******************************************************************************/

/*!
* @brief Sets the input signal
*/
bool setInputSignal(bool state)
{
    s_input_signal = state;
}

/*!
 * @brief adds item to the list of SSIDs
 */
void addItemToSSIDList(const char * text)
{
    if (s_active_page != PAGE_NETWORK)
    {
        return;
    }

	//Write style LV_BTN_PART_MAIN for network_screen_ssidlist
	static lv_style_t style_network_screen_ssidlist_main_child;
	lv_style_init(&style_network_screen_ssidlist_main_child);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_ssidlist_main_child
	lv_style_set_radius(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, &lv_font_simsun_28);

	lv_obj_t *network_screen_ssidlist_btn;
	network_screen_ssidlist_btn = lv_list_add_btn(guider_ui.network_screen_ssidlist, NULL, text);
	lv_obj_add_style(network_screen_ssidlist_btn, LV_BTN_PART_MAIN, &style_network_screen_ssidlist_main_child);
}

/*!
* @brief Opens the network screen
*/
void openNetworkScreen()
{
    lv_obj_clean(lv_scr_act());
    setup_scr_network_screen(&guider_ui);
    lv_scr_load(guider_ui.network_screen);

    s_active_page = PAGE_NETWORK;

    lv_list_clean(guider_ui.network_screen_ssidlist);

    ssidScan();
}

/*!
* @brief Opens the help screen
*/
void openHelpScreen()
{
    lv_obj_clean(lv_scr_act());
    setup_scr_help_screen(&guider_ui);
    lv_scr_load(guider_ui.help_screen);

    s_active_page = PAGE_HELP;
}

/*!
* @brief Opens the welcome screen
*/
void openWelcomeScreen()
{
    lv_obj_clean(lv_scr_act());
    setup_scr_welcome_screen(&guider_ui);
    lv_scr_load(guider_ui.welcome_screen);

    s_active_page = PAGE_WELCOME;
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
		lv_label_set_text(guider_ui.welcome_screen_userlabel0, "User button ON!");
    }
    else
    {
		lv_label_set_text(guider_ui.welcome_screen_userlabel0, "User button OFF");
    }
    
    lv_obj_set_hidden(guider_ui.welcome_screen_usruntglimg0, state);
    lv_obj_set_hidden(guider_ui.welcome_screen_usrtglimg0, !state);
}

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void lvgl_task(void *param)
{
    lv_port_pre_init();
    lv_init();
    lv_port_disp_init();
//pf lv_port_indev_init();    //disable until new touch driver is added

    s_lvgl_initialized = true;
    s_current_action = 1;

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    
    // set the user button initial state
    toggleUserButton(false);

    for (;;)
    {
        if (s_input_signal)
        {
            switch (s_current_action)
            {
                // case 1:
                //     toggleRedButton(true);
                //     toggleUserButton(true);

                //     s_current_action++;
                //     break;

                // case 2:
                //     toggleGreenButton(true);
                //     toggleUserButton(false);

                //     s_current_action++;
                //     break;

                // case 3:
                //     toggleBlueButton(true);
                //     toggleUserButton(true);

                //     s_current_action++;
                //     break;

                // case 4:
                //     toggleRedButton(false);
                //     toggleUserButton(false);

                //     s_current_action++;
                //     break;

                // case 5:
                //     toggleGreenButton(false);
                //     toggleUserButton(true);

                //     s_current_action++;
                //     break;

                // case 6:
                //     toggleBlueButton(false);
                //     toggleUserButton(false);

                //     s_current_action++;
                //     break;

                // case 7:

                //     s_current_action = 1;
                //     break;
                case 1:
                    openNetworkScreen();

                    s_current_action++;
                    break;

                case 2:
                    openHelpScreen();

                    s_current_action++;
                    break;

                case 3:
                    openWelcomeScreen();

                    s_current_action = 1;
                    break;
            }

            s_input_signal = false;
        }

        GPIO_PinWrite(BOARD_USER_LED_GPIO,      BOARD_USER_LED_GPIO_PIN,      get_green_led() ? 1U : 0U);
        GPIO_PinWrite(BOARD_USER_LED_RED_GPIO,  BOARD_USER_LED_RED_GPIO_PIN,  get_red_led()   ? 1U : 0U);
        GPIO_PinWrite(BOARD_USER_LED_BLUE_GPIO, BOARD_USER_LED_BLUE_GPIO_PIN, get_blue_led()  ? 1U : 0U);

        lv_task_handler();
        vTaskDelay(5);
    }
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook_lvgl(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}
