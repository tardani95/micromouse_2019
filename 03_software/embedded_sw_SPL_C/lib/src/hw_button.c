/***********************
 * @file 	hw_button.c
 * @author	tard
 * @date	Mar 8, 2019
 * @version	vx_x
 ************************/

#include "hw_button.h"

/** @addtogroup hardware_modules
 * @{
 */

/** @defgroup 	button	Button
 * @{
 */

void Init_Button() {
	/* button1 -- PB12*/
	/* button2 -- PB13*/

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef button_GPIO_InitStructure; /**< gpio init typedef for button1_GPIO_InitTypeDef */
	GPIO_StructInit(&button_GPIO_InitStructure); /* set defaults value for the initstruct */

	/* by input the ouput type (push-pull or open-drain) and output speed does not matter */
	button_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; /* set mode in*/
	button_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; /* set input pull up */

	button_GPIO_InitStructure.GPIO_Pin = BTN1_PIN | BTN2_PIN; /* set pin */
	GPIO_Init(BTN_PORT, &button_GPIO_InitStructure);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource12); /* use PB12 for EXTI_Line12 */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource13); /* use PB13 for EXTI_Line13 */

	EXTI_InitTypeDef button_EXTI_InitStructure;
	EXTI_StructInit(&button_EXTI_InitStructure);

	button_EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	button_EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	button_EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	button_EXTI_InitStructure.EXTI_Line = BTN1_EXTI_Line | BTN2_EXTI_Line;
	EXTI_Init(&button_EXTI_InitStructure);

//	button_EXTI_InitStructure.EXTI_Line = BTN1_EXTI_Line;
//	EXTI_Init(&button_EXTI_InitStructure);

}

void Init_Button2() {

}

/**
 * @brief	initialize button peripherals
 * @note 	Button1 on PB12
 * @note	Button2 on PB13
 * @param 	None
 * @return	None
 */
void Init_Buttons() {


	Init_Button();

	NVIC_InitTypeDef nvicInitStructure;

	/* button1 + button 2 NVIC */
	nvicInitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	nvicInitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
	nvicInitStructure.NVIC_IRQChannelSubPriority = 0x0F;
	nvicInitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvicInitStructure);


}

//TODO user code here
/**
 * @}
 */

/**
 * @}
 */
