/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_AD_25 (coord M15), LPUART1_RXD/J32[2] */
/* Routed pin properties */
#define BOARD_INITPINS_LPUART1_RXD_PERIPHERAL                            LPUART1   /*!< Peripheral name */
#define BOARD_INITPINS_LPUART1_RXD_SIGNAL                                    RXD   /*!< Signal name */

/* GPIO_AD_24 (coord L13), LPUART1_TXD/J31[2] */
/* Routed pin properties */
#define BOARD_INITPINS_LPUART1_TXD_PERIPHERAL                            LPUART1   /*!< Peripheral name */
#define BOARD_INITPINS_LPUART1_TXD_SIGNAL                                    TXD   /*!< Signal name */

/* GPIO_EMC_B2_18 (coord N3), USER_GREEN */
/* Routed pin properties */
#define BOARD_INITPINS_USER_GREEN_PERIPHERAL                               GPIO8   /*!< Peripheral name */
#define BOARD_INITPINS_USER_GREEN_SIGNAL                                 gpio_io   /*!< Signal name */
#define BOARD_INITPINS_USER_GREEN_CHANNEL                                    28U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_USER_GREEN_GPIO                                     GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_USER_GREEN_GPIO_PIN                                   28U   /*!< GPIO pin number */
#define BOARD_INITPINS_USER_GREEN_GPIO_PIN_MASK                      (1U << 28U)   /*!< GPIO pin mask */

/* GPIO_AD_08 (coord R15), USER_RED */
/* Routed pin properties */
#define BOARD_INITPINS_USER_RED_PERIPHERAL                                 GPIO9   /*!< Peripheral name */
#define BOARD_INITPINS_USER_RED_SIGNAL                                   gpio_io   /*!< Signal name */
#define BOARD_INITPINS_USER_RED_CHANNEL                                       7U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_USER_RED_GPIO                                       GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_USER_RED_GPIO_PIN                                      7U   /*!< GPIO pin number */
#define BOARD_INITPINS_USER_RED_GPIO_PIN_MASK                         (1U << 7U)   /*!< GPIO pin mask */

/* GPIO_AD_10 (coord R17), USER_BLUE */
/* Routed pin properties */
#define BOARD_INITPINS_USER_BLUE_PERIPHERAL                                GPIO9   /*!< Peripheral name */
#define BOARD_INITPINS_USER_BLUE_SIGNAL                                  gpio_io   /*!< Signal name */
#define BOARD_INITPINS_USER_BLUE_CHANNEL                                      9U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_USER_BLUE_GPIO                                      GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_USER_BLUE_GPIO_PIN                                     9U   /*!< GPIO pin number */
#define BOARD_INITPINS_USER_BLUE_GPIO_PIN_MASK                        (1U << 9U)   /*!< GPIO pin mask */

/* WAKEUP (coord T8), USER_S1 */
/* Routed pin properties */
#define BOARD_INITPINS_USER_S1_PERIPHERAL                                 GPIO13   /*!< Peripheral name */
#define BOARD_INITPINS_USER_S1_SIGNAL                                    gpio_io   /*!< Signal name */
#define BOARD_INITPINS_USER_S1_CHANNEL                                        0U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_USER_S1_GPIO                                       GPIO13   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_USER_S1_GPIO_PIN                                       0U   /*!< GPIO pin number */
#define BOARD_INITPINS_USER_S1_GPIO_PIN_MASK                          (1U << 0U)   /*!< GPIO pin mask */

/* GPIO_AD_34 (coord J16), 1588_EVENT0_IN/SD1_VSELECT */
/* Routed pin properties */
#define BOARD_INITPINS_SD1_VSELECT_PERIPHERAL                             USDHC1   /*!< Peripheral name */
#define BOARD_INITPINS_SD1_VSELECT_SIGNAL                          usdhc_vselect   /*!< Signal name */

/* GPIO_SD_B1_00 (coord B16), SD1_CMD/J15[3]/WIFI_SDIO_CMD/J54[11]/NVCC_SD/U19G[D14] */
/* Routed pin properties */
#define BOARD_INITPINS_SD1_CMD_PERIPHERAL                                 USDHC1   /*!< Peripheral name */
#define BOARD_INITPINS_SD1_CMD_SIGNAL                                  usdhc_cmd   /*!< Signal name */

/* GPIO_SD_B1_01 (coord D15), SD1_CLK/J15[5]/WIFI_SDIO_CLK/J54[9] */
/* Routed pin properties */
#define BOARD_INITPINS_SD1_CLK_PERIPHERAL                                 USDHC1   /*!< Peripheral name */
#define BOARD_INITPINS_SD1_CLK_SIGNAL                                  usdhc_clk   /*!< Signal name */

