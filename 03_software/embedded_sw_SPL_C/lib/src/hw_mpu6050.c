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


uint8_t i2cTxBuffer[] = { REG_ACCEL_X_OUT_H };

//#define HALFWORD_FIFO

uint8_t i2cRxBuffer[14] = { };
int16_t accel_temp_gyro[7] = { };


float gForceX, gForceY, gForceZ;
float rotX, rotY, rotZ;
float temp_C;

volatile uint8_t WRITE_READY_FLAG = 0;
volatile uint8_t READ_READY_FLAG = 0;

volatile uint8_t i2cDirectionWrite = 0;

/**
 * @brief Initialize the peripheral settings
 * @note Call setupIMU() function after this to set some registers initial value
 */
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

//	I2C_ITConfig(I2Cx, I2C_IT_EVT, ENABLE);
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
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable; // disabled by default
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full; // 1 quarter by default
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
#ifdef HALFWORD_FIFO
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) accel_temp_gyro;
#else
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) i2cRxBuffer;
#endif
	DMA_InitStructure.DMA_BufferSize = 0;
	DMA_Init(I2Cx_DMA_STREAM_RX, &DMA_InitStructure);

	/* enable DMA ITs*/
//	DMA_ITConfig(I2Cx_DMA_STREAM_TX, DMA_IT_TC, ENABLE);
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

/**
 * @brief Sets up the configuration registers in the MPU6050
 * @param   None
 * @return  1 if the connection is successful
 */
uint8_t setupIMU() {

	IMU_DisableSleep_and_SetClockSource(MPU6050_CLOCK_PLL_XGYRO);

	/* do not need to call these because these are the initial settings */
	IMU_SetGyroFSRange(MPU6050_GYRO_FS_250_deg_per_s);
	IMU_SetAccelFSRange(MPU6050_ACCEL_FS_2_g);

	uint8_t retVal = (IMU_GetDeviceID() == MPU6050_ADDRESS_AD0_LOW);

	I2C_ITConfig(I2Cx, I2C_IT_EVT, ENABLE);

	return retVal;
}

void setupByte(uint8_t *bytoToSetup, uint8_t bitStart, uint8_t length,
		uint8_t data) {
	//      010 value to write
	// 76543210 bit numbers
	//    yyy   args: bitStart=4, length=3
	// 00011100 mask byte
	// 10101111 original value (sample)
	// 10100011 original & ~mask
	// 10101011 masked | value
	uint8_t mask = (((0x01 << length) - 1) << bitStart);
	data <<= bitStart; 	// shift data into correct position
	data &= mask; 						// zero all non-important bits in data
	(*bytoToSetup) &= ~(mask); 		// zero all important bits in existing byte
	(*bytoToSetup) |= data; 			// combine data with existing byte
}

/**
 * @brief Returns the MPU6050 default low AD0 address
 * @return MPU6050_ADDRESS_AD0_LOW
 */
uint8_t IMU_GetDeviceID() {
	return IMU_readREG(WHO_AM_I);
}

/**
 * @brief Read a single byte from the MPU6050 register
 * @param  regAddr 	Register address to read from
 * @return data 	The value that the register holds
 */
uint8_t IMU_readREG(uint8_t regAddr) {

	/* While the bus is busy */
	while (I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY))
		;

	/* Send START condition */
	I2C_GenerateSTART(I2Cx, ENABLE);

	/* Test on EV5 and clear it */
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT))
		;

	/* Send MPU6050 address for write */
	I2C_Send7bitAddress(I2Cx, SLAVE_ADDRESS, I2C_Direction_Transmitter);

	/* Test on EV6 and clear it */
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		;

	/* Clear EV6 by setting again the PE bit */
	I2C_Cmd(I2Cx, ENABLE);

	/* Send the MPU6050's internal address to write to */
	I2C_SendData(I2Cx, regAddr);

	/* Test on EV8 and clear it */
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		;

	/* Send STRAT condition a second time */
	I2C_GenerateSTART(I2Cx, ENABLE);

	/* Test on EV5 and clear it */
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT))
		;

	/* Send MPU6050 address for read */
	I2C_Send7bitAddress(I2Cx, SLAVE_ADDRESS, I2C_Direction_Receiver);

	/* Test on EV6 and clear it */
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
		;

	/* Disable Acknowledgement */
	I2C_AcknowledgeConfig(I2Cx, DISABLE);

	/* Send STOP Condition */
	I2C_GenerateSTOP(I2Cx, ENABLE);

	/* Test on EV7 and clear it with a read from I2Cx->DR */
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED))
		;

	/* Read a byte from the MPU6050 */
	uint8_t temp = I2C_ReceiveData(I2Cx);

	/* Enable Acknowledgement to be ready for another reception */
	I2C_AcknowledgeConfig(I2Cx, ENABLE);

	return temp;
}

