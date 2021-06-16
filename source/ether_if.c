/*
 * ether_if.c
 *
 *  Created on: Jun 2, 2021
 *      Author: gulziibayar
 */


#include "lwip/opt.h"
//#define EXAMPLE_USE_100M_ENET_PORT
#if LWIP_IPV4 && LWIP_DHCP && LWIP_NETCONN

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "event_groups.h"
#include "globals.h"

#include "lwip/dhcp.h"
#include "lwip/ip_addr.h"
#include "lwip/netifapi.h"
#include "lwip/prot/dhcp.h"
#include "lwip/tcpip.h"
#include "lwip/sys.h"
#include "enet_ethernetif.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_phy.h"

#include "fsl_phyksz8081.h"
#include "fsl_phyksz9131rnx.h"
#include "fsl_enet_mdio.h"
#include "fsl_gpio.h"
#include "fsl_iomuxc.h"
#include "fsl_enet.h"

/* MAC address configuration. */
#define configMAC_ADDR_100M                \
    {                                      \
        0x02, 0x12, 0x13, 0x10, 0x15, 0x11 \
    }

#define configMAC_ADDR_1G                  \
    {                                      \
        0x02, 0x12, 0x13, 0x10, 0x15, 0x12 \
    }


#define PHY_ADDRESS_100M    BOARD_ENET0_PHY_ADDRESS
#define PHY_ADDRESS_1G      BOARD_ENET1_PHY_ADDRESS

#define PHY_OPS_100M        phyksz8081_ops
#define PHY_OPS_1G          phyksz9131rnx_ops

#define NETIF_INIT_FN_100M 	ethernetif0_init
#define NETIF_INIT_FN_1G 	ethernetif1_init


/* MDIO operations. */
#define EXAMPLE_MDIO_OPS enet_ops

/* ENET clock frequency. */
#define EXAMPLE_CLOCK_FREQ CLOCK_GetRootClockFreq(kCLOCK_Root_Bus)

#ifndef EXAMPLE_NETIF_INIT_FN
/*! @brief Network interface initialization function. */
#define EXAMPLE_NETIF_INIT_FN ethernetif0_init
#endif /* EXAMPLE_NETIF_INIT_FN */

/*! @brief Stack size of the thread which prints DHCP info. */
#define PRINT_THREAD_STACKSIZE 512

/*! @brief Priority of the thread which prints DHCP info. */
#define PRINT_THREAD_PRIO DEFAULT_THREAD_PRIO

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static uint8_t enet_mode_cnt = 0;

static mdio_handle_t mdioHandle = {.ops = &EXAMPLE_MDIO_OPS};
static phy_handle_t phyHandle_100m   = {.phyAddr = PHY_ADDRESS_100M, .mdioHandle = &mdioHandle, .ops = &PHY_OPS_100M};
static phy_handle_t phyHandle_1g   = {.phyAddr = PHY_ADDRESS_1G, .mdioHandle = &mdioHandle, .ops = &PHY_OPS_1G};

static struct netif netif_100m;
static struct netif netif_1g;
// global variables for storing ethernet interfaces state
static bool gConnected;

ip_ro_t eth_100mb_addr;
ip_ro_t eth_1g_addr;

static EventGroupHandle_t *temp_event_group;
/*******************************************************************************
 * Code
 ******************************************************************************/
static void BOARD_InitModuleClock(void)
{
    const clock_sys_pll1_config_t sysPll1Config = {
        .pllDiv2En = true,
    };
    CLOCK_InitSysPll1(&sysPll1Config);

//#ifdef EXAMPLE_USE_100M_ENET_PORT
//    clock_root_config_t rootCfg = {.mux = 4, .div = 10}; /* Generate 50M root clock. */
//    CLOCK_SetRootClock(kCLOCK_Root_Enet1, &rootCfg);
//#else
//    clock_root_config_t rootCfg = {.mux = 4, .div = 4}; /* Generate 125M root clock. */
//    CLOCK_SetRootClock(kCLOCK_Root_Enet2, &rootCfg);
//#endif

    // set clock for 100M
    clock_root_config_t rootCfg = {.mux = 4, .div = 10}; /* Generate 50M root clock. */
    CLOCK_SetRootClock(kCLOCK_Root_Enet1, &rootCfg);

    // set clock for 1G
    rootCfg.mux = 4;
    rootCfg.div = 4;
    CLOCK_SetRootClock(kCLOCK_Root_Enet2, &rootCfg);

    /* Select syspll2pfd3, 528*18/24 = 396M */
    CLOCK_InitPfd(kCLOCK_PllSys2, kCLOCK_Pfd3, 24);
    rootCfg.mux = 7;
    rootCfg.div = 2;
    CLOCK_SetRootClock(kCLOCK_Root_Bus, &rootCfg); /* Generate 198M bus clock. */
}

