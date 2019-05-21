/***********************
 * @file 	hw_adc_common.c
 * @author	tard
 * @date	May 21, 2019
 * @version	vx_x
 ************************/

#include "hw_adc_module.h"
#include "stm32f4xx_adc.h"
#include "hw_IR_module.h"
#include "hw_bat_lvl_watcher.h"
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

	initIR();
	initBatLvlWatcher();

	ADC_CommonInitTypeDef ADCCommonInitStructure;
	ADC_CommonStructInit(&ADCCommonInitStructure);
	ADCCommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADCCommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4; /*f_ADCCLK = PCLK2/4 = 20MHz */
	//TODO check what happens if two adc started from different location of the program
	//TODO set interrupt priorities so that this situation can not occure
	//	ADCCommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_20Cycles;
	ADC_CommonInit(&ADCCommonInitStructure);
}

float ADC_getBatLvl(){
	return getBatLvl();
}

uint16_t * ADC_measureIRAll(){
	return measureIRAll();
}

/**
 * @}
 */
/**
 * @}
 */
