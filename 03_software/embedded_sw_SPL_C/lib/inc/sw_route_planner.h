/***********************
 * @file 	sw_route_planner.h
 * @author	tard
 * @date	May 19, 2019
 * @version	vx_x
************************/

#ifndef SW_ROUTE_PLANNER_H_
#define SW_ROUTE_PLANNER_H_

#include <stdint.h>
#include "sw_maze.h"

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup Route_Planner
 * @{
 */

void initCost();
void calculateDistances(Maze maze, Heuristic h);

void discoverWalls();
Cell calcNextPosition(Cell current);

uint8_t bestDepthFirstSearch(Cell next_cell);
uint8_t bestDepthFirstSearchXY(Cell next_cell);

/**
 * @}
 */

/**
 * @}
 */

#endif /* SW_ROUTE_PLANNER_H_ */
