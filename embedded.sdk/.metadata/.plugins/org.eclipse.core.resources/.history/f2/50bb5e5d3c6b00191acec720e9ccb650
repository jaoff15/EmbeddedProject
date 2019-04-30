/*
 * entity.h
 *
 *  Created on: Apr 24, 2019
 *      Author: Jacob Offersen
 */

#ifndef HEADERS_ENTITY_H_
#define HEADERS_ENTITY_H_

/* Includes */
#include "types.h"
#include "world.h"
#include "score.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/* Defines */
#define MAX_ENEMIES 5
#define INFTY 100

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
} Entity;


/* Function declarations */

/* Initialize an entity */
void initEntity(Entity *e, EntityType type, Pos pos,Difficulty diff);

/* Move the given entity in the given direction. */
void moveEntity(Entity *e, World *world, World *food, Move m);

/* Load the entity into the world */
void loadEntity(Entity *e,World *world);


/* Check if the given entity has been killed by any its enemy */
bool entityKilled(Entity *e, Entity *enemy);


/* Get the next move of the given entity.
 * Function called various other functions depending on the difficulty */
Move controlEntity(Entity *enemy, World *world, Entity *player);

/* Move algorithm for easy mode */
Move getMoveEasy(Entity *entity, World *world);

Move getMoveHard(Entity *entity, World *world, Entity *target);

#endif /* HEADERS_ENTITY_H_ */
