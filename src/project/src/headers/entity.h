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


/* Type definitions */
typedef enum enum_Entity{
	PLAYER,
	ENEMY
} enum_Entity;

typedef struct Pos{
	u8 x;
	u8 y;
} Pos;

typedef struct Entity{
	char x;
	char y;
} Entity;


/* Function declarations */
void initEntity(Entity e, enum_Entity type);
void setLocation(Entity e, Pos pos);


#endif /* HEADERS_ENTITY_H_ */
