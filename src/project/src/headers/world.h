/*
 * world.h
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */


#ifndef HEADERS_WORLD_H_
#define HEADERS_WORLD_H_

/* Includes */
#include <stdio.h>
#include "types.h"

/* Global Variables */
#define WIDTH 	8
#define HEIGHT 	8

#define EDGE_TOP		7
#define EDGE_BOTTOM  	0
#define EDGE_LEFT		0
#define EDGE_RIGHT		7
/* 	7
 * 	^
 * 	|
 * 	|
 * 0|--------->7
 *  0
 */

/* Type definitions */
typedef enum e_BlockType{
	NONE,
	WALL,
	PATH,
	FOOD,
	ENTITY_PLAYER,
	ENTITY_ENEMY
} BlockType;


enum e_Map{
	MAP1,
	MAP2
};

typedef struct s_World{
	BlockType cells[WIDTH][HEIGHT];
} World;



/* Function declarations */
void updateMap();
void printWorld(World *world);
void loadMap(World *world, u8 mapIndex);



#endif /* HEADERS_WORLD_H_ */

