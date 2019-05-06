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



/* Function declarations */

Difficulty getDifficulty();

u8 getEnemyAmount();

bool countDown();

#endif /* SRC_HEADERS_GAME_H_ */
