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
#include <math.h>


/* Defines */
#define MAX_ENEMIES 5

/* Type definitions */
typedef enum e_EntityType{
	PLAYER,
	ENEMY
} EntityType;

typedef struct s_Pos{
	u8 x;
	u8 y;
} Pos;

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


typedef struct s_Entity{
	Pos 		pos;
	EntityType 	type;
	Difficulty  diff;
	Move		lastMove;
} Entity;


/* Function declarations */
void initEntity(Entity *e, EntityType type, Pos pos,Difficulty diff);

Move controlEntity(Entity *enemy, World *world, Entity *player);

void moveEntity(Entity *e, World *world, World *food, Move m);

void loadEntity(Entity *e,World *world);

#endif /* HEADERS_ENTITY_H_ */
