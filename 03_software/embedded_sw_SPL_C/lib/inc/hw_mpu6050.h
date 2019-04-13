/***********************
 * @file 	hw_mpu6050.h
 * @author	tard
 * @date	Apr 12, 2019
 * @version	vx_x
 ************************/

#ifndef HW_MPU6050_H_
#define HW_MPU6050_H_

/** @addtogroup hardware_modules
 * @{
 */

/** @addtogroup IMU
 *  @brief 		MPU6050
 * @{
 */

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_dma.h"
#include "misc.h"

#define MPU6050_ADDRESS_AD0_LOW     0x68 // address pin low (GND), default for InvenSense evaluation board
#define MPU6050_ADDRESS_AD0_HIGH    0x69 // address pin high (VCC)
#define SLAVE_ADDRESS 				(MPU6050_ADDRESS_AD0_LOW<<1)

/* USER_TIMEOUT value for waiting loops. This timeout is just a guarantee that the
 application will not remain stuck if the I2C communication is corrupted.
 You may modify this timeout value depending on CPU frequency and application
 conditions (interrupts routines, number of data to transfer, speed, CPU
 frequency...). */
#define USER_TIMEOUT                  ((uint32_t)0x64) /* Waiting 1s */

/* I2Cx Communication boards Interface */
#define DMAx_CLK                      RCC_AHB1Periph_DMA1
#define I2Cx_CLK                      RCC_APB1Periph_I2C1
#define I2Cx_GPIO_CLK             	  RCC_AHB1Periph_GPIOB

#define I2Cx_AF                   	  GPIO_AF_I2C1
#define I2Cx_GPIO_PORT            	  GPIOB

#define I2Cx_SDA_PIN                  GPIO_Pin_9
#define I2Cx_SDA_SOURCE               GPIO_PinSource9

#define I2Cx_SCL_PIN                  GPIO_Pin_8
#define I2Cx_SCL_SOURCE               GPIO_PinSource8

/* To use the I2C at 400 KHz (in fast mode), the PCLK1 frequency (I2C peripheral
 input clock) must be a multiple of 10 MHz */
#define I2Cx                          I2C1
#define I2C_SPEED 					  400000
#define I2C_DUTYCYCLE 				  I2C_DutyCycle_16_9

#define I2Cx_DMA                      DMA1
#define I2Cx_DMA_CHANNEL              DMA_Channel_1
#define I2Cx_DR_ADDRESS               ((uint32_t) (&(I2Cx->DR))) /*0x40005410*/
#define I2Cx_DMA_STREAM_TX            DMA1_Stream6
#define I2Cx_DMA_STREAM_RX            DMA1_Stream0

#define I2Cx_TX_DMA_TCFLAG            DMA_FLAG_TCIF6
#define I2Cx_TX_DMA_FEIFLAG           DMA_FLAG_FEIF6
#define I2Cx_TX_DMA_DMEIFLAG          DMA_FLAG_DMEIF6
#define I2Cx_TX_DMA_TEIFLAG           DMA_FLAG_TEIF6
#define I2Cx_TX_DMA_HTIFLAG           DMA_FLAG_HTIF6
#define I2Cx_RX_DMA_TCFLAG            DMA_FLAG_TCIF0
#define I2Cx_RX_DMA_FEIFLAG           DMA_FLAG_FEIF0
#define I2Cx_RX_DMA_DMEIFLAG          DMA_FLAG_DMEIF0
#define I2Cx_RX_DMA_TEIFLAG           DMA_FLAG_TEIF0
#define I2Cx_RX_DMA_HTIFLAG           DMA_FLAG_HTIF0

#define TXBUFFERSIZE   2
#define RXBUFFERSIZE   14

/* MPU6050 registers */
#define WHO_AM_I				0x75

#define REG_PWR_MGMT_1			0x6B
#define REG_GYRO_CONFIG 		0x1B
#define REG_ACCEL_CONFIG		0x1C

#define REG_ACCEL_X_OUT_H		0x3B
#define REG_ACCEL_X_OUT_L		0x3C
#define REG_ACCEL_Y_OUT_H		0x3D
#define REG_ACCEL_Y_OUT_L		0x3E
#define REG_ACCEL_Z_OUT_H		0x3F
#define REG_ACCEL_Z_OUT_L		0x40

/* Temperature in degrees C = (TEMP_OUT Register Value as a signed quantity)/340 + 36.53 */
#define REG_TEMP_OUT_H			0x41
#define REG_TEMP_OUT_L			0x42

#define REG_GYRO_X_OUT_H		0x43
#define REG_GYRO_X_OUT_L		0x44
#define REG_GYRO_Y_OUT_H		0x45
#define REG_GYRO_Y_OUT_L		0x46
#define REG_GYRO_Z_OUT_H		0x47
#define REG_GYRO_Z_OUT_L		0x48

/* MPU6050 register settings */
#define MPU6050_PWR1_SLEEP_BIT          6
#define MPU6050_CLOCK_INTERNAL          0x00
#define MPU6050_CLOCK_PLL_XGYRO         0x01
#define MPU6050_CLOCK_PLL_YGYRO         0x02
#define MPU6050_CLOCK_PLL_ZGYRO         0x03

#define MPU6050_GYRO_FS_250_deg_per_s   0x00
#define MPU6050_GYRO_FS_500_deg_per_s   0x01
#define MPU6050_GYRO_FS_1000_deg_per_s  0x02
#define MPU6050_GYRO_FS_2000_deg_per_s  0x03

#define MPU6050_ACCEL_FS_2_g            0x00
#define MPU6050_ACCEL_FS_4_g            0x01
#define MPU6050_ACCEL_FS_8_g            0x02
#define MPU6050_ACCEL_FS_16_g           0x03

void initIMU(void);
uint8_t setupIMU(void);
void setupByte(uint8_t *bytoToSetup, uint8_t bitStart, uint8_t length, uint8_t data);
uint8_t IMU_GetDeviceID(void);
uint8_t IMU_readREG(uint8_t regAddr);

void IMU_DisableSleep_and_SetClockSource(uint8_t source);
void IMU_SetGyroFSRange(uint8_t fsRange);
void IMU_SetAccelFSRange(uint8_t fsRange);

void IMU_DMA_BufferWrite(uint8_t regAddr, uint16_t numByteToWrite);
void IMU_DMA_BufferRead(uint8_t regAddr, uint16_t numByteToRead);
void IMU_DMA_GetRaw();

void I2C1_EV_IRQHandler(void);
void DMA1_Stream0_IRQHandler(void);
void DMA1_Stream6_IRQHandler(void);

/**
 * @}
 */

/**
 * @}
 */
#endif /* HW_MPU6050_H_ */

