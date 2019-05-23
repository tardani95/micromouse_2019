/***********************
 * @file 	hw_params.h
 * @author	resiz
 * @date	Mar 13, 2019
 ************************/

#ifndef HW_PARAMS_H_
#define HW_PARAMS_H_

/** @addtogroup hardware_modules
 * @{
 */

/** @addtogroup parameters
 * @brief		physical parameters of the mouse
 * @{
 */

 //TODO: measure params
#define WHEEL_DIAMETER_mm 	20
#define AXLE_LENGTH_mm 		45
#define MOTOR_SPEED_CONSTANT_rpmPvolt 	4000
#define MOT_MAX_VOLT 		3.3f
#define VCC 				3.3f
#define MOT_MAX_SPEED_mmPs	2000.0f


#define STEADY_STATE_GAIN_W_LEFT  14.375
#define STEADY_STATE_GAIN_W_RIGHT -9.157
#define STEADY_STATE_GAIN_V_LEFT  0.288
#define STEADY_STATE_GAIN_V_RIGHT 0.183


uint16_t distByADCValue(uint16_t adc_value);//TODO: define fcn

/**
 * @}
 */

/**
 * @}
 */
#endif /* HW_PARAMS_H_ */