static void IOMUXC_SelectENETClock(void)
{
//#ifdef EXAMPLE_USE_100M_ENET_PORT
//    IOMUXC_GPR->GPR4 |= 0x3; /* 50M ENET_REF_CLOCK output to PHY and ENET module. */
//#else
//    IOMUXC_GPR->GPR5 |= IOMUXC_GPR_GPR5_ENET1G_RGMII_EN_MASK; /* bit1:iomuxc_gpr_enet_clk_dir
//                                                                 bit0:GPR_ENET_TX_CLK_SEL(internal or OSC) */
//#endif
	IOMUXC_GPR->GPR4 |= 0x3; /* 50M ENET_REF_CLOCK output to PHY and ENET module. */
	IOMUXC_GPR->GPR5 |= IOMUXC_GPR_GPR5_ENET1G_RGMII_EN_MASK; /* bit1:iomuxc_gpr_enet_clk_dir
	                                                                 bit0:GPR_ENET_TX_CLK_SEL(internal or OSC) */
}

void BOARD_ENETFlexibleConfigure(enet_config_t *config)
{
//#ifdef EXAMPLE_USE_100M_ENET_PORT
//    config->miiMode = kENET_RmiiMode;
//#else
//    config->miiMode = kENET_RgmiiMode;
//#endif
	if (enet_mode_cnt == 0)
	{
		config->miiMode = kENET_RmiiMode;
		enet_mode_cnt++;
	}
	else
	{
		config->miiMode = kENET_RgmiiMode;
	}
}

/*!
 * @brief Prints DHCP status of the interface when it has changed from last status.
 *
 * @param arg pointer to network interface structure
 */
static void print_dhcp_state(void *arg)
{
    struct netif *netif = (struct netif *)arg;
    struct dhcp *dhcp;
    u8_t dhcp_last_state = DHCP_STATE_OFF;

    while (netif_is_up(netif))
    {
        dhcp = netif_dhcp_data(netif);

        if (dhcp == NULL)
        {
            dhcp_last_state = DHCP_STATE_OFF;
        }
        else if (dhcp_last_state != dhcp->state)
        {
            dhcp_last_state = dhcp->state;

            PRINTF(" DHCP state       : ");
            switch (dhcp_last_state)
            {
                case DHCP_STATE_OFF:
                    PRINTF("OFF");
                    break;
                case DHCP_STATE_REQUESTING:
                    PRINTF("REQUESTING");
                    break;
                case DHCP_STATE_INIT:
                    PRINTF("INIT");
                    break;
                case DHCP_STATE_REBOOTING:
                    PRINTF("REBOOTING");
                    break;
                case DHCP_STATE_REBINDING:
                    PRINTF("REBINDING");
                    break;
                case DHCP_STATE_RENEWING:
                    PRINTF("RENEWING");
                    break;
                case DHCP_STATE_SELECTING:
                    PRINTF("SELECTING");
                    break;
                case DHCP_STATE_INFORMING:
                    PRINTF("INFORMING");
                    break;
                case DHCP_STATE_CHECKING:
                    PRINTF("CHECKING");
                    break;
                case DHCP_STATE_BOUND:
                    PRINTF("BOUND");
                    break;
                case DHCP_STATE_BACKING_OFF:
                    PRINTF("BACKING_OFF");
                    break;
                default:
                    PRINTF("%u", dhcp_last_state);
                    PRINTF("UNKNOWN STATE");
                    assert(0);
                    break;
            }
            PRINTF("\r\n");

            if (dhcp_last_state == DHCP_STATE_BOUND)
            {
				eth_100mb_addr.connected = true;
				eth_100mb_addr.ip = (netif->ip_addr).addr;
				eth_100mb_addr.sub = (netif->netmask).addr;
				eth_100mb_addr.gw = (netif->gw).addr;
				PRINTF("\r\n IPv4 Address     : %s\r\n", ipaddr_ntoa(&netif->ip_addr));
				PRINTF(" IPv4 Subnet mask : %s\r\n", ipaddr_ntoa(&netif->netmask));
				PRINTF(" IPv4 Gateway     : %s\r\n\r\n", ipaddr_ntoa(&netif->gw));
				xEventGroupSetBits(*temp_event_group, ETH_100m_RDY );
            }
        }
        vTaskDelay(20);
    }
    PRINTF("\r\n DHCP Task is deleted\r\n");
    vTaskDelete(NULL);
}

