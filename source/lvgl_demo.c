
#include "gui_guider.h"
#include "littlevgl_support.h"
#include "lvgl.h"
#include "events_init.h"

#include "demo_common.h"
#include "lvgl_demo.h"
#include "network_demo.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

typedef enum _activePage
{
    PAGE_MENU       = 0,
    PAGE_LED        = 1,
    PAGE_NETWORK    = 2,
    PAGE_USB        = 3,
    PAGE_AV         = 4,
    PAGE_SYSTEM     = 5,
    PAGE_HELP       = 6,
} activePage;

/*******************************************************************************
 * Variables
 ******************************************************************************/

static volatile uint8_t s_current_action = 1;        // action index
static volatile bool s_lvgl_initialized = false;
static volatile activePage s_active_page = PAGE_LED;

lv_ui guider_ui;

static bool s_lgvl_ready = false;

/*******************************************************************************
 * Functions
 ******************************************************************************/

/*!
 * @brief adds item to the list of SSIDs
 */
void addItemToSSIDList(const char * text)
{
    if (s_active_page != PAGE_NETWORK)
    {
        return;
    }

	//Write style LV_BTN_PART_MAIN for screen2_WIFI_ssid_list
	static lv_style_t style_screen2_WIFI_ssid_list_main_child;
	lv_style_init(&style_screen2_WIFI_ssid_list_main_child);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_ssid_list_main_child
	lv_style_set_radius(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, &lv_font_simsun_28);

	lv_obj_t *screen2_WIFI_ssid_list_btn;
	screen2_WIFI_ssid_list_btn = lv_list_add_btn(guider_ui.screen2_WIFI_ssid_list, NULL, text);
	lv_obj_add_style(screen2_WIFI_ssid_list_btn, LV_BTN_PART_MAIN, &style_screen2_WIFI_ssid_list_main_child);
}

/*!
* @brief Opens the network screen
*/
void openNetworkScreen()
{
    setup_scr_screen2_WIFI(&guider_ui);
    lv_scr_load_anim(guider_ui.screen2_WIFI, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    initLEDs();

    s_active_page = PAGE_NETWORK;

    lv_list_clean(guider_ui.screen2_WIFI_ssid_list);

    ssidScan();
}

/*!
* @brief Opens the menu screen
*/
void openMenuScreen()
{
    setup_scr_screen0_MENU(&guider_ui);
    lv_scr_load_anim(guider_ui.screen0_MENU, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    initLEDs();

    s_active_page = PAGE_MENU;
}

/*!
* @brief Opens the LED screen
*/
void openLEDScreen()
{
    setup_scr_screen1_LEDs(&guider_ui);
    lv_scr_load_anim(guider_ui.screen1_LEDs, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    initLEDs();

    s_active_page = PAGE_LED;

}

/*!
* @brief Opens the USB screen
*/
void openUSBScreen()
{
    setup_scr_screen3_USB(&guider_ui);
    lv_scr_load_anim(guider_ui.screen3_USB, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    initLEDs();

    s_active_page = PAGE_USB;
}

/*!
* @brief Opens the A/V screen
*/
void openAVScreen()
{
    setup_scr_screen4_AV(&guider_ui);
    lv_scr_load_anim(guider_ui.screen4_AV, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    initLEDs();

    s_active_page = PAGE_AV;
}

/*!
* @brief Opens the System screen
*/
void openSystemScreen()
{
    setup_scr_screen5_SYSTEM(&guider_ui);
    lv_scr_load_anim(guider_ui.screen5_SYSTEM, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    initLEDs();

    s_active_page = PAGE_SYSTEM;
}

/*!
* @brief Opens the Help screen
*/
void openHelpScreen()
{
    setup_scr_screen6_HELP(&guider_ui);
    lv_scr_load_anim(guider_ui.screen6_HELP, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    initLEDs();

    s_active_page = PAGE_HELP;
}

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void lvgl_task(void *param)
{
    while (!isWifiReady())
    {
        vTaskDelay(15);
    }

    lv_port_pre_init();
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    s_lvgl_initialized = true;
    s_current_action = 1;

	set_red_led(false);
	set_green_led(false);
	set_blue_led(false);

    setup_ui(&guider_ui);
    events_init(&guider_ui);

    s_lgvl_ready = true;

    for (;;)
    {
        if (getInputSignal())
        {
            switch (s_current_action)
            {
                case 1:
                    openNetworkScreen();

                    s_current_action++;
                    break;
                
                case 2:
                    openUSBScreen();

                    s_current_action++;
                    break;
                
                case 3:
                    openAVScreen();

                    s_current_action++;
                    break;
                
                case 4:
                    openSystemScreen();

                    s_current_action++;
                    break;
                
                case 5:
                    openHelpScreen();

                    s_current_action++;
                    break;

                case 6:
                    openMenuScreen();

                    s_current_action++;
                    break;

                case 7:
                    openLEDScreen();

                    s_current_action = 1;
                    break;
            }

            setInputSignal(false);
        }

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

/*!
 * @brief returns 'true' if lvgl task has been properly initialized.
 */
bool isLvglReady(void)
{
    return s_lgvl_ready;
}
