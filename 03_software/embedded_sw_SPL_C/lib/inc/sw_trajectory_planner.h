/***********************
 * @file 	sw_trajectory_planner.h
 * @author	tard
 * @date	Aug 04, 2019
 * @version	vx_x
************************/

#ifndef SW_TRAJECTORY_PLANNER_H_
#define SW_TRAJECTORY_PLANNER_H_

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup Trajectory_Planner
 * @{
 */

#define CELL_DIST_cm 18.0f
#define ACC_DIST_cm 0.0f
#define DEACC_DIST_cm 3.0f
#define ACC_MAX 10.0f
#define TOP_SPEED_cmPs 0.0f

#define FINISH_TRESHOLD 0.2f

typedef enum TrajectoryType{
	TrajectoryType_STRAIGHT,
	TrajectoryType_TURN
}TrajectoryType;

typedef struct Frame Frame;
typedef struct State State;

void initTrajectoryPlanner(void);
void updateTrajectory(State global_state, TrajectoryType* trajectory_type_p, Frame* local_frame);
float getNormRef(State local_state);
float getVRef(State local_state);
float getWRef(State local_state);

/**
 * @}
 */

/**
 * @}
 */

#endif /* SW_TRAJECTORY_PLANNER_H_ */

