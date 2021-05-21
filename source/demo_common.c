
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
    PAGE_MENU       = 0,
    PAGE_LED        = 1,
    PAGE_NETWORK    = 2,
    PAGE_USB        = 3,
    PAGE_AV      = 4,
    PAGE_SYSTEM     = 5,
    PAGE_HELP       = 6,
} activePage;

/*******************************************************************************
 * Variables
 ******************************************************************************/

static volatile uint8_t s_current_action = 1;        // action index
static volatile bool s_input_signal = false;         // S1 button switch page signal
static volatile bool s_lvgl_initialized = false;
static volatile activePage s_active_page = PAGE_LED;

static volatile bool s_red_led_state = false;
static volatile bool s_green_led_state = false;
static volatile bool s_blue_led_state = false;

lv_ui guider_ui;

static bool s_lgvl_ready = false;

/*******************************************************************************
 * Functions
 ******************************************************************************/

void printSeparator(void)
{
    PRINTF("========================================\r\n");
}

static void menuPrint(void);

typedef struct
{
    char key;
    void (*func)(void);
    const char *text;
} menu_item_t;

menu_item_t menuItems[] = {
    {'s', ssidScan, "Start Scan for SSIDs"},
    {'p', printWlanInfo, "Print All Network info"},
    {'h', menuPrint, "Help (print this menu)"},
    {0, NULL, NULL},
};

static void menuAction(int ch)
{
    if (ch == '\r' || ch == ' ')
    {
        printSeparator();
        return;
    }

    for (int i = 0; menuItems[i].func != NULL; i++)
    {
        if (menuItems[i].key == ch)
        {
            PRINTF("Key '%c': %s\r\n", ch, menuItems[i].text);
            menuItems[i].func();
            return;
        }
    }
    PRINTF("ERROR: No action bound to '%c'\r\n", ch);
}

static void menuPrint(void)
{
    for (int i = 0; menuItems[i].text != NULL; i++)
    {
        if (menuItems[i].key)
            PRINTF("  %c  %s\r\n", menuItems[i].key, menuItems[i].text);
        else
            PRINTF("  %d  %s\r\n", i, menuItems[i].text);
    }
}

static int pollChar()
{
    //    if (!UART_HAL_GetStatusFlag(BOARD_DEBUG_UART_BASEADDR, kUartRxDataRegFull))
    //        return -1;
    //
    //    uint8_t ch;
    //    UART_HAL_Getchar(BOARD_DEBUG_UART_BASEADDR, &ch);
    //    // Flush the UART to avoid the "OpenSDA UART infinite RX FIFO" bug:
    //    // If user presses keys very quickly then after a while, the UART enters
    //    // a mode where the same sequence of characters are repeatedly returned
    //    // by UART_HAL_Getchar(). Even a hard reset does not fix it.
    //    // Only way to recover is by unplugging OpenSDA USB.
    //    UART_HAL_FlushRxFifo(BOARD_DEBUG_UART_BASEADDR);

    int tmp;
    // TODO: verify the message above. Which board has this issue ?
    tmp = GETCHAR();
    return tmp;
}

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

    s_active_page = PAGE_MENU;
}

