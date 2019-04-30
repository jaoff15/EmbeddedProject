
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

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



//
//// Function to reset memory
//void clearMemory(){
//	for(u8 col = 0; col < 8; col++){
//		for(u8 row = 0; row < 8; row++){
//			render(col, row, 0, 0, 0);
//		}
//	}
//}
//
//
//// Function to render a pixel to the display
//void render(u8 x, u8 y, u8 r, u8 g, u8 b){
//	u32 Addr = XPAR_BRAM_0_BASEADDR + x*4 + y*32;
//	u32 value = 0x00000000;
//	value +=(r << 16);
//	value +=(g << 8);
//	value +=(b);
//	Xil_Out32(Addr, value);
//}










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

		/* Place initial food */
		initFood(&world, &food);

		/* Copy food to world */
		loadFood(&world, &food);


		/* Get number of enemies */
		u8 noEnemies = 1;

		/* Set enemy difficulty */
		Difficulty diff = HARD;

		/* Create player */
		Entity player;
		Pos pos = {.x=4, .y=7};
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
//		printWorld(&world);
		renderWorld(&world);

		Move nextMove = STANDSTILL;

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
//			printWorld(&world);											// Print world
			renderWorld(&world);
			usleep(SLEEP_500ms);
		}
		printScore();														// Print the score board
		resetScore();														// Reset the score
		printGameoverScreen();												// Print game over screen
	}
}

