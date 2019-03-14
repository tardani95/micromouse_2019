/***********************
 * @file   status_led.h
 * @author resiz
 * @date   Mar 12, 2019
 ************************/

#ifndef HW_STATUS_LED_H_
#define HW_STATUS_LED_H_

/** @addtogroup hardware_modules
 * @{
 */

/** @addtogroup Status_LED
 * @{
 */

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
//#include "stm32f4xx_exti.h"
#include "stm32f4xx_tim.h"
//#include "stm32f4xx_adc.h"
//#include "stm32f4xx_i2c.h"
//#include "stm32f4xx_usart.h"
//#include "stm32f4xx_dma.h"
//#include "misc.h"

/* Function Prototypes */
/**
 * @brief  dummy
 * @param  None
 * @return None
 */
/*void initPeriph(void);

void initStatusLEDs(void);
void initButtons(void);
void initIRModules(void);
void initEncoders(void);
void initMotorCtrl(void);
void initIMU(void);
void initGeneralPurposeTIM(void);

void initDebug(void);*/

/* Defines */
#define ST_LED_HEARTBEAT_PORT 	GPIOB
#define ST_LED_HEARTBEAT_PIN 	GPIO_Pin_3

#define ST_LED_PINK_PORT 		GPIOB
#define ST_LED_PINK_PIN 		GPIO_Pin_4

#define ST_LED_YELLOW_PORT 		GPIOB
#define ST_LED_YELLOW_PIN 		GPIO_Pin_5

#define ST_LED_RGBR_PORT 		GPIOA
#define ST_LED_RGBR_PIN 		GPIO_Pin_7

#define ST_LED_RGBG_PORT 		GPIOB
#define ST_LED_RGBG_PIN 		GPIO_Pin_0

#define ST_LED_RGBB_PORT 		GPIOB
#define ST_LED_RGBB_PIN 		GPIO_Pin_1

#define ST_LED_RGB_TIM 			TIM8
#define ST_LED_RGB_TIM_PERIOD 	1000

#define m_setRedPulse(pulse) 	ST_LED_RGB_TIM->CCR1 = pulse
#define m_setBluePulse(pulse) 	ST_LED_RGB_TIM->CCR2 = pulse
#define m_setGreenPulse(pulse)	ST_LED_RGB_TIM->CCR3 = pulse


typedef enum {
	HEARTBEAT,
	PINK,
	YELLOW
}ST_LED;

typedef enum {
	LED_PORT,
	LED_PIN
}LED_def;

typedef enum {
	RGB_WHITE,
	RGB_RED,
	RGB_ORANGE,
	RGB_YELLOW,
	RGB_GREEN_LIGHT,
	RGB_GREEN_DARK,
	RGB_BLUE_LIGHT,
	RGB_BLUE_DARK,
	RGB_PINK,
	RGB_PURPLE
}RGB_COLOR;

typedef enum {
	RGBR,
	RGBG,
	RGBB
}RGB_def;

void initStatusLEDs(void);
void setLED(ST_LED);
void resetLED(ST_LED);
void toggleLED(ST_LED);
void setRGB(RGB_COLOR);
void resetRGB(void);
uint16_t calcPulseWidth(uint8_t rgb_value);




/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_STATUS_LED_H_ */

