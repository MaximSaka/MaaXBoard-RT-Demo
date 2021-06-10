
#ifndef _NETWORK_DEMO_H_
#define _NETWORK_DEMO_H_

#include <wm_os.h>

/*******************************************************************************
 * Functions
 ******************************************************************************/

void getTargetSSID(char* nameBuffer, int bufLen);
void ssidScan(void);
int connectToAP(void);
uint8_t printWlanInfo(void);
short getCurrentSignalStrength(void);

bool isWifiReady(void);

void wifi_task(void *param);

#endif //_NETWORK_DEMO_H_
