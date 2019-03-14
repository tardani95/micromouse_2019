/**
 * @mainpage 	Micromouse 2019 - Waldläufer
 * @author 		Daniel Tar, Zoltan Resi, Andras Lauko
 * @date		11-03-2019
 *
 * here comes the code style,
 * naming conventions,
 * general information,
 *
 @verbatim
 Documentation Rules:

 For variables:
 int var; Detailed description after the member

 For functions one can use the @ param command to document the parameters and then use [in], [out], [in,out] to document the direction. For inline documentation this is also possible by starting with the direction attribute, e.g.

 * @ brief description
 * @ param v
 * @ return None

 @endverbatim

 @code
 int sum(int a, int b){
 return a+b;
 }
 @endcode

 void foo(int v << [in] docs for input parameter v. );
 */

/**
 ******************************************************************************
 * @file    main.c
 * @author  Daniel Tar, Zoltar Resi, Andras Lauko
 * @version V0.1
 * @date    11-03-2019
 * @brief   main program
 ******************************************************************************
 * @attention
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ******************************************************************************
 */

/**
 * @defgroup micromouse2019_main main_software
 * @brief 	main()
 * @{
 */
/* Includes */
#include "stm32f4xx.h"
#include "misc.h"

/**
 * @defgroup hardware_modules Hardware Modules
 * @{
 */
#include "hw_button.h"
#include "hw_encoder.h"
#include "hw_IMU.h"
#include "hw_IR_module.h"
#include "hw_motor_control.h"
#include "hw_status_led.h"
/**
 * @}
 */

/**
 * @defgroup software_modules Software Modules
 * @{
 */
#include "sw_debug.h"
#include "sw_GPTIM.h"
#include "sw_menu.h"
/**
 * @}
 */
/* Private macro */
/* Private variables */
uint8_t i2cRxBuffer[14] = { };
uint8_t i2cTxBuffer[] = { 0x3B };
int16_t accel_gyro_temp[7];
float gForceX, gForceY, gForceZ;
float rotX, rotY, rotZ;
float temp_C;

/* Private function prototypes */
void MPU6050_CalcAccelRot(void);
/* Private functions */

/**
 * @brief Initialize all peripherals\n
 * but with all interrupts disabled
 * @param None
 * @return None
 */
void Init_Periph(void) {
	RCC_ClocksTypeDef clock_info;
	RCC_GetClocksFreq(&clock_info);

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); /* 4 bit (0-15 -- the lower the higher) for preemption, and 0 bit for sub-priority */
//	Init_Buttons();
}

/**
 **===========================================================================
 **
 **  Abstract: main program
 **
 **===========================================================================
 */
int main(void) {
	int i = 0;

	SystemInit(); /*startup script calls this function before main*/
	Init_Periph();
	/**
	 *  IMPORTANT NOTE!
	 *  The symbol VECT_TAB_SRAM needs to be defined when building the project
	 *  if code has been located to RAM and interrupts are used.
	 *  Otherwise the interrupt table located in flash will be used.
	 *  See also the <system_*.c> file and how the SystemInit() function updates
	 *  SCB->VTOR register.
	 *  E.g.  SCB->VTOR = 0x20000000;
	 */

	/* TODO - Add your application code here */
	uint8_t success = Init_IMU();

	Init_MPU6050_I2C_DMA(i2cTxBuffer, i2cRxBuffer);

	for (uint32_t i = 0; i < 32000; i += 2) {
		i--;
	}

	MPU6050_DMAGetRawAccelGyro();



	/* Infinite loop */
	while (1) {
		i++;

	}
}

/**
 * external interrupt handler for the buttons
 */
void EXTI15_10_IRQHandler() {
	/* button1 pressed*/
	if (SET == EXTI_GetITStatus(BTN1_EXTI_Line)) {

		//TODO handle button1 pressed action

		EXTI->PR = BTN1_EXTI_Line; /*clear pendig bit for button1*/
		return;
	}

	/* button2 pressed*/
	if (SET == EXTI_GetITStatus(BTN2_EXTI_Line)) {

		//TODO handle button2 pressed action

		EXTI->PR = BTN2_EXTI_Line; /*clear pendig bit for button2*/
		return;
	}
}

