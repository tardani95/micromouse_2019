/***********************
 * @file 	hw_adc_module.h
 * @author	tard
 * @date	May 21, 2019
 * @version	vx_x
************************/

#ifndef HW_ADC_MODULE_H_
#define HW_ADC_MODULE_H_
#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"

/**
 * @addtogroup hardware_modules
 * @{
 */

/**
 * @addtogroup adc_module
 * @{
 */

#define TIM_delay_us 					TIM5
#define NVIC_IRQChannel_TIM_delay_us 	TIM5_IRQn
#define ADC_delayTIM_IRQHandler 		TIM5_IRQHandler
#define TIM_delay_us_PERIOD				0xFFFF
#define TIM_max_delay_us 				TIM_delay_us_PERIOD-1

typedef enum{
	MS_IRD_OFF,
	MS_IRD_ON,
	END
}MEASUREMENT_STAGE;

void initADC(void);
float ADC_getBatLvl(void);
//uint16_t* ADC_measureIRAll(void); /* deprecated use */

void ADC_startIRMeasurement(MEASUREMENT_STAGE with_measurement_stage);
uint16_t * ADC_getMeasuredValues(void);

void ADC_measureCycle(uint8_t measurement_stage, uint8_t conversion_cnt);
void ADC_IRQHandler(void);
void TIM5_IRQHandler(void);
/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_ADC_MODULE_H_ */
