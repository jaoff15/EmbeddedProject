/*
 * world.c
 *
 *  Created on: Apr 24, 2019
 *      Author: Jacob Offersen
 */


/* Includes */
#include "../headers/world.h"

/* Variables */
static const char symbols[] = {'W','W','_','o','C','A'};







void updateMap(){

}

/* Print out the map to the terminal */
void printWorld(World *world){
	for(int y = WIDTH-1; y >= 0; y--){
		for(int x = 0; x < HEIGHT; x++){
			printf(" %c",symbols[world->cells[x][y]]);
		}
		printf("\n");
	}
}

/* Load a predefined map to the frame buffer */
void loadMap(World *world, u8 mapIndex){
	for(int x = 0; x < WIDTH; x++){
		for(int y = 0; y < HEIGHT; y++){
			switch(mapIndex){
				case 0:
					world->cells[x][y] = map1[x][y];
					break;
				case 1:
					world->cells[x][y] = map2[x][y];
					break;
				default:
					world->cells[x][y] = map1[x][y];
			}
		}
	}
}

