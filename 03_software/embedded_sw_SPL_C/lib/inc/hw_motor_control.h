/***********************
 * @file 	hw_motor_control.h
 * @author	resiz
 * @date	Mar 13, 2019
 ************************/

#ifndef HW_MOTOR_CONTROL_H_
#define HW_MOTOR_CONTROL_H_

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"

/** @addtogroup hardware_modules
 * @{
 */

/** @addtogroup motor_control
 * @brief		DRV8836
 * @{
 */

#define MOT_PORT 		GPIOC
#define MOT_AIN1_PIN 	GPIO_Pin_6
#define MOT_AIN2_PIN 	GPIO_Pin_7
#define MOT_BIN1_PIN 	GPIO_Pin_8
#define MOT_BIN2_PIN 	GPIO_Pin_9

#define MOT_TIM 		TIM3
#define MOT_TIM_PERIOD 	1680

#define m_speedToAngularSpeed(speed_mmPs, wheel_diameter_mm) 	\
	(speed_mmPs/(wheel_diameter_mm/2))

#define m_radPsToRPM(radPs) 								 	\
	(radPs/(2*3.1415)*60)

#define m_RPMtoVolt(RPM) 									 	\
	(RPM/MOTOR_SPEED_CONSTANT_rpmPvolt)

#define m_calcMotVoltage(speed_mmPs) 							\
	m_RPMtoVolt(												\
		m_radPsToRPM(											\
			m_speedToAngularSpeed(speed_mmPs,WHEEL_DIAMETER_mm)	\
		)														\
	)

#define m_abs(var) (var >= 0 ? var : -var)

#define m_capVoltageAtMax(voltage_abs) 							\
	(voltage_abs > MOT_MAX_VOLT ? MOT_MAX_VOLT : voltage_abs)

#define m_voltToPulseWidth(voltage) 							\
	( m_capVoltageAtMax(m_abs(voltage))/VCC * MOT_TIM_PERIOD)


#define m_setPulse(mot_ccrx_p, pulse) (*mot_ccrx_p = pulse)

typedef enum{
	MOT_LEFT_FORWARD,
	MOT_LEFT_BACKWARD,
	MOT_RIGHT_FORWARD,
	MOT_RIGHT_BACKWARD
}MOT_DIR;

typedef enum{
	AIN1,
	AIN2,
	BIN1,
	BIN2
}MOT_CHANNEL;

void initMotorControl(void);

void actuateMotors(uint16_t v, uint16_t w);

/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_MOTOR_CONTROL_H_ */
