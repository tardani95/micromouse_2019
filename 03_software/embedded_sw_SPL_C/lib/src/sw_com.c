/***********************
 * @file 	sw_com.c
 * @author	resiz
 * @date	24 Apr 2019
 ************************/

/** @addtogroup software_modules
 * @{
 */

/** @defgroup com_module Communication Module
 * @brief Functions, command definitions and handlers for communication.
 * @{
 */

#include "hw_BT_module.h"
#include "sw_com.h"

uint8_t com_tx_buffer[COM_TX_PACKET_MAX_LENGTH + 2];

volatile PacketReceivedHandler handler_mapping[COMMAND_COUNT];

void handleReceivedPacket(uint16_t length, uint8_t *data){
	COMMAND command = (COMMAND)data[0];
	PacketReceivedHandler handler = NULL;
	if((int)command == IR_CALIB_MEASURE){
		handler = handler_mapping[0];
	}
	if((int)command == IR_AMBIENT_MEASURE){
		handler = handler_mapping[1];
	}
	if(handler != NULL){
		if(length > 1){
			handler(length - 1, &data[1]);
		}
		else{
			handler(0, NULL);
		}
	}

}

void comSendPacket(COMMAND command, uint16_t length, uint8_t *data){
	uint8_t packet_length = length > COM_TX_PACKET_MAX_LENGTH ?
							COM_TX_PACKET_MAX_LENGTH : length;

	com_tx_buffer[0] = (uint8_t)(length + 1);
	com_tx_buffer[1] = (uint8_t)command;
	memcpy(&com_tx_buffer[2], data, packet_length);
	UART_DMASendBytes(packet_length + 2, (char*)com_tx_buffer);
}

void addComReceivedPacketHandler(COMMAND command, PacketReceivedHandler handler){
	if((int)command == IR_CALIB_MEASURE){
		handler_mapping[0] = handler;
	}
	if((int)command == IR_AMBIENT_MEASURE){
		handler_mapping[1] = handler;
	}
}



/**
 * @}
 */

/**
 * @}
 */
