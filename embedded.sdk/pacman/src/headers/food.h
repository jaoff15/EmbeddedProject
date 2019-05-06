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
#include "world.h"


/* Function declarations */
void initFood(World *world, World *food);
void loadFood(World *world, World *food);
void clearFood(World *food);
bool foodEmpty(World *food);

#endif /* HEADERS_FOOD_H_ */
