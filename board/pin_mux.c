/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: MIMXRT1176xxxxx
package_id: MIMXRT1176DVMAA
mcu_data: ksdk2_0
processor_version: 9.0.1
board: MIMXRT1170-EVK
pin_labels:
- {pin_num: R1, pin_signal: GPIO_EMC_B2_03, label: DSI_BL_PWM, identifier: DSI_BL_PWM}
- {pin_num: K2, pin_signal: GPIO_EMC_B2_00, label: LPI2C2_SCL, identifier: LPI2C2_SCL}
- {pin_num: N3, pin_signal: GPIO_EMC_B2_18, label: USER_GREEN, identifier: SEMC_DQS4;USER_GREEN}
- {pin_num: K4, pin_signal: GPIO_EMC_B2_01, label: LPI2C2_SDA, identifier: LPI2C2_SDA}
- {pin_num: N12, pin_signal: GPIO_AD_00}
- {pin_num: R14, pin_signal: GPIO_AD_01}
- {pin_num: A4, pin_signal: GPIO_DISP_B2_15, label: 'WDOG_B/LCM_PWR_EN/J48[32]', identifier: DSI_EN}
- {pin_num: P13, pin_signal: GPIO_AD_05, label: DSI_TS_RST, identifier: DSI_TS_RST}
- {pin_num: R15, pin_signal: GPIO_AD_08, label: USER_RED, identifier: USER_RED}
- {pin_num: R16, pin_signal: GPIO_AD_09, label: DSI_RST, identifier: DSI_RST}
- {pin_num: R17, pin_signal: GPIO_AD_10, label: USER_BLUE, identifier: USER_BLUE}
- {pin_num: M14, pin_signal: GPIO_AD_15, label: LCD_RST_B, identifier: LCD_RST_B}
- {pin_num: M17, pin_signal: GPIO_AD_29, label: DSI_EN, identifier: DSI_EN}
- {pin_num: K17, pin_signal: GPIO_AD_30, label: DSI_TS_INT, identifier: DSI_TS_INT}
- {pin_num: T8, pin_signal: WAKEUP, label: USER_S1, identifier: USER_BUTTON;USER_S1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm7, enableClock: 'true'}
- pin_list:
  - {pin_num: M15, peripheral: LPUART1, signal: RXD, pin_signal: GPIO_AD_25, software_input_on: Enable, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper,
    open_drain: Disable, drive_strength: Normal, slew_rate: Slow}
  - {pin_num: L13, peripheral: LPUART1, signal: TXD, pin_signal: GPIO_AD_24, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper, open_drain: Disable, drive_strength: Normal,
    slew_rate: Slow}
  - {pin_num: N3, peripheral: GPIO8, signal: 'gpio_io, 28', pin_signal: GPIO_EMC_B2_18, identifier: USER_GREEN, direction: OUTPUT}
  - {pin_num: R15, peripheral: GPIO9, signal: 'gpio_io, 07', pin_signal: GPIO_AD_08, direction: OUTPUT}
  - {pin_num: R17, peripheral: GPIO9, signal: 'gpio_io, 09', pin_signal: GPIO_AD_10, direction: OUTPUT}
  - {pin_num: T8, peripheral: GPIO13, signal: 'gpio_io, 00', pin_signal: WAKEUP, identifier: USER_S1, direction: INPUT, gpio_interrupt: kGPIO_IntFallingEdge}
  - {pin_num: J16, peripheral: USDHC1, signal: usdhc_vselect, pin_signal: GPIO_AD_34}
  - {pin_num: B16, peripheral: USDHC1, signal: usdhc_cmd, pin_signal: GPIO_SD_B1_00, software_input_on: Enable, pull_down_pull_up_config: Pull_Up, pdrv_config: High_Driver}
  - {pin_num: D15, peripheral: USDHC1, signal: usdhc_clk, pin_signal: GPIO_SD_B1_01, software_input_on: Enable, pull_down_pull_up_config: No_Pull}
  - {pin_num: C15, peripheral: USDHC1, signal: 'usdhc_data, 0', pin_signal: GPIO_SD_B1_02, software_input_on: Enable, pdrv_config: High_Driver}
  - {pin_num: B17, peripheral: USDHC1, signal: 'usdhc_data, 1', pin_signal: GPIO_SD_B1_03, software_input_on: Enable, pdrv_config: High_Driver}
  - {pin_num: B15, peripheral: USDHC1, signal: 'usdhc_data, 2', pin_signal: GPIO_SD_B1_04, software_input_on: Enable, pdrv_config: High_Driver}
  - {pin_num: A16, peripheral: USDHC1, signal: 'usdhc_data, 3', pin_signal: GPIO_SD_B1_05, software_input_on: Enable, pull_down_pull_up_config: Pull_Up, pdrv_config: High_Driver}
  - {pin_num: G17, peripheral: GPIO10, signal: 'gpio_io, 02', pin_signal: GPIO_AD_35}
  - {pin_num: K16, peripheral: CM7_GPIO3, signal: 'gpio_mux_io_cm7, 31', pin_signal: GPIO_AD_32}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins, assigned for the Cortex-M7F core.
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           /* LPCG on: LPCG is ON. */

  /* GPIO configuration of USER_GREEN on GPIO_EMC_B2_18 (pin N3) */
  gpio_pin_config_t USER_GREEN_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_EMC_B2_18 (pin N3) */
  GPIO_PinInit(GPIO8, 28U, &USER_GREEN_config);

  /* GPIO configuration of USER_RED on GPIO_AD_08 (pin R15) */
  gpio_pin_config_t USER_RED_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_08 (pin R15) */
  GPIO_PinInit(GPIO9, 7U, &USER_RED_config);

  /* GPIO configuration of USER_BLUE on GPIO_AD_10 (pin R17) */
  gpio_pin_config_t USER_BLUE_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_10 (pin R17) */
  GPIO_PinInit(GPIO9, 9U, &USER_BLUE_config);

  /* GPIO configuration of USER_S1 on WAKEUP_DIG (pin T8) */
  gpio_pin_config_t USER_S1_config = {
      .direction = kGPIO_DigitalInput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_IntFallingEdge
  };
  /* Initialize GPIO functionality on WAKEUP_DIG (pin T8) */
  GPIO_PinInit(GPIO13, 0U, &USER_S1_config);
  /* Enable GPIO pin interrupt on WAKEUP_DIG (pin T8) */
  GPIO_PortEnableInterrupts(GPIO13, 1U << 0U);

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_08_GPIO9_IO07,           /* GPIO_AD_08 is configured as GPIO9_IO07 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_10_GPIO9_IO09,           /* GPIO_AD_10 is configured as GPIO9_IO09 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_24_LPUART1_TXD,          /* GPIO_AD_24 is configured as LPUART1_TXD */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_25_LPUART1_RXD,          /* GPIO_AD_25 is configured as LPUART1_RXD */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_25 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_32_GPIO_MUX3_IO31,       /* GPIO_AD_32 is configured as GPIO_MUX3_IO31 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_34_USDHC1_VSELECT,       /* GPIO_AD_34 is configured as USDHC1_VSELECT */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_35_GPIO10_IO02,          /* GPIO_AD_35 is configured as GPIO10_IO02 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_EMC_B2_18_GPIO8_IO28,       /* GPIO_EMC_B2_18 is configured as GPIO8_IO28 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_00_USDHC1_CMD,        /* GPIO_SD_B1_00 is configured as USDHC1_CMD */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_00 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_01_USDHC1_CLK,        /* GPIO_SD_B1_01 is configured as USDHC1_CLK */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_01 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_02_USDHC1_DATA0,      /* GPIO_SD_B1_02 is configured as USDHC1_DATA0 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_02 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_03_USDHC1_DATA1,      /* GPIO_SD_B1_03 is configured as USDHC1_DATA1 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_03 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_04_USDHC1_DATA2,      /* GPIO_SD_B1_04 is configured as USDHC1_DATA2 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_04 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_05_USDHC1_DATA3,      /* GPIO_SD_B1_05 is configured as USDHC1_DATA3 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_05 */
  IOMUXC_GPR->GPR43 = ((IOMUXC_GPR->GPR43 &
    (~(IOMUXC_GPR_GPR43_GPIO_MUX3_GPIO_SEL_HIGH_MASK))) /* Mask bits to zero which are setting */
      | IOMUXC_GPR_GPR43_GPIO_MUX3_GPIO_SEL_HIGH(0x8000U) /* GPIO3 and CM7_GPIO3 share same IO MUX function, GPIO_MUX3 selects one GPIO function: 0x8000U */
    );
  IOMUXC_SetPinMux(
      IOMUXC_WAKEUP_DIG_GPIO13_IO00,          /* WAKEUP_DIG is configured as GPIO13_IO00 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_24_LPUART1_TXD,          /* GPIO_AD_24 PAD functional properties : */
      0x00U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: normal drive strength
                                                 Pull / Keep Select Field: Pull Disable, Highz
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_25_LPUART1_RXD,          /* GPIO_AD_25 PAD functional properties : */
      0x00U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: normal drive strength
                                                 Pull / Keep Select Field: Pull Disable, Highz
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_00_USDHC1_CMD,        /* GPIO_SD_B1_00 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_01_USDHC1_CLK,        /* GPIO_SD_B1_01 PAD functional properties : */
      0x0CU);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: No Pull
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_02_USDHC1_DATA0,      /* GPIO_SD_B1_02 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_03_USDHC1_DATA1,      /* GPIO_SD_B1_03 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_04_USDHC1_DATA2,      /* GPIO_SD_B1_04 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_05_USDHC1_DATA3,      /* GPIO_SD_B1_05 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitMipiPanelPins:
- options: {callFromInitBoot: 'false', coreID: cm7, enableClock: 'true'}
- pin_list:
  - {pin_num: M17, peripheral: GPIO9, signal: 'gpio_io, 28', pin_signal: GPIO_AD_29, gpio_init_state: no_init, pull_up_down_config: Pull_Up, pull_keeper_select: Pull,
    drive_strength: High}
  - {pin_num: K2, peripheral: LPI2C2, signal: SCL, pin_signal: GPIO_EMC_B2_00, software_input_on: Enable, pdrv_config: no_init, open_drain: Enable}
  - {pin_num: K4, peripheral: LPI2C2, signal: SDA, pin_signal: GPIO_EMC_B2_01, software_input_on: Enable, pull_down_pull_up_config: Pull_Down, pdrv_config: no_init,
    open_drain: Enable}
  - {pin_num: K17, peripheral: GPIO9, signal: 'gpio_io, 29', pin_signal: GPIO_AD_30, gpio_interrupt: no_init, software_input_on: Enable, pull_up_down_config: Pull_Down,
    pull_keeper_select: no_init, drive_strength: Normal}
  - {pin_num: P13, peripheral: GPIO9, signal: 'gpio_io, 04', pin_signal: GPIO_AD_05, gpio_init_state: no_init, pull_up_down_config: Pull_Down, pull_keeper_select: no_init,
    open_drain: Disable, drive_strength: Normal, slew_rate: Slow}
  - {pin_num: M14, peripheral: GPIO9, signal: 'gpio_io, 14', pin_signal: GPIO_AD_15, pull_keeper_select: no_init}
  - {pin_num: R1, peripheral: GPIO8, signal: 'gpio_io, 13', pin_signal: GPIO_EMC_B2_03, gpio_init_state: no_init, pull_down_pull_up_config: Pull_Down, pdrv_config: Normal_Driver}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitMipiPanelPins, assigned for the Cortex-M7F core.
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitMipiPanelPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           /* LPCG on: LPCG is ON. */

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_05_GPIO9_IO04,           /* GPIO_AD_05 is configured as GPIO9_IO04 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_15_GPIO9_IO14,           /* GPIO_AD_15 is configured as GPIO9_IO14 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_29_GPIO9_IO28,           /* GPIO_AD_29 is configured as GPIO9_IO28 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_30_GPIO9_IO29,           /* GPIO_AD_30 is configured as GPIO9_IO29 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_30 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_EMC_B2_00_LPI2C2_SCL,       /* GPIO_EMC_B2_00 is configured as LPI2C2_SCL */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_EMC_B2_00 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_EMC_B2_01_LPI2C2_SDA,       /* GPIO_EMC_B2_01 is configured as LPI2C2_SDA */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_EMC_B2_01 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_EMC_B2_03_GPIO8_IO13,       /* GPIO_EMC_B2_03 is configured as GPIO8_IO13 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_05_GPIO9_IO04,           /* GPIO_AD_05 PAD functional properties : */
      0x04U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: normal drive strength
                                                 Pull / Keep Select Field: Pull Enable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_29_GPIO9_IO28,           /* GPIO_AD_29 PAD functional properties : */
      0x0EU);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: high drive strength
                                                 Pull / Keep Select Field: Pull Enable
                                                 Pull Up / Down Config. Field: Weak pull up
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_30_GPIO9_IO29,           /* GPIO_AD_30 PAD functional properties : */
      0x04U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: normal drive strength
                                                 Pull / Keep Select Field: Pull Enable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_EMC_B2_00_LPI2C2_SCL,       /* GPIO_EMC_B2_00 PAD functional properties : */
      0x18U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pulldown resistor enabled
                                                 Open Drain Field: Enabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_EMC_B2_01_LPI2C2_SDA,       /* GPIO_EMC_B2_01 PAD functional properties : */
      0x18U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pulldown resistor enabled
                                                 Open Drain Field: Enabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_EMC_B2_03_GPIO8_IO13,       /* GPIO_EMC_B2_03 PAD functional properties : */
      0x0AU);                                 /* PDRV Field: normal drive strength
                                                 Pull Down Pull Up Field: Internal pulldown resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
