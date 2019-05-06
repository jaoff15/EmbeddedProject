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
#include "entity.h"
#include "io_devices.h"

/* Defines */
#define MIN_VALUE			5000
#define STANDSTILL_TOP 		40000
#define STANDSTILL_BOTTOM 	28000


/* No movement:
 * X = 33600
 * Y = 33300
 *
 * Right:
 * X = 4400
 * Y = 33300
 *
 * Left:
 * X = 60000
 * Y = 33300
 *
 * Up:
 * X = 33300
 * Y = 2500
 *
 * Down:
 * X = 33300
 * Y = 63000
 * */


Move getMovement();


u32 getSleepTime();

#endif /* SRC_HEADERS_MOVEMENT_H_ */
