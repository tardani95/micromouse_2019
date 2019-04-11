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

void initBTModule(char *txBuffer, char *rxBuffer) {

	/* deinitialize before use */
	USART_Cmd(BT_UART, DISABLE);
	USART_DeInit(BT_UART);

	/* Enable USART clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

	//TODO call USART_OverSampling8Cmd(); if need higher baud rates (1MHz or more)

	/* Enable GPIO clock*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	/* Enable the DMA clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

	/* Connect USART pins to AF */
	GPIO_PinAFConfig(BT_Port, BT_TX_PinSource, GPIO_AF_USART3);
	GPIO_PinAFConfig(BT_Port, BT_RX_PinSource, GPIO_AF_USART3);

	GPIO_InitTypeDef bt_gpio;
	bt_gpio.GPIO_Mode = GPIO_Mode_AF;
	bt_gpio.GPIO_OType = GPIO_OType_PP;
	bt_gpio.GPIO_PuPd = GPIO_PuPd_UP;
	bt_gpio.GPIO_Speed = GPIO_Speed_50MHz;
	bt_gpio.GPIO_Pin = BT_RX_Pin | BT_TX_Pin;
	GPIO_Init(BT_Port, &bt_gpio);

	USART_InitTypeDef bt_uart;
	bt_uart.USART_BaudRate = BT_UART_Baud;
	bt_uart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	bt_uart.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	bt_uart.USART_Parity = BT_UART_Parity;
	bt_uart.USART_StopBits = USART_StopBits_1;
	bt_uart.USART_WordLength = USART_WordLength_8b;
	USART_Init(BT_UART, &bt_uart);

	DMA_InitTypeDef bt_dma;

	/* DMA 1, Stream3, CH4 for USART3 TX */
	DMA_StructInit(&bt_dma);
	bt_dma.DMA_Channel = DMA_Channel_4;
	bt_dma.DMA_DIR = DMA_DIR_MemoryToPeripheral;
	bt_dma.DMA_Memory0BaseAddr = (uint32_t) txBuffer;
	bt_dma.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	bt_dma.DMA_MemoryInc = DMA_MemoryInc_Enable;
	bt_dma.DMA_PeripheralBaseAddr = (uint32_t) &(BT_UART->DR);
	bt_dma.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	bt_dma.DMA_FIFOMode = DMA_FIFOMode_Disable;
	bt_dma.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;
	DMA_Init(BT_UART_TX_DMA_Stream, &bt_dma);

	/* DMA 1, Stream1, CH4 for USART3 RX */
	DMA_StructInit(&bt_dma);
	bt_dma.DMA_BufferSize = 10;
	bt_dma.DMA_Mode = DMA_Mode_Normal;
	bt_dma.DMA_Channel = DMA_Channel_4;
	bt_dma.DMA_DIR = DMA_DIR_PeripheralToMemory;
	bt_dma.DMA_PeripheralBaseAddr = (uint32_t) &(BT_UART->DR);
	bt_dma.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	bt_dma.DMA_Memory0BaseAddr = (uint32_t) rxBuffer;
	bt_dma.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	bt_dma.DMA_MemoryInc = DMA_MemoryInc_Enable;
	bt_dma.DMA_FIFOMode = DMA_FIFOMode_Disable;
	bt_dma.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
	DMA_Init(BT_UART_RX_DMA_Stream, &bt_dma);

	NVIC_InitTypeDef bt_nvic;

	/* USART3 TX*/
	bt_nvic.NVIC_IRQChannel = DMA1_Stream3_IRQn;
	bt_nvic.NVIC_IRQChannelPreemptionPriority = 5;
	bt_nvic.NVIC_IRQChannelSubPriority = 0;
	bt_nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&bt_nvic);

	/* USART3 RX*/
	bt_nvic.NVIC_IRQChannel = DMA1_Stream1_IRQn;
	bt_nvic.NVIC_IRQChannelPreemptionPriority = 6;
	bt_nvic.NVIC_IRQChannelSubPriority = 0;
	bt_nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&bt_nvic);

	DMA_ITConfig(BT_UART_TX_DMA_Stream, DMA_IT_TC, ENABLE);
	DMA_ITConfig(BT_UART_RX_DMA_Stream, DMA_IT_TC, ENABLE);

	USART_DMACmd(BT_UART, USART_DMAReq_Tx, ENABLE);
	USART_DMACmd(BT_UART, USART_DMAReq_Rx, ENABLE);

	USART_Cmd(BT_UART, ENABLE);
}

void BTSendString(char *string) {
	for (uint8_t i = 0; i < MAX_STRING_SIZE; i++) {
		//this doesnt work cause jdy buffer gets full
		/*while(!USART_GetFlagStatus(BT_UART, USART_FLAG_TXE))
		 ;
		 USART_SendData(BT_UART, string[i]);*/
		while (!USART_GetFlagStatus(BT_UART, USART_FLAG_TXE))
			;
		USART_SendData(BT_UART, string[i]);
		//this works
		if (string[i] == '\0') {
			break;
		}

	}
	waitForAck();

}

void BTSendChar(char c) {
	USART_SendData(BT_UART, c);
	waitForAck();
}

void waitForAck(void) {
	while (!USART_GetFlagStatus(BT_UART, USART_FLAG_RXNE))
		;
	uint16_t data = USART_ReceiveData(BT_UART);
	if (data != 100) {	// 100 is acknowledgement byte
		setLED(PINK);
	}
}

/**
 * @}
 */

/**
 * @}
 */
