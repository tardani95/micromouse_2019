/***********************
 * @file 	sw_localization.h
 * @author	resiz
 * @date	4 Aug 2019
 ************************/
#ifndef INC_SW_LOCALIZATION_H_
#define INC_SW_LOCALIZATION_H_

#include "stm32f4xx.h"

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup localization
 * @{
 */

typedef struct State{
	float x;
	float y;
	float fi;
	float v_tan;
	float omega;
}State;

typedef struct Frame{
	float x;
	float y;
	float fi;
}Frame;

const State start_state = {
	.x = 4.5,
	.y = 4.5,
	.fi = 3.1415/2,
	.v_tan = 0,
	.omega = 0
};

const Frame start_frame = {
	.x = 4.5,
	.y = 0,
	.fi = 0
};

State updateState(void);
float encToCm(uint32_t encCnt);

State transformStateToLocal(State global_state, Frame local_frame);




/**
 * @}
 */

/**
 * @}
 */

#endif /* INC_SW_LOCALIZATION_H_ */
