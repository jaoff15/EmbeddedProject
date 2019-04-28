/*
 * score.h
 *
 *  Created on: Apr 27, 2019
 *      Author: Jacob Offersen
 */

#ifndef HEADERS_SCORE_H_
#define HEADERS_SCORE_H_

#include "types.h"
#include "entity.h"

static u16 score = 0;
static u16 highscore = 0;

void incrementScore();
void resetScore();
void setHighscore();
void resetHighscore();

u16 getScore();
u16 getHighscore();




#endif /* HEADERS_SCORE_H_ */
