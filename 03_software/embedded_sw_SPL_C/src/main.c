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

#define STM_EVAL /* TODO comment it out if the stm evaluation board is not used */

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

#ifdef STM_EVAL
	/* Initialize LEDs */
	STM_EVAL_LEDInit(LED3);
	STM_EVAL_LEDInit(LED4);
	STM_EVAL_LEDInit(LED5);
	STM_EVAL_LEDInit(LED6);
#else
	initStatusLEDs();
#endif

	//	initMotorControl();
	//	ADC_DeInit();
	//	initBatLvlWatcher();
	//	initEncoders();
	//	initMenus(&main_menu_p, &after_run_menu_p);
	//	Init_Buttons();

	initBTModule();
	initIMU();
	if (setupIMU()) { /* if the communication not working then it stops here */
#ifdef STM_EVAL
		STM_EVAL_LEDOn(LED3);
#else
		setLED(PINK);
#endif
	}

}

void delaySome_ms(void) {
	for (uint32_t i = 0; i < 32000; i += 2) {
		i--;
	}
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

	/* TODO - Add your application code here */
//	resetRGB();
//	uint32_t enc_left;
//	uint32_t enc_right;
//	setRGB(RGB_PINK);
//	setLED(PINK);
//	setLED(YELLOW);
//	actuateMotors(7000, 0);
	UART_DMASend("checkpoint1\n");
#ifdef STM_EVAL
	STM_EVAL_LEDOn(LED4);
#endif

	IMU_DMA_GetRaw();
	delaySome_ms();

	IMU_DMA_GetRaw();
	delaySome_ms();

	UART_DMASend("checkpoint2\n");
#ifdef STM_EVAL
	STM_EVAL_LEDOn(LED5);
#endif

	UART_DMA_StartListening();
	STM_EVAL_LEDOn(LED6);

	/* Infinite loop */
	while (1) {
		i++;

//		enc_left = m_getEncCnt(ENC_LEFT);
//		enc_right = m_getEncCnt(ENC_RIGHT);
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

		IMU_DMA_GetRaw();
		STM_EVAL_LEDToggle(LED3);
		delay_ms(500);
		STM_EVAL_LEDToggle(LED4);
		delay_ms(500);
		STM_EVAL_LEDToggle(LED5);
		delay_ms(500);
		STM_EVAL_LEDToggle(LED6);
		delay_ms(500);
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

		toggleLED(PINK);
		rgb_led_status++;
		EXTI_ClearITPendingBit(BTN1_EXTI_Line);
		//EXTI->PR = BTN1_EXTI_Line; /*clear pendig bit for button1*/
//		return;
	}

	/* button2 pressed*/
	if (SET == EXTI_GetITStatus(BTN2_EXTI_Line)) {

		//INFO("Button2 pressed");
		//TODO handle button2 pressed action

		rgb_led_status++;

		EXTI_ClearITPendingBit(BTN2_EXTI_Line);
		//EXTI->PR = BTN2_EXTI_Line; /*clear pendig bit for button2*/
//		return;
	}

	setRGB(rgb_led_status % 10);
}


/**
 * @}
 */

