/*
 * game.c
 *
 *  Created on: May 6, 2019
 *      Author: jacoboffersen
 */

/* Includes */
#include "../headers/game.h"

/* Listen to uart and read out inputtet difficulty */
Difficulty getDifficulty(){
	printf( "Enter difficulty (1 = easy, 2 = hard): ");
	Difficulty difficulty = NO;
	while(difficulty == NO){
		char input = getchar( );
		switch(input){
		case '1':
			difficulty = EASY;
			break;
		case '2':
			difficulty = HARD;
			break;
		default:
			difficulty = NO;
		}
	}
	return difficulty;
}


/* Listen to uart and read out amount of enemies */
u8 getEnemyAmount(){
	printf("Enter amount of enemies (1-4):");
	u8 enemies = 0;
	while(enemies == 0){
		char input = getchar( );
		switch(input){
			case '1':
				enemies = 1;
				break;
			case '2':
				enemies = 2;
				break;
			case '3':
				enemies = 3;
				break;
			case '4':
				enemies = 4;
				break;
			default:
				enemies = 0;
		}
	}
	return enemies;
}

/* Make a countdown before the game starts. Counts down for 3 sec */
bool countDown(){
	for(u8 i = 3; i >= 1; i--){
		printf("%i\n",(int)i);
		usleep(SLEEP_1s);
	}
	printf("GO!\n");
	return TRUE;
}
