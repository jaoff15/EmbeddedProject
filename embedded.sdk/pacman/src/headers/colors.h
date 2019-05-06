/*
 * colors.h
 *
 *  Created on: May 1, 2019
 *      Author: jacoboffersen
 */

#ifndef SRC_HEADERS_COLORS_H_
#define SRC_HEADERS_COLORS_H_


/* Defines */
#define COLOR_COUNT 3
#define R 0
#define G 1
#define B 2

#define FULL_ON  	102		//255*40% = 102
#define TWO_THIRDS	(102*2)/3
#define HALF_ON		FULL_ON/2
#define ONE_THIRD	FULL_ON/3
#define ONE_FIFTH	FULL_ON/5
#define ONE_TENTH   FULL_ON/10
#define FULL_OFF	0


/* Type definitions */
/* Can hold an RGB color */
typedef struct s_Color{
	u8 r;
	u8 g;
	u8 b;
} Color;


// Color definitions
static const Color BLANK 	= {.r = FULL_OFF,   .g = FULL_OFF,  .b = FULL_OFF}; // PATH

static const Color GREEN  	= {.r = FULL_OFF,   .g = FULL_ON, 	.b = FULL_OFF}; // Wall

static const Color WHITE  	= {.r = ONE_FIFTH, 	.g = ONE_FIFTH, 	.b = ONE_FIFTH};  // Food
static const Color PURPLE  	= {.r = ONE_TENTH, 	.g = FULL_OFF, 	    .b = ONE_TENTH};  // Food

/* Enemies */
static const Color RED    	= {.r = FULL_ON, 	.g = FULL_OFF,  .b = FULL_OFF};
static const Color BLUE 	= {.r = FULL_OFF,   .g = FULL_OFF,  .b = FULL_ON};
static const Color ORANGE 	= {.r = FULL_ON, 	.g = ONE_THIRD, 	.b = FULL_OFF};
static const Color PINK 	= {.r = FULL_ON, 	.g = ONE_FIFTH, .b = ONE_FIFTH};

/* Player */
static const Color YELLOW 	= {.r = FULL_ON, 	.g = FULL_ON, 	.b = FULL_OFF};


#endif /* SRC_HEADERS_COLORS_H_ */
