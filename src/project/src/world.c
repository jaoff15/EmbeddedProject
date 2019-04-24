/*
 * world.c
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */


/* Includes */
#include "headers/world.h"

/* Variables */
static const char symbols[3] = {'O','X','F'};




enum_Block map1[WIDTH][HEIGHT] = {
		{PATH,PATH,PATH,PATH,PATH,PATH,PATH,PATH},
		{PATH,WALL,WALL,PATH,PATH,WALL,WALL,PATH},
		{PATH,WALL,PATH,PATH,PATH,PATH,WALL,PATH},
		{PATH,WALL,PATH,WALL,WALL,PATH,WALL,PATH},
		{PATH,WALL,PATH,WALL,WALL,PATH,WALL,PATH},
		{PATH,WALL,PATH,PATH,PATH,PATH,WALL,PATH},
		{PATH,WALL,WALL,PATH,PATH,WALL,WALL,PATH},
		{PATH,PATH,PATH,PATH,PATH,PATH,PATH,PATH}};

enum_Block map2[WIDTH][HEIGHT] = {
		{WALL,WALL,PATH,PATH,PATH,PATH,WALL,WALL},
		{WALL,PATH,PATH,WALL,WALL,PATH,PATH,WALL},
		{PATH,PATH,PATH,PATH,PATH,WALL,PATH,PATH},
		{PATH,WALL,PATH,WALL,PATH,PATH,WALL,PATH},
		{PATH,WALL,PATH,PATH,WALL,PATH,WALL,PATH},
		{PATH,PATH,WALL,PATH,PATH,PATH,PATH,PATH},
		{WALL,PATH,PATH,WALL,WALL,PATH,PATH,WALL},
		{WALL,WALL,PATH,PATH,PATH,PATH,WALL,WALL}};


void updateMap(){

}

/* Print out the map to the terminal */
void printWorld(enum_Block *world){
	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			enum_Block *pBlock = world+sizeof(enum_Block)*x+sizeof(enum_Block)*y*WIDTH;
			printf("%c",symbols[*pBlock]);
		}
		printf("\n");
	}
}

/* Load a predefined map to the frame buffer */
void loadMap(enum_Block *world, u8 mapIndex){
	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			u8 offset = sizeof(enum_Block)*x+sizeof(enum_Block)*y*WIDTH;
			enum_Block *pBlock = world+offset;
			switch(mapIndex){
				case 0:
					*pBlock = map1[y][x];
					break;
				case 1:
					*pBlock = map2[y][x];
					break;
				default:
					*pBlock = map1[y][x];
				}
		}
	}
}



