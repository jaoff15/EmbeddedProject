/*
 * control.h
 *
 *  Created on: May 1, 2019
 *      Author: jacoboffersen
 */

#ifndef SRC_HEADERS_MOVEMENT_H_
#define SRC_HEADERS_MOVEMENT_H_

/* Includes */
#include "types.h"
#include "entity_types.h"
#include "io_devices.h"
#include <math.h>

/* Defines */
#define MIN_VALUE			5000

/* Get next player move. Read the joystick position and output a new move */
Move getMovement();

/* Get the sleep time. Read the potmeter and output an amount of millisec to sleep */
u32 getSleepTime();

#endif /* SRC_HEADERS_MOVEMENT_H_ */
