/*
 ============================================================================
 Name        : Pacman
 Author      : Jacob Offersen
 Version     :
 Copyright   : Your copyright notice
 Description : Embedded Project
 Date        : Spring 2019
 ============================================================================
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include "headers/entity.h"
#include "headers/world.h"
#include "headers/food.h"


enum_Block world[WIDTH][HEIGHT]; // frame buffer
enum_Block food[WIDTH][HEIGHT]; // food frame buffer

int main(void) {
	loadMap(world, MAP1);
	initFood(world, food);
//	loadFood(world, food);

	printWorld(world);

	return EXIT_SUCCESS;
}
