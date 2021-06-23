/*
 * board_i2c.h
 *
 *  Created on: May 14, 2021
 *      Author: gulziibayar
 */

#ifndef EXPANSION_I2C_H_
#define EXPANSION_I2C_H_

#include "fsl_lpi2c.h"
#include "fsl_lpi2c_freertos.h"
/*
 * LPI2C3 is used. pins are configured on #3, #5 pin on the 40 pin header
 * More detailed information can be found on the pin_mux.c and MaaxBoardRT schematics pdf.
 * */

/* Get frequency of lpi2c clock */
#define LPI2C_CLOCK_FREQUENCY (CLOCK_GetFreq(kCLOCK_OscRc48MDiv2))

#define LPI2C_MASTER_CLOCK_FREQUENCY LPI2C_CLOCK_FREQUENCY
#define WAIT_TIME 10U

#define IO_EXP_I2C_MASTER_1 ((LPI2C_Type *)(LPI2C2_BASE))	// camera, display, t0136 (security device)
#define IO_EXP_I2C_MASTER_2 ((LPI2C_Type *)(LPI2C3_BASE))	// 40 pin #3 #5
#define IO_EXP_I2C_MASTER_3 ((LPI2C_Type *)(LPI2C5_BASE))	// codec, 18 pin #18 #17
#define IO_EXP_I2C_MASTER_4 ((LPI2C_Type *)(LPI2C6_BASE))	// 40 pin #27, #28


#define LPI2C_MASTER_SLAVE_ADDR_7BIT 0x7EU
#define LPI2C_BAUDRATE               100000U
#define LPI2C_DATA_LENGTH            33U

void init_expansion_i2c(LPI2C_Type *base);
void scan_i2c_bus(lpi2c_rtos_handle_t *rtos_i2c_handle, uint8_t *buff);
//void scan_i2c_test(lpi2c_rtos_handle_t *rtos_i2c_handle, uint8_t *buff);
//void scan_i2c_bus(LPI2C_Type *base, uint8_t *buff);
lpi2c_rtos_handle_t *select_i2c_bus(uint8_t index);
//LPI2C_Type *select_i2c_bus(uint8_t index);
uint8_t valid_i2c_index(int index);
#endif /* EXPANSION_I2C_H_ */
