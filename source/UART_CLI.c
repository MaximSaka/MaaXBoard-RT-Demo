

/*
 * UART_CLI.c
 *
 *  Created on: May 14, 2021
 *      Author: gulziibayar
 */

/*
 * MaaxBoard RT CLI use LPUART1 on J17 Debug UART 3 pin header
 *
 * Lists all the registered commands
 * clear    : Clear Screen by sending VT100 Escape Code
 * led ***  : on/off leds
 * scan     : Scan I2C bus
 * lsusb    : List USB devices
 * mouse    : mouse DEMO
 * keyboard : keyboard DEMO
 * q/ctrl+c : Abort command
*/

#include "fsl_debug_console.h"
#include <expansion_i2c.h>
#include "UART_CLI.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "event_groups.h"
#include "timers.h"
#include "board.h"
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "FreeRTOS_CLI.h"
#include <stdio.h>
#include "usb_peripherals.h"
#include "globals.h"
#include "fsl_lpuart.h"
#include "network_demo.h"
/*******************************************************************************
 * Globals
 ******************************************************************************/
extern struct hid_peripheral usb_devices[2];
static uint8_t i2cScannedNodes[16];
static lpuart_rtos_handle_t *handle;
static QueueHandle_t *wifi_cmd_queue;
static EventGroupHandle_t event_group_wifi;
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Task priorities. */
#define uart_task_PRIORITY (configMAX_PRIORITIES - 1)

#define MAX_INPUT_LENGTH    50
//#define MAX_OUTPUT_LENGTH   configCOMMAND_INT_MAX_OUTPUT_SIZE
#define MAX_OUTPUT_LENGTH   128
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* Constant TEXT for cli */
const char *TEXT_WELCOME            = "**** MaaxBoard RT CLI ****\r\n>";
const char *TEXT_ABORT_CMD			= "\r\n***Command Aborted****\r\n>";
const char *TEXT_BUFFER_OVERRUN     = "\r\nRing buffer overrun!\r\n";
const char *TEXT_HW_OVERRUN 		= "\r\nHardware buffer overrun!\r\n";
const char *TEXT_VT100_CLEARSCREEN  = "\033[2J\033[H";
const char *TEXT_SCAN_I2C			= "\r\nList of i2c addresses:\r\n";
const char *TEXT_LIST_USB			= "\r\nList of USB devices:\r\n";
const char *TEXT_MOUSE_DEMO		    = "\r\nMove the mouse:\r\n";
const char *TEXT_KBOARD_DEMO		= "\r\nType Keyboard:\r\n";
const char *TEXT_LED_ERROR			= "\r\nParam error: Eg: led 101\r\n";
const char *TEXT_CMD_ERROR			= "\r\nCommand Error\r\n";
const char *TEXT_FREETOS_STATS		= "\r\nTask                    Abs Time        %Time\r\n"
										   "____________________________________________\r\n";

/*******************************************************************************
 * Code
 ******************************************************************************/

extern volatile uint32_t cmdEnable;
// pointer used points to allocated temporary memory on the heap.
static void *ptr_temp = NULL;
static char *ptr_aux = NULL;
static volatile EventBits_t bits;
static struct t_user_wifi_command wifi_cmd_toSend;
/*!
 * @brief Application entry point.
 */

/* Utility function prototypes */
static uint16_t copyTillNewLine(char * dest, char *src);

/* Console functions starts here */

/*****************************************************************************\
 * Function:    clearCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function clears the screen. It is run by the CLI interpreter
\*****************************************************************************/
BaseType_t clearCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    static int processed = 0;

    const char *clearScreen = TEXT_VT100_CLEARSCREEN;
    // Only allowed to write up top xWriteBufferLen bytes ...
    strncpy(pcWriteBuffer,&clearScreen[processed],xWriteBufferLen-1);
    pcWriteBuffer[xWriteBufferLen-1]=0;

    processed = processed + xWriteBufferLen-1;
    if(processed < (int)strlen(clearScreen))
        return pdTRUE;

    processed = 0;
    return pdFALSE;
}

