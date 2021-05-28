
#include "gui_guider.h"
#include "littlevgl_support.h"
#include "lvgl.h"
#include "events_init.h"

#include "demo_common.h"
#include "lvgl_demo.h"
#include "network_demo.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/

static volatile uint8_t s_current_action = 1;        // action index
static volatile bool s_input_signal = false;         // S1 button switch page signal

static volatile bool s_red_led_state = false;
static volatile bool s_green_led_state = false;
static volatile bool s_blue_led_state = false;

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
void setInputSignal(bool state)
{
    s_input_signal = state;
}

/*!
* @brief Gets the input signal state
*/
bool getInputSignal()
{
    return s_input_signal;
}

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

// void console_task(void *param)
// {
//     while (!isWifiReady() || !isLvglReady())
//     {
//         vTaskDelay(15);
//     }

//     int32_t result = 0;
//     (void)result;

//     printSeparator();

//     menuPrint();

//     while (1)
//     {
//         int ch = pollChar();

//         if (ch != -1)
//         {
//             menuAction(ch);
//         }

//         // os_thread_sleep(os_msec_to_ticks(500));
//         vTaskDelay(5);
//     }
// }

void set_red_led(bool state)
{
	s_red_led_state = state;

    GPIO_PinWrite(BOARD_USER_LED_RED_GPIO, BOARD_USER_LED_RED_GPIO_PIN, state ? 1U : 0U);
}

void set_green_led(bool state)
{
	s_green_led_state = state;

    GPIO_PinWrite(BOARD_USER_LED_GPIO, BOARD_USER_LED_GPIO_PIN, state ? 1U : 0U);
}

void set_blue_led(bool state)
{
	s_blue_led_state = state;

    GPIO_PinWrite(BOARD_USER_LED_BLUE_GPIO, BOARD_USER_LED_BLUE_GPIO_PIN, state ? 1U : 0U);
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

/*!
* @brief Init color LEDs
*/
void initLEDs()
{
	set_red_led(false);
	set_green_led(false);
	set_blue_led(false);
}
