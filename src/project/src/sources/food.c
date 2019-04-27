/*
 * food.c
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */

#include "../headers/food.h"

void initFood(World *world, World *food){
	u8 foodLeft = FOOD_AMOUNT;
//	BlockType *pWorld;
//	BlockType *pFood;
	while(foodLeft > 0){
		u8 x = rand() % 8;
		u8 y = rand() % 8;
//		u16 offset = sizeof(BlockType)*x + sizeof(BlockType)*y*WIDTH;
//		pWorld = world + offset;
//		pFood  = food + offset;
//		if(*pWorld == PATH && *pFood != FOOD){
		if(world->cells[x][y] == PATH && food->cells[x][y] != FOOD){
			food->cells[x][y] = FOOD;
//			*pFood = FOOD;
			foodLeft--;
		}
	}
}


void loadFood(World *world, World *food){
	for(int x = 0; x < WIDTH; x++){
		for(int y = 0; y < HEIGHT; y++){
//			u16 offset = sizeof(BlockType)*x + sizeof(BlockType)*y*WIDTH;
//			BlockType *pFood = food + offset;
//			if(*pFood == FOOD){
			if(food->cells[x][y] == FOOD){
				world->cells[x][y] = FOOD;
//				BlockType *pWorld = world + offset;
//				*pWorld = *pFood;
			}
		}
	}
}
