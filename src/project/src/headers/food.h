/*
 * food.h
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */

#ifndef HEADERS_FOOD_H_
#define HEADERS_FOOD_H_

/* Includes */
#include "types.h"

/* Defines */
#define FOOD_AMOUNT 10

/* Function declarations */
void initFood(enum_Block *world, enum_Block *food);
void loadFood(enum_Block *world, enum_Block *food);

#endif /* HEADERS_FOOD_H_ */
