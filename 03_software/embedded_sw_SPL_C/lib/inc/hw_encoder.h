/***********************
 * @file 	hw_encoder.h
 * @author	resiz
 * @date	Mar 12, 2019
 * @version	vx_x
 ************************/

#ifndef HW_ENCODER_H_
#define HW_ENCODER_H_

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"


/** @addtogroup hardware_modules
 * @{
 */

/** @addtogroup encoder
 * @{
 */

#define ENC_LEFT_PORT GPIOA
#define ENC_LEFTA_PIN GPIO_Pin_9
#define ENC_LEFTB_PIN GPIO_Pin_8
#define ENC_LEFT_TIM  TIM1

#define ENC_RIGHT_PORT GPIOB
#define ENC_RIGHTA_PIN GPIO_Pin_7
#define ENC_RIGHTB_PIN GPIO_Pin_6
#define ENC_RIGHT_TIM  TIM4

#define ENC_RIGHT ENC_RIGHT_TIM
#define ENC_LEFT ENC_LEFT_TIM

#define ENC_CNT_BASEVALUE 30000//32768

#define m_getEncCnt(enc_timer) 			(enc_timer->CNT)
#define m_setEncCnt(enc_timer, value) 	(enc_timer->CNT = value)
#define m_resetEncCnt(enc_timer) 		(enc_timer->CNT = ENC_CNT_BASEVALUE)

void initEncoders(void);



/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_ENCODER_H_ */