/* GPIO_SD_B1_02 (coord C15), SD1_D0/J15[7]/WIFI_SDIO_D0/J54[13]/NVCC_SD/U19G[D14] */
/* Routed pin properties */
#define BOARD_INITPINS_SD1_D0_PERIPHERAL                                  USDHC1   /*!< Peripheral name */
#define BOARD_INITPINS_SD1_D0_SIGNAL                                  usdhc_data   /*!< Signal name */
#define BOARD_INITPINS_SD1_D0_CHANNEL                                         0U   /*!< Signal channel */

/* GPIO_SD_B1_03 (coord B17), SD1_D1/J15[8]/WIFI_SDIO_D1/J54[15] */
/* Routed pin properties */
#define BOARD_INITPINS_SD1_D1_PERIPHERAL                                  USDHC1   /*!< Peripheral name */
#define BOARD_INITPINS_SD1_D1_SIGNAL                                  usdhc_data   /*!< Signal name */
#define BOARD_INITPINS_SD1_D1_CHANNEL                                         1U   /*!< Signal channel */

/* GPIO_SD_B1_04 (coord B15), SD1_D2/J15[1]/WIFI_SDIO_D2/J54[17] */
/* Routed pin properties */
#define BOARD_INITPINS_SD1_D2_PERIPHERAL                                  USDHC1   /*!< Peripheral name */
#define BOARD_INITPINS_SD1_D2_SIGNAL                                  usdhc_data   /*!< Signal name */
#define BOARD_INITPINS_SD1_D2_CHANNEL                                         2U   /*!< Signal channel */

/* GPIO_SD_B1_05 (coord A16), SD1_D3/J15[2]/WIFI_SDIO_D3/J54[19] */
/* Routed pin properties */
#define BOARD_INITPINS_SD1_D3_PERIPHERAL                                  USDHC1   /*!< Peripheral name */
#define BOARD_INITPINS_SD1_D3_SIGNAL                                  usdhc_data   /*!< Signal name */
#define BOARD_INITPINS_SD1_D3_CHANNEL                                         3U   /*!< Signal channel */

/* GPIO_AD_35 (coord G17), 1588_EVENT0_OUT/SD_PWREN_B */
/* Routed pin properties */
#define BOARD_INITPINS_SD_PWREN_B_PERIPHERAL                              GPIO10   /*!< Peripheral name */
#define BOARD_INITPINS_SD_PWREN_B_SIGNAL                                 gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SD_PWREN_B_CHANNEL                                     2U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SD_PWREN_B_GPIO                                    GPIO10   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SD_PWREN_B_GPIO_PIN                                    2U   /*!< GPIO pin number */
#define BOARD_INITPINS_SD_PWREN_B_GPIO_PIN_MASK                       (1U << 2U)   /*!< GPIO pin mask */

/* GPIO_AD_32 (coord K16), ENET_MDC/U7[12]/SD1_CD_B/J15[9] */
/* Routed pin properties */
#define BOARD_INITPINS_ENET_MDC_PERIPHERAL                             CM7_GPIO3   /*!< Peripheral name */
#define BOARD_INITPINS_ENET_MDC_SIGNAL                           gpio_mux_io_cm7   /*!< Signal name */
#define BOARD_INITPINS_ENET_MDC_CHANNEL                                      31U   /*!< Signal channel */

/* GPIO_DISP_B2_10 (coord D9), LPUART2_TXD/BT_UART_TXD/U354[4]/U16[2]/J25[3]/J9[4] */
/* Routed pin properties */
#define BOARD_INITPINS_BT_UART_TXD_PERIPHERAL                             LPI2C3   /*!< Peripheral name */
#define BOARD_INITPINS_BT_UART_TXD_SIGNAL                                    SCL   /*!< Signal name */

/* GPIO_DISP_B2_11 (coord A6), LPUART2_RXD/BT_UART_RXD/U16[3]/U355[20]/J9[2] */
/* Routed pin properties */
#define BOARD_INITPINS_BT_UART_RXD_PERIPHERAL                             LPI2C3   /*!< Peripheral name */
#define BOARD_INITPINS_BT_UART_RXD_SIGNAL                                    SDA   /*!< Signal name */

/* GPIO_EMC_B1_41 (coord L1), SEMC_CSX0/U14A[C6] */
/* Routed pin properties */
#define BOARD_INITPINS_SEMC_CSX0_PERIPHERAL                              LPUART6   /*!< Peripheral name */
#define BOARD_INITPINS_SEMC_CSX0_SIGNAL                                      RXD   /*!< Signal name */

/* GPIO_EMC_B1_40 (coord K1), SEMC_RDY/U14A[C8] */
/* Routed pin properties */
#define BOARD_INITPINS_SEMC_RDY_PERIPHERAL                               LPUART6   /*!< Peripheral name */
#define BOARD_INITPINS_SEMC_RDY_SIGNAL                                       TXD   /*!< Signal name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);                    /* Function assigned for the Cortex-M7F */