/**
 * @brief Writes one byte to the MPU6050 register
 * @param regAddr	The address of the register in which the data will be written
 * @param data		The data to be written
 * @return None
 */
void IMU_writeREG(uint8_t regAddr, uint8_t data) {
	/* Send START condition */
	I2C_GenerateSTART(I2Cx, ENABLE);

	/* Test on EV5 and clear it */
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT))
		;

	/* Send MPU6050 address for write */
	I2C_Send7bitAddress(I2Cx, SLAVE_ADDRESS, I2C_Direction_Transmitter);

	/* Test on EV6 and clear it */
	while (!I2C_CheckEvent(I2Cx,
	I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		;

	/* Send the MPU6050's internal register address to write to */
	I2C_SendData(I2Cx, regAddr);

	/* Test on EV8 and clear it */
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		;

	/* Send the byte to be written */
	I2C_SendData(I2Cx, data);

	/* Test on EV8 and clear it */
	while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		;

	/* Send STOP condition */
	I2C_GenerateSTOP(I2Cx, ENABLE);
}

void IMU_DisableSleep_and_SetClockSource(uint8_t source) {

	/* read the current value of the register */
	uint8_t temp = IMU_readREG(REG_PWR_MGMT_1);

	/* disable sleep mode - set sleep bit to 0 */
	temp &= ((uint8_t) ~(0x01 << MPU6050_PWR1_SLEEP_BIT));

	/* set the clock source */
	setupByte(&temp, 0, 3, source);

	/* write in the register with polling */
	IMU_writeREG(REG_PWR_MGMT_1, temp);
}

void IMU_SetGyroFSRange(uint8_t fsRange) {
	uint8_t temp = IMU_readREG(REG_GYRO_CONFIG);
	setupByte(&temp, 3, 2, fsRange);
	IMU_writeREG(REG_GYRO_CONFIG, temp);
}

void IMU_SetAccelFSRange(uint8_t fsRange) {
	uint8_t temp = IMU_readREG(REG_ACCEL_CONFIG);
	setupByte(&temp, 3, 2, fsRange);
	IMU_writeREG(REG_ACCEL_CONFIG, temp);
}

void IMU_DMA_BufferWrite(uint8_t regAddr, uint16_t numByteToWrite) {

}
void IMU_DMA_BufferRead(uint8_t regAddr, uint16_t numByteToRead) {

}

void IMU_DMA_GetRaw() {
	i2cDirectionWrite = 1;
	DMA_SetCurrDataCounter(I2Cx_DMA_STREAM_TX, 1);
	DMA_SetCurrDataCounter(I2Cx_DMA_STREAM_RX, 14); /* read from registers: 0x3B to 0x48 (accel, temp , gyro) *//*14*/
	I2C_GenerateSTART(I2Cx, ENABLE);
}

void I2C1_EV_IRQHandler(void) {

	if (I2C_GetFlagStatus(I2Cx, I2C_FLAG_SB) == SET) {
		if (i2cDirectionWrite) {
			// STM32 Transmitter
			I2C_Send7bitAddress(I2Cx, SLAVE_ADDRESS,
			I2C_Direction_Transmitter);
		} else {
			// STM32 Receiver
			I2C_Send7bitAddress(I2Cx, SLAVE_ADDRESS,
			I2C_Direction_Receiver);
		}
	} else if (I2C_CheckEvent(I2Cx,
	I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == SUCCESS) {
		if (i2cDirectionWrite) {
			// STM32 Transmitter
			DMA_Cmd(I2Cx_DMA_STREAM_TX, ENABLE);
		}
	} else if (I2C_GetFlagStatus(I2Cx, I2C_FLAG_BTF) == SET) {
		if (i2cDirectionWrite) {
			// STM32 Transmitter
			/*enable i2c rx stream*/
			DMA_Cmd(I2Cx_DMA_STREAM_RX, ENABLE);
			I2C_DMALastTransferCmd(I2Cx, ENABLE);
			i2cDirectionWrite = 0;
			I2C_ClearFlag(I2Cx, I2C_FLAG_BTF);

			I2C_GenerateSTART(I2Cx, ENABLE); /* generates a restart condition*/
		}
	}
}

void MPU6050_CalcAccelRot() {

#ifdef HALFWORD_FIFO
	gForceX = (float) accel_temp_gyro[0] / 1.67;
	gForceY = (float) accel_temp_gyro[1] / 1.67;
	gForceZ = (float) accel_temp_gyro[2] / 1.67;

	rotX = (float) accel_temp_gyro[4] / 65.5; 	//131.0; gyro @250 [LSB / deg/s]
	rotY = (float) accel_temp_gyro[5] / 65.5;//65.5   gyro @500 [LSB / deg/s]
	rotZ = (float) accel_temp_gyro[6] / 65.5;//131.0;

	temp_C = (float) accel_temp_gyro[3] / 340 + 36.53;
#else
	accel_temp_gyro[0] = (int16_t) (i2cRxBuffer[0] << 8 | i2cRxBuffer[1]);
	accel_temp_gyro[1] = (int16_t) (i2cRxBuffer[2] << 8 | i2cRxBuffer[3]);
	accel_temp_gyro[2] = (int16_t) (i2cRxBuffer[4] << 8 | i2cRxBuffer[5]);
	accel_temp_gyro[3] = (int16_t) (i2cRxBuffer[6] << 8 | i2cRxBuffer[7]); //temp
	accel_temp_gyro[4] = (int16_t) (i2cRxBuffer[8] << 8 | i2cRxBuffer[9]);
	accel_temp_gyro[5] = (int16_t) (i2cRxBuffer[10] << 8 | i2cRxBuffer[11]);
	accel_temp_gyro[6] = (int16_t) (i2cRxBuffer[12] << 8 | i2cRxBuffer[13]);

	gForceX = (float) accel_temp_gyro[0] / 1.67;
	gForceY = (float) accel_temp_gyro[1] / 1.67;
	gForceZ = (float) accel_temp_gyro[2] / 1.67;

	rotX = (float) accel_temp_gyro[4] / 65.5; //131.0; gyro @250 [LSB / deg/s]
	rotY = (float) accel_temp_gyro[5] / 65.5; //65.5   gyro @500 [LSB / deg/s]
	rotZ = (float) accel_temp_gyro[6] / 65.5; //131.0;

	temp_C = (float) accel_temp_gyro[3] / 340 + 36.53;
#endif

//	gForceX = (float) accel_gyro_temp[0] / 16384.0 * 9810;
//	gForceY = (float) accel_gyro_temp[1] / 16384.0 * 9810;
//	gForceZ = (float) accel_gyro_temp[2] / 16384.0 * 9810;

}

/**
 * rx
 */
void DMA1_Stream0_IRQHandler(void) {
	DMA_ClearFlag(I2Cx_DMA_STREAM_TX, DMA_FLAG_TCIF6);
	DMA_ClearFlag(I2Cx_DMA_STREAM_RX, DMA_FLAG_TCIF0);
	I2C_GenerateSTOP(I2Cx, ENABLE);
	DMA_Cmd(I2Cx_DMA_STREAM_TX, DISABLE);
	DMA_Cmd(I2Cx_DMA_STREAM_RX, DISABLE);

	MPU6050_CalcAccelRot();
}

/**
 * tx
 */
void DMA1_Stream6_IRQHandler(void) {
//	DMA_Cmd(I2Cx_DMA_STREAM_TX, DISABLE);
}

/**
 * @}
 */

/**
 * @}
 */
