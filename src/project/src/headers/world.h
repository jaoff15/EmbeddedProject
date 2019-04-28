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

/* Global Variables */
#define WIDTH 	8
#define HEIGHT 	8

#define EDGE_TOP		7
#define EDGE_BOTTOM  	0
#define EDGE_LEFT		0
#define EDGE_RIGHT		7
/* 	7
 * 	^
 * 	|
 * 	|
 * 0|--------->7
 *  0
 */

/* Type definitions */
typedef enum e_BlockType{
	NONE,
	WALL,
	PATH,
	FOOD,
	ENTITY_PLAYER,
	ENTITY_ENEMY
} BlockType;


enum e_Map{
	MAP1,
	MAP2
};

typedef struct s_World{
	BlockType cells[WIDTH][HEIGHT];
} World;


typedef struct s_Color{
	u8 red;
	u8 green;
	u8 blue;
} Color;


/* Function declarations */
void updateMap();
void printWorld(World *world);
void loadMap(World *world, u8 mapIndex);

static const BlockType map1[WIDTH][HEIGHT] = {
		{PATH,PATH,PATH,PATH,PATH,PATH,PATH,PATH},
		{PATH,WALL,WALL,PATH,PATH,WALL,WALL,PATH},
		{PATH,WALL,PATH,PATH,PATH,PATH,WALL,PATH},
		{PATH,WALL,PATH,WALL,WALL,PATH,WALL,PATH},
		{PATH,WALL,PATH,WALL,WALL,PATH,WALL,PATH},
		{PATH,WALL,PATH,PATH,PATH,PATH,WALL,PATH},
		{PATH,WALL,WALL,PATH,PATH,WALL,WALL,PATH},
		{PATH,PATH,PATH,PATH,PATH,PATH,PATH,PATH}};

static const BlockType map2[WIDTH][HEIGHT] = {
		{WALL,WALL,PATH,PATH,PATH,PATH,WALL,WALL},
		{WALL,PATH,PATH,WALL,WALL,PATH,PATH,WALL},
		{PATH,PATH,PATH,PATH,PATH,WALL,PATH,PATH},
		{PATH,WALL,PATH,WALL,PATH,PATH,WALL,PATH},
		{PATH,WALL,PATH,PATH,WALL,PATH,WALL,PATH},
		{PATH,PATH,WALL,PATH,PATH,PATH,PATH,PATH},
		{WALL,PATH,PATH,WALL,WALL,PATH,PATH,WALL},
		{WALL,WALL,PATH,PATH,PATH,PATH,WALL,WALL}};


#define BLANK   {.red=0,   	.green=0, 	.blue=0}
#define BLUE    {.red=0,   	.green=0, 	.blue=255}
#define GREEN   {.red=0,   	.green=255,	.blue=0}
#define WHITE   {.red=255,  .green=255, .blue=255}
#define PURPLE  {.red=255,  .green=0, 	.blue=255}
#define ORANGE  {.red=255, 	.green=125, .blue=50}
#define YELLOW  {.red=255, 	.green=255, .blue=0}
#define RED     {.red=255,  .green=0, 	.blue=0}

static u8 gameOver[WIDTH][HEIGHT] = {
		{1,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,1,0},
		{0,0,1,0,0,1,0,0},
		{0,0,0,1,1,0,0,0},
		{0,0,0,1,1,0,0,0},
		{0,0,1,0,0,1,0,0},
		{0,1,0,0,0,0,1,0},
		{1,0,0,0,0,0,0,1}};

#endif /* HEADERS_WORLD_H_ */

