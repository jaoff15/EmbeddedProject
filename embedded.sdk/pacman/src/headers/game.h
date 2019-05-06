/*
 * game.h
 *
 *  Created on: May 6, 2019
 *      Author: jacoboffersen
 */

#ifndef SRC_HEADERS_GAME_H_
#define SRC_HEADERS_GAME_H_

/* Includes */
#include "types.h"
#include "entity.h"
#include <sleep.h>
#include "time.h"


/* Function declarations */
/* Listen to uart and read out inputtet difficulty */
Difficulty getDifficulty();

/* Listen to uart and read out amount of enemies */
u8 getEnemyAmount();

/* Make a countdown before the game starts. Counts down for 3 sec */
bool countDown();

#endif /* SRC_HEADERS_GAME_H_ */
