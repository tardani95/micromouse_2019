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

//#define STM_EVAL /* TODO comment it out if the stm evaluation board is not used */
/* Includes */
#include "stm32f4xx.h"

#include "misc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @defgroup hardware_modules Hardware Modules
 * @{
 */
#include "hw_button.h"
#include "hw_encoder.h"
#include "hw_IMU.h"
#include "hw_motor_control.h"
#include "hw_status_led.h"
#include "hw_BT_module.h"

#include "hw_adc_module.h"

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
#include "sw_control.h"

#include "util.h"

/**
 * @}
 */

#ifdef STM_EVAL
#include "stm32f4_discovery.h"
#endif

/* Private macro */
/* Private variables */

//uint8_t i2cRxBuffer[14] = { };
//uint8_t i2cTxBuffer[] = { 0x3B, 0x3B, 0x3B, 0x3B };
//int16_t accel_gyro_temp[7];
//float gForceX, gForceY, gForceZ;
//float rotX, rotY, rotZ;
//float temp_C;
//volatile uint16_t *adc_readings;
volatile uint8_t toggle = 1;
volatile uint8_t rgb_led_status = 0;

menu_p_t main_menu_p;
menu_p_t after_run_menu_p;

/* Private function prototypes */
/* Private functions */

/**
 * @brief Initialize all peripherals\n
 * but with all interrupts disabled
 * @param None
 * @return None
 */
void Init_Periph(void) {

	initSysTick();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); /* 4 bit (0-15 -- the lower the higher) for preemption, and 0 bit for sub-priority */

	initStatusLEDs();
	initMotorControl();

	initADC();

	initEncoders();
//	initMenus(&main_menu_p, &after_run_menu_p);

	initBTModule();
	initIMU();
	if (setupIMU()) { /* if the communication working with the IMU, than sets the pink led for 1.5 seconds */
		setLED(LED_PINK);
		delay_ms(1500);
		resetLED(LED_PINK);
	}

	Init_Buttons();

	Init_Control();
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
	/*Remap vector table to enable debugging*/
	SCB->VTOR = 0x08008000 & (int32_t) 0x1FFFFF80;

	Init_Periph();

//	uint32_t enc_left;
//	uint32_t enc_right;
//	actuateMotors(7000, 0);
	UART_DMASend("checkpoint1\n");

//	IMU_DMA_GetRaw();
//	delaySome_ms();

//	IMU_DMA_GetRaw();
//	delaySome_ms();

//	setLED(PINK);

	UART_DMASend("checkpoint2\n");

	UART_DMA_StartListening();

	/* Infinite loop */
	while (1) {
		i++;

		float battery_voltage = ADC_getBatLvl();
//		uint16_t *adc_readings = ADC_measureIRAll();
		setLED(LED_PINK);
		ADC_startIRMeasurement(MS_IRD_OFF);
		delay_ms(2);
		uint16_t *adc_readings = ADC_getMeasuredValues();
		delay_ms(2);
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
//
//		MPU6050_GetRawAccelGyro(accel_gyro_temp);
//		MPU6050_DMAGetRawAccelGyro();
//		for (uint32_t i = 0; i < 32000; i += 2) {
//			i--;
//		}

	}
}

/**
 * external interrupt handler for the buttons
 */
void EXTI15_10_IRQHandler() {
	/**
	 * @note sometimes button 1 interrupt also gets called when button 2 is pressed
	 *  it is because we forgot to put an 1k resistor between the button and the ground
	 */

	/* button1 pressed*/
	if (SET == EXTI_GetITStatus(BTN1_EXTI_Line)) {

		//INFO("Button1 pressed");
		//TODO handle button1 pressed action

		toggle = !toggle;

		if (!toggle) {

			/*reset encoder values*/
			m_resetEncCnt(ENC_LEFT_TIM);
			m_resetEncCnt(ENC_RIGHT_TIM);
//			ControlLoop_Cmd(ENABLE);

		} else {
//			ControlLoop_Cmd(DISABLE);
			actuateMotor(LEFT, COAST, 0);
			actuateMotor(RIGHT, COAST, 0);
//			TIM3->CCR1 = 0;
//			TIM3->CCR2 = 0;
//			TIM3->CCR3 = 0;
//			TIM3->CCR4 = 0;
//			volatile uint32_t testLEFT = TIM1->CNT;
//			volatile uint32_t testRIGHT = TIM4->CNT;
//			int j;
//			if (testRIGHT > ENC_CNT_BASEVALUE) {
//				j = 0;
//			} else {
//				j = 1;
//			}
		}

		rgb_led_status++;
		EXTI_ClearITPendingBit(BTN1_EXTI_Line);
	}

	/* button2 pressed*/
	if (SET == EXTI_GetITStatus(BTN2_EXTI_Line)) {

		//INFO("Button2 pressed");
		//TODO handle button2 pressed action

		rgb_led_status++;
		EXTI_ClearITPendingBit(BTN2_EXTI_Line);
	}

	setRGB(rgb_led_status % 10);
}

/**
 * @}
 */

