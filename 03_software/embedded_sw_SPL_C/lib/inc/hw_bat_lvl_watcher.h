/***********************
 * @file 	hw_bat_lvl_watcher.c
 * @author	resiz
 * @date	Mar 14, 2019
 ************************/

#ifndef HW_BAT_LVL_WATCHER_H_
#define HW_BAT_LVL_WATCHER_H_

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"
#include "hw_params.h"

/**
 * @addtogroup hardware_modules
 * @{
 */

/**
 * @addtogroup bat_lvl_watcher
 * @{
 */

#define BAT_LVL_WATCHER_PORT 			GPIOA
#define BAT_LVL_WATCHER_PIN  			GPIO_Pin_6
#define BAT_LVL_WATCHER_ADC	 			ADC2
#define BAT_LVL_WATCHER_ADC_CHANNEL		ADC_Channel_6
#define BAT_LVL_WATCHER_ADC_SAMPLE_TIME	ADC_SampleTime_15Cycles

#define HIGH_LVL_VOLTAGE				5.3f //TODO set the high level voltage
#define LOW_LVL_VOLTAGE					3.6f //TODO set the low level voltage
#define SHUTDOWN_VOLTAGE				3.5f



/**
 * @brief Calculate the voltage of the battery by the adc value
 */
#define adcValueToVolt(adc_value) ((float)adc_value/4096 * VCC * 2)

/**
 * @brief Calculate the expected adc value of the given battery voltage
 * @note used for setting the ADC Watchdog
 */
#define voltToAdcValue(volt) ((float)volt*4096 / VCC / 2)

void initBatLvlWatcher(void);

float getBatLvl(void);

/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_BAT_LVL_WATCHER_H_ */
