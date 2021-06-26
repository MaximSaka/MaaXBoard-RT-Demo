/*
 * board_i2c.c
 *
 *  Created on: May 14, 2021
 *      Author: gulziibayar
 */
#include "fsl_lpi2c.h"
#include "board.h"
#include "expansion_i2c.h"
#include "fsl_debug_console.h"
#include "audio_demo.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define I2C_BUS_SIZE  4

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern lpi2c_rtos_handle_t master_rtos_handle2;
extern lpi2c_rtos_handle_t master_rtos_handle3;
extern lpi2c_rtos_handle_t master_rtos_handle6;

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
//void scan_i2c_bus(lpi2c_rtos_handle_t *rtos_i2c_handle, uint8_t *buff)
//{
//	uint8_t rxBuff;	// dummy byte
//	uint8_t index = 0;
//	uint8_t bit_pos = 0;
//
//	// Iterate through the address starting at 0x00
//	for(uint32_t i2caddress=0;i2caddress<0x80;i2caddress++)
//	{
//		index = i2caddress/8;
//		bit_pos = 7-(i2caddress%8);
//		if (BOARD_RTOS_LPI2C_Receive(rtos_i2c_handle, i2caddress, 0x00, 1, &rxBuff, 1) == kStatus_Success)
//		{
//			buff[index] |= (1<<bit_pos);
//		}
//		else
//		{
//			buff[index] &= ~(1<<bit_pos);
//		}
//	}
//}

void scan_i2c_bus(lpi2c_rtos_handle_t *rtos_i2c_handle, uint8_t *buff)
{
	uint8_t rxBuff;	// dummy byte
	uint8_t index = 0;
	uint8_t bit_pos = 0;
	status_t ret;
	uint32_t status;
	status_t reVal        = kStatus_Fail;
	size_t txCount        = 0xFFU;


    /* Lock resource mutex */
    if (xSemaphoreTake(rtos_i2c_handle->mutex, portMAX_DELAY) != pdTRUE)
    {
        return;
    }
	// Iterate through the address starting at 0x00
	for(uint8_t i2caddress=0;i2caddress<0x80;i2caddress++)
	{
		index = i2caddress/8;
		bit_pos = 7-(i2caddress%8);
		if (BOARD_LPI2C_Receive(rtos_i2c_handle->base, i2caddress, 0, 0, &rxBuff, 1) == kStatus_LPI2C_Nak)
		{
			buff[index] &= ~(1<<bit_pos);
			LPI2C_MasterStop(rtos_i2c_handle->base);
		}
		else
		{
			buff[index] |= (1<<bit_pos);
		}

		SDK_DelayAtLeastUs(100, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

//		index = i2caddress/8;
//		bit_pos = 7-(i2caddress%8);
//		buff[index] &= ~(1<<bit_pos);
//		if (LPI2C_MasterStart(rtos_i2c_handle->base, i2caddress, 0) == kStatus_Success)
//		{
//			 /* Check master tx FIFO empty or not */
//			LPI2C_MasterGetFifoCounts(rtos_i2c_handle->base, NULL, &txCount);
//			while (txCount)
//			{
//				LPI2C_MasterGetFifoCounts(rtos_i2c_handle->base, NULL, &txCount);
//			}
//
//			//while(LPI2C_MasterGetStatusFlags(rtos_i2c_handle->base) & kLPI2C_MasterBusyFlag );
//
//			/* Check communicate with slave successful or not */
//			if (LPI2C_MasterGetStatusFlags(rtos_i2c_handle->base) & kLPI2C_MasterNackDetectFlag) //kLPI2C_MasterNackDetectFlag
//			{
//				buff[index] &= ~(1<<bit_pos);
//			}
//			else
//			{
//				buff[index] |= (1<<bit_pos);
//			}
//			ret = LPI2C_MasterStop(rtos_i2c_handle->base);
//			if (ret != kStatus_Success)
//			{
//				PRINTF("i2c stop error\r\n");
//			}
//		    /* Wait until the slave is ready for transmit, wait time depend on user's case.
//		       Slave devices that need some time to process received byte or are not ready yet to
//		       send the next byte, can pull the clock low to signal to the master that it should wait.*/
//		    for (uint32_t i = 0U; i < 200; i++)
//		    {
//		        __NOP();
//		    }
//
//		}
	}

	LPI2C_MasterStop(rtos_i2c_handle->base);
	/* Unlock resource mutex */
	(void)xSemaphoreGive(rtos_i2c_handle->mutex);
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
 *     returns the LPI2C handle address based on the 1-4 indexing.
\*****************************************************************************/
lpi2c_rtos_handle_t *select_i2c_bus(uint8_t index)
{
	lpi2c_rtos_handle_t *rtos_i2c_handle;

	switch(index)
	{
	case 2:
		rtos_i2c_handle = &master_rtos_handle2;
		break;
	case 3:
		rtos_i2c_handle = &master_rtos_handle3;
		break;
	case 5:
		rtos_i2c_handle = (lpi2c_rtos_handle_t *)getRtosI2cHandle();
		break;
	case 6:
		rtos_i2c_handle = &master_rtos_handle6;
		break;
	default:
		rtos_i2c_handle = &master_rtos_handle3;
		break;
	}
	return rtos_i2c_handle;
}


