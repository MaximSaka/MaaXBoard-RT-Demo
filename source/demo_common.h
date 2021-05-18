
#ifndef _DEMO_COMMON_H_
#define _DEMO_COMMON_H_

#include "FreeRTOS.h"
#include "task.h"
#include "pin_mux.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_soc_src.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/

void addItemToSSIDList(const char * text);
bool setInputSignal(bool state);

void lvgl_task(void *param);
void vApplicationTickHook_lvgl(void);

#endif //_DEMO_COMMON_H_
