/***********************
 * @file 	hw_motor_control.c
 * @author	resiz
 * @date	Mar 13, 2019
 ************************/

#include "hw_motor_control.h"
#include "hw_params.h"
/** @addtogroup hardware_modules
 * @{
 */

/** @defgroup motor_control Motor Control
 * @brief Motor controller defines and handling functions.
 * @{
 */

MOT_CHANNEL mot_channel_mapping[4] = { AOUT1, AOUT2, BOUT1, BOUT2 };

/*uint16_t mot_pin_mapping[4] = {
 MOT_AIN1_PIN,
 MOT_AIN2_PIN,
 MOT_BIN1_PIN,
 MOT_BIN2_PIN
 };*/

__IO uint32_t *mot_ccr_mapping[4] = { &(MOT_TIM->CCR1), &(MOT_TIM->CCR2),
		&(MOT_TIM->CCR3), &(MOT_TIM->CCR4) };

void initMotorControl(void) {
	/*Enable clock for GPIOC*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_PinAFConfig(MOT_PORT, GPIO_PinSource6, GPIO_AF_TIM3);
	GPIO_PinAFConfig(MOT_PORT, GPIO_PinSource7, GPIO_AF_TIM3);
	GPIO_PinAFConfig(MOT_PORT, GPIO_PinSource8, GPIO_AF_TIM3);
	GPIO_PinAFConfig(MOT_PORT, GPIO_PinSource9, GPIO_AF_TIM3);

	/*Configure GPIO for PWM*/
	GPIO_InitTypeDef mot_ctrl_InitStructure;
	mot_ctrl_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	mot_ctrl_InitStructure.GPIO_OType = GPIO_OType_PP;
	mot_ctrl_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	mot_ctrl_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	mot_ctrl_InitStructure.GPIO_Pin = MOT_AIN1_PIN;
	GPIO_Init(MOT_PORT, &mot_ctrl_InitStructure);

	mot_ctrl_InitStructure.GPIO_Pin = MOT_AIN2_PIN;
	GPIO_Init(MOT_PORT, &mot_ctrl_InitStructure);

	mot_ctrl_InitStructure.GPIO_Pin = MOT_BIN1_PIN;
	GPIO_Init(MOT_PORT, &mot_ctrl_InitStructure);

	mot_ctrl_InitStructure.GPIO_Pin = MOT_BIN2_PIN;
	GPIO_Init(MOT_PORT, &mot_ctrl_InitStructure);

	/*Configure timer*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseInitTypeDef mot_ctrl_TimerInitStructure;
	TIM_TimeBaseStructInit(&mot_ctrl_TimerInitStructure);
	mot_ctrl_TimerInitStructure.TIM_Prescaler = 8 - 1; /* Clock freqeuency: 80MHz/8 = 10MHz = 10000kHz */
	mot_ctrl_TimerInitStructure.TIM_Period = MOT_TIM_PERIOD - 1; /* PWM frequency: 10000kHz/1000 = 10KHz */
	mot_ctrl_TimerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	mot_ctrl_TimerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	mot_ctrl_TimerInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(MOT_TIM, &mot_ctrl_TimerInitStructure);

	/*Configure PWM*/
	TIM_OCInitTypeDef mot_ctrl_OCInitStructure;
	mot_ctrl_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	mot_ctrl_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	mot_ctrl_OCInitStructure.TIM_OutputNState = TIM_OutputState_Disable;
	mot_ctrl_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	mot_ctrl_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_Low;
	mot_ctrl_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	mot_ctrl_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	mot_ctrl_OCInitStructure.TIM_Pulse = 0;

	TIM_OC1Init(MOT_TIM, &mot_ctrl_OCInitStructure);
	TIM_OC2Init(MOT_TIM, &mot_ctrl_OCInitStructure);
	TIM_OC3Init(MOT_TIM, &mot_ctrl_OCInitStructure);
	TIM_OC4Init(MOT_TIM, &mot_ctrl_OCInitStructure);

	TIM_OC1PreloadConfig(MOT_TIM, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(MOT_TIM, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(MOT_TIM, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(MOT_TIM, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(MOT_TIM, ENABLE);
	TIM_Cmd(MOT_TIM, ENABLE);

}

void actuateMotor(MOT_SIDE motor, MOT_DIR dir, uint16_t pulse) {
	if (pulse > MAX_PULSE) { /* set maximal pulse*/
		pulse = MAX_PULSE;
	}

	__IO uint32_t *mot_ccr1;
	__IO uint32_t *mot_ccr2;

	switch (motor) {
	case LEFT:
		mot_ccr1 = mot_ccr_mapping[0];
		mot_ccr2 = mot_ccr_mapping[1];
		break;

	case RIGHT:
		mot_ccr1 = mot_ccr_mapping[2];
		mot_ccr2 = mot_ccr_mapping[3];
		break;
	}

	/* set the direction pwm frequency max and only control the break*/
	switch (dir) {
	case FORWARD:
		*mot_ccr1 = MAX_PULSE;
		*mot_ccr2 = MAX_PULSE - pulse;
		break;
	case BACKWARD:
		*mot_ccr1 = MAX_PULSE - pulse;
		*mot_ccr2 = MAX_PULSE;
		break;
	case COAST:
		*mot_ccr1 = 0;
		*mot_ccr2 = 0;
		break;
	case BREAK:
		*mot_ccr1 = pulse;
		*mot_ccr2 = pulse;
		break;
	}
}

/* assuming that motors have zero time constant!
 * this assumption will most likely be wrong, because if v = 0,
 * motors enter coasting, but won't brake
 */
void actuateMotors(float v_cmPs, float w_radPs) {
	//float v_left_mmPs = v_mmPs - w_radPs * AXLE_LENGTH_mm / 2;
	//float v_right_mmPs = v_mmPs + w_radPs * AXLE_LENGTH_mm / 2;

	float v_mmPs = v_cmPs*10;

	float u_left_volt = MotorVoltageLeft(v_mmPs,w_radPs);
	float u_right_volt = MotorVoltageRight(v_mmPs,w_radPs);

	MOT_DIR mot_dir_left = u_left_volt >= 0 ? FORWARD : BACKWARD;
	MOT_DIR mot_dir_right = u_right_volt >= 0 ? FORWARD : BACKWARD;

	uint16_t pulse_left = m_voltToPulseWidth(u_left_volt);
	uint16_t pulse_right = m_voltToPulseWidth(u_right_volt);

	actuateMotor(LEFT,  mot_dir_left,  pulse_left);
	actuateMotor(RIGHT, mot_dir_right, pulse_right);
//	m_setPulse(mot_left_ccr_p, pulse_left);
//	m_setPulse(mot_right_ccr_p, pulse_right);
}

/**
 * @}
 */

/**
 * @}
 */
