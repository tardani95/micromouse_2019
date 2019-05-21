/***********************
 * @file 	hw_adc_module.h
 * @author	tard
 * @date	May 21, 2019
 * @version	vx_x
************************/

#ifndef HW_ADC_MODULE_H_
#define HW_ADC_MODULE_H_
#include "stm32f4xx.h"

/**
 * @addtogroup hardware_modules
 * @{
 */

/**
 * @addtogroup adc_common
 * @{
 */

void initADC(void);
float ADC_getBatLvl(void);
uint16_t* ADC_measureIRAll(void);

void ADC_measureCycle(uint8_t measurement_stage, uint8_t conversion_cnt);

void ADC_IRQHandler(void);
/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_ADC_MODULE_H_ */
