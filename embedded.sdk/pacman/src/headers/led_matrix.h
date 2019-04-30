/*
 * led_matrix.h
 *
 *  Created on: Apr 2, 2019
 *      Author: jacoboffersen
 */

#ifndef SRC_LED_MATRIX_H_
#define SRC_LED_MATRIX_H_

/* Includes */
#include "xparameters.h"
#include "xbram.h"
#include "xil_io.h"
#include "types.h"
#include "entity.h"

/* Defines */
#define COLOR_COUNT 3
#define R 0
#define G 1
#define B 2

#define FULL_ON  	102		//255*40% = 102
#define HALF_ON		FULL_ON/2
#define FULL_OFF	0

// 3-dimentional array that contains the three different colors
static u8 matrix[WIDTH][HEIGHT][COLOR_COUNT];


/* Can hold an RGB color */
typedef struct s_Color{
	ui8 r;
	ui8 g;
	ui8 b;
} Color;



// Color definitions
static const Color RED    	= {.r = FULL_ON, 	.g = FULL_OFF,  .b = FULL_OFF};
static const Color GREEN  	= {.r = FULL_OFF,   .g = FULL_ON, 	.b = FULL_OFF};
static const Color BLUE 	= {.r = FULL_OFF,   .g = FULL_OFF,  .b = FULL_ON};
static const Color YELLOW 	= {.r = FULL_ON, 	.g = FULL_ON, 	.b = FULL_OFF};
static const Color ORANGE 	= {.r = FULL_ON, 	.g = HALF_ON, 	.b = FULL_OFF};
static const Color PURPLE 	= {.r = FULL_ON, 	.g = FULL_OFF,  .b = FULL_ON};
static const Color WHITE  	= {.r = FULL_ON, 	.g = FULL_ON, 	.b = FULL_ON};
static const Color BLANK 	= {.r = FULL_OFF,   .g = FULL_OFF,  .b = FULL_OFF};

// Initialize the LED matrix
void initLedMatrix();

// Function to reset memory
void resetAllPixels();

// Writes r, g and b colors to the specified x,y pixel
void setPixelValue(u8 x, u8 y, u8 r, u8 g, u8 b);

// Write the col specified by the col struct to the position specified
void setPixel(Pos pos, Color col);
void getPixel(Pos pos, Color *col);

// Decrement specified pixel
void decrementPixel(Pos pos);

// Writes the specified pixel to the device
void writePixelToDevice(Pos pos);

// Writes all pixel values to the device
void writeAllPixelToDevice();

// Write pixel value to the LED matrix
void ledMatrixOut(u32 addr, u32 data);


#endif /* SRC_LED_MATRIX_H_ */
