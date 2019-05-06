/*
 * food.h
 *
 *  Created on: Apr 24, 2019
 *      Author: Jacob Offersen
 */

#ifndef HEADERS_FOOD_H_
#define HEADERS_FOOD_H_

/* Includes */
#include <stdlib.h>
#include "defines.h"
#include "types.h"
#include "world_types.h"


/* Function declarations */
/* Place food randomly around the map */
void initFood(World *world, World *food);

/* Put food into the world */
void loadFood(World *world, World *food);

/* Remove all food */
void clearFood(World *food);

/* Test if all food is gone from the world */
bool foodEmpty(World *food);

#endif /* HEADERS_FOOD_H_ */
