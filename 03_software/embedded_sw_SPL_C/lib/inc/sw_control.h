/***********************
 * @file 	sw_control.h
 * @author	tard
 * @date	May 19, 2019
 * @version	vx_x
************************/

#ifndef SW_CONTROL_H_
#define SW_CONTROL_H_

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup control_plane
 * @{
 */

//TODO user code here
#define CONTROL_LOOP_PERIOD_us		1000

#define CONTROL_LOOP_IRQHandler		TIM2_IRQHandler

void Init_Control();
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
