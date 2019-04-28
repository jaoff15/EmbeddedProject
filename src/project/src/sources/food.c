/*
 * food.c
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */

#include "../headers/food.h"

void initFood(World *world, World *food){
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


void loadFood(World *world, World *food){
	for(int x = 0; x < WIDTH; x++){
		for(int y = 0; y < HEIGHT; y++){
			if(food->cells[x][y] == FOOD){
				world->cells[x][y] = FOOD;
			}
		}
	}
}
