/*
 * entity.h
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */

#ifndef HEADERS_ENTITY_H_
#define HEADERS_ENTITY_H_

/* Includes */
#include "types.h"
#include "world.h"
#include "score.h"

/* Type definitions */
typedef enum e_EntityType{
	PLAYER,
	ENEMY
} EntityType;

typedef struct s_Pos{
	u8 x;
	u8 y;
} Pos;

typedef struct s_Entity{
	EntityType 	type;
	Pos 		pos;
} Entity;

typedef enum e_Move{
	STANDSTILL,
	UP,
	DOWN,
	LEFT,
	RIGHT
}Move;


/* Function declarations */
void initEntity(Entity *e, EntityType type, Pos pos);

void controlEntity(Entity *e, Move *m);

void moveEntity(Entity *e, World *world, World *food, Move m);

void loadEntity(Entity *e,World *world);

#endif /* HEADERS_ENTITY_H_ */
