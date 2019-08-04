/***********************
 * @file 	sw_maze.c
 * @author	tard
 * @date	Aug 4, 2019
 * @version	vx_x
 ************************/

#include "sw_maze.h"
#include "math.h"

/** @addtogroup software_modules
 * @{
 */

/** @defgroup maze Maze
 * @{
 */

uint8_t isCellEquals(Cell c1, Cell c2) {
	if (c1.x == c2.x && c1.y == c2.y) {
		return 1;
	}
	return 0;
}

float distanceToH(Cell c1, Cell c2, Heuristic h) {
	switch (h) {
	case MANHATTAN:
		return fabs(c1.x - c2.x) + fabs(c1.y - c2.y);
	case EUCLIDEAN:
		return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
	default:
		return -1.0f;
	}
}

float distanceTo(Cell c1, Cell c2){
	return distanceToH(c1, c2, EUCLIDEAN);
}

/**
 * @}
 */

/**
 * @}
 */
