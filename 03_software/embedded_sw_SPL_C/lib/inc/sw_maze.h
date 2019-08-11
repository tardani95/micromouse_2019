/***********************
 * @file 	sw_maze.h
 * @author	tard
 * @date	Aug 4, 2019
 * @version	vx_x
 ************************/

#ifndef INC_SW_MAZE_H_
#define INC_SW_MAZE_H_

#include <stdint.h>

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup maze
 * @{
 */

#define MAX_MAZE_SIZE 32

typedef enum Heuristic {
	MANHATTAN, EUCLIDEAN
} Heuristic;

typedef enum CellType {
	DEFAULT, CURRENT, NEXT, START, DESTINATION
} CellType;

typedef enum WallType {
	RIGHT_WALL, TOP_WALL, LEFT_WALL, BOTTOM_WALL
} WallType;

typedef enum Direction {
	RIGHT, TOP, LEFT, BOTTOM, UNKNOWN
} Direction;

typedef struct Cell Cell;

struct Cell {
	uint8_t x;
	uint8_t y;

	uint8_t explored;
	uint8_t visited;
	float cost;
	float destination_distance;

//CellType type;

	Cell *parent_p;
};

uint8_t isCellEquals(Cell c1, Cell c2);
float distanceToH(Cell c1, Cell c2, Heuristic h);
float distanceTo(Cell c1, Cell c2);

typedef struct Maze {
	Cell *current_p;
	Cell start;
	Cell goal;

	uint32_t walls[2][MAX_MAZE_SIZE + 1];

	Cell cells[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
} Maze;

extern Maze maze;

uint8_t getWall(Maze maze, Cell c, WallType wall_type);
uint8_t getWallXY(uint32_t **walls, uint8_t x, uint8_t y, WallType wall_type);
uint8_t setWall(Maze maze, Cell c, WallType wall_type);
uint8_t setWallXY(uint32_t **walls, uint8_t x, uint8_t y, WallType wall_type);


/**
 * @}
 */

/**
 * @}
 */

#endif /* INC_SW_MAZE_H_ */
