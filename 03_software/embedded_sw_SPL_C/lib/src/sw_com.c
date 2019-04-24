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
	PacketReceivedHandler handler = handler_mapping[command];
	handler(length - 1, data + 1);

}

void comSendPacket(COMMAND command, uint16_t length, uint8_t *data){
	uint8_t packet_length = length > COM_TX_PACKET_MAX_LENGTH ?
							COM_TX_PACKET_MAX_LENGTH : length;

	com_tx_buffer[0] = (uint8_t)command;
	memcpy(data, &com_tx_buffer[1], packet_length);
	com_tx_buffer[packet_length + 1] = '\n';
	UART_DMASend((char*)com_tx_buffer);
}

void addComReceivedPacketHandler(COMMAND command, PacketReceivedHandler handler){
	if((int)command < COMMAND_COUNT){
		handler_mapping[command] = handler;
	}
}



/**
 * @}
 */

/**
 * @}
 */