void I2C2_EV_IRQHandler(void) {
	if (I2C_GetFlagStatus(MPU6050_I2C, I2C_FLAG_SB) == SET) {
		if (i2cDirectionWrite) {
			// STM32 Transmitter
			I2C_Send7bitAddress(MPU6050_I2C, MPU6050_DEFAULT_ADDRESS,
			I2C_Direction_Transmitter);
		} else {
			// STM32 Receiver
			I2C_Send7bitAddress(MPU6050_I2C, MPU6050_DEFAULT_ADDRESS,
			I2C_Direction_Receiver);
		}
	} else if (I2C_CheckEvent(MPU6050_I2C,
	I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == SUCCESS) {
		if (i2cDirectionWrite) {
			// STM32 Transmitter
			DMA_Cmd(MPU6050_I2C_TX_Stream, ENABLE);
		}
	} else if (I2C_GetFlagStatus(MPU6050_I2C, I2C_FLAG_BTF)) {
		if (i2cDirectionWrite) {
			// STM32 Transmitter
			/*enable i2c rx stream*/
			DMA_Cmd(MPU6050_I2C_RX_Stream, ENABLE);
			I2C_DMALastTransferCmd(MPU6050_I2C, ENABLE);
			I2C_GenerateSTART(MPU6050_I2C, ENABLE);
			i2cDirectionWrite = 0;
			I2C_ClearFlag(MPU6050_I2C, I2C_FLAG_BTF);
		}
	}
}

// mpu6050 readings are ready
void DMA1_Stream0_IRQHandler(void) {
	DMA_ClearFlag(MPU6050_I2C_RX_Stream, DMA_FLAG_TCIF0);
	I2C_GenerateSTOP(MPU6050_I2C, ENABLE);
	DMA_Cmd(MPU6050_I2C_TX_Stream, DISABLE);
	DMA_Cmd(MPU6050_I2C_RX_Stream, DISABLE);

	MPU6050_CalcAccelRot();
}

void MPU6050_CalcAccelRot() {
	accel_gyro_temp[0] = (int16_t) (i2cRxBuffer[0] << 8 | i2cRxBuffer[1]);
	accel_gyro_temp[1] = (int16_t) (i2cRxBuffer[2] << 8 | i2cRxBuffer[3]);
	accel_gyro_temp[2] = (int16_t) (i2cRxBuffer[4] << 8 | i2cRxBuffer[5]);
	accel_gyro_temp[6] = (int16_t) (i2cRxBuffer[6] << 8 | i2cRxBuffer[7]); //temp
	accel_gyro_temp[3] = (int16_t) (i2cRxBuffer[8] << 8 | i2cRxBuffer[9]);
	accel_gyro_temp[4] = (int16_t) (i2cRxBuffer[10] << 8 | i2cRxBuffer[11]);
	accel_gyro_temp[5] = (int16_t) (i2cRxBuffer[12] << 8 | i2cRxBuffer[13]);

//	gForceX = (float) accel_gyro_temp[0] / 16384.0 * 9810;
//	gForceY = (float) accel_gyro_temp[1] / 16384.0 * 9810;
//	gForceZ = (float) accel_gyro_temp[2] / 16384.0 * 9810;
	gForceX = (float) accel_gyro_temp[0] / 1.67;
	gForceY = (float) accel_gyro_temp[1] / 1.67;
	gForceZ = (float) accel_gyro_temp[2] / 1.67;

	rotX = (float) accel_gyro_temp[3] / 65.5; //131.0; gyro @250 [LSB / deg/s]
	rotY = (float) accel_gyro_temp[4] / 65.5; //65.5   gyro @500 [LSB / deg/s]
	rotZ = (float) accel_gyro_temp[5] / 65.5; //131.0;

	temp_C = (float) accel_gyro_temp[6] / 340 + 36.53;
}

/**
 * @}
 */

