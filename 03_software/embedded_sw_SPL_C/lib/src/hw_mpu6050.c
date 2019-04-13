/***********************
 * @file 	hw_mpu6050.c
 * @author	tard
 * @date	Apr 12, 2019
 * @version	vx_x
 ************************/

#include "hw_mpu6050.h"

/** @addtogroup hardware_modules
 * @{
 */

/** @defgroup 	IMU Internal Measurement Unit
 *  @brief 		MPU6050 library for stm32f4xx
 * @{
 */

uint8_t i2cRxBuffer[14] = { };
uint8_t i2cTxBuffer[] = { 0x3B, 0x3B, 0x3B, 0x3B };

void initIMU() {

	GPIO_InitTypeDef GPIO_InitStructure;
	I2C_InitTypeDef I2C_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* Deinitialize the I2Cx peripheral*/
	I2C_DeInit(I2Cx);

	/* Enable peripheral clocks */
	RCC_APB1PeriphClockCmd(I2Cx_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd(I2Cx_GPIO_CLK, ENABLE);

	/* Configure the GPIO's alternate function */
	GPIO_PinAFConfig(I2Cx_GPIO_PORT, I2Cx_SCL_SOURCE, I2Cx_AF);
	GPIO_PinAFConfig(I2Cx_GPIO_PORT, I2Cx_SDA_SOURCE, I2Cx_AF);

	/* Configure I2C GPIO pins: SCL and SDA */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = I2Cx_SCL_PIN;
	GPIO_Init(I2Cx_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = I2Cx_SDA_PIN;
	GPIO_Init(I2Cx_GPIO_PORT, &GPIO_InitStructure);

	/* I2C configuration */
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = I2C_SPEED;
	I2C_InitStructure.I2C_DutyCycle = I2C_DUTYCYCLE;
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_OwnAddress1 = 0xA0;

	I2C_ITConfig(I2Cx, I2C_IT_EVT, ENABLE);
	I2C_DMACmd(I2Cx, ENABLE);

	/* all I2C register values set - initialize and enable I2C Peripheral */
	I2C_Init(I2Cx, &I2C_InitStructure);

	/* enable NVIC for I2C IRQs */
	NVIC_InitStructure.NVIC_IRQChannel = I2C1_EV_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/*
	 mpu6050_NVIC_InitStructure.NVIC_IRQChannel = I2C2_ER_IRQn;
	 mpu6050_NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	 mpu6050_NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	 mpu6050_NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	 NVIC_Init(&mpu6050_NVIC_InitStructure);

	 I2C_ITConfig(I2C2, I2C_IT_ERR, ENABLE);
	 */

	/* DMA configuration*/

	/* reset, release and enable DMA clock*/
//	RCC_AHB1PeriphResetCmd(DMAx_CLK, ENABLE);
//	RCC_AHB1PeriphResetCmd(DMAx_CLK, DISABLE);
	RCC_AHB1PeriphClockCmd(DMAx_CLK, ENABLE);

	/* deinitialize DMA Streams */
	DMA_DeInit(I2Cx_DMA_STREAM_TX);
	DMA_DeInit(I2Cx_DMA_STREAM_RX);

	/* common DMA settings */
	DMA_StructInit(&DMA_InitStructure);

	DMA_InitStructure.DMA_Channel = I2Cx_DMA_CHANNEL;
	DMA_InitStructure.DMA_PeripheralBaseAddr = I2Cx_DR_ADDRESS;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable;		// disabled by default
//	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full; // 1 quarter by default
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;

	/* DMA TX settings - DMA1 Stream 6, CH1 - I2C2 TX */
	DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) i2cTxBuffer;
	DMA_InitStructure.DMA_BufferSize = 0;
	DMA_Init(I2Cx_DMA_STREAM_TX, &DMA_InitStructure);

	/* DMA RX settings - DMA1 Stream 0, CH1 - I2C2 RX */
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) i2cRxBuffer;
	DMA_InitStructure.DMA_BufferSize = 0;
	DMA_Init(I2Cx_DMA_STREAM_RX, &DMA_InitStructure);


	/* enable DMA ITs*/
	DMA_ITConfig(I2Cx_DMA_STREAM_TX, DMA_IT_TC, ENABLE);
	DMA_ITConfig(I2Cx_DMA_STREAM_RX, DMA_IT_TC, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}

void IMU_DMASend(uint8_t *data, uint8_t length);
void IMU_readREG(uint8_t *regAddres);
void setupIMU();

void IMU_DMAGetRaw();

void I2C1_EV_IRQHandler(void){

}
void DMA1_Stream0_IRQHandler(void){

}
void DMA1_Stream6_IRQHandler(void){

}

/**
 * @}
 */

/**
 * @}
 */
