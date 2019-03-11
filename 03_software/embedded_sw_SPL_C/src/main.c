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
/* Private function prototypes */
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

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); /* 4 bit (0-15 -- the lower the higher) for preemption, and 0 bit for sub-priority */
	Init_Buttons();
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

	//SystemInit(); /*startup script calls this function before main*/
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

	/* Infinite loop */
	while (1) {
		i++;
	}
}

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

/**
 * @}
 */

