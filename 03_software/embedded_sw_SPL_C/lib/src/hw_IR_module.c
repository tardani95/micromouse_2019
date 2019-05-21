/***********************
 * @file 	hw_IR_module.c
 * @author	resiz
 * @date	Mar 14, 2019
 ************************/

#include "hw_IR_module.h"
#include "hw_params.h"
#include "util.h"
#include "hw_status_led.h"

/** @addtogroup hardware_modules
 * @{
 */

/** @defgroup IR_module IR Module
 * @brief IR LED and phototransistor defines and handling functions.
 * @{
 */

GPIO_TypeDef *IR_port_mapping[4] = {
IRD_L_PORT,
IRD_R_PORT,
IRD_L_PORT,
IRD_R_PORT };

uint16_t IRD_pin_mapping[4] = {
IRD_LF_PIN,
IRD_RS_PIN,
IRD_LS_PIN,
IRD_RF_PIN };

/*uint8_t PTR_channel_mapping[4] = {
 PTR1_CH,
 PTR2_CH,
 PTR3_CH,
 PTR4_CH
 };*/

void initIR(void) {

	/* Enable clock for ADC*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/* Enable clock for GPIOA (IRD12, PTR12)*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	/* Enable clock for GPIOC (IRD34, PTR34*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef IR_GPIOInitStructure;
	GPIO_StructInit(&IR_GPIOInitStructure);

	/* Init IR LED pins*/
	IR_GPIOInitStructure.GPIO_Mode = GPIO_Mode_OUT;
	IR_GPIOInitStructure.GPIO_OType = GPIO_OType_PP;
	IR_GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	IR_GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	IR_GPIOInitStructure.GPIO_Pin = IRD1_PIN | IRD2_PIN;
	GPIO_Init(IR12_PORT, &IR_GPIOInitStructure);
	IR_GPIOInitStructure.GPIO_Pin = IRD3_PIN | IRD4_PIN;
	GPIO_Init(IR34_PORT, &IR_GPIOInitStructure);

	/* Init phototransistor pins*/
	GPIO_StructInit(&IR_GPIOInitStructure);
	IR_GPIOInitStructure.GPIO_Mode = GPIO_Mode_AN;
	IR_GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	IR_GPIOInitStructure.GPIO_Speed = GPIO_Speed_100MHz;

	IR_GPIOInitStructure.GPIO_Pin = PTR1_PIN | PTR2_PIN;
	GPIO_Init(IR12_PORT, &IR_GPIOInitStructure);
	IR_GPIOInitStructure.GPIO_Pin = PTR3_PIN | PTR4_PIN;
	GPIO_Init(IR34_PORT, &IR_GPIOInitStructure);

	/* Init ADC for phototransistors*/

//	ADC_CommonInitTypeDef ADCCommonInitStructure;
//	ADC_CommonStructInit(&ADCCommonInitStructure);
//	ADCCommonInitStructure.ADC_Mode = ADC_Mode_Independent;
//	ADCCommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4; /*f_ADCCLK = PCLK2/4 = 20MHz */
////	ADCCommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_15Cycles;
//	ADC_CommonInit(&ADCCommonInitStructure);

	ADC_InitTypeDef PTR_ADCInitStructure;
	PTR_ADCInitStructure.ADC_ScanConvMode = ENABLE;
	PTR_ADCInitStructure.ADC_ContinuousConvMode = DISABLE;
	PTR_ADCInitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	PTR_ADCInitStructure.ADC_ExternalTrigConvEdge =
	ADC_ExternalTrigConvEdge_None;
	PTR_ADCInitStructure.ADC_NbrOfConversion = 4;
	PTR_ADCInitStructure.ADC_Resolution = ADC_Resolution_12b; /*t_conv = 15*t_ADCCLK < 1 us*/
	ADC_Init(PTR_ADC, &PTR_ADCInitStructure);

//	ADC_Cmd(PTR_ADC, ENABLE);

//TODO: sample time?
	ADC_EOCOnEachRegularChannelCmd(PTR_ADC, ENABLE);
	ADC_RegularChannelConfig(PTR_ADC, PTR_LF_CH, 1, PTR_ADC_SAMPLE_TIME);
	ADC_RegularChannelConfig(PTR_ADC, PTR_RS_CH, 2, PTR_ADC_SAMPLE_TIME);
	ADC_RegularChannelConfig(PTR_ADC, PTR_LS_CH, 3, PTR_ADC_SAMPLE_TIME);
	ADC_RegularChannelConfig(PTR_ADC, PTR_RF_CH, 4, PTR_ADC_SAMPLE_TIME);

	ADC_Init(PTR_ADC, &PTR_ADCInitStructure);

	ADC_DiscModeChannelCountConfig(PTR_ADC, 1);
	ADC_DiscModeCmd(PTR_ADC, ENABLE);

	ADC_Cmd(PTR_ADC, ENABLE);
	//TODO: ADC calibration?
}

void setIRD(IR_SENSOR IR_sensor) {
	GPIO_SetBits(IR_port_mapping[IR_sensor], IRD_pin_mapping[IR_sensor]);
}

void resetIRD(IR_SENSOR IR_sensor) {
	GPIO_ResetBits(IR_port_mapping[IR_sensor], IRD_pin_mapping[IR_sensor]);
}

uint16_t getPTRValue(void) {
	ADC_SoftwareStartConv(PTR_ADC);

	while (ADC_GetFlagStatus(PTR_ADC, ADC_FLAG_EOC) == RESET)
		; /* Wait until conversion completion (~4us@sampleTime=56cycles) */

	return ADC_GetConversionValue(PTR_ADC);
}

uint16_t IR_dist_buff[4] = { 0, 0, 0, 0 };

uint16_t ledPins[4] = {
IRD_LF_PIN,
IRD_RS_PIN,
IRD_LS_PIN,
IRD_RF_PIN };

GPIO_TypeDef* ledPorts[4] = {
IRD_L_PORT,
IRD_R_PORT,
IRD_L_PORT,
IRD_R_PORT };

uint16_t adcBuf[4] = { 0 };

uint16_t measureIRSingle(IR_SENSOR IR_sensor) {
	setIRD(IR_sensor);
	setLED(PINK);
//	uint8_t k = 0;
//	for(uint16_t i = 0; i< 60;i++){
//		k += k-2;
//	}
	resetLED(PINK);
	delay_ms(1);
	uint16_t ptr_adc_value = getPTRValue();
	resetIRD(IR_sensor);
//	return distByADCValue(ptr_adc_value);
	return ptr_adc_value;
}

uint16_t * measureIRAll(void) {
	for (int i = 0; i < 4; i++) {
		IR_dist_buff[i] = measureIRSingle(i);
//		delay_ms(200);
	}
	return IR_dist_buff;
}

/**
 * @}
 */

/**
 * @}
 */
