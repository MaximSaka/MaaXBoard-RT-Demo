/*
 * board_i2c.c
 *
 *  Created on: May 14, 2021
 *      Author: gulziibayar
 */
#include "fsl_lpi2c.h"
#include "board.h"
#include "expansion_i2c.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define I2C_BUS_SIZE  4

/*****************************************************************************\
 * Function:    init_expansion_i2c
 * Input:       LPI2C_Type *base - base memory address of the LPI2C peripheral
 * Returns:     void
 * Description:
 *     Configures the LPI2C with 100Khz master device
\*****************************************************************************/
void init_expansion_i2c(LPI2C_Type *base) {
	BOARD_LPI2C_Init(base, LPI2C_MASTER_CLOCK_FREQUENCY);
}

/*****************************************************************************\
 * Function:    scan_i2c_bus
 * Inputs:      LPI2C_Type *base - i2c bus base address
 * 				uint8_t *buff - expecting 16 byte buffer
 * Returns:     void
 * Description:
 *     This function checks all nodes 0 - 0x80 addresses. Store the address
 *     information inside input buffer. There can be total of 128 nodes.
 *     16 = 128/8. Each bit represents the node.
\*****************************************************************************/

void scan_i2c_bus(LPI2C_Type *base, uint8_t *buff)
{
	uint8_t rxBuff;	// dummy byte
	uint8_t index = 0;
	uint8_t bit_pos = 0;

	// Iterate through the address starting at 0x00
	for(uint32_t i2caddress=0;i2caddress<0x80;i2caddress++)
	{
		index = i2caddress/8;
		bit_pos = 7-(i2caddress%8);
		if (BOARD_LPI2C_Receive(base, i2caddress, 0x00, 1, &rxBuff, 1) == kStatus_LPI2C_Nak) {
			buff[index] &= ~(1<<bit_pos);
		} else {
			buff[index] |= (1<<bit_pos);
		}
	}
}


/*****************************************************************************\
 * Function:    validate_i2c_index
 * Input:       index for i2c bus
 * Returns:     uint8_t
 * Description:
 *     returns the 1 - valid, 0 - not valid
\*****************************************************************************/
uint8_t valid_i2c_index(int index)
{
	int validIndexes[I2C_BUS_SIZE] = {2, 3, 5, 6};

	for (int i=0; i < I2C_BUS_SIZE; i++)
	{
		if (index == validIndexes[i])
		{
			return 1;
		}
	}
	return 0;
}

/*****************************************************************************\
 * Function:    select_i2c_bus
 * Input:       uint8_t index - index for i2c peripherals (1-4)
 * Returns:     void
 * Description:
 *     returns the LPI2C base address based on the 1-4 indexing.
\*****************************************************************************/
LPI2C_Type *select_i2c_bus(uint8_t index)
{
	LPI2C_Type *i2c_periph;
	switch(index)
	{
	case 2:
		i2c_periph = ((LPI2C_Type *)(LPI2C2_BASE));
		break;
	case 3:
		i2c_periph = ((LPI2C_Type *)(LPI2C3_BASE));
		break;
	case 5:
		i2c_periph = ((LPI2C_Type *)(LPI2C5_BASE));
		break;
	case 6:
		i2c_periph = ((LPI2C_Type *)(LPI2C6_BASE));
		break;
	default:
		i2c_periph = ((LPI2C_Type *)(LPI2C3_BASE));
		break;
	}
	return i2c_periph;
}


