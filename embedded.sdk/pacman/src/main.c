
#include <stdio.h>
#include <stdlib.h>

#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xbram.h"
#include "xil_io.h"
#include <string.h>


/* Pacman */
#include "headers/entity.h"
#include "headers/world.h"
#include "headers/food.h"
#include "headers/score.h"
#include "headers/time.h"
#include "headers/led_matrix.h"

//void render(u8 x, u8 y, u8 r, u8 g, u8 b);
//void clearMemory();
void pacman();


int main()
{
    init_platform();

    initLedMatrix();
    pacman();

    cleanup_platform();
    return 0;
}


void pacman(){
	printf("Start: \n");
	World blankWorld;
	World world; 	// frame buffer
	World food; 	// food frame buffer


	/* Set randomizer seed */
	srand(1);

	while(1){

		/* Setup game*/
		/* Create world */
		loadMap(&world, MAP1);

		/* Make a copy of the world */
		blankWorld = world;

//		/* Place initial food */
//		initFood(&world, &food);
//
//		/* Copy food to world */
//		loadFood(&world, &food);


		/* Get number of enemies */
		u8 noEnemies = MAX_ENEMIES;

		/* Set enemy difficulty */
		Difficulty difficulty = HARD;

		/* List of entities */
		Entities entities;
		initEntities(&entities);

		/* Create player */
		Entity player;
		Pos pos = {.x=3, .y=2};
		initEntity(&player,PLAYER,pos,NO, YELLOW);
		registerEntity(&entities, &player);

		/* Copy entity to world */
//		loadEntity(&player, &world);

		/* Create list Enemy */
		Entity enemy[MAX_ENEMIES];
		Pos ps[MAX_ENEMIES] = { {.x=0,.y=0},
								{.x=7,.y=0},
								{.x=0,.y=7},
								{.x=7,.y=7}};

		Color cols[MAX_ENEMIES] = {RED, PINK, BLUE, ORANGE};

		/* Initialize enemies and load them into the world */
		for(u8 i = 0; i < noEnemies; i++){
			initEntity(&enemy[i], ENEMY, ps[i],difficulty, cols[i]);
			registerEntity(&entities, &enemy[i]);
//			loadEntity(&enemy[i], &world);
		}

		/* Print world */
//		printWorld(&world);
//		renderWorld(&world,&entities);

		/* Enter first move */
		Move nextMove = STANDSTILL;

		/* Initialize the game state */
		bool gameover = FALSE;

		while(!gameover){
			char move = STANDSTILL;

			/* Check for next move */
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

			/* Load world */
			world = blankWorld;											// Load a blank world

			/* Load food */
			if(foodEmpty(&food)){										// If world is empty
				initFood(&world, &food);								// Create more food
			}
			loadFood(&world, &food);									// Load food into the world

			/* Load player */
			moveEntity(&player, &world, &food, nextMove);				// Move the player
			loadEntity(&player, &world);								// Load the player into the world

			/* Load enemies */
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
			/* Render world */
//			printWorld(&world);											// Print world
			renderWorld(&world,&entities);
			usleep(SLEEP_500ms);
		}
		printScore();														// Print the score board
		resetScore();														// Reset the score
		printGameoverScreen();												// Print game over screen
	}
}

