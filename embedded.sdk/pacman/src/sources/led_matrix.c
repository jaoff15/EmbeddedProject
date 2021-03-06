/*
 * led_matrix.c
 *
 *  Created on: Apr 2, 2019
 *      Author: jacoboffersen
 */

/* Includes */
#include "../headers/led_matrix.h"


// Initialize the LED matrix
void initLedMatrix(){
	resetAllPixels();
	writeAllPixelToDevice();
}

// Function to reset memory
void resetAllPixels(){
	for(u8 y = 0; y < HEIGHT; y++){
		for(u8 x = 0; x < WIDTH; x++){
			Pos pos = {.x=x, .y=y};
			setPixel(pos, BLANK);
		}
	}
}


// Write the col specified by the col struct to the position specified
void setPixel(Pos pos, Color col){
	matrix[pos.x][pos.y][R] = col.r;
	matrix[pos.x][pos.y][G] = col.g;
	matrix[pos.x][pos.y][B] = col.b;
}


// Writes the specified pixel to the device
void writePixelToDevice(Pos pos){
	u8 r = matrix[pos.x][pos.y][R];
	u8 g = matrix[pos.x][pos.y][G];
	u8 b = matrix[pos.x][pos.y][B];
	u32 addr = XPAR_BRAM_0_BASEADDR + pos.x*4 + pos.y*32;
	u32 value = (r << 16) + (g << 8) + b;
	ledMatrixOut(addr, value);
}

// Writes all pixel values to the device
void writeAllPixelToDevice(){
	for(u8 y = 0; y < HEIGHT; y++){
		for(u8 x = 0; x < WIDTH; x++){
			Pos pos = {.x=WIDTH-1-x, .y=y};
			writePixelToDevice(pos);
		}
	}
}

// Write pixel value to the LED matrix
void ledMatrixOut(u32 addr, u32 data){
	Xil_Out32(addr, data);
}




