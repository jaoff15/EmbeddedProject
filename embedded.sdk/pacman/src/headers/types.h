/*
 * types.h
 *
 *  Created on: Apr 24, 2019
 *      Author: Jacob Offersen
 */

#ifndef HEADERS_TYPES_H_
#define HEADERS_TYPES_H_

/* Includes */
#include "defines.h"


/* Type definitions */
typedef unsigned char		bool;
typedef unsigned char		u8;
typedef signed char			s8;
typedef short unsigned int  u16;
typedef short signed int 	s16;
//typedef unsigned int 		ui32;
//typedef signed int 			si32;
//typedef long unsigned int 	ui64;
//typedef long signed int 	si64;
typedef float 				f32;
typedef double				f64;

/* For boolean type */
#define FALSE 0
#define TRUE 1



/* Type definitions */
/* Type of the entity.
 * Used to specify whether the entity is a player or an enemy */
typedef enum e_EntityType{
	PLAYER,
	ENEMY
} EntityType;

/* Used to define an entities position in the world */
typedef struct s_Pos{
	u8 x;
	u8 y;
} Pos;

/* Can hold an RGB color */
typedef struct s_Color{
	u8 r;
	u8 g;
	u8 b;
} Color;


/* Used to specify the difficulty of an enemy */
typedef enum e_Difficulty{
	NO,
	EASY,					// Enemy moves randomly
	MEDIUM,					// Enemy moves like the original pacman. Follows the player for 5 sec and runs away for 5 sec
	HARD,					// Enemy only moves after the player
	IMPOSSIBLE				// Enemy only moves after the player, and collects all food encountered
} Difficulty;


/* Possible moves */
typedef enum e_Move{
	STANDSTILL,				// Entity does not move
	UP,						// Entity moves up
	DOWN,					// Entity moves down
	LEFT,					// Entity moves to the left
	RIGHT					// Entity moves to the right
}Move;



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


/* Used to describe the different blocks in the world */
typedef enum e_BlockType{
	NONE,
	WALL,
	PATH,
	FOOD,
	ENTITY
} BlockType;

/* Used to specify the map that should be used */
enum e_Map{
	MAP1,
	MAP2
};

/* Used to hold a world */
typedef struct s_World{
	BlockType cells[WIDTH][HEIGHT];
} World;


#endif /* HEADERS_TYPES_H_ */
