/***********************
 * @file 	hw_bat_lvl_watcher.c
 * @author	resiz
 * @date	Mar 14, 2019
 ************************/

#include "hw_bat_lvl_watcher.h"

/**
 * @addtogroup adc_module
 * @{
 */

/**
 * @defgroup bat_lvl_watcher Battery Level Watcher
 * @{
 */

void initBatLvlWatcher(void) {

	/* Enable clock for ADC*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);

	/* Enable clock for GPIOA*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef bat_lvl_watcher_GPIOInitStructure;
	GPIO_StructInit(&bat_lvl_watcher_GPIOInitStructure);
	bat_lvl_watcher_GPIOInitStructure.GPIO_Mode = GPIO_Mode_AN;
	bat_lvl_watcher_GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	bat_lvl_watcher_GPIOInitStructure.GPIO_Speed = GPIO_Speed_100MHz;

	bat_lvl_watcher_GPIOInitStructure.GPIO_Pin = BAT_LVL_WATCHER_PIN;
	GPIO_Init(BAT_LVL_WATCHER_PORT, &bat_lvl_watcher_GPIOInitStructure);

	/*Init ADC*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);

	ADC_InitTypeDef bat_lvl_watcher_ADCInitStructure;
	bat_lvl_watcher_ADCInitStructure.ADC_ScanConvMode = DISABLE;
	bat_lvl_watcher_ADCInitStructure.ADC_ContinuousConvMode = DISABLE;
	bat_lvl_watcher_ADCInitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	bat_lvl_watcher_ADCInitStructure.ADC_ExternalTrigConvEdge =
	ADC_ExternalTrigConvEdge_None;
	bat_lvl_watcher_ADCInitStructure.ADC_NbrOfConversion = 1;
	bat_lvl_watcher_ADCInitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_Init(BAT_LVL_WATCHER_ADC, &bat_lvl_watcher_ADCInitStructure);

	ADC_RegularChannelConfig(BAT_LVL_WATCHER_ADC, BAT_LVL_WATCHER_ADC_CHANNEL,
			1, BAT_LVL_WATCHER_ADC_SAMPLE_TIME);
//	ADC_Init(BAT_LVL_WATCHER_ADC, &bat_lvl_watcher_ADCInitStructure);

	ADC_AnalogWatchdogSingleChannelConfig(BAT_LVL_WATCHER_ADC,
	BAT_LVL_WATCHER_ADC_CHANNEL);
	ADC_AnalogWatchdogThresholdsConfig(BAT_LVL_WATCHER_ADC,
			voltToAdcValue(HIGH_LVL_VOLTAGE), voltToAdcValue(LOW_LVL_VOLTAGE));
	ADC_AnalogWatchdogCmd(BAT_LVL_WATCHER_ADC,
			ADC_AnalogWatchdog_SingleRegEnable);

	ADC_ITConfig(BAT_LVL_WATCHER_ADC, ADC_IT_AWD, ENABLE);

	ADC_Cmd(BAT_LVL_WATCHER_ADC, ENABLE);
}

float getBatLvl(void) {
	ADC_SoftwareStartConv(BAT_LVL_WATCHER_ADC);
	while (ADC_GetFlagStatus(BAT_LVL_WATCHER_ADC, ADC_FLAG_EOC) == RESET)
		; /* Wait until conversion completion (~4us@sampleTime=56cycles) */

	uint16_t bat_lvl_adc_value = ADC_GetConversionValue(BAT_LVL_WATCHER_ADC);
	float bat_lvl_volt = adcValueToVolt(bat_lvl_adc_value);
	return bat_lvl_volt;
}

/**
 * @}
 */
/**
 * @}
 */
