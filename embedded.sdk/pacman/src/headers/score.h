/*
 * score.h
 *
 *  Created on: Apr 27, 2019
 *      Author: Jacob Offersen
 */

#ifndef HEADERS_SCORE_H_
#define HEADERS_SCORE_H_

/* Includes */
#include "types.h"
#include "entity.h"

/* Global Variables */
static u16 score = 0;
static u16 highscore = 0;


/* Function declarations */

/* Increment the player score */
void incrementScore();

/* Reset the player score */
void resetScore();

/* Set the highscore */
void setHighscore(u16 score_);

/* Reset the highscore */
void resetHighscore();

/* Get the current player score */
u16 getScore();

/* Get the current highscore */
u16 getHighscore();

/* Print the score in a pretty way */
void printScore();



#endif /* HEADERS_SCORE_H_ */
