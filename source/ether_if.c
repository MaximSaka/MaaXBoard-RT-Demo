/*
 * ether_if.c
 *
 *  Created on: Jun 2, 2021
 *      Author: gulziibayar
 */


#include "lwip/opt.h"
#define EXAMPLE_USE_100M_ENET_PORT
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
/*******************************************************************************
 * Code
 ******************************************************************************/
void BOARD_InitModuleClock(void)
{
    const clock_sys_pll1_config_t sysPll1Config = {
        .pllDiv2En = true,
    };
    CLOCK_InitSysPll1(&sysPll1Config);

#ifdef EXAMPLE_USE_100M_ENET_PORT
    clock_root_config_t rootCfg = {.mux = 4, .div = 10}; /* Generate 50M root clock. */
    CLOCK_SetRootClock(kCLOCK_Root_Enet1, &rootCfg);
#else
    clock_root_config_t rootCfg1 = {.mux = 4, .div = 4}; /* Generate 125M root clock. */
    CLOCK_SetRootClock(kCLOCK_Root_Enet2, &rootCfg1);
#endif

    /* Select syspll2pfd3, 528*18/24 = 396M */
    CLOCK_InitPfd(kCLOCK_PllSys2, kCLOCK_Pfd3, 24);
    rootCfg.mux = 7;
    rootCfg.div = 2;
    CLOCK_SetRootClock(kCLOCK_Root_Bus, &rootCfg); /* Generate 198M bus clock. */
}

void IOMUXC_SelectENETClock(void)
{
#ifdef EXAMPLE_USE_100M_ENET_PORT
    IOMUXC_GPR->GPR4 |= 0x3; /* 50M ENET_REF_CLOCK output to PHY and ENET module. */
#else
    IOMUXC_GPR->GPR5 |= IOMUXC_GPR_GPR5_ENET1G_RGMII_EN_MASK; /* bit1:iomuxc_gpr_enet_clk_dir
                                                                 bit0:GPR_ENET_TX_CLK_SEL(internal or OSC) */
#endif
}

void BOARD_ENETFlexibleConfigure(enet_config_t *config)
{
	if (enet_mode_cnt == 0)
	{
		config->miiMode = kENET_RmiiMode;
		enet_mode_cnt++;
	}
	else
	{
		config->miiMode = kENET_RgmiiMode;
	}
//#ifdef EXAMPLE_USE_100M_ENET_PORT
//    config->miiMode = kENET_RmiiMode;
//#else
//    config->miiMode = kENET_RgmiiMode;
//#endif
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
                PRINTF("\r\n IPv4 Address     : %s\r\n", ipaddr_ntoa(&netif->ip_addr));
                PRINTF(" IPv4 Subnet mask : %s\r\n", ipaddr_ntoa(&netif->netmask));
                PRINTF(" IPv4 Gateway     : %s\r\n\r\n", ipaddr_ntoa(&netif->gw));
            }
        }
        vTaskDelay(20);
        //sys_msleep(20U);
    }
    PRINTF("\r\n DHCP Task is deleted\r\n");
    vTaskDelete(NULL);
}

static void init_ENET_100mb_test(EventGroupHandle_t *temp_event_group)
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

	    IP4_ADDR(&netif_ipaddr, 0U, 0U, 0U, 0U);
	    IP4_ADDR(&netif_netmask, 0U, 0U, 0U, 0U);
	    IP4_ADDR(&netif_gw, 0U, 0U, 0U, 0U);

	    //tcpip_init(NULL, NULL);

	    netifapi_netif_add(&netif_100m, &netif_ipaddr, &netif_netmask, &netif_gw, &enet_config, NETIF_INIT_FN_100M,
	                       tcpip_input);
	    netifapi_netif_set_default(&netif_100m);
	    netifapi_netif_set_up(&netif_100m);

	    netifapi_dhcp_start(&netif_100m);

	    PRINTF("\r\n************************************************\r\n");
	    PRINTF(" 100Mb DHCP example\r\n");
	    PRINTF("************************************************\r\n");

	    xEventGroupSetBits(*temp_event_group, ETH_100m_RDY );
	    print_dhcp_state(&netif_100m);
}