/* GPIO_AD_29 (coord M17), DSI_EN */
/* Routed pin properties */
#define BOARD_INITMIPIPANELPINS_DSI_EN_PERIPHERAL                          GPIO9   /*!< Peripheral name */
#define BOARD_INITMIPIPANELPINS_DSI_EN_SIGNAL                            gpio_io   /*!< Signal name */
#define BOARD_INITMIPIPANELPINS_DSI_EN_CHANNEL                               28U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITMIPIPANELPINS_DSI_EN_GPIO                                GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITMIPIPANELPINS_DSI_EN_GPIO_PIN                              28U   /*!< GPIO pin number */
#define BOARD_INITMIPIPANELPINS_DSI_EN_GPIO_PIN_MASK                 (1U << 28U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_00 (coord K2), LPI2C2_SCL */
/* Routed pin properties */
#define BOARD_INITMIPIPANELPINS_LPI2C2_SCL_PERIPHERAL                     LPI2C2   /*!< Peripheral name */
#define BOARD_INITMIPIPANELPINS_LPI2C2_SCL_SIGNAL                            SCL   /*!< Signal name */

/* GPIO_EMC_B2_01 (coord K4), LPI2C2_SDA */
/* Routed pin properties */
#define BOARD_INITMIPIPANELPINS_LPI2C2_SDA_PERIPHERAL                     LPI2C2   /*!< Peripheral name */
#define BOARD_INITMIPIPANELPINS_LPI2C2_SDA_SIGNAL                            SDA   /*!< Signal name */

/* GPIO_AD_30 (coord K17), DSI_TS_INT */
/* Routed pin properties */
#define BOARD_INITMIPIPANELPINS_DSI_TS_INT_PERIPHERAL                      GPIO9   /*!< Peripheral name */
#define BOARD_INITMIPIPANELPINS_DSI_TS_INT_SIGNAL                        gpio_io   /*!< Signal name */
#define BOARD_INITMIPIPANELPINS_DSI_TS_INT_CHANNEL                           29U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITMIPIPANELPINS_DSI_TS_INT_GPIO                            GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITMIPIPANELPINS_DSI_TS_INT_GPIO_PIN                          29U   /*!< GPIO pin number */
#define BOARD_INITMIPIPANELPINS_DSI_TS_INT_GPIO_PIN_MASK             (1U << 29U)   /*!< GPIO pin mask */

/* GPIO_AD_05 (coord P13), DSI_TS_RST */
/* Routed pin properties */
#define BOARD_INITMIPIPANELPINS_DSI_TS_RST_PERIPHERAL                      GPIO9   /*!< Peripheral name */
#define BOARD_INITMIPIPANELPINS_DSI_TS_RST_SIGNAL                        gpio_io   /*!< Signal name */
#define BOARD_INITMIPIPANELPINS_DSI_TS_RST_CHANNEL                            4U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITMIPIPANELPINS_DSI_TS_RST_GPIO                            GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITMIPIPANELPINS_DSI_TS_RST_GPIO_PIN                           4U   /*!< GPIO pin number */
#define BOARD_INITMIPIPANELPINS_DSI_TS_RST_GPIO_PIN_MASK              (1U << 4U)   /*!< GPIO pin mask */

/* GPIO_AD_15 (coord M14), LCD_RST_B */
/* Routed pin properties */
#define BOARD_INITMIPIPANELPINS_LCD_RST_B_PERIPHERAL                       GPIO9   /*!< Peripheral name */
#define BOARD_INITMIPIPANELPINS_LCD_RST_B_SIGNAL                         gpio_io   /*!< Signal name */
#define BOARD_INITMIPIPANELPINS_LCD_RST_B_CHANNEL                            14U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITMIPIPANELPINS_LCD_RST_B_GPIO                             GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITMIPIPANELPINS_LCD_RST_B_GPIO_PIN                           14U   /*!< GPIO pin number */
#define BOARD_INITMIPIPANELPINS_LCD_RST_B_GPIO_PIN_MASK              (1U << 14U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_03 (coord R1), DSI_BL_PWM */
/* Routed pin properties */
#define BOARD_INITMIPIPANELPINS_DSI_BL_PWM_PERIPHERAL                      GPIO8   /*!< Peripheral name */
#define BOARD_INITMIPIPANELPINS_DSI_BL_PWM_SIGNAL                        gpio_io   /*!< Signal name */
#define BOARD_INITMIPIPANELPINS_DSI_BL_PWM_CHANNEL                           13U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITMIPIPANELPINS_DSI_BL_PWM_GPIO                            GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITMIPIPANELPINS_DSI_BL_PWM_GPIO_PIN                          13U   /*!< GPIO pin number */
#define BOARD_INITMIPIPANELPINS_DSI_BL_PWM_GPIO_PIN_MASK             (1U << 13U)   /*!< GPIO pin mask */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitMipiPanelPins(void);           /* Function assigned for the Cortex-M7F */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
