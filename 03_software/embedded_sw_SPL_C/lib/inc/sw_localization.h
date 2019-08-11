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

const extern State start_state;

const extern Frame start_frame;

void initLocalization(void);
State updateState(void);
float encToCm(int32_t encCnt);

State transformStateToLocal(State global_state, Frame local_frame);




/**
 * @}
 */

/**
 * @}
 */

#endif /* INC_SW_LOCALIZATION_H_ */
