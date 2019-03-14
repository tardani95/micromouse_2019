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

void Init_Button1() {
	/* button1 -- PB12*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef button1_GPIO_InitStructure; /**< gpio init typedef for button1_GPIO_InitTypeDef */
	GPIO_StructInit(&button1_GPIO_InitStructure); /* set defaults value for the initstruct */

	/* by input the ouput type (push-pull or open-drain) and output speed does not matter */
	button1_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; /* set mode in*/
	button1_GPIO_InitStructure.GPIO_Pin = BTN1_PIN; /* set pin */
	button1_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; /* set input pull up */
	GPIO_Init(BTN1_PORT, &button1_GPIO_InitStructure);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource12); /* use PB12 for EXTI_Line12 */

	EXTI_InitTypeDef button1_EXTI_InitStructure;
	EXTI_StructInit(&button1_EXTI_InitStructure);

	button1_EXTI_InitStructure.EXTI_Line = EXTI_Line12;
	button1_EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	button1_EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	button1_EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&button1_EXTI_InitStructure);
}

void Init_Button2() {
	/* button2 -- PB13*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef button2_GPIO_InitTypeDef; /**< gpio init typedef for button2_GPIO_InitTypeDef */
	GPIO_StructInit(&button2_GPIO_InitTypeDef);

	/* by input the ouput type (push-pull or open-drain) and output speed does not matter */
	button2_GPIO_InitTypeDef.GPIO_Mode = GPIO_Mode_IN; /* set mode in*/
	button2_GPIO_InitTypeDef.GPIO_Pin = BTN2_PIN; /* set pin */
	button2_GPIO_InitTypeDef.GPIO_PuPd = GPIO_PuPd_UP; /* set input pull up */
	GPIO_Init(BTN2_PORT, &button2_GPIO_InitTypeDef);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource13); /* use PB13 for EXTI_Line13 */

	EXTI_InitTypeDef button2_EXTI_InitStructure;
	EXTI_StructInit(&button2_EXTI_InitStructure);

	button2_EXTI_InitStructure.EXTI_Line = EXTI_Line13;
	button2_EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	button2_EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	button2_EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&button2_EXTI_InitStructure);
}

/**
 * @brief	initialize button peripherals
 * @note 	Button1 on PB12
 * @note	Button2 on PB13
 * @param 	None
 * @return	None
 */
void Init_Buttons() {

	Init_Button1();
	Init_Button2();

	NVIC_InitTypeDef nvicInitStructure;

	/* button1 + button 2 NVIC */
	nvicInitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	nvicInitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	nvicInitStructure.NVIC_IRQChannelSubPriority = 0;
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
