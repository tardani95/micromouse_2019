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
#include <stdio.h>

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
#include "hw_BT_module.h"
#include "hw_bat_lvl_watcher.h"
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

#include "util.h"

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

menu_p_t main_menu_p;
menu_p_t after_run_menu_p;

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

	initSysTick();
//	initBTModule();
	initStatusLEDs();
//	initMotorControl();
//	ADC_DeInit();
//	initBatLvlWatcher();
//	initEncoders();
	Init_IMU();
//	initMenus(&main_menu_p, &after_run_menu_p);
	//Init_MPU6050_I2C_DMA(i2cTxBuffer, i2cRxBuffer);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); /* 4 bit (0-15 -- the lower the higher) for preemption, and 0 bit for sub-priority */
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

//	SystemInit(); /*startup script calls this function before main*/

	Init_Periph();

//	SystemCoreClockUpdate();

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

	for (uint32_t i = 0; i < 32000; i += 2) {
		i--;
	}

	//resetRGB();
	//uint32_t enc_left;
	//uint32_t enc_right;

	setRGB(RGB_PINK);
	//setLED(PINK);
	setLED(YELLOW);
	//actuateMotors(7000, 0);

	/* Infinite loop */
	while (1) {
		i++;
		//enc_left = m_getEncCnt(ENC_LEFT);
		//enc_right = m_getEncCnt(ENC_RIGHT);

//		while (!USART_GetFlagStatus(BT_UART, USART_FLAG_RXNE))
//			;
//
//		uint16_t data = USART_ReceiveData(BT_UART);
//
//		while (!USART_GetFlagStatus(BT_UART, USART_FLAG_TXE))
//					;
//
//		if(data == 'n'){
//			nextItem(main_menu_p);
//		}
//		else if (data == 's'){
//			selectItem(main_menu_p);
//		}
//		else if(data == 'f'){//check how big the bluetooth module buffer is. apparently works fine up to 50 bytes
//			SEND("0123456789012345678901234567890123456789012345678901234567890123456789");
//		}
//		else if(data == 'm'){
//			MATSEND("insert sensor data and stuff");
//		}

		MPU6050_GetRawAccelGyro(accel_gyro_temp);
		for (uint32_t i = 0; i < 32000; i += 2) {
			i--;
		}

		//MPU6050_CalcAccelRot();

	}
}

/**
 * external interrupt handler for the buttons
 */
void EXTI15_10_IRQHandler() {
	//TODO - sometimes button 1 interrupt also gets called when button 2 is pressed
	/* button1 pressed*/
	if (SET == EXTI_GetITStatus(BTN1_EXTI_Line)) {

		//INFO("Button1 pressed");
		//TODO handle button1 pressed action

		resetLED(PINK);
		EXTI_ClearITPendingBit(BTN1_EXTI_Line);
		//EXTI->PR = BTN1_EXTI_Line; /*clear pendig bit for button1*/
		return;
	}

	/* button2 pressed*/
	if (SET == EXTI_GetITStatus(BTN2_EXTI_Line)) {

		INFO("Button2 pressed");
		//TODO handle button2 pressed action

		EXTI_ClearITPendingBit(BTN2_EXTI_Line);
		//EXTI->PR = BTN2_EXTI_Line; /*clear pendig bit for button2*/
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

