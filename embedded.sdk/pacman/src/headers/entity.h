/*
 * entity.h
 *
 *  Created on: Apr 24, 2019
 *      Author: Jacob Offersen
 */

#ifndef HEADERS_ENTITY_H_
#define HEADERS_ENTITY_H_

/* Includes */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "defines.h"
#include "types.h"
#include "world.h"
#include "score.h"
#include "colors.h"


/* Function declarations */

/* Initialize an entity */
void initEntity(Entity *e, EntityType type, Pos pos,Difficulty diff, Color color);

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


void initEntities(Entities *entities);
void registerEntity(Entities *entities, Entity *e);

#endif /* HEADERS_ENTITY_H_ */
