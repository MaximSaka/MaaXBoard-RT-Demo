/*
 * board_i2c.h
 *
 *  Created on: May 14, 2021
 *      Author: gulziibayar
 */

#ifndef EXPANSION_I2C_H_
#define EXPANSION_I2C_H_

#include "fsl_lpi2c.h"

/*
 * LPI2C3 is used. pins are configured on #3, #5 pin on the 40 pin header
 * More detailed information can be found on the pin_mux.c and MaaxBoardRT schematics pdf.
 * */
#define EXAMPLE_I2C_MASTER_BASE (LPI2C3_BASE)

/* Get frequency of lpi2c clock */
#define LPI2C_CLOCK_FREQUENCY (CLOCK_GetFreq(kCLOCK_OscRc48MDiv2))

#define LPI2C_MASTER_CLOCK_FREQUENCY LPI2C_CLOCK_FREQUENCY
#define WAIT_TIME 10U

#define IO_EXP_I2C_MASTER ((LPI2C_Type *)EXAMPLE_I2C_MASTER_BASE)

#define LPI2C_MASTER_SLAVE_ADDR_7BIT 0x7EU
#define LPI2C_BAUDRATE               100000U
#define LPI2C_DATA_LENGTH            33U

void init_expansion_i2c();
void scan_i2c_bus(uint8_t *buff);
#endif /* EXPANSION_I2C_H_ */
