/*
 * world_types.h
 *
 *  Created on: May 6, 2019
 *      Author: jacoboffersen
 */

#ifndef SRC_HEADERS_WORLD_TYPES_H_
#define SRC_HEADERS_WORLD_TYPES_H_

#include "defines.h"

/* Used to describe the different blocks in the world */
typedef enum e_BlockType{
	NONE,
	WALL,
	PATH,
	FOOD,
	ENTITY
} BlockType;


/* Used to hold a world */
typedef struct s_World{
	BlockType cells[WIDTH][HEIGHT];
} World;

#endif /* SRC_HEADERS_WORLD_TYPES_H_ */
