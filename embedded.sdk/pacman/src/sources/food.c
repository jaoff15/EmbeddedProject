/*
 * food.c
 *
 *  Created on: Apr 24, 2019
 *      Author: Jacob Offersen
 */

/* Includes */
#include "../headers/food.h"

/* Place food randomly around the map */
void initFood(World *world, World *food){
	clearFood(food);
	u8 foodLeft = FOOD_AMOUNT;
	while(foodLeft > 0){
		u8 x = rand() % 8;
		u8 y = rand() % 8;
		if(world->cells[x][y] == PATH && food->cells[x][y] != FOOD){
			food->cells[x][y] = FOOD;
			foodLeft--;
		}
	}
}

/* Remove all food */
void clearFood(World *food){
	for(int x = 0; x < WIDTH; x++){
		for(int y = 0; y < HEIGHT; y++){
			food->cells[x][y] = NONE;
		}
	}
}

/* Put food into the world */
void loadFood(World *world, World *food){
	for(int x = 0; x < WIDTH; x++){
		for(int y = 0; y < HEIGHT; y++){
			if(food->cells[x][y] == FOOD){
				world->cells[x][y] = FOOD;
			}
		}
	}
}


/* Test if all food is gone from the world */
bool foodEmpty(World *food){
	bool isEmpty = TRUE;
	for(int x = 0; x < WIDTH; x++){
		for(int y = 0; y < HEIGHT; y++){
			if(food->cells[x][y] == FOOD){
				isEmpty = FALSE;
				break;
			}
		}
		if(!isEmpty){
			break;
		}
	}
	return isEmpty;
}
