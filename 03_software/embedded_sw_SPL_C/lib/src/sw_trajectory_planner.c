/***********************
 * @file 	sw_trajectory_planner.c
 * @author	tard
 * @date	Aug 4, 2019
 * @version	vx_x
************************/

#include "sw_trajectory_planner.h"
#include "sw_localization.h"
#include "math.h"

/** @addtogroup software_modules
 * @{
 */

/** @defgroup Trajectory_Planner Trajectory Planner
 * @{
 */

Frame local_frame = start_frame;
TrajectoryType current_trajectory_type;

static float speedByDistance(float s){
	if(s < ACC_DIST_cm){

	}
	else if(s < CELL_DIST_cm - DEACC_DIST_cm){

	}
	else{

	}
}

void updateTrajectory(State global_state, TrajectoryType* trajectory_type_p, Frame* local_frame_p){
	switch(current_trajectory_type){
	case TrajectoryType_STRAIGHT:
		if(fabs(transformStateToLocal(global_state, local_frame).y - CELL_DIST_cm) < 0.2f){
			//consult with route planner about next cell
		}

		*trajectory_type_p = TrajectoryType_STRAIGHT;
		*local_frame_p = start_frame;
		break;
	case TrajectoryType_TURN:

		break;
	}

}

float getNormRef(State local_state){
	return local_frame.y;
}

float getVRef(State local_state){
	float v = speedByDistance(local_state.y);
}

float getWRef(State local_state){

}

/**
 * @}
 */

/**
 * @}
 */
