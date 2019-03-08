/**
 * @file   status_led.h
 * @author tard
 * @date   Mar 8, 2019
 */

#ifndef STATUS_LED_H_
#define STATUS_LED_H_


/** @addtogroup micromouse2019_main
  * @{
  */

/** @addtogroup Status_LEDs
  * @{
  */



/* Includes */
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_dma.h"
#include "misc.h"

/* Function Prototypes */
/**
 * @brief  dummy
 * @param  None
 * @return None
 */
void initPeriph(void);

void initStatusLEDs(void);
void initButtons(void);
void initIRModules(void);
void initEncoders(void);
void initMotorCtrl(void);
void initIMU(void);
void initGeneralPurposeTIM(void);

void initDebug(void);


/* Defines */
#define HEARTBEAT_PORT GPIO_
#define HEARTBEAT_SPEED GPIO_Speed_25MHz

#endif /* STATUS_LED_H_ */

/**
  * @}
  */

/**
  * @}
  */
