/*
 * control.c
 *
 *  Created on: May 1, 2019
 *      Author: jacoboffersen
 */


#include "../headers/movement.h"

void calibrateControl(){
	offsetX = getJoystickX();
	offsetY = getJoystickY();
}

Move getMovement(){
	Move move = STANDSTILL;
	// Get and normalize x and y positions
	s32 x = getJoystickX() - offsetX;
	s32 y = getJoystickY() - offsetY;


	// Up
	if(y < -MIN_VALUE && y < abs(x)){
		move = UP;
	}
	// Down
	else if(y > MIN_VALUE && y > abs(x)){
		move = DOWN;
	}
	// Left
	else if(x > MIN_VALUE && x > abs(y)){
		move = LEFT;
	}
	// Right
	else if(x < -MIN_VALUE && x < abs(y)){
		move = RIGHT;
	}

	return move;
}

u32 getSleepTime(){
	return (u32)(getPotmeter()/655)*10000+100000;			// 100ms -> 1100ms
}