void init_ENET_100mb()
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

	    IP4_ADDR(&netif_ipaddr, 0U, 0U, 0U, 0U);
	    IP4_ADDR(&netif_netmask, 0U, 0U, 0U, 0U);
	    IP4_ADDR(&netif_gw, 0U, 0U, 0U, 0U);

	    tcpip_init(NULL, NULL);

	    netifapi_netif_add(&netif_100m, &netif_ipaddr, &netif_netmask, &netif_gw, &enet_config, NETIF_INIT_FN_100M,
	                       tcpip_input);
	    netifapi_netif_set_default(&netif_100m);
	    netifapi_netif_set_up(&netif_100m);

	    netifapi_dhcp_start(&netif_100m);

	    PRINTF("\r\n************************************************\r\n");
	    PRINTF(" 100Mb DHCP example\r\n");
	    PRINTF("************************************************\r\n");

	    if (sys_thread_new("100mb_dhcp", print_dhcp_state, &netif_100m, PRINT_THREAD_STACKSIZE, PRINT_THREAD_PRIO) == NULL)
	    {
	        LWIP_ASSERT("stack_init(): Task creation failed.", 0);
	    }
}

void init_ENET_1g() // must be called after 100m
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

	    //BOARD_InitModuleClock();
	    //IOMUXC_SelectENETClock();

	    BOARD_InitEnet1GPins();
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

	    //tcpip_init(NULL, NULL);

	    netifapi_netif_add(&netif_1g, &netif_ipaddr, &netif_netmask, &netif_gw, &enet_config, NETIF_INIT_FN_1G,
	                       tcpip_input);
	    netifapi_netif_set_default(&netif_1g);
	    netifapi_netif_set_up(&netif_1g);

	    netifapi_dhcp_start(&netif_1g);

	    PRINTF("\r\n************************************************\r\n");
	    PRINTF(" DHCP example\r\n");
	    PRINTF("************************************************\r\n");

	    if (sys_thread_new("1G_dhcp", print_dhcp_state, &netif_1g, PRINT_THREAD_STACKSIZE, PRINT_THREAD_PRIO) == NULL)
	    {
	        LWIP_ASSERT("stack_init(): Task creation failed.", 0);
	    }
}

static void init_ENET_1g_test() // must be called after 100m
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

	    //BOARD_InitModuleClock();
	    //IOMUXC_SelectENETClock();

	    BOARD_InitEnet1GPins();
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

	    //tcpip_init(NULL, NULL);

	    netifapi_netif_add(&netif_1g, &netif_ipaddr, &netif_netmask, &netif_gw, &enet_config, NETIF_INIT_FN_1G,
	                       tcpip_input);
	    netifapi_netif_set_default(&netif_1g);
	    netifapi_netif_set_up(&netif_1g);

	    netifapi_dhcp_start(&netif_1g);

	    PRINTF("\r\n************************************************\r\n");
	    PRINTF(" DHCP 1G example\r\n");
	    PRINTF("************************************************\r\n");

	    print_dhcp_state(&netif_1g);

//	    if (sys_thread_new("1G_dhcp", print_dhcp_state, &netif_1g, PRINT_THREAD_STACKSIZE, PRINT_THREAD_PRIO) == NULL)
//	    {
//	        LWIP_ASSERT("stack_init(): Task creation failed.", 0);
//	    }
}

void eth_100m_task(void *pvParameters)
{
	EventGroupHandle_t *temp_event_group;
	temp_event_group = (EventGroupHandle_t *)pvParameters;
	EventBits_t bits;
	// used for waiting wifi, wifi should initialize lwip thread.
	bits = xEventGroupWaitBits(*temp_event_group, WIFI_RDY, pdFALSE, pdTRUE, 10000 / portTICK_RATE_MS);
	init_ENET_100mb_test(temp_event_group);
}

void eth_1g_task(void *pvParameters)
{
	EventGroupHandle_t *temp_event_group;
	temp_event_group = (EventGroupHandle_t *)pvParameters;
	EventBits_t bits;
	bits = xEventGroupWaitBits(*temp_event_group, WIFI_RDY|ETH_100m_RDY, pdFALSE, pdTRUE, 10000 / portTICK_RATE_MS);
	init_ENET_1g_test();
}

#endif
