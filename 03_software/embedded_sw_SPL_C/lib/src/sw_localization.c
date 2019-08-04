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

State state;
float T = 0.001; // @1 kHz

void initLocalization(void){
	state = start_state;
}

State updateState(void){
	float enc_right_cm = encToCm(m_getEncCnt(ENC_RIGHT));
	float enc_left_cm = encToCm(m_getEncCnt(ENC_LEFT));

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

float encToCm(uint32_t encCnt){
	return encCnt / 8096 * 2 * 3.1415 * WHEEL_DIAMETER_cm;
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
