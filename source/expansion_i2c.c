/*
 * board_i2c.c
 *
 *  Created on: May 14, 2021
 *      Author: gulziibayar
 */
#include "fsl_lpi2c.h"
#include "board.h"
#include "expansion_i2c.h"

void init_expansion_i2c() {
	BOARD_LPI2C_Init(IO_EXP_I2C_MASTER, LPI2C_MASTER_CLOCK_FREQUENCY);
}

/*****************************************************************************\
 * Function:    scan_i2c_bus
 * Input:       uint8_t *buff - expecting 16 byte buffer
 * Returns:     void
 * Description:
 *     This function checks all nodes 0 - 0x80 addresses. Store the address
 *     information inside input buffer. There can be total of 128 nodes.
 *     16 = 128/8. Each bit represents the node.
\*****************************************************************************/

void scan_i2c_bus(uint8_t *buff)
{
	uint8_t rxBuff;	// dummy byte
	uint8_t index = 0;
	uint8_t bit_pos = 0;

	// Iterate through the address starting at 0x00
	for(uint32_t i2caddress=0;i2caddress<0x80;i2caddress++)
	{
		index = i2caddress/8;
		bit_pos = 7-(i2caddress%8);
		if (BOARD_LPI2C_Receive(IO_EXP_I2C_MASTER, i2caddress, 0x00, 1, &rxBuff, 1) == kStatus_LPI2C_Nak) {
			buff[index] &= ~(1<<bit_pos);
		} else {
			buff[index] |= (1<<bit_pos);
		}
	}
}
