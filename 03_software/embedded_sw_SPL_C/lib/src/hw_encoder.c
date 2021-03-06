/***********************
 * @file 	hw_encoder.c
 * @author	resiz
 * @date	Mar 12, 2019
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

	GPIO_PinAFConfig(ENC_LEFT_PORT, GPIO_PinSource9, GPIO_AF_TIM1);
	GPIO_PinAFConfig(ENC_LEFT_PORT, GPIO_PinSource8, GPIO_AF_TIM1);

	GPIO_InitTypeDef enc_left_GPIO_InitStructure;
	GPIO_StructInit(&enc_left_GPIO_InitStructure);

	enc_left_GPIO_InitStructure.GPIO_Pin = ENC_LEFTA_PIN | ENC_LEFTB_PIN;
	enc_left_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	enc_left_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	enc_left_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	enc_left_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(ENC_LEFT_PORT, &enc_left_GPIO_InitStructure);


	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	TIM_EncoderInterfaceConfig(ENC_LEFT_TIM, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Falling);
	TIM_Cmd(ENC_LEFT_TIM, ENABLE);
	m_resetEncCnt(ENC_LEFT_TIM);


	/*right encoder: PB6, PB7, TIM4, CH1, CH2*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_PinAFConfig(ENC_RIGHT_PORT, GPIO_PinSource7, GPIO_AF_TIM4);
	GPIO_PinAFConfig(ENC_RIGHT_PORT, GPIO_PinSource6, GPIO_AF_TIM4);

	GPIO_InitTypeDef enc_right_GPIO_InitStructure;
	GPIO_StructInit(&enc_right_GPIO_InitStructure);

	enc_right_GPIO_InitStructure.GPIO_Pin = ENC_RIGHTA_PIN | ENC_RIGHTB_PIN;
	enc_right_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	enc_right_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	enc_right_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	enc_right_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(ENC_RIGHT_PORT, &enc_right_GPIO_InitStructure);


	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	TIM_EncoderInterfaceConfig(ENC_RIGHT_TIM, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	TIM_Cmd(ENC_RIGHT_TIM, ENABLE);
	m_resetEncCnt(ENC_RIGHT_TIM);
}



/**
 * @}
 */

/**
 * @}
 */
