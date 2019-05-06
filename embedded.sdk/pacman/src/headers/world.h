/*
 * world.h
 *
 *  Created on: Apr 24, 2019
 *      Author: Jacob Offersen
 */


#ifndef HEADERS_WORLD_H_
#define HEADERS_WORLD_H_

/* Includes */
#include <stdio.h>
#include "types.h"
#include "time.h"
#include "led_matrix.h"
#include "entity_types.h"
#include "world_types.h"


/* Global variables */
static const BlockType map1[WIDTH][HEIGHT] = {
		{PATH,PATH,PATH,PATH,PATH,PATH,PATH,PATH},
		{PATH,WALL,WALL,PATH,PATH,WALL,WALL,PATH},
		{PATH,WALL,PATH,PATH,PATH,PATH,WALL,PATH},
		{PATH,WALL,PATH,WALL,WALL,PATH,WALL,PATH},
		{PATH,WALL,PATH,WALL,WALL,PATH,WALL,PATH},
		{PATH,WALL,PATH,PATH,PATH,PATH,WALL,PATH},
		{PATH,WALL,WALL,PATH,PATH,WALL,WALL,PATH},
		{PATH,PATH,PATH,PATH,PATH,PATH,PATH,PATH}};


static u8 gameOver[WIDTH][HEIGHT] = {
		{1,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,1,0},
		{0,0,1,0,0,1,0,0},
		{0,0,0,1,1,0,0,0},
		{0,0,0,1,1,0,0,0},
		{0,0,1,0,0,1,0,0},
		{0,1,0,0,0,0,1,0},
		{1,0,0,0,0,0,0,1}};

/* Function declarations */

/* Print out the map to the terminal */
void printWorld(World *world);

/* Load a predefined map to the frame buffer */
void loadMap(World *world);

/* Render the current world to the led matrix */
void renderWorld(World *world, Entities *entities);

/* Write the gameover screen to the frame buffer. The gameover screen is a red cross */
void renderGameoverScreen();

#endif /* HEADERS_WORLD_H_ */

