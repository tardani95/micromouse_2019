/***********************
 * @file 	hw_adc_common.c
 * @author	tard
 * @date	May 21, 2019
 * @version	vx_x
 ************************/

#include "hw_adc_common.h"
#include "stm32f4xx_adc.h"
#include "util.h"


/**
 * @addtogroup hardware_modules
 * @{
 */

/**
 * @defgroup adc_common ADC common setup
 * @{
 */

/**
 *	@brief reset and initialize ADC peripherals and set the common settings
 *	@note call this function before operating with ADC
 */
void initADC() {
	ADC_DeInit();
	delay_ms(1);

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	ADC_CommonInitTypeDef ADCCommonInitStructure;
	ADC_CommonStructInit(&ADCCommonInitStructure);
	ADCCommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADCCommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4; /*f_ADCCLK = PCLK2/4 = 20MHz */
	ADCCommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_15Cycles;
	ADC_CommonInit(&ADCCommonInitStructure);
}

/**
 * @}
 */
/**
 * @}
 */
