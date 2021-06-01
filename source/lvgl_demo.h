
#ifndef _LVGL_DEMO_H_
#define _LVGL_DEMO_H_

/*******************************************************************************
 * Functions
 ******************************************************************************/

void addItemToSSIDList(const char * text);

bool isLvglReady(void);

void lvgl_task(void *param);
void vApplicationTickHook_lvgl(void);

void openNetworkScreen();
void openMenuScreen();
void openLEDScreen();
void openUSBScreen();
void openAVScreen();
void openSystemScreen();
void openHelpScreen();

void setLedRedImgState(bool state);
void setLedGreenImgState(bool state);
void setLedBlueImgState(bool state);

void setHIDsRefreshed(void);

void scani2cBusAndDisplay(void);
void writeToHIDInputTextArea(const char* text);
bool capturingMouseInputOnTA(void);
void setCaptureMouseInputOnTA(bool state);
bool capturingKeyboardInputOnTA(void);
void setCaptureKeyboardInputOnTA(bool state);

#endif //_LVGL_DEMO_H_
