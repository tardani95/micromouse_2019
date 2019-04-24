/***********************
 * @file 	hw_IR_module.h
 * @author	resiz
 * @date	Mar 14, 2019
 ************************/

#ifndef HW_IR_MODULE_H_
#define HW_IR_MODULE_H_

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"

/** @addtogroup hardware_modules
 * @{
 */

/** @addtogroup IR_module
 * @{
 */

#define IR12_PORT 	GPIOA
#define IRD1_PIN 	GPIO_Pin_0
#define IRD2_PIN 	GPIO_Pin_1
#define PTR1_PIN	GPIO_Pin_2
#define PTR2_PIN	GPIO_Pin_3

#define IR34_PORT	GPIOC
#define IRD3_PIN 	GPIO_Pin_0
#define IRD4_PIN 	GPIO_Pin_1
#define PTR3_PIN	GPIO_Pin_2
#define PTR4_PIN	GPIO_Pin_3

#define PTR_ADC		ADC1
#define PTR1_CH		ADC_Channel_2
#define PTR2_CH		ADC_Channel_3
#define PTR3_CH		ADC_Channel_12
#define PTR4_CH		ADC_Channel_13

#define PTR_ADC_SAMPLE_TIME ADC_SampleTime_56Cycles

typedef enum{
	IR_LEFT_FORWARD,
	IR_LEFT_SIDEWAYS,
	IR_RIGHT_FORWARD,
	IR_RIGHT_SIDEWAYS
}IR_SENSOR;


void initIR(void);

void setIRD(IR_SENSOR);
void resetIRD(IR_SENSOR);
uint16_t getPTRValue(void);

uint16_t measureIRSingle(IR_SENSOR);
uint16_t *measureIRAll(void);

#define IRDCALIB_PORT 	GPIOA
#define IRDCALIB_PIN	GPIO_Pin_0

#define PTRCALIB_PORT	GPIOA
#define PTRCALIB_PIN	GPIO_Pin_2

#define PTRCALIB_ADC	ADC1
#define PTRCALIB_CH		ADC_Channel_2

#define IR_CALIB		IR_LEFT_FORWARD

void initIRCalib(void);
void measureIRCalibSingle(void);
/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_IR_MODULE_H_ */

