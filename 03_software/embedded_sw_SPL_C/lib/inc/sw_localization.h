/***********************
 * @file 	sw_localization.h
 * @author	resiz
 * @date	4 Aug 2019
 ************************/
#ifndef INC_SW_LOCALIZATION_H_
#define INC_SW_LOCALIZATION_H_

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

void updateState(void);
float encToCm(uint32_t encCnt);

/**
 * @}
 */

/**
 * @}
 */

#endif /* INC_SW_LOCALIZATION_H_ */
