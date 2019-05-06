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
void loadMap(World *world){
	for(u8 x = 0; x < WIDTH; x++){
		for(u8 y = 0; y < HEIGHT; y++){
			world->cells[x][y] = map1[x][y];
		}
	}
}


/* Render the current world to the led matrix */
void renderWorld(World *world, Entities *entities){
	for(u8 y = 0; y < HEIGHT; y++){							// For each y
		for(u8 x = 0; x < WIDTH; x++){						// For each x
			BlockType block = world->cells[x][y];			// Read in the block type
			Pos pos = {.x=WIDTH-1-x, .y=y};					// Get position
			switch(block){
				case WALL:									// If the block is wall
					setPixel(pos, GREEN);					// Make it green
					break;
				case PATH:									// If the block is path
					setPixel(pos, BLANK);					// Make it black / no color
					break;
				case FOOD:									// If the block is food
					setPixel(pos, PURPLE);					// Make it purple
					break;
				case ENTITY:								// If the block is an entity
					setPixel(pos, BLANK);					// Set a default color
					/* Go through each entity to find which entity is in this position */
					for(u8 i = 0; i < entities->entityCount; i++){								// For each entity
						if(entities->entity[i]->pos.x == x && entities->entity[i]->pos.y == y){	// If is it in the spot
							setPixel(pos, entities->entity[i]->color);							// Set the led color to the entities color
							break;
						}
					}
					break;
				default:
					setPixel(pos, BLANK);
					break;
			}

		}
	}
	writeAllPixelToDevice();
}

/* Write the gameover screen to the frame buffer. The gameover screen is a red cross */
void renderGameoverScreen(){
	for(u8 y = 0; y < HEIGHT; y++){				// For each y
		for(u8 x = 0; x < WIDTH; x++){			// For each x
			Pos pos = {.x=x, .y=y};				// Get position
			if(gameOver[x][y] == 1){
				setPixel(pos, RED);				// Set pixel to red
			} else{
				setPixel(pos, BLANK);			// Set pixel to black/blank
			}

		}
	}
	writeAllPixelToDevice();					// Write it to the led matrix
	printf("Gameover \n\n");					// Print game over
}