/*****************************************************************************\
 * Function:    listUSBCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function prints lists all the USB hid devices on the console.
\*****************************************************************************/
BaseType_t listUSBCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    static int processed = 0;
    const char *titleText = TEXT_LIST_USB;
    // Only allowed to write up top xWriteBufferLen bytes ...
    strncpy(pcWriteBuffer,&titleText[0],xWriteBufferLen-1);

    if (usb_devices[0].deviceExist) {
    	sprintf(pcWriteBuffer+strlen(pcWriteBuffer), "hid mouse attached:pid=0x%x vid=0x%x addr=%d\r\n",
    			usb_devices[0].devicePid, usb_devices[0].deviceVid, usb_devices[0].address);
    }
    if (usb_devices[1].deviceExist) {
    	sprintf(pcWriteBuffer+strlen(pcWriteBuffer), "hid keyboard attached:pid=0x%x vid=0x%x addr=%d\r\n",
        		usb_devices[1].devicePid, usb_devices[1].deviceVid, usb_devices[1].address);
    }

    pcWriteBuffer[xWriteBufferLen-1]=0;
    return pdFALSE;
}

/*****************************************************************************\
 * Function:    scanCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function prints discovered i2c nodes on the console.
\*****************************************************************************/
BaseType_t scanCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    static int processed = 0;
    BaseType_t xReturn;
    uint16_t offset;
    // first time calling this function
    if (processed==0)
    {
    	// i2cScannedNodes stores the all the discovered address info.
    	scan_i2c_bus(i2cScannedNodes);
        const char *text = TEXT_SCAN_I2C;
        // Only allowed to write up top xWriteBufferLen bytes ...
        strncpy(pcWriteBuffer,&text[0],xWriteBufferLen-1);
    	strncpy(pcWriteBuffer+strlen(pcWriteBuffer), "   ", 4);
    	offset = strlen(pcWriteBuffer);
    	for(int i=0;i<0x10;i++)
    	{
    		sprintf(pcWriteBuffer+offset+i*3, "%02X ", i);
    	}
    	processed++;
    	xReturn = pdTRUE;
    } else if (processed < 9)
    {
    	uint8_t index = 0;
    	uint8_t bit_pos = 0;
    	sprintf(pcWriteBuffer, "\r\n%02X ", (processed-1)<<4);
    	offset = strlen(pcWriteBuffer);
    	for (int i2caddress=0; i2caddress<0x10; i2caddress++)
    	{
    		uint8_t curr_node = (processed-1)*16+i2caddress;
    		index = curr_node/8;
    		bit_pos = 7-(curr_node%8);
    		if (i2cScannedNodes[index] & (1<<bit_pos))
    		{
    			sprintf(pcWriteBuffer+offset+i2caddress*3, "%02X ", curr_node);
    		} else
    		{
    			strncpy(pcWriteBuffer+offset+i2caddress*3, "-- ", 4);
    		}
    	}
    	processed++;
    	xReturn = pdTRUE;
    } else
    {
    	processed = 0;
    	pcWriteBuffer[0]=0;
    	xReturn = pdFALSE;
    }

    return xReturn;
}

/*****************************************************************************\
 * Function:    mouseCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function enables printing mouse coordinates on the console.
\*****************************************************************************/
BaseType_t mouseCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    static int processed = 0;

    const char *text = TEXT_MOUSE_DEMO;
    // Only allowed to write up top xWriteBufferLen bytes ...
    strncpy(pcWriteBuffer,&text[processed],xWriteBufferLen-1);
    pcWriteBuffer[xWriteBufferLen-1]=0;

    cmdEnable |= (1<<mouseLogEn);
    return pdFALSE;
}

/*****************************************************************************\
 * Function:    keyboardCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function enables printing keyboard keys on the console.
\*****************************************************************************/
BaseType_t keyboardCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    static int processed = 0;

    const char *text = TEXT_KBOARD_DEMO;
    // Only allowed to write up top xWriteBufferLen bytes ...
    strncpy(pcWriteBuffer,&text[processed],xWriteBufferLen-1);
    pcWriteBuffer[xWriteBufferLen-1]=0;

    cmdEnable |= (1<<keyboardLogEn);
    return pdFALSE;
}

