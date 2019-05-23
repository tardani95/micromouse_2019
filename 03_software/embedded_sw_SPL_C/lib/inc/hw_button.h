/***********************
 * @file 	button.h
 * @author	tard
 * @date	Mar 8, 2019
 * @version	vx_x
 ************************/

#ifndef HW_BUTTON_H_
#define HW_BUTTON_H_

#include "stm32f4xx_rcc.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_exti.h"
#include "misc.h"

/** @addtogroup hardware_modules
 * @{
 */

/** @addtogroup button
 * @{
 */

/*for set and reset the gpio state use GPIOx_BSRR */

/* button1 -- PB12*/
#define BTN_PORT		GPIOB

#define BTN1_PIN		GPIO_Pin_12
#define BTN1_PORT		GPIOB
#define BTN1_EXTI_Line  EXTI_Line12

/* button2 -- PB13*/
#define BTN2_PIN 		GPIO_Pin_13
#define BTN2_PORT		GPIOB
#define BTN2_EXTI_Line  EXTI_Line13

void initButtons(void);
/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_BUTTON_H_ */

