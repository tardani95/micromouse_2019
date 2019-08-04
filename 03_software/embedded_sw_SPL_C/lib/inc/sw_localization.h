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
	x;
	y;
	fi;
	v_tan;
	omega;
}State;

void updateState(void);


/**
 * @}
 */

/**
 * @}
 */

#endif /* INC_SW_LOCALIZATION_H_ */
