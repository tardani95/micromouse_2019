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


void initBTModule(void);

void BTSendString(char *string);

/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_BT_MODULE_H_ */
