/***********************
 * @file 	sw_com.h
 * @author	resiz
 * @date	24 Apr 2019
 ************************/
#ifndef SW_COM_H_
#define SW_COM_H_

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup com_module
 * @{
 */

#define COM_TX_PACKET_MAX_LENGTH	100

typedef enum{
	IR_CALIB_MEASURE,
	COMMAND_COUNT
}COMMAND;

typedef void (*PacketReceivedHandler)(uint16_t length, uint8_t *data);

void handleReceivedPacket(uint16_t length, uint8_t *data);
void sendPacket(COMMAND command, uint16_t length, uint8_t *data);

void addHandler(COMMAND command, PacketReceivedHandler handler);

/**
 * @}
 */

/**
 * @}
 */

#endif /* SW_COM_H_ */
