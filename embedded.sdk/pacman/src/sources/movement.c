/*
 * control.c
 *
 *  Created on: May 1, 2019
 *      Author: jacoboffersen
 */


#include "../headers/movement.h"



/* Get next player move. Read the joystick position and output a new move */
Move getMovement(){
	Move move = STANDSTILL;
	// Get and normalize x and y positions
	s32 x = getJoystickX();
	s32 y = getJoystickY();


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

/* Get the sleep time. Read the potmeter and output an amount of millisec to sleep */
u32 getSleepTime(){
	return (u32)(getPotmeter()/655)*10000+100000;			// 100ms -> 1100ms
}
