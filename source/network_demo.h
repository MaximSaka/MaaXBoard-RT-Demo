
#ifndef _NETWORK_DEMO_H_
#define _NETWORK_DEMO_H_

#include <wm_os.h>

/*******************************************************************************
 * Functions
 ******************************************************************************/

void ssidScan(void);
void printWlanInfo(void);

bool isWifiReady(void);

void wifi_task(void *param);

#endif //_NETWORK_DEMO_H_
