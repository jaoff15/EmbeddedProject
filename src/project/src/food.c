/*
 * food.c
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */

#include "headers/food.h"

void initFood(enum_Block *world, enum_Block *food){
	u8 foodLeft = FOOD_AMOUNT;
	enum_Block *pWorld;
	enum_Block *pFood;
	while(foodLeft > 0){
		u8 x = rand() % 8;
		u8 y = rand() % 8;
		u16 offset = sizeof(enum_Block)*x + sizeof(enum_Block)*y*WIDTH;
		pWorld = world + offset;
		pFood  = food + offset;
		if(*pWorld == PATH && *pFood != FOOD){
			*pFood = FOOD;
			foodLeft--;
		}
	}
}


void loadFood(enum_Block *world, enum_Block *food){
	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			u16 offset = sizeof(enum_Block)*x + sizeof(enum_Block)*y*WIDTH;
			enum_Block *pFood = food + offset;
			if(*pFood == FOOD){
				enum_Block *pWorld = world + offset;
				*pWorld = *pFood;
			}
		}
	}
}