/*****************************************************************************\
 * Function:    controlLedCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function controls individual leds. E.g. led 101 -> red on, green off, blue on
\*****************************************************************************/
BaseType_t controlLedCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    /* Expecting one parameter */
    int8_t *pcParameter1;
    BaseType_t xParameter1StringLength;

    pcParameter1 = (int8_t *)FreeRTOS_CLIGetParameter
                        (
                          /* The command string itself. */
                          pcCommandString,
                          /* Return the first parameter. */
                          1,
                          /* Store the parameter string length. */
                          &xParameter1StringLength
                        );
    /* Terminate parameter. */
    pcParameter1[ xParameter1StringLength ] = 0x00;

    uint8_t validInput = 1;
    /* input parameter validation */
    if (xParameter1StringLength == 3) {
    	uint8_t count = 0;
    	for (uint8_t i=0; i<3; i++) {
    		if(pcParameter1[i] == 0x31 || pcParameter1[i] == 0x30) {
    			count++;
    		}
    	}
    	if (count==3) {
    		toggleRedButton(pcParameter1[0]==0x30?0:1);
    		toggleGreenButton(pcParameter1[1]==0x30?0:1);
    		toggleBlueButton(pcParameter1[2]==0x30?0:1);
    		pcWriteBuffer[0] = 0; // to make sure
    		return pdFALSE;
    	}
    }

    // Only allowed to write up top xWriteBufferLen bytes ...
    strncpy(pcWriteBuffer,TEXT_LED_ERROR,xWriteBufferLen-1);
    pcWriteBuffer[xWriteBufferLen-1]=0;

    return pdFALSE;
}

/*****************************************************************************\
 * Function:    exitCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function disables printing mouse, keyboard data on the console.
\*****************************************************************************/
BaseType_t exitCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    static int processed = 0;

    char *text = "\r\nquit\r\n";
    // Only allowed to write up top xWriteBufferLen bytes ...
    strncpy(pcWriteBuffer,&text[processed],xWriteBufferLen-1);
    pcWriteBuffer[xWriteBufferLen-1]=0;

    cmdEnable = 0;
    return pdFALSE;
}

/*****************************************************************************\
 * Function:    scanWifiCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function scans the wifi networks and print.
\*****************************************************************************/
BaseType_t scanWifiCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    static int processed = 0;

    pcWriteBuffer[0]=0;
    ssidScan();

    return pdFALSE;
}

/*****************************************************************************\
 * Function:    taskStatsCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function returns list of tasks.
\*****************************************************************************/
BaseType_t taskStatsCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    static int processed = 0;
    int char_cnt = 0;
    UBaseType_t cnt;
    BaseType_t xReturn;
    char *text;
    // initial call
    if (processed == 0)
    {
    	cnt = uxTaskGetNumberOfTasks();
    	if (cnt>0 && cnt<20)
    	{
    		ptr_temp = pvPortMalloc(40*cnt);
    		vTaskGetRunTimeStats((char *)ptr_temp);
    		ptr_aux = (char *)ptr_temp;
    		text = (char *)TEXT_FREETOS_STATS;
    		strncpy(pcWriteBuffer,&text[0],xWriteBufferLen-1);
    		processed++;
    		xReturn = pdTRUE;
    	}
    	else
    	{
    		// more than 20 or 0 tasks
    		text = "\r\ncan't list more than 20\r\n";
    	    // Only allowed to write up top xWriteBufferLen bytes ...
    	    strncpy(pcWriteBuffer,&text[0],xWriteBufferLen-1);
    		xReturn = pdFALSE;
    	}
    }
    else if (processed == 1)
    {
    	char_cnt = copyTillNewLine(pcWriteBuffer, ptr_aux);
		ptr_aux = ptr_aux + char_cnt;
		if (char_cnt)
		{
			xReturn = pdTRUE;
		}
		else
		{
			xReturn = pdFALSE;
	    	// free the memory
	    	vPortFree(ptr_temp);
	    	pcWriteBuffer[0] = 0;
	    	processed = 0;
		}
    }
    return xReturn;
}

