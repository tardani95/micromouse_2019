/***********************
 * @file 	hw_encoder.c
 * @author	tard
 * @date	Mar 8, 2019
 * @version	vx_x
 ************************/

#include "hw_encoder.h"

/** @addtogroup hardware_modules
 * @{
 */

/** @defgroup 	encoder	Encoder
 *  @brief		AS5047D
 * @{
 */

void initEncoders(void){
	/*left encoder: PA8, PA9, TIM1, CH1, CH2*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef enc_left_GPIO_InitStructure;
	GPIO_StructInit(&enc_left_GPIO_InitStructure);

	enc_left_GPIO_InitStructure.GPIO_Pin = ENC_LEFTA_PIN | ENC_LEFTB_PIN;
	enc_left_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(ENC_LEFT_PORT, &enc_left_GPIO_InitStructure);

	GPIO_PinAFConfig(ENC_LEFT_PORT, GPIO_PinSource9, GPIO_AF_TIM1);
	GPIO_PinAFConfig(ENC_LEFT_PORT, GPIO_PinSource8, GPIO_AF_TIM1);

	TIM_TimeBaseInitTypeDef enc_left_TimeBaseStructure;
	enc_left_TimeBaseStructure.TIM_Period = 0xFFFF;
	enc_left_TimeBaseStructure.TIM_Prescaler = 0;
	enc_left_TimeBaseStructure.TIM_ClockDivision = 0;
	enc_left_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	enc_left_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(ENC_LEFT_TIM, &enc_left_TimeBaseStructure);

	m_resetEncCnt(ENC_LEFT_TIM);

	TIM_EncoderInterfaceConfig(ENC_LEFT_TIM, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge, TIM_ICPolarity_BothEdge);

	TIM_Cmd(ENC_LEFT_TIM, ENABLE);

	/*right encoder: PB6, PB7, TIM4, CH1, CH2*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef enc_right_GPIO_InitStructure;
	GPIO_StructInit(&enc_right_GPIO_InitStructure);

	enc_right_GPIO_InitStructure.GPIO_Pin = ENC_RIGHTA_PIN | ENC_RIGHTB_PIN;
	enc_right_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(ENC_RIGHT_PORT, &enc_right_GPIO_InitStructure);

	GPIO_PinAFConfig(ENC_RIGHT_PORT, GPIO_PinSource7, GPIO_AF_TIM4);
	GPIO_PinAFConfig(ENC_RIGHT_PORT, GPIO_PinSource6, GPIO_AF_TIM4);

	TIM_TimeBaseInitTypeDef enc_right_TimeBaseStructure;
	enc_right_TimeBaseStructure.TIM_Period = 0xFFFF;
	enc_right_TimeBaseStructure.TIM_Prescaler = 0;
	enc_right_TimeBaseStructure.TIM_ClockDivision = 0;
	enc_right_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	enc_right_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(ENC_RIGHT_TIM, &enc_right_TimeBaseStructure);

	m_resetEncCnt(ENC_RIGHT_TIM);

	TIM_EncoderInterfaceConfig(ENC_RIGHT_TIM, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge, TIM_ICPolarity_BothEdge);

	TIM_Cmd(ENC_RIGHT_TIM, ENABLE);


}



/**
 * @}
 */

/**
 * @}
 */
