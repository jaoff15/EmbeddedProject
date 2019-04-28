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
#include "headers/score.h"
#include <time.h>

World blankWorld;
World world; 	// frame buffer
World food; 	// food frame buffer


int main(void) {

	srand(time(0));
	/* Setup game*/

	/* Create world */
	loadMap(&world, MAP1);

	/* Make a copy of the world */
	blankWorld = world;

	/* Place initial food */
	initFood(&world, &food);

	/* Copy food to world */
	loadFood(&world, &food);


	/* Get number of enemies */
	u8 noEnemies = 5;

	/* Set enemy difficulty */
	Difficulty diff = EASY;

	/* Create player */
	Entity player;
	Pos pos = {.x=7, .y=7};
	initEntity(&player,PLAYER,pos,NO);

	/* Copy entity to world */
	loadEntity(&player, &world);

	/* Create list Enemy */
	Entity enemy[MAX_ENEMIES];
	Pos ps[MAX_ENEMIES] = { {.x=0,.y=0},
							{.x=0,.y=1},
							{.x=0,.y=2},
							{.x=0,.y=3},
							{.x=0,.y=4}};

	for(u8 i = 0; i < noEnemies; i++){
		initEntity(&enemy[i], ENEMY, ps[i],diff);
		loadEntity(&enemy[i], &world);

	}


	/* Print world */
	printWorld(&world);

	Move nextMove = STANDSTILL;
	while(1){//for(u8 i = 0; i < 8; i++){
		printf("Next move: \n");
		char move = getchar();
		switch(move){
		case 'd':
			nextMove = RIGHT;
			break;
		case 'a':
			nextMove = LEFT;
			break;
		case 'w':
			nextMove = UP;
			break;
		case 's':
			nextMove = DOWN;
			break;
		default:
			nextMove = STANDSTILL;
		}
		if(nextMove != STANDSTILL){
			world = blankWorld;
			loadFood(&world, &food);
			moveEntity(&player, &world, &food, nextMove);
			loadEntity(&player, &world);
			for(u8 i = 0; i < noEnemies; i++){
				Move move = controlEntity(&enemy[i], &world, &player);
				moveEntity(&enemy[i], &world, &food, move);
				loadEntity(&enemy[i], &world);
			}
			bool gameover = entityKilled(&player, &enemy, noEnemies);
			if(gameover){
				printGameoverScreen();
			}else{
				printWorld(&world);
			}
			printf("\n");
		}


	}

	return EXIT_SUCCESS;
}
