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



/* Print out the map to the terminal */
void printWorld(World *world){
	for(u8 y = HEIGHT-1; y >= 0; y--){
		for(u8 x = 0; x < WIDTH; x++){
			printf(" %c",symbols[world->cells[x][y]]);
		}
		printf("\n");
	}
	printf("\n");
}

/* Load a predefined map to the frame buffer */
void loadMap(World *world, u8 mapIndex){
	for(u8 x = 0; x < WIDTH; x++){
		for(u8 y = 0; y < HEIGHT; y++){
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

/* Print the game over screen to the terminal */
void printGameoverScreen(){
	for(s8 y = HEIGHT-1; y >= 0; y--){
		for(u8 x = 0; x < WIDTH; x++){
			if(gameOver[x][y] == 1){
				printf(" X");
			}else{
				printf(" _");
			}
		}
		printf("\n");
	}
	printf("\n");
}

