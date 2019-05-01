/*
 * control.c
 *
 *  Created on: May 1, 2019
 *      Author: jacoboffersen
 */


#include "../headers/movement.h"


Move getMovement(){
	Move move = STANDSTILL;
	// Get and normalize x and y positions
	s32 x = getJoystickX() - OFFSET;
	s32 y = getJoystickY() - OFFSET;

	if(abs(x) > MIN_VALUE || abs(y) > MIN_VALUE){
		// Up
		if()

		// Down


		// Left


		// Right
		printf("x: %d, y: %d\n",x,y);
	}


	return move;
}
