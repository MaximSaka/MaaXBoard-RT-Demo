
#include "gui_guider.h"
#include "littlevgl_support.h"
#include "lvgl.h"
#include "events_init.h"

#include "demo_common.h"
#include "lvgl_demo.h"
#include "network_demo.h"
#include "usb_peripherals.h"
#include "expansion_i2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

typedef enum _activePage
{
    PAGE_NONE       = -1,
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

static volatile bool s_lvgl_initialized = false;
static volatile activePage s_active_page = PAGE_NONE;

lv_ui guider_ui;

static bool s_lgvl_ready = false;

static void (*s_page_refresh)(void) = NULL;

static bool s_hid_list_refresh_required = true;

static uint8_t s_i2c_scanned_nodes[16];

static char s_text_area_buffer[100];
static volatile char s_text_area_buffer_offset = 0;
static bool s_capture_mouse_input = false;
static bool s_capture_keyboard_input = false;

/*******************************************************************************
 * Functions
 ******************************************************************************/

/*!
 * @brief adds item to lvgl list
 */
void addItemToList(lv_obj_t * obj, const char * text)
{
	static lv_style_t list_child_style;
	lv_style_init(&list_child_style);

	lv_style_set_radius(&list_child_style, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&list_child_style, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&list_child_style, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&list_child_style, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&list_child_style, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&list_child_style, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&list_child_style, LV_STATE_DEFAULT, &lv_font_OpenSans_Light_28);

	lv_obj_t *list_btn;
	list_btn = lv_list_add_btn(obj, NULL, text);
	lv_obj_add_style(list_btn, LV_BTN_PART_MAIN, &list_child_style);
}

/*!
 * @brief add scanned i2c nodes to table
 */
void scani2cBusAndDisplay(void)
{
    char buffer[12];

    if (s_active_page != PAGE_USB)
    {
        return;
    }

    scan_i2c_bus(s_i2c_scanned_nodes);

    for (uint16_t row = 1; row < 9; row++)
    {
        uint16_t col = 1;

        for (int i2caddress = 0; i2caddress < 0x10; i2caddress++)
        {
            uint8_t curr_node = ((row - 1) * 16) + i2caddress;
            uint8_t index = curr_node / 8;
            uint8_t bit_pos = 7 - (curr_node % 8);
            uint8_t offset = (i2caddress % 4);
            uint8_t bufferOffset = offset * 3;

            if (s_i2c_scanned_nodes[index] & (1 << bit_pos))
            {
                sprintf(buffer + bufferOffset, "%02X", curr_node);
            } 
            else
            {
                sprintf(buffer + bufferOffset, "--");
            }

            if (offset < 3)
            {
                sprintf(buffer + bufferOffset + 2, ":");
            }
            else
            {
	            lv_table_set_cell_value(guider_ui.screen3_USB_ic2_table, row, col, buffer);
                col++;
            }
        }
    }
}

/*!
 * @brief send text to the HID input test text area
 */
void writeToHIDInputTextArea(const char* text)
{
    if (s_active_page != PAGE_USB)
    {
        return;
    }

    taskENTER_CRITICAL();

    s_text_area_buffer_offset += sprintf(s_text_area_buffer + s_text_area_buffer_offset, text);

    taskEXIT_CRITICAL();
}

/*!
 * @brief clear the HID input test text area buffer
 */
void clearTextAreaBuffer()
{
    if (s_active_page != PAGE_USB)
    {
        return;
    }

    taskENTER_CRITICAL();

    s_text_area_buffer[0] = '\0';
    s_text_area_buffer_offset = 0;

    taskEXIT_CRITICAL();
}

/*!
 * @brief clear the HID input test text area
 */
void clearTextArea()
{
    if (s_active_page != PAGE_USB)
    {
        return;
    }
    
    lv_textarea_set_text(guider_ui.screen3_USB_input_area, "");
}

/*!
 * @brief check if mouse input is being captured by HID input text area
 */
bool capturingMouseInputOnTA(void)
{
    if (s_active_page != PAGE_USB)
    {
        return false;
    }

    return s_capture_mouse_input;
}

/*!
 * @brief set text area to capture mouse input
 */
void setCaptureMouseInputOnTA(bool state)
{
    if (s_active_page != PAGE_USB)
    {
        return;
    }

    s_capture_mouse_input = state;

    if (state)
    {
        s_capture_keyboard_input = false;

        lv_btn_set_state(guider_ui.screen3_USB_kbd_imgbtn, LV_BTN_STATE_RELEASED);

        clearTextAreaBuffer();
        clearTextArea();
    }
}

/*!
 * @brief check if keyboard input is being captured by HID input text area
 */
bool capturingKeyboardInputOnTA(void)
{
    if (s_active_page != PAGE_USB)
    {
        return false;
    }

    return s_capture_keyboard_input;
}

/*!
 * @brief set text area to capture keyboard input
 */
void setCaptureKeyboardInputOnTA(bool state)
{
    if (s_active_page != PAGE_USB)
    {
        return;
    }

    s_capture_keyboard_input = state;

    if (state)
    {
        s_capture_mouse_input = false;

        lv_btn_set_state(guider_ui.screen3_USB_mouse_imgbtn, LV_BTN_STATE_RELEASED);

        clearTextAreaBuffer();
        clearTextArea();
    }
}

/*!
 * @brief refresh the HID input test text area
 */
void refreshTextArea()
{
    if (s_active_page != PAGE_USB)
    {
        return;
    }

    taskENTER_CRITICAL();

    if (s_text_area_buffer[0] != '\0')
    {
        lv_textarea_add_text(guider_ui.screen3_USB_input_area, s_text_area_buffer);
        s_text_area_buffer[0] = '\0';
        s_text_area_buffer_offset = 0;
    }

    taskEXIT_CRITICAL();
}

/*!
 * @brief updates the list of HID devices in the USB page.
 */
void refreshHIDList(void)
{
    if (s_active_page != PAGE_USB)
    {
        return;
    }

    if (!s_hid_list_refresh_required)
        return;

    lv_list_clean(guider_ui.screen3_USB_usb_list);

    char buffer[100];

    if (usb_devices[0].deviceExist) {
    	sprintf(buffer, "hid mouse: pid=0x%x vid=0x%x addr=%d",
    			usb_devices[0].devicePid, usb_devices[0].deviceVid, usb_devices[0].address);
        addItemToList(guider_ui.screen3_USB_usb_list, buffer); 
    }

    if (usb_devices[1].deviceExist) {
    	sprintf(buffer, "hid keyboard: pid=0x%x vid=0x%x addr=%d",
        		usb_devices[1].devicePid, usb_devices[1].deviceVid, usb_devices[1].address);
        addItemToList(guider_ui.screen3_USB_usb_list, buffer); 
    }

    s_hid_list_refresh_required = false;
}

/*!
 * @brief refreshes the USB page.
 */
void refreshUSBPage(void)
{
    refreshHIDList();
    refreshTextArea();
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

	addItemToList(guider_ui.screen2_WIFI_ssid_list, text);
}

void setLedRedImgState(bool state)
{
    if (s_active_page != PAGE_LED)
    {
        return;
    }

    lv_obj_set_hidden(guider_ui.screen1_LEDs_led_red_off, state);
}

void setLedGreenImgState(bool state)
{
    if (s_active_page != PAGE_LED)
    {
        return;
    }

    lv_obj_set_hidden(guider_ui.screen1_LEDs_led_green_off, state);
}

void setLedBlueImgState(bool state)
{
    if (s_active_page != PAGE_LED)
    {
        return;
    }

    lv_obj_set_hidden(guider_ui.screen1_LEDs_led_blue_off, state);
}

/*!
* @brief Init color LEDs
*/
void initDefaultPageInteractions()
{
    initLEDs();

    s_page_refresh = NULL;
}

/*!
* @brief Opens the network screen
*/
void openNetworkScreen()
{
    setup_scr_screen2_WIFI(&guider_ui);
    lv_scr_load_anim(guider_ui.screen2_WIFI, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_NETWORK;

    initDefaultPageInteractions();

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

    initDefaultPageInteractions();
}

/*!
* @brief Opens the LED screen
*/
void openLEDScreen()
{
    setup_scr_screen1_LEDs(&guider_ui);
    lv_scr_load_anim(guider_ui.screen1_LEDs, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_LED;

    initDefaultPageInteractions();
}

/*!
* @brief Opens the USB screen
*/
void openUSBScreen()
{
    setup_scr_screen3_USB(&guider_ui);
    lv_scr_load_anim(guider_ui.screen3_USB, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_USB;

    clearTextAreaBuffer();
    s_capture_mouse_input = false;
    s_capture_keyboard_input = false;

    initDefaultPageInteractions();

    s_page_refresh = &refreshUSBPage;

    s_hid_list_refresh_required = true;

    scani2cBusAndDisplay();
}

/*!
* @brief Opens the A/V screen
*/
void openAVScreen()
{
    setup_scr_screen4_AV(&guider_ui);
    lv_scr_load_anim(guider_ui.screen4_AV, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_AV;

    initDefaultPageInteractions();
}

/*!
* @brief Opens the System screen
*/
void openSystemScreen()
{
    setup_scr_screen5_SYSTEM(&guider_ui);
    lv_scr_load_anim(guider_ui.screen5_SYSTEM, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_SYSTEM;

    initDefaultPageInteractions();
}

/*!
* @brief Opens the Help screen
*/
void openHelpScreen()
{
    setup_scr_screen6_HELP(&guider_ui);
    lv_scr_load_anim(guider_ui.screen6_HELP, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

    s_active_page = PAGE_HELP;

    initDefaultPageInteractions();
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

/*!
 * @brief indicate that array of connected HIDs has been refreshed.
 */
void setHIDsRefreshed(void)
{
    s_hid_list_refresh_required = true;
}

/*******************************************************************************
 * Task
 ******************************************************************************/

void lvgl_task(void *param)
{
    lv_port_pre_init();
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    s_lvgl_initialized = true;

    setup_ui(&guider_ui);
    events_init(&guider_ui);

    s_lgvl_ready = true;

	set_red_led(false);
	set_green_led(false);
	set_blue_led(false);

    s_page_refresh = NULL;

    openMenuScreen();

    for (;;)
    {
        if (getInputSignal())
        {
            switch (s_active_page)
            {
                case PAGE_LED:
                    openNetworkScreen();
                    break;
                
                case PAGE_NETWORK:
                    openUSBScreen();
                    break;
                
                case PAGE_USB:
                    openAVScreen();
                    break;
                
                case PAGE_AV:
                    openSystemScreen();
                    break;
                
                case PAGE_SYSTEM:
                    openHelpScreen();
                    break;

                case PAGE_NONE:
                case PAGE_HELP:
                    openMenuScreen();
                    break;

                case PAGE_MENU:
                    openLEDScreen();
                    break;
            }

            setInputSignal(false);
        }

        if (s_page_refresh != NULL)
        {
            (*s_page_refresh)();
        }

        lv_task_handler();
        vTaskDelay(5);
    }
}
