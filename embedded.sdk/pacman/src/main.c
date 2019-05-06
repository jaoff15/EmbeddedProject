
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

#include "platform.h"
//#include "xil_printf.h"
#include "xparameters.h"
//#include "xbram.h"
#include "xil_io.h"

#include "headers/io_devices.h"
#include "headers/pacman.h"




int main()
{
    init_platform();

    initLedMatrix();								// Initialize the LED matrix
    initIoDevices();								// Initialize the IO devices

    while(1){
		u8 enemyCount 			= getEnemyAmount(); // Get number of enemies
		Difficulty difficulty 	= getDifficulty();  // Get game difficulty

		/* Start pacman game */
		pacman(enemyCount, difficulty);				// Start game
    }
    cleanup_platform();
    return 0;
}



