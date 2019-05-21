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
#include "hw_status_led.h"

/**
 * @addtogroup hardware_modules
 * @{
 */

/**
 * @defgroup adc_common ADC common setup
 * @{
 */

volatile uint8_t IR_measurement_stage = 0;
volatile uint8_t ADC_conversion_cnt = 0;

/**
 *	@brief reset and initialize ADC peripherals and set the common settings
 *	@note call this function before operating with ADC
 */
void initADC() {
	ADC_DeInit();
	delay_ms(1);

	initIR();
	initBatLvlWatcher();

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 7;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	ADC_CommonInitTypeDef ADCCommonInitStructure;
	ADC_CommonStructInit(&ADCCommonInitStructure);
	ADCCommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADCCommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4; /*f_ADCCLK = PCLK2/4 = 20MHz */
	//TODO check what happens if two adc started from different location of the program
	//TODO set interrupt priorities so that this situation can not occure
	//	ADCCommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_20Cycles;
	ADC_CommonInit(&ADCCommonInitStructure);
}

float ADC_getBatLvl() {
	return getBatLvl();
}

uint16_t * ADC_measureIRAll() {
	return measureIRAll();
}

void ADC_startIRMeasurement(){
	ADC_measureCycle(0,0);
}

void ADC_measureCycle(uint8_t measurement_stage, uint8_t conversion_cnt){
	switch(measurement_stage){
	case 0: /*read photo transistor values without IR LEDs*/

		break;
	case 1: /*read photo transistor values with IR LEDs*/
		break;
	case 2:
		break;
	case 3:
		break;

	}
}

void ADC_delayTIM_IRQHandler(){
	//TODO clear IT pendig bits
}

void ADC_IRQHandler() {
	//TODO clear IT pending bits
	if (ADC_GetITStatus(BAT_LVL_WATCHER_ADC, ADC_IT_AWD) == SET) {
		ADC_ClearITPendingBit(BAT_LVL_WATCHER_ADC, ADC_IT_AWD);
		setLED(LED_YELLOW);

		if(ADC_GetConversionValue(BAT_LVL_WATCHER_ADC) < voltToAdcValue(SHUTDOWN_VOLTAGE)){
			/*shutdown voltage reached - shutting down peripherals*/
			setLED(LED_PINK);
			//TODO shut down motors and ir diodes
		}
	}

	if (ADC_GetITStatus(PTR_ADC, ADC_IT_EOC) == SET) { /*one conversion completed*/
		ADC_ClearITPendingBit(PTR_ADC, ADC_IT_EOC);
		ADC_conversion_cnt++;
	}
}

/**
 * @}
 */
/**
 * @}
 */
