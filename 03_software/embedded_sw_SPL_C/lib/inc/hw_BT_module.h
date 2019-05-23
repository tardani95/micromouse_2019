/***********************
 * @file 	hw_BT_module.h
 * @author	resiz
 * @date	Mar 14, 2019
 ************************/

#ifndef HW_BT_MODULE_H_
#define HW_BT_MODULE_H_

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_dma.h"
#include "misc.h"
#include <string.h>

/** @addtogroup hardware_modules
 * @{
 */

/** @addtogroup bluetooth_module
 * @{
 */

#define BT_Port				GPIOC

#define BT_RX_Pin			GPIO_Pin_11
#define BT_TX_Pin   		GPIO_Pin_10

#define BT_RX_PinSource		GPIO_PinSource11
#define BT_TX_PinSource		GPIO_PinSource10

#define BT_UART_Baud		115200
#define BT_UART_Parity 		USART_Parity_No
#define BT_UART				USART3
#define BT_UART_TX_DMA_Stream	DMA1_Stream3
#define BT_UART_RX_DMA_Stream	DMA1_Stream1

void initBTModule();

void UART_Send(char *data);
void UART_DMASendString(char *data);
void UART_DMASendByteArray(uint8_t *data, uint8_t size);
void UART_DMA_StartListening(void);

void clearBuffer(void);

void BTSendString(char *string);
void BTSendChar(char string);

/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_BT_MODULE_H_ */
