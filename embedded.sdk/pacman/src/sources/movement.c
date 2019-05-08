/*
 * control.c
 *
 *  Created on: May 1, 2019
 *      Author: jacoboffersen
 */

/* Includes */
#include "../headers/movement.h"



/* Get next player move. Read the joystick position and output a new move */
Move getMovement(){
	Move move = STANDSTILL;
	// Get and normalize x and y positions
//	s32 x = getJoystickX();
//	s32 y = getJoystickY();
	Pos pos = getJoystickPosition();
	s16 x = pos.x;
	s16 y = pos.y;

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
	 return ((getPotmeter() / 72.8) + 100) * 1000; // 100ms -> 1000ms
}

//u32 getSleepTime(){
//	u32 raw 	= getPotmeter();		// 0 -> 65536
//	f64 scaled 	= raw / 72.8; 			// 0 -> 900
//	u32 time 	= (u32) scaled + 100;	// 100 -> 1000 [us]
//	return (u32)1000 * time;			// 100 -> 1000 [ms]
//}

