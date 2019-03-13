/***********************
 * @file 	hw_status_led.c
 * @author	resiz
 * @date	Mar 12, 2019
 ************************/

#include "hw_status_led.h"

/** @addtogroup hardware_modules
 * @{
 */

/** @defgroup Status_LED Status LED
 * @{
 */

/*
 * array for holding status led port and pin definitions
 */
GPIO_TypeDef *LED_ports[3] = {
		ST_LED_HEARTBEAT_PORT,
		ST_LED_PINK_PORT,
		ST_LED_YELLOW_PORT,
};

uint16_t LED_pins[3] = {
		ST_LED_HEARTBEAT_PIN,
		ST_LED_PINK_PIN,
		ST_LED_YELLOW_PIN
};

/*
 * array for holding RGB color definitions
 * codes taken from htmlcolorcodes.com
 */
const uint8_t RGB_codes[10][3] = {
		{255, 255, 255}, //white
		{255,   0,   0}, //red
		{255,  87,  51}, //orange
		{255, 255,   0}, //yellow
		{  0, 255,   0}, //light green
		{  0, 128,   0}, //dark green
		{  0, 255, 255}, //light blue
		{  0,   0, 255}, //dark blue
		{255,   0, 255}, //pink
		{128,   0, 128}  //white
};


void initStatusLeds(void){
	/*Enable clock for PINK, YELLOW, HEARTBEAT, RGBG, RGBB GPIO*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	/*Enable clock for RGBR GPIO*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	/*Configure GPIO for normal status leds*/
	GPIO_InitTypeDef st_led_GPIO_InitStructure;
	st_led_GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	st_led_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	st_led_GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	st_led_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	st_led_GPIO_InitStructure.GPIO_Pin = ST_LED_HEARTBEAT_PIN;
	GPIO_Init(ST_LED_HEARTBEAT_PORT, &st_led_GPIO_InitStructure);

	st_led_GPIO_InitStructure.GPIO_Pin = ST_LED_PINK_PIN;
	GPIO_Init(ST_LED_PINK_PORT, &st_led_GPIO_InitStructure);

	st_led_GPIO_InitStructure.GPIO_Pin = ST_LED_YELLOW_PIN;
	GPIO_Init(ST_LED_YELLOW_PORT, &st_led_GPIO_InitStructure);

	/*Configure GPIO for RGB led (PWM)*/
	st_led_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;

	st_led_GPIO_InitStructure.GPIO_Pin = ST_LED_RGBR_PIN;
	GPIO_Init(ST_LED_RGBR_PORT, &st_led_GPIO_InitStructure);

	st_led_GPIO_InitStructure.GPIO_Pin = ST_LED_RGBG_PIN;
	GPIO_Init(ST_LED_RGBG_PORT, &st_led_GPIO_InitStructure);

	st_led_GPIO_InitStructure.GPIO_Pin = ST_LED_RGBB_PIN;
	GPIO_Init(ST_LED_RGBB_PORT, &st_led_GPIO_InitStructure);

	GPIO_PinAFConfig(ST_LED_RGBR_PORT, ST_LED_RGBR_PIN, GPIO_AF_TIM8);
	GPIO_PinAFConfig(ST_LED_RGBG_PORT, ST_LED_RGBG_PIN, GPIO_AF_TIM8);
	GPIO_PinAFConfig(ST_LED_RGBB_PORT, ST_LED_RGBB_PIN, GPIO_AF_TIM8);

	/*Configure timer for RGB led*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);

	TIM_TimeBaseInitTypeDef RGB_TimerInitStructure;
	TIM_TimeBaseStructInit(&RGB_TimerInitStructure);
	RGB_TimerInitStructure.TIM_Prescaler 		 = 168 - 1; 				/* Clock freqeuency: 168MHz/168 = 1 MHz */
	RGB_TimerInitStructure.TIM_Period 			 = ST_LED_RGB_TIM_PERIOD - 1; 	/* PWM frequency: 1MHz/1000 = 1KHz */
	RGB_TimerInitStructure.TIM_CounterMode 		 = TIM_CounterMode_Up;
	RGB_TimerInitStructure.TIM_ClockDivision 	 = TIM_CKD_DIV1;
	RGB_TimerInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(ST_LED_RGB_TIM, &RGB_TimerInitStructure);

	TIM_Cmd(ST_LED_RGB_TIM, ENABLE);

	/*Configure PWM*/
	TIM_OCInitTypeDef RGB_OCInitStructure;
	RGB_OCInitStructure.TIM_OCMode = 		TIM_OCMode_PWM1; //TODO: difference between pwm1 and pwm2
	RGB_OCInitStructure.TIM_OutputState = 	TIM_OutputState_Disable;
	RGB_OCInitStructure.TIM_OutputNState = 	TIM_OutputState_Enable;
	RGB_OCInitStructure.TIM_OCPolarity = 	TIM_OCPolarity_Low;
	RGB_OCInitStructure.TIM_OCNPolarity = 	TIM_OCPolarity_High;
	RGB_OCInitStructure.TIM_OCIdleState = 	TIM_OCIdleState_Reset;
	RGB_OCInitStructure.TIM_OCNIdleState = 	TIM_OCNIdleState_Reset;
	RGB_OCInitStructure.TIM_Pulse = 		0.5*ST_LED_RGB_TIM_PERIOD;

	TIM_OC1Init(ST_LED_RGB_TIM, &RGB_OCInitStructure);
	TIM_OC2Init(ST_LED_RGB_TIM, &RGB_OCInitStructure);
	TIM_OC3Init(ST_LED_RGB_TIM, &RGB_OCInitStructure);

	TIM_OC1PreloadConfig(ST_LED_RGB_TIM, ENABLE);
	TIM_OC2PreloadConfig(ST_LED_RGB_TIM, ENABLE);
	TIM_OC3PreloadConfig(ST_LED_RGB_TIM, ENABLE);

}

void setLED(ST_LED st_led){
	GPIO_SetBits(m_getPort(st_led),  m_getPin(st_led));
}

void resetLED(ST_LED st_led){
	GPIO_ResetBits(m_getPort(st_led),  m_getPin(st_led));
}

void toggleLED(ST_LED st_led){
	GPIO_ToggleBits(m_getPort(st_led),  m_getPin(st_led));
}

void setRGB(RGB_COLOR color){
	uint16_t pulse_red   = RGB_codes[color][RGBR];
	uint16_t pulse_green = RGB_codes[color][RGBG];
	uint16_t pulse_blue  = RGB_codes[color][RGBB];
	m_setRedPulse(pulse_red);
	m_setBluePulse(pulse_green);
	m_setGreenPulse(pulse_blue);
}

void resetRGB(void){
	m_setRedPulse(0);
	m_setBluePulse(0);
	m_setGreenPulse(0);
}

uint16_t calcPulseWidth(uint8_t rgb_value){
	uint16_t pulse = rgb_value/255 * ST_LED_RGB_TIM_PERIOD;
	return pulse;
}

/**
 * @}
 */

/**
 * @}
 */
