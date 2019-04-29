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

/* Global variables */
World blankWorld;
World world; 	// frame buffer
World food; 	// food frame buffer


int main(void) {

	/* Set randomizer seed */
	srand(time(0));


	while(1){

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
		u8 noEnemies = 1;

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

		/* Initialize enemies and load them into the world */
		for(u8 i = 0; i < noEnemies; i++){
			initEntity(&enemy[i], ENEMY, ps[i],diff);
			loadEntity(&enemy[i], &world);

		}

		/* Print world */
		printWorld(&world);

		Move nextMove = STANDSTILL;

		bool gameover = FALSE;
		while(!gameover){

			/* Listen for next move */
			printf("Next move: \n");
			char move = getchar();
			if(move == 'd' || move == 's' || move == 'a' || move == 'w'){
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

				world = blankWorld;											// Load a blank world
				if(foodEmpty(&food)){
					initFood(&world, &food);
				}
				loadFood(&world, &food);									// Load food into the world
				moveEntity(&player, &world, &food, nextMove);				// Move the player
				loadEntity(&player, &world);								// Load the player into the world
				for(u8 i = 0; i < noEnemies; i++){							// For each active enemy
					Move move = controlEntity(&enemy[i], &world, &player);	// 	 Get next move for enemy
					moveEntity(&enemy[i], &world, &food, move);				// 	 Move enemy
					loadEntity(&enemy[i], &world);							//   Load enemy into the world
				}

				/* Check if any of the enemies has killed the player */
				for(u8 i = 0; i < noEnemies; i++){
					gameover = entityKilled(&player, &enemy[i]);
					if(gameover){
						break;
					}
				}
				printWorld(&world);											// Print world
				printf("\n");
			}
		}
		printScore();														// Print the score board
		resetScore();														// Reset the score
		printGameoverScreen();												// Print game over screen
	}
	return EXIT_SUCCESS;
}
