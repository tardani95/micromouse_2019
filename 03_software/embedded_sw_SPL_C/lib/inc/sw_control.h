/***********************
 * @file 	sw_control.h
 * @author	tard
 * @date	May 19, 2019
 * @version	vx_x
************************/

#ifndef SW_CONTROL_H_
#define SW_CONTROL_H_

#include "stm32f4xx.h"

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup control_plane
 * @{
 */

#define CONTROL_LOOP_PERIOD_us		1000

#define CONTROL_LOOP_IRQHandler		TIM2_IRQHandler

void initControl(void);
void initControlDebug(void);
void ControlLoop_Cmd(FunctionalState NewState);
void CONTROL_LOOP_IRQHandler();




/**
 * @}
 * end of control pane
 */
/**
 * @}
 * end of software_modules
 */

#endif /* SW_CONTROL_H_ */
