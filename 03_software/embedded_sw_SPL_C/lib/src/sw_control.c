/***********************
 * @file 	sw_control.c
 * @author	tard
 * @date	May 19, 2019
 * @version	vx_x
 ************************/

#include "sw_control.h"

#include "hw_motor_control.h"
#include "hw_encoder.h"
#include "hw_params.h"
#include "hw_status_led.h"
#include "sw_debug.h"
#include "misc.h"
#include "sw_localization.h"

/** @addtogroup software_modules
 * @{
 */

/** @defgroup control_plane Control Plane
 * @{
 */

float T = 0.001; // @1 kHz

//float Kp_w = 1/((STEADY_STATE_GAIN_V_RIGHT+STEADY_STATE_GAIN_W_LEFT)/2); /* P */ //1.5
float Kp_w = 0.5; /* P */ //1.5
float Ki_W = 0.1; /* I */ // 0.05
float Kd = 0.0; /* D */ //0.1

float I = 0;
float D = 0;
float Imax = 1.5; /* anti wind-up */

float e_w = 10.0;
float e_w_prev = 0.0;
float e_w_max = 1000.0;

float w = 0.0;
float v_base_mmPs = 200;

uint32_t debug_counter = 0;



/**
 * Initialize control loop @1kHz
 */
void initControl() {

	/* Enable TIM clock using RCC_APBxPeriphClockCmd(RCC_APBxPeriph_TIMx, ENABLE) function */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	/* Fill the TIM_TimeBaseInitStruct with the desired parameters */
	TIM_TimeBaseInitTypeDef TimeBaseInitStructure;
	TIM_TimeBaseStructInit(&TimeBaseInitStructure);
	TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TimeBaseInitStructure.TIM_Prescaler = 80 - 1; /* Clock freqeuency: 80MHz/80 = 1000kHz */
	TimeBaseInitStructure.TIM_Period = 1000 - 1; /* PWM frequency: 10000kHz/10 /1000 = 1KHz */
	TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TimeBaseInitStructure.TIM_RepetitionCounter = 0;

	/* Call TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStruct) to configure the Time Base unit
	 with the corresponding configuration */
	TIM_TimeBaseInit(TIM2, &TimeBaseInitStructure);

	/* Enable the NVIC to generate the update interrupt */
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable the corresponding interrupt using the function TIM_ITConfig(TIMx, TIM_IT_Update) */
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM2->CNT = 0;
	actuateMotors(0, 0);

	/* Call the TIM_Cmd(ENABLE) function to enable the TIM counter. */
//	TIM_Cmd(TIM2, DISABLE);
//	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	initControlDebug();
}



void ControlLoop_Cmd(FunctionalState NewState) {
	TIM_Cmd(TIM2, NewState);
	TIM2->CNT = 0;
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
}

float norm_prev, norm_I;
float v_prev, v_I;
float w_prev, w_I;

norm_prev = norm_I = v_prev = v_I = w_prev = w_I = 0;

/**
 * control loop function called @1kHz, @see Init_Control() function.
 */
void CONTROL_LOOP_IRQHandler() {
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	//setLED(LED_PINK);

	State global_state = updateState();
	TrajectoryType trajectory_type;
	Frame local_frame;
	updateTrajectory(current_state, &trajectory_type, &local_frame);
	State local_state = transformStateToLocal(global_State, local_frame);
	Controller controller = getController(trajectory_type);

	switch(trajectory_type){
	case TrajectoryType.STRAIGHT:
		float norm_ref = getNormRef(current_state);
		float v_ref = getVRef(current_state);

		float norm_dev = norm_ref - local_state.x;
		float v_dev = v_ref - local_state.v_tan;

		v_I = v_I + v_dev;
		float v_D = (v_prev - v_dev)/2;
		float v_ctrl = v_dev*controller.P + v_I*controller.I + v_D*controller.D;
		float v_reg = v_ref + v_ctrl;

		break;
	case TrajectoryType.TURN:
		float w_ref = getWRef(current_state);

		break;
	}



	//D = Kd * (e_w - e_w_prev) / T;

	I += Ki_W * e_w;
	if (I > Imax)
		I = Imax;
	if (I < -Imax)
		I = -Imax;
//	I = 0;

	w = Kp_w * e_w + I + D;


	if (m_abs(w) > 100) {
		//setLED(LED_YELLOW);
		w = 100;
	} else {
		//resetLED(LED_YELLOW);
	}

	actuateMotors(v_base_mmPs, w);

	m_resetEncCnt(ENC_RIGHT);
	m_resetEncCnt(ENC_LEFT);

	debug_counter++;
	if(debug_counter%1000 == 0){
		sendDebugData();
	}

}


void initControlDebug(){
	debug("e_w" , DEBUG_TYPE_FLOAT, &e_w);
	//debug("e_w_prev" , DEBUG_TYPE_FLOAT, &e_w_prev);
	//debug("I" , DEBUG_TYPE_FLOAT, &I);
	//debug("w" , DEBUG_TYPE_FLOAT, &w);

}

/**
 * @}
 */

/**
 * @}
 */
