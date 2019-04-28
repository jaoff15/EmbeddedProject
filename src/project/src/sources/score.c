/*
 * score.c
 *
 *  Created on: Apr 27, 2019
 *      Author: Jacob Offersen
 */

#include "../headers/score.h"

void incrementScore(){
	score++;
}


void resetScore(){
	score = 0;
}

void setHighscore(){
	highscore = score;
}

void resetHighscore(){
	highscore = 0;
}


u16 getScore(){
	return score;
}
u16 getHighscore(){
	return highscore;
}
