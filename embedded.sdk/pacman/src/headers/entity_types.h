/*
 * entity_type.h
 *
 *  Created on: May 6, 2019
 *      Author: jacoboffersen
 */

#ifndef SRC_HEADERS_ENTITY_TYPES_H_
#define SRC_HEADERS_ENTITY_TYPES_H_

/* Includes */
#include "types.h"
#include "defines.h"
#include "colors.h"


/* Type of the entity.
 * Used to specify whether the entity is a player or an enemy */
typedef enum e_EntityType{
	PLAYER,
	ENEMY
} EntityType;

/* Used to define an entities position in the world */
typedef struct s_Pos{
	s16 x;
	s16 y;
} Pos;

/* Used to specify the difficulty of an enemy */
typedef enum e_Difficulty{
	NO,
	EASY,					// Enemy moves randomly
//	MEDIUM,					// Enemy moves like the original pacman. Follows the player for 5 sec and runs away for 5 sec
	HARD,					// Enemy only moves after the player
//	IMPOSSIBLE				// Enemy only moves after the player, and collects all food encountered
} Difficulty;


/* Possible moves */
typedef enum e_Move{
	STANDSTILL,				// Entity does not move
	UP,						// Entity moves up
	DOWN,					// Entity moves down
	RIGHT,					// Entity moves to the right
	LEFT					// Entity moves to the left
}Move;


const static Pos D_STANDSTILL 	= {.x =  0, .y =  0};
const static Pos D_UP 			= {.x =  0, .y =  1};
const static Pos D_DOWN 	 	= {.x =  0, .y = -1};
const static Pos D_RIGHT 	 	= {.x =  1, .y =  0};
const static Pos D_LEFT 		= {.x = -1, .y =  0};

/* A structure used to hold all data for a specific entity */
typedef struct s_Entity{
	Pos 		pos;
	EntityType 	type;
	Difficulty  diff;
	Move		lastMove;
	Pos 		lastPos;
	Color		color;
} Entity;


typedef struct e_Entities{
	Entity *entity[MAX_ENEMIES+1];
	u8 entityCount;
} Entities;

#endif /* SRC_HEADERS_ENTITY_TYPES_H_ */
