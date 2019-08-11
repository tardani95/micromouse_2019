/***********************
 * @file 	sw_localization.cpp
 * @author	resiz
 * @date	4 Aug 2019
 ************************/

#include "sw_localization.h"
#include "hw_encoder.h"
#include "hw_params.h"
#include "math.h"

/** @addtogroup software_modules
 * @{
 */

/** @defgroup localization	Localization
 * @{
 */

const State start_state = {
	.x = 4.5,
	.y = 4.5,
	.fi = 3.1415/2,
	.v_tan = 0,
	.omega = 0
};

const Frame start_frame  = {
	.x = 4.5,
	.y = 4.5,
	.fi = 0
};

State state;

void initLocalization(void){
	state = start_state;
}

float enc_right_cm;
float enc_left_cm;
State updateState(void){
	float T = 0.001; // @1 kHz

	enc_right_cm = encToCm(m_getEncCnt(ENC_RIGHT) - ENC_CNT_BASEVALUE);
	enc_left_cm = encToCm(m_getEncCnt(ENC_LEFT) - ENC_CNT_BASEVALUE);

	m_resetEncCnt(ENC_RIGHT);
	m_resetEncCnt(ENC_LEFT);

	float ds = (enc_right_cm + enc_left_cm)/2;
	float dfi = (enc_left_cm - enc_right_cm)/AXLE_LENGTH_cm;

	float tmpfi = state.fi + dfi/2;

	float dx = ds*cos(tmpfi);
	float dy = ds*sin(tmpfi);

	float v_tan = ds/T;
	float omega = dfi/T;

	state.x += dx;
	state.y += dy;
	state.fi += dfi;
	state.v_tan = v_tan;
	state.omega = omega;

	return state;
}

float encToCm(int32_t encCnt){
	return (float)encCnt / 8192.0f * 2.0f * 3.1415f * WHEEL_DIAMETER_cm;
}

State transformStateToLocal(State global_state, Frame local_frame){
	State local_state;
	local_state.x = global_state.x - local_frame.x;
	local_state.y = global_state.y - local_frame.y;
	local_state.fi = global_state.fi - local_frame.fi;
	return local_state;
}


/**
 * @}
 */

/**
 * @}
 */