/*****************************************************************************\
 * Function:    wifiScanCommand
 * Input:       char *pcWriteBufer,size_t xWriteBufferLen,const char *pcCommandString
 * Returns:     BaseType_t
 * Description:
 *     This function initiates wifi scan, prints discovered networks on the console.
\*****************************************************************************/
BaseType_t wifiScanCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString )
{
    (void)pcCommandString;
    static int processed = 0;
    BaseType_t xReturn;

    const EventBits_t xBitsToWaitFor = WIFI_CONSOLE_NDATA;
    char *text;
    if (processed == 0)	// initial call
    {
    	wifi_cmd_toSend.cmd_type = WIFI_SCAN;
		wifi_cmd_toSend.task_name = CONSOLE_TASK;
		wifi_cmd_toSend.payload = NULL;
		xEventGroupClearBits(event_group_wifi, xBitsToWaitFor);
		xQueueSend(*wifi_cmd_queue, (void *) &wifi_cmd_toSend, 10);
		text = "\r\nScanning Wifi\r\n";
		// Only allowed to write up top xWriteBufferLen bytes ...
		strncpy(pcWriteBuffer,&text[0],xWriteBufferLen-1);
		pcWriteBuffer[xWriteBufferLen-1]=0;
		processed++;
		xReturn = pdTRUE;
    }
    else if (processed==1)
    {
    	// wait 10seconds;
    	bits = xEventGroupWaitBits(event_group_wifi, xBitsToWaitFor, pdTRUE, pdFALSE, 30000 / portTICK_RATE_MS);

    	if (bits&WIFI_CONSOLE_NDATA)
    	{
    		//event arrived
    		text = "\r\nScan ended\r\n";
			// Only allowed to write up top xWriteBufferLen bytes ...
			strncpy(pcWriteBuffer,&text[0],xWriteBufferLen-1);
			sprintf(pcWriteBuffer+strlen(pcWriteBuffer),"ssid cnt=%d\r\n", shared_buff[2]);
			pcWriteBuffer[xWriteBufferLen-1]=0;
			processed = 0;
			xReturn = pdFALSE;
    	}
    	else
    	{
    		//no event arrived
    		text = "\r\n Wifi not working\r\n";
			strncpy(pcWriteBuffer,text,xWriteBufferLen-1);
			pcWriteBuffer[xWriteBufferLen-1]=0;
			processed = 0;
			xReturn = pdFALSE;
    	}
    }
    return xReturn;
}

/* Utility functions */

/*****************************************************************************\
 * Function:    copyTillNewLine
 * Input:       char * dest, char *src
 * Returns:     number bytes copied
 * Description:
 *     This function copies the src data to destination until first \n or 0.
\*****************************************************************************/
static uint16_t copyTillNewLine(char * dest, char *src)
{
	uint16_t cnt = 0;
	while(*src!=0 && *src!='\n')
	{
		*(dest++) = *(src++);
		cnt++;
	}
    // terminate the string
    if (*src=='\n')
    {
        *(dest++) = *src;
        cnt++;
    }
    *dest = 0;
	return cnt;
}

/* Console command structs */

static const CLI_Command_Definition_t clearCommandStruct =
{
    "clr",
    " clr      : Clear Screen \r\n",
    clearCommand,
    0
};

static const CLI_Command_Definition_t i2cScanCommandStruct =
{
    "s",
    " s        : Scan I2C bus \r\n",
	scanCommand,
    0
};

static const CLI_Command_Definition_t listUSBCommandStruct =
{
    "l",
    " l        : List USB devices \r\n",
	listUSBCommand,
    0
};

static const CLI_Command_Definition_t controlLedCommandStruct =
{
    "led",
    " led ***  : on/off leds \r\n",
	controlLedCommand,
    1
};

static const CLI_Command_Definition_t enableMouseCommandStruct =
{
    "m",
    " m        : mouse DEMO \r\n",
	mouseCommand,
    0
};

static const CLI_Command_Definition_t enableKeyboardCommandStruct =
{
    "k",
    " k        : keyboard DEMO \r\n",
	keyboardCommand,
    0
};

static const CLI_Command_Definition_t exitCommandStruct =
{
    "q",
    " q/ctrl+c : Abort command \r\n",
	exitCommand,
    0
};

static const CLI_Command_Definition_t wifiScanCommandStruct =
{
    "scan",
    " scan     : Scan SSID \r\n",
	scanWifiCommand,
    0
};

static const CLI_Command_Definition_t taskStatsCommandStruct =
{
    "stats",
    " stats    : List of tasks stats \r\n",
	taskStatsCommand,
    0
};

static const CLI_Command_Definition_t scanWifiCommandStruct =
{
    "wscan",
    " wscan    : scan wifi \r\n",
	wifiScanCommand,
    0
};

/*!
 * @brief Task responsible for loopback.
 */