static void print_dhcp_state_1g(void *arg)
{
    struct netif *netif = (struct netif *)arg;
    struct dhcp *dhcp;
    u8_t dhcp_last_state = DHCP_STATE_OFF;

    while (netif_is_up(netif))
    {
        dhcp = netif_dhcp_data(netif);

        if (dhcp == NULL)
        {
            dhcp_last_state = DHCP_STATE_OFF;
        }
        else if (dhcp_last_state != dhcp->state)
        {
            dhcp_last_state = dhcp->state;

            PRINTF(" DHCP state       : ");
            switch (dhcp_last_state)
            {
                case DHCP_STATE_OFF:
                    PRINTF("OFF");
                    break;
                case DHCP_STATE_REQUESTING:
                    PRINTF("REQUESTING");
                    break;
                case DHCP_STATE_INIT:
                    PRINTF("INIT");
                    break;
                case DHCP_STATE_REBOOTING:
                    PRINTF("REBOOTING");
                    break;
                case DHCP_STATE_REBINDING:
                    PRINTF("REBINDING");
                    break;
                case DHCP_STATE_RENEWING:
                    PRINTF("RENEWING");
                    break;
                case DHCP_STATE_SELECTING:
                    PRINTF("SELECTING");
                    break;
                case DHCP_STATE_INFORMING:
                    PRINTF("INFORMING");
                    break;
                case DHCP_STATE_CHECKING:
                    PRINTF("CHECKING");
                    break;
                case DHCP_STATE_BOUND:
                    PRINTF("BOUND");
                    break;
                case DHCP_STATE_BACKING_OFF:
                    PRINTF("BACKING_OFF");
                    break;
                default:
                    PRINTF("%u", dhcp_last_state);
                    PRINTF("UNKNOWN STATE");
                    assert(0);
                    break;
            }
            PRINTF("\r\n");

            if (dhcp_last_state == DHCP_STATE_BOUND)
            {
				eth_1g_addr.connected = true;
				eth_1g_addr.ip = (netif->ip_addr).addr;
				eth_1g_addr.sub = (netif->netmask).addr;
				eth_1g_addr.gw = (netif->gw).addr;
				PRINTF("\r\n IPv4 Address     : %s\r\n", ipaddr_ntoa(&netif->ip_addr));
				PRINTF(" IPv4 Subnet mask : %s\r\n", ipaddr_ntoa(&netif->netmask));
				PRINTF(" IPv4 Gateway     : %s\r\n\r\n", ipaddr_ntoa(&netif->gw));
            }
        }
        vTaskDelay(20);
    }
    PRINTF("\r\n DHCP Task is deleted\r\n");
    vTaskDelete(NULL);
}


static void cbETHLinkStatus(struct netif *state_netif)
{
	if (netif_is_link_up(state_netif))
	{
		PRINTF("LINK IS UP\r\n");
	}
	else
	{
		PRINTF("LINK IS UP\r\n");
	}
}

//---------------------------------------------------------------------------------------
// netif callback
// called when netif (ETH) goes up or down
//---------------------------------------------------------------------------------------
static void cbETHNetIFStatus(struct netif *state_netif)
{
	char ip[16];
	char ipgw[16];
	if (netif_is_up(state_netif))
	{
		//strcpy(ip, ip4addr_ntoa(netif_ip4_addr(state_netif)));
		//strcpy(ipgw, ip4addr_ntoa(netif_ip4_gw(state_netif)));
		//messageDebug(DBG_INFO, __MODULE__, __LINE__,"cbETHNetIFStatus==UP, local interface IP is %s, GW IP is %s", ip, ipgw);
		PRINTF("cbETHNetIFStatus==UP\r\n");
		if (state_netif->ip_addr.addr)
		{
			gConnected=true;
		}
	}
	else
	{
		PRINTF("cbETHNetIFStatus==DOWN\r\n");
		gConnected=false;
	}
}