/*!
* @brief Opens the LED screen
*/
void openLEDScreen()
{
    setup_scr_screen1_LEDs(&guider_ui);
    lv_scr_load_anim(guider_ui.screen1_LEDs, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_LED;
}

/*!
* @brief Opens the USB screen
*/
void openUSBScreen()
{
    setup_scr_screen3_USB(&guider_ui);
    lv_scr_load_anim(guider_ui.screen3_USB, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_USB;
}

/*!
* @brief Opens the A/V screen
*/
void openAVScreen()
{
    setup_scr_screen4_AV(&guider_ui);
    lv_scr_load_anim(guider_ui.screen4_AV, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_AV;
}

/*!
* @brief Opens the System screen
*/
void openSystemScreen()
{
    setup_scr_screen5_SYSTEM(&guider_ui);
    lv_scr_load_anim(guider_ui.screen5_SYSTEM, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_SYSTEM;
}

/*!
* @brief Opens the Help screen
*/
void openHelpScreen()
{
    setup_scr_screen6_HELP(&guider_ui);
    lv_scr_load_anim(guider_ui.screen6_HELP, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_HELP;
}

/*!
 * @brief Toggles the red button
 */
void toggleRedButton(bool state)
{
    if (state)
    {
        lv_obj_set_state(guider_ui.screen1_LEDs_redbtn0, LV_STATE_CHECKED|LV_STATE_PRESSED);
        lv_event_send(guider_ui.screen1_LEDs_redbtn0, LV_EVENT_PRESSED, NULL);
    }
    else
    {
        lv_obj_set_state(guider_ui.screen1_LEDs_redbtn0, LV_STATE_DEFAULT);
        lv_event_send(guider_ui.screen1_LEDs_redbtn0, LV_EVENT_RELEASED, NULL);
    }
}

/*!
 * @brief Toggles the green button
 */
void toggleGreenButton(bool state)
{
    if (state)
    {
        lv_obj_set_state(guider_ui.screen1_LEDs_greenbtn0, LV_STATE_CHECKED|LV_STATE_PRESSED);
        lv_event_send(guider_ui.screen1_LEDs_greenbtn0, LV_EVENT_PRESSED, NULL);
    }
    else
    {
        lv_obj_set_state(guider_ui.screen1_LEDs_greenbtn0, LV_STATE_DEFAULT);
        lv_event_send(guider_ui.screen1_LEDs_greenbtn0, LV_EVENT_RELEASED, NULL);
    }
}

/*!
 * @brief Toggles the blue button
 */
void toggleBlueButton(bool state)
{
    if (state)
    {
        lv_obj_set_state(guider_ui.screen1_LEDs_bluebtn0, LV_STATE_CHECKED|LV_STATE_PRESSED);
        lv_event_send(guider_ui.screen1_LEDs_bluebtn0, LV_EVENT_PRESSED, NULL);
    }
    else
    {
        lv_obj_set_state(guider_ui.screen1_LEDs_bluebtn0, LV_STATE_DEFAULT);
        lv_event_send(guider_ui.screen1_LEDs_bluebtn0, LV_EVENT_RELEASED, NULL);
    }
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
        if (s_input_signal)
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

            s_input_signal = false;
        }

        if (s_active_page == PAGE_LED)
        {
            GPIO_PinWrite(BOARD_USER_LED_GPIO,      BOARD_USER_LED_GPIO_PIN,      get_green_led() ? 1U : 0U);
            GPIO_PinWrite(BOARD_USER_LED_RED_GPIO,  BOARD_USER_LED_RED_GPIO_PIN,  get_red_led()   ? 1U : 0U);
            GPIO_PinWrite(BOARD_USER_LED_BLUE_GPIO, BOARD_USER_LED_BLUE_GPIO_PIN, get_blue_led()  ? 1U : 0U);
        }
        else
        {
            GPIO_PinWrite(BOARD_USER_LED_GPIO,      BOARD_USER_LED_GPIO_PIN,      0U);
            GPIO_PinWrite(BOARD_USER_LED_RED_GPIO,  BOARD_USER_LED_RED_GPIO_PIN,  0U);
            GPIO_PinWrite(BOARD_USER_LED_BLUE_GPIO, BOARD_USER_LED_BLUE_GPIO_PIN, 0U);
        }

        lv_task_handler();
        vTaskDelay(5);
    }
}

void console_task(void *param)
{
    while (!isWifiReady() || !s_lgvl_ready)
    {
        vTaskDelay(15);
    }

    int32_t result = 0;
    (void)result;

    printSeparator();

    menuPrint();

    while (1)
    {
        int ch = pollChar();

        if (ch != -1)
        {
            menuAction(ch);
        }

        // os_thread_sleep(os_msec_to_ticks(500));
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

void set_red_led(bool state)
{
	s_red_led_state = state;
}

void set_green_led(bool state)
{
	s_green_led_state = state;
}

void set_blue_led(bool state)
{
	s_blue_led_state = state;
}

bool get_red_led()
{
	return s_red_led_state;
}

bool get_green_led()
{
	return s_green_led_state;
}

bool get_blue_led()
{
	return s_blue_led_state;
}
