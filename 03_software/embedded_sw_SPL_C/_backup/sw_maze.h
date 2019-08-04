/***********************
 * @file 	sw_maze.h
 * @author	tard
 * @date	Aug 4, 2019
 * @version	vx_x
 ************************/

#ifndef INC_SW_MAZE_H_
#define INC_SW_MAZE_H_

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup maze
 * @{
 */

#define MAX_MAZE_SIZE 32

typedef enum Heuristic{
	MANHATTAN,
	EUCLIDEAN
}Heuristic;

typedef struct Cell {
	uint8_t x;
	uint8_t y;

	uint8_t explored;
	uint8_t visited;
	float cost;
	float destination_distance;

	//CellType type;

	Cell *parent_p;
} Cell;

uint8_t isCellEquals(Cell c1, Cell c2);
float distanceTo(Cell c1, Cell c2, Heuristic h);

typedef struct Maze {
	Cell *current_p;
	Cell start;
	Cell goal;

	int walls[2][MAX_MAZE_SIZE + 1];
	Cell cells[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
} Maze;

/**
 * @}
 */

/**
 * @}
 */

#endif /* INC_SW_MAZE_H_ */