static void init_ENET_100mb()
{
	#if defined(FSL_FEATURE_SOC_LPC_ENET_COUNT) && (FSL_FEATURE_SOC_LPC_ENET_COUNT > 0)
	    static mem_range_t non_dma_memory[] = NON_DMA_MEMORY_ARRAY;
	#endif /* FSL_FEATURE_SOC_LPC_ENET_COUNT */
	    ip4_addr_t netif_ipaddr, netif_netmask, netif_gw;
	    ethernetif_config_t enet_config = {
	        .phyHandle  = &phyHandle_100m,
	        .macAddress = configMAC_ADDR_100M,
	#if defined(FSL_FEATURE_SOC_LPC_ENET_COUNT) && (FSL_FEATURE_SOC_LPC_ENET_COUNT > 0)
	        .non_dma_memory = non_dma_memory,
	#endif /* FSL_FEATURE_SOC_LPC_ENET_COUNT */
	    };

	    IP4_ADDR(&netif_ipaddr, 0U, 0U, 0U, 0U);
	    IP4_ADDR(&netif_netmask, 0U, 0U, 0U, 0U);
	    IP4_ADDR(&netif_gw, 0U, 0U, 0U, 0U);

	    //tcpip_init(NULL, NULL);

	    netifapi_netif_add(&netif_100m, &netif_ipaddr, &netif_netmask, &netif_gw, &enet_config, NETIF_INIT_FN_100M,
	                       tcpip_input);

	    netif_set_status_callback(&netif_100m, cbETHNetIFStatus);
	    netif_set_link_callback(&netif_100m, cbETHLinkStatus);


	    //netifapi_netif_set_default(&netif_100m);
	    //netifapi_netif_set_up(&netif_100m);

	    //netifapi_dhcp_start(&netif_100m);

	    sys_unlock_tcpip_core();
//	    PRINTF("\r\n************************************************\r\n");
//	    PRINTF(" 100Mb DHCP example\r\n");
//	    PRINTF("************************************************\r\n");
//
//	    print_dhcp_state(&netif_100m);
	    bool link;
	    static bool oldLink=false;
	    while(1)
	    {
	    	PHY_GetLinkStatus(enet_config.phyHandle, &link);

	    	if (link != oldLink)
	    	{
	    	   if (link)
	    	   {
	    		   sys_lock_tcpip_core();
	    		   netif_set_up(&netif_100m);
	    		   dhcp_start(&netif_100m);
	    		   sys_unlock_tcpip_core();
	    		   PRINTF("Link is coming up");
	    	   }
	    	   else
	    	   {
	    		   sys_lock_tcpip_core();
	    		   dhcp_release_and_stop(&netif_100m);
	    		   netif_set_down(&netif_100m);
	    		   sys_unlock_tcpip_core();
	    		   PRINTF("Link is going down..");
	    	   }
	    	   oldLink=link;
	    	}
	    	vTaskDelay(10);
	    }

}

static void init_ENET_1g() // must be called after 100m
{
	#if defined(FSL_FEATURE_SOC_LPC_ENET_COUNT) && (FSL_FEATURE_SOC_LPC_ENET_COUNT > 0)
	    static mem_range_t non_dma_memory[] = NON_DMA_MEMORY_ARRAY;
	#endif /* FSL_FEATURE_SOC_LPC_ENET_COUNT */
	    ip4_addr_t netif_ipaddr, netif_netmask, netif_gw;
	    ethernetif_config_t enet_config = {
	        .phyHandle  = &phyHandle_1g,
	        .macAddress = configMAC_ADDR_1G,
	#if defined(FSL_FEATURE_SOC_LPC_ENET_COUNT) && (FSL_FEATURE_SOC_LPC_ENET_COUNT > 0)
	        .non_dma_memory = non_dma_memory,
	#endif /* FSL_FEATURE_SOC_LPC_ENET_COUNT */
	    };

	    gpio_pin_config_t gpio_config = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};
	    /*
	     * Following 2 lines must be uncommented when running ethernet 1G alone without 100mb
	     */
	    //BOARD_InitModuleClock();
	    //IOMUXC_SelectENETClock();

	    BOARD_InitEnet1GPins();

	    /*
	     *  So does the following 4 lines, This below code reset the phy.
	     *  ethernet 100mb, ethernet 1g share same reset.
	     */
