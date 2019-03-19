/***********************
 * @file 	hw_BT_module.c
 * @author	tard
 * @date	Mar 15, 2019
 * @version	vx_x
 ************************/

#include "hw_BT_module.h"
#include "sw_debug.h"
#include "hw_status_led.h"

/** @addtogroup hardware_modules
 * @{
 */

/** @defgroup bluetooth_module Bluetooth Module
 * @{
 */

void initBTModule(void) {

	/* deinitialize before use */
	USART_Cmd(BT_UART, DISABLE);
	USART_DeInit(BT_UART);

	/* enable clock*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

	//TODO call USART_OverSampling8Cmd(); if need higher baud rates (1MHz or more)

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_PinAFConfig(BT_Port, BT_TX_PinSource, GPIO_AF_USART3);
	GPIO_PinAFConfig(BT_Port, BT_RX_PinSource, GPIO_AF_USART3);

	GPIO_InitTypeDef bt_gpio;
	bt_gpio.GPIO_Mode = GPIO_Mode_AF;
	bt_gpio.GPIO_OType = GPIO_OType_OD;
	bt_gpio.GPIO_Pin = BT_RX_Pin | BT_TX_Pin;
	bt_gpio.GPIO_PuPd = GPIO_PuPd_UP;	//TODO - check pullup - theoretically ok
	bt_gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BT_Port, &bt_gpio);

	USART_InitTypeDef bt_uart;
	bt_uart.USART_BaudRate = BT_UART_Baud;
	bt_uart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	bt_uart.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	bt_uart.USART_Parity = BT_UART_Parity;
	bt_uart.USART_StopBits = USART_StopBits_1;
	bt_uart.USART_WordLength = USART_WordLength_8b;
	USART_Init(BT_UART, &bt_uart);




//	/* USART3 TX*/
//	NVIC_InitStructure->NVIC_IRQChannel = DMA1_Channel4_IRQn;
//	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 1;
//	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(NVIC_InitStructure);
//
//	/* USART3 RX*/
//	NVIC_InitStructure->NVIC_IRQChannel = DMA1_Channel5_IRQn;
//	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 2;
//	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(NVIC_InitStructure);

//	/* DMA 1, Channel 4 for USART1 TX */
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
//	DMA_DeInit(DMA1_Channel4);
//	DMA_InitStructure->DMA_PeripheralBaseAddr = (uint32_t) &(USART1->DR);
//	DMA_InitStructure->DMA_MemoryBaseAddr = (uint32_t) usart_transmit_array;
//	DMA_InitStructure->DMA_DIR = DMA_DIR_PeripheralDST;
//	DMA_InitStructure->DMA_BufferSize = 0;
//	DMA_InitStructure->DMA_PeripheralInc = DMA_PeripheralInc_Disable;
//	DMA_InitStructure->DMA_MemoryInc = DMA_MemoryInc_Enable;
//	DMA_InitStructure->DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
//	DMA_InitStructure->DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
//	DMA_InitStructure->DMA_Mode = DMA_Mode_Normal;
//	DMA_InitStructure->DMA_Priority = DMA_Priority_Medium;
//	DMA_InitStructure->DMA_M2M = DMA_M2M_Disable;
//	DMA_Init(DMA1_Channel4, DMA_InitStructure);
//
//	/* DMA 1, Channel 5 for USART1 RX */
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
//	DMA_DeInit(DMA1_Channel5);
//	DMA_StructInit(DMA_InitStructure);
//	DMA_InitStructure->DMA_PeripheralBaseAddr = (uint32_t) &(USART1->DR);
//	DMA_InitStructure->DMA_MemoryBaseAddr = (uint32_t) usart_receive_array;
//	DMA_InitStructure->DMA_DIR = DMA_DIR_PeripheralSRC;
//	DMA_InitStructure->DMA_BufferSize = 0;
//	DMA_InitStructure->DMA_PeripheralInc = DMA_PeripheralInc_Disable;
//	DMA_InitStructure->DMA_MemoryInc = DMA_MemoryInc_Enable;
//	DMA_InitStructure->DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
//	DMA_InitStructure->DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
//	DMA_InitStructure->DMA_Mode = DMA_Mode_Circular;
//	DMA_InitStructure->DMA_Priority = DMA_Priority_Medium;
//	DMA_InitStructure->DMA_M2M = DMA_M2M_Disable;
//	DMA_Init(DMA1_Channel5, DMA_InitStructure);


	USART_Cmd(BT_UART, ENABLE);
}


void BTSendString(char *string){
	for(uint8_t i = 0; i < MAX_STRING_SIZE; i++){
		//this doesnt work cause jdy buffer gets full
		/*while(!USART_GetFlagStatus(BT_UART, USART_FLAG_TXE))
			;
		USART_SendData(BT_UART, string[i]);*/
		while(!USART_GetFlagStatus(BT_UART, USART_FLAG_TXE));
		USART_SendData(BT_UART, string[i]);
		//this works
		if(string[i] == '\0'){
			break;
		}

	}
	waitForAck();

}

void BTSendChar(char c){
	USART_SendData(BT_UART, c);
	waitForAck();
}

void waitForAck(void){
	while(!USART_GetFlagStatus(BT_UART, USART_FLAG_RXNE));
	uint16_t data = USART_ReceiveData(BT_UART);
	if(data != 100){// 100 is acknowledgement byte
		setLED(PINK);
	}
}

/**
 * @}
 */

/**
 * @}
 */
