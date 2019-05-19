/***********************
 * @file 	sw_control.c
 * @author	tard
 * @date	May 19, 2019
 * @version	vx_x
 ************************/

#include "sw_control.h"
#include "hw_status_led.h"
#include "misc.h"

/** @addtogroup software_modules
 * @{
 */

/** @defgroup control_plane Control Plane
 * @{
 */

/**
 * Initialize control loop @1kHz
 */
void Init_Control() {

	/* Enable TIM clock using RCC_APBxPeriphClockCmd(RCC_APBxPeriph_TIMx, ENABLE) function */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	/* Fill the TIM_TimeBaseInitStruct with the desired parameters */
	TIM_TimeBaseInitTypeDef TimeBaseInitStructure;
	TIM_TimeBaseStructInit(&TimeBaseInitStructure);
	TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TimeBaseInitStructure.TIM_Prescaler = 80-1; /* Clock freqeuency: 80MHz/80 = 1000kHz */
	TimeBaseInitStructure.TIM_Period = 1000; /* PWM frequency: 10000kHz/10 /1000 = 1KHz */
	TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TimeBaseInitStructure.TIM_RepetitionCounter = 0;

	/* Call TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStruct) to configure the Time Base unit
	 with the corresponding configuration */
	TIM_TimeBaseInit(TIM2, &TimeBaseInitStructure);

	/* Enable the NVIC to generate the update interrupt */
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable the corresponding interrupt using the function TIM_ITConfig(TIMx, TIM_IT_Update) */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
//	TIM_ARRPreloadConfig(TIM2, ENABLE);
	/* Call the TIM_Cmd(ENABLE) function to enable the TIM counter. */
	TIM_Cmd(TIM2,ENABLE);
}

/**
 * control loop function called @1kHz, @see Init_Control() function.
 */
void CONTROL_LOOP_IRQHandler(){
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	//TODO user code here

}

//TODO user code here

/**
 * @}
 */

/**
 * @}
 */