void console_task(void *pvParameters)
{
	custom_console_instance_t *t_console_instance = (custom_console_instance_t *)pvParameters;
	handle = t_console_instance->uart_handle;
	wifi_cmd_queue = t_console_instance->cmd_queue;
	event_group_wifi = t_console_instance->event_group_wifi;

	char pcOutputString[ MAX_OUTPUT_LENGTH ], pcInputString[ MAX_INPUT_LENGTH ];

	memset( pcInputString, 0x00, MAX_INPUT_LENGTH );
	uint8_t cRxedChar, cInputIndex = 0;
	BaseType_t xMoreDataToFollow;
    int error;
    size_t n = 0;

    /* Initialize i2c peripheral */
    init_expansion_i2c();

//    if (kStatus_Success != LPUART_RTOS_Init(&handle, &t_handle, &lpuart_config))
//    {
//        vTaskSuspend(NULL);
//    }

    /* Send introduction message. */
    if (kStatus_Success != LPUART_RTOS_Send(handle, (uint8_t *)TEXT_WELCOME, strlen(TEXT_WELCOME)))
    {
        vTaskSuspend(NULL);
    }

    /* Registering cli commands*/
    FreeRTOS_CLIRegisterCommand( &clearCommandStruct );
    FreeRTOS_CLIRegisterCommand( &controlLedCommandStruct );
    FreeRTOS_CLIRegisterCommand( &i2cScanCommandStruct );
    FreeRTOS_CLIRegisterCommand( &listUSBCommandStruct );
    FreeRTOS_CLIRegisterCommand( &enableMouseCommandStruct );
    FreeRTOS_CLIRegisterCommand( &enableKeyboardCommandStruct );
    FreeRTOS_CLIRegisterCommand( &wifiScanCommandStruct );
    FreeRTOS_CLIRegisterCommand( &taskStatsCommandStruct );
    FreeRTOS_CLIRegisterCommand( &scanWifiCommandStruct );
    FreeRTOS_CLIRegisterCommand( &exitCommandStruct );

    /* Receive user input and send it back to terminal. */

    while(1)
    {
    	LPUART_RTOS_Receive(handle, &cRxedChar, sizeof( cRxedChar ), &n);
		if( cRxedChar == '\r' )
		{
			/* A newline character was received, so the input command string is
			complete and can be processed.  Transmit a line separator, just to
			make the output easier to read. */
			LPUART_RTOS_Send(handle,&cRxedChar,1);
			/* The command interpreter is called repeatedly until it returns
			pdFALSE.  See the "Implementing a command" documentation for an
			exaplanation of why this is. */
			do
			{
				/* Send the command string to the command interpreter.  Any
				output generated by the command interpreter will be placed in the
				pcOutputString buffer. */
				xMoreDataToFollow = FreeRTOS_CLIProcessCommand
				(
					pcInputString,   /* The command string.*/
					pcOutputString,  /* The output buffer. */
					MAX_OUTPUT_LENGTH/* The size of the output buffer. */
				);
				/* Write the output generated by the command interpreter to the
				console. */
				if (pcOutputString[0] !=0)
				{
					LPUART_RTOS_Send(handle, pcOutputString, strlen( pcOutputString ) );
				}
			} while( xMoreDataToFollow != pdFALSE );
			//print prompt after each command
			sprintf(pcOutputString, "\r\n> ", 4);
			LPUART_RTOS_Send(handle, pcOutputString, strlen( pcOutputString ) );
			/* All the strings generated by the input command have been sent.
			Processing of the command is complete.  Clear the input string ready
			to receive the next command. */
			cInputIndex = 0;
			memset( pcInputString, 0x00, MAX_INPUT_LENGTH );
		}
		else if (cRxedChar == 0x03)	// end of text, ctrl+c
		{
			cmdEnable = 0;
			LPUART_RTOS_Send(handle, (uint8_t *)TEXT_ABORT_CMD, strlen(TEXT_ABORT_CMD));
		}
		else
		{
		/* The if() clause performs the processing after a newline character
		is received.  This else clause performs the processing if any other
		character is received. */
			if( cRxedChar == 8 ) // backspace character
			{
				LPUART_RTOS_Send(handle,&cRxedChar,1);
				/* Backspace was pressed.  Erase the last character in the input
				buffer - if there are any. */
				if( cInputIndex > 0 )
				{
					cInputIndex--;
					pcInputString[ cInputIndex ] = '\0';
				}
			}
			else
			{
				/* A character was entered.  It was not a new line, backspace
				or carriage return, so it is accepted as part of the input and
				placed into the input buffer.  When a \n is entered the complete
				string will be passed to the command interpreter. */
				if( cInputIndex < MAX_INPUT_LENGTH )
				{
					LPUART_RTOS_Send(handle,&cRxedChar,1);
					pcInputString[ cInputIndex ] = cRxedChar;
					cInputIndex++;
				}
			}
		}
		vTaskDelay(100/portTICK_PERIOD_MS);
    }
    vTaskSuspend(NULL);
}