//	    GPIO_PinInit(GPIO8, 21, &gpio_config);
//	    /* For a complete PHY reset of RTL8211FDI-CG, this pin must be asserted low for at least 10ms. And
//		 * wait for a further 30ms(for internal circuits settling time) before accessing the PHY register */
//	    GPIO_WritePinOutput(GPIO8, 21, 0);
//	    SDK_DelayAtLeastUs(10000, CLOCK_GetFreq(kCLOCK_CpuClk));
//	    GPIO_WritePinOutput(GPIO8, 21, 1);
//	    SDK_DelayAtLeastUs(30000, CLOCK_GetFreq(kCLOCK_CpuClk));

	    EnableIRQ(ENET_1G_MAC0_Tx_Rx_1_IRQn);
	    EnableIRQ(ENET_1G_MAC0_Tx_Rx_2_IRQn);

	    mdioHandle.resource.csrClock_Hz = EXAMPLE_CLOCK_FREQ;

	    IP4_ADDR(&netif_ipaddr, 0U, 0U, 0U, 0U);
	    IP4_ADDR(&netif_netmask, 0U, 0U, 0U, 0U);
	    IP4_ADDR(&netif_gw, 0U, 0U, 0U, 0U);

	    /* tcpip_init must be uncommented, if there is no wifi or ethernet100mb task*/
	    //tcpip_init(NULL, NULL);

	    netifapi_netif_add(&netif_1g, &netif_ipaddr, &netif_netmask, &netif_gw, &enet_config, NETIF_INIT_FN_1G,
	                       tcpip_input);
	    netifapi_netif_set_default(&netif_1g);
	    netifapi_netif_set_up(&netif_1g);

	    netifapi_dhcp_start(&netif_1g);

	    PRINTF("\r\n************************************************\r\n");
	    PRINTF(" DHCP 1G example\r\n");
	    PRINTF("************************************************\r\n");

	    print_dhcp_state_1g(&netif_1g);
}

void dual_eth_configuration()
{
    gpio_pin_config_t gpio_config = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};
    BOARD_InitModuleClock();
    IOMUXC_SelectENETClock();
    BOARD_InitEnetPins();
    GPIO_PinInit(GPIO9, 11, &gpio_config);
    GPIO_PinInit(GPIO8, 21, &gpio_config);
    /* Pull up the ENET_INT before RESET. */
    GPIO_WritePinOutput(GPIO9, 11, 1);
    GPIO_WritePinOutput(GPIO8, 21, 0);
    SDK_DelayAtLeastUs(10000, CLOCK_GetFreq(kCLOCK_CpuClk));
    GPIO_WritePinOutput(GPIO8, 21, 1);
    SDK_DelayAtLeastUs(6, CLOCK_GetFreq(kCLOCK_CpuClk));

    mdioHandle.resource.csrClock_Hz = EXAMPLE_CLOCK_FREQ;

}


void eth_100m_task(void *pvParameters)
{
	temp_event_group = (EventGroupHandle_t *)pvParameters;
	EventBits_t bits;
	// used for waiting wifi, wifi should initialize lwip thread.
	bits = xEventGroupWaitBits(*temp_event_group, WIFI_RDY, pdFALSE, pdTRUE, portMAX_DELAY);
	init_ENET_100mb();
}

void eth_1g_task(void *pvParameters)
{
	temp_event_group = (EventGroupHandle_t *)pvParameters;
	EventBits_t bits;
	bits = xEventGroupWaitBits(*temp_event_group, WIFI_RDY|ETH_100m_RDY, pdFALSE, pdTRUE, portMAX_DELAY);
	init_ENET_1g();
}

#endif
