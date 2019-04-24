/*
 * world.h
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */


#ifndef HEADERS_WORLD_H_
#define HEADERS_WORLD_H_

/* Includes */
#include "types.h"

/* Type definitions */
typedef enum enum_Block{
	WALL,
	PATH,
	FOOD,
	PLAYER,
	ENEMY
} enum_Block;


enum enum_Maps{
	MAP1,
	MAP2
};

/* Global Variables */
#define WIDTH 	8
#define HEIGHT 	8

/* Function declarations */
void updateMap();
void printWorld(enum_Block *world);
void loadMap(enum_Block *world, u8 mapIndex);




#endif /* HEADERS_WORLD_H_ */

