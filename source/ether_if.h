/*
 * ether_if.h
 *
 *  Created on: Jun 2, 2021
 *      Author: gulziibayar
 */

#ifndef ETHER_IF_H_
#define ETHER_IF_H_

void init_ENET_100mb();
void init_ENET_1g();
void eth_100m_task(void *pvParameters);
void eth_1g_task(void *pvParameters);

#endif /* ETHER_IF_H_ */
