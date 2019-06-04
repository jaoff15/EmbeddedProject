/*
 * pacman.c
 *
 *  Created on: May 6, 2019
 *      Author: jacoboffersen
 */

/* Includes */
#include "../headers/pacman.h"

void pacman(u8 enemyCount, Difficulty difficulty){
	World world; 		// Frame buffer
	World blankWorld;	// Copy of world
	World food; 		// Food frame buffer

	/* Set randomizer seed */
	srand(getJoystickX() + getJoystickY() + getPotmeter());

	/* Initialize the game states */
	bool gameStarted = FALSE;											// Mark game as not started yet (used by countdown function)
	bool gameover = FALSE;												// Mark game as not lost

	while(!gameover){

		/* Setup game*/
		/* Create world */
		loadMap(&world);											// Load map into world

		/* Make a copy of the world */
		blankWorld = world;

		/* List of entities */
		Entities entities;
		initEntities(&entities);										// Initialize entity list

		/* Create player */
		Entity player;
		Pos pos = {.x=3, .y=2};											// Set player start location
		initEntity(&player,PLAYER,pos,NO, YELLOW);						// Initialize player entity
		registerEntity(&entities, &player);								// Register player to the entity list


		/* Create list Enemy */
		Entity enemy[MAX_ENEMIES];
		Pos ps[MAX_ENEMIES] = { {.x=0,.y=0},							// Initialize enemy start locations
								{.x=7,.y=0},
								{.x=0,.y=7},
								{.x=7,.y=7}};

		Color cols[MAX_ENEMIES] = {RED, PINK, BLUE, ORANGE};			// Define the 4 enemy colors

		/* Initialize enemies and load them into the world */
		for(u8 i = 0; i < enemyCount; i++){								// For each active enemy
			initEntity(&enemy[i], ENEMY, ps[i],difficulty, cols[i]);	// Initialize enemy entity
			registerEntity(&entities, &enemy[i]);						// Register enemy to the entity list
		}


		Move nextMove = STANDSTILL;										// Define variable to hold player movements

		while(!gameover){
			nextMove = getMovement();									// Read next player movement

			/* Load world */
			world = blankWorld;											// Load a blank world

			/* Load food */
			if(foodEmpty(&food)){										// If world is empty
				initFood(&world, &food);								// Create more food
			}
			loadFood(&world, &food);									// Load food into the world

			/* Load player */
			if(gameStarted){
				moveEntity(&player, &world, &food, nextMove);				// Move the player
			}
			loadEntity(&player, &world);								// Load the player into the world

			/* Load enemies */
			for(u8 i = 0; i < enemyCount; i++){							// For each active enemy
				Move move = controlEntity(&enemy[i], &world, &player);	// 	 Get next move for enemy
				if(gameStarted){
					moveEntity(&enemy[i], &world, &food, move);				// 	 Move enemy
				}
				loadEntity(&enemy[i], &world);							//   Load enemy into the world
			}

			/* Check if any of the enemies has killed the player */
			for(u8 i = 0; i < enemyCount; i++){							// For each active enemy
				gameover = entityKilled(&player, &enemy[i]);			// Check if they killed the player
				if(gameover){											// If so break the for loop
					clearFood(&food);
					break;
				}
			}
			renderWorld(&world,&entities);								// Render the world to the led matrix

			if(!gameStarted){											// If the game just started
				gameStarted = countDown();								// Do a 3 sec countdown
			}
			usleep(getSleepTime());										// Sleep until next game tick

		}
		printScore();													// Print the score board
		resetScore();													// Reset the score
	}

	renderGameoverScreen();												// Print gameover screen

}
