/*
 * score.c
 *
 *  Created on: Apr 27, 2019
 *      Author: Jacob Offersen
 */

/* Includes */
#include "../headers/score.h"

/* Increment the player score */
void incrementScore(){
	score++;
}

/* Reset the player score */
void resetScore(){
	score = 0;
}

/* Set the highscore */
void setHighscore(ui16 score_){
	highscore = score_;
}

/* Reset the highscore */
void resetHighscore(){
	highscore = 0;
}

/* Get the current player score */
ui16 getScore(){
	return score;
}

/* Get the current highscore */
ui16 getHighscore(){
	return highscore;
}

/* Print the score in a pretty way */
void printScore(){
	if(score > highscore){
		setHighscore(score);
		printf("New highscore!\nscore: %d\n", getScore());
	}else{
		printf("Score: %d\nHighscore: %d\n",getScore(), getHighscore());
	}

}
