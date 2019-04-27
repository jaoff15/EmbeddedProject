/*
 * food.h
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */

#ifndef HEADERS_FOOD_H_
#define HEADERS_FOOD_H_

/* Includes */
#include <stdlib.h>
#include "types.h"
#include "world.h"


/* Defines */
#define FOOD_AMOUNT 3

/* Function declarations */
void initFood(World *world, World *food);
void loadFood(World *world, World *food);

#endif /* HEADERS_FOOD_H_ */
