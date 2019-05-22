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
#define MOT_TIM_PERIOD 	1000
#define MAX_PULSE		MOT_TIM_PERIOD - 1

#define m_speedToAngularSpeed(speed_mmPs, wheel_diameter_mm) 	\
	(speed_mmPs/(wheel_diameter_mm/2) * 4) // factor 4 from the gear ratio

#define m_radPsToRPM(radPs) 								 	\
	(radPs / 0.104) //(2*PI)/60 = 0.104

#define m_RPMtoVolt(RPM) 									 	\
	(RPM/MOTOR_SPEED_CONSTANT_rpmPvolt)

#define m_calcMotVoltage(speed_mmPs) 							\
	m_RPMtoVolt(												\
		m_radPsToRPM(											\
			m_speedToAngularSpeed(speed_mmPs,WHEEL_DIAMETER_mm)	\
		)														\
	)

#define MotorVoltageLeft(v_mmPs, w_radPs)									\
	v_mmPs*0.001/STEADY_STATE_GAIN_V_LEFT+w_radPs/STEADY_STATE_GAIN_W_LEFT

#define MotorVoltageRight(v_mmPs, w_radPs)									\
	v_mmPs*0.001/STEADY_STATE_GAIN_V_RIGHT+w_radPs/STEADY_STATE_GAIN_W_RIGHT

#define m_abs(var) (var >= 0 ? var : -var)

#define m_capVoltageAtMax(voltage_abs) 							\
	(voltage_abs > MOT_MAX_VOLT ? MOT_MAX_VOLT : voltage_abs)

#define m_voltToPulseWidth(voltage) 							\
	( m_capVoltageAtMax(m_abs(voltage))/VCC * MAX_PULSE)


#define m_setPulse(mot_ccrx_p, pulse) (*mot_ccrx_p = pulse)

typedef enum{
	LEFT,
	RIGHT
}MOT_SIDE;

typedef enum{
	FORWARD,
	BACKWARD,
	COAST,
	BREAK
}MOT_DIR;

typedef enum{
	AOUT1,
	AOUT2,
	BOUT1,
	BOUT2
}MOT_CHANNEL;

void initMotorControl(void);

void actuateMotor(MOT_SIDE motor, MOT_DIR dir, uint16_t pulse);
void actuateMotors(float v, float w);

/**
 * @}
 */

/**
 * @}
 */

#endif /* HW_MOTOR_CONTROL_H_ */
