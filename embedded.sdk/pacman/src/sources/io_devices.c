/*
 * io_devices.c
 *
 *  Created on: May 1, 2019
 *      Author: jacoboffersen
 */

/* Includes */
#include "../headers/io_devices.h"

/* Global variables */
static XAdcPs XAdcInst;      /* XADC driver instance */
static XAdcPs *XAdcInstPtr;	 /* Pointer to driver istance */

void initIoDevices(){
	XAdcPs_Config *ConfigPtr;												// Create config pointer
	XAdcInstPtr = &XAdcInst;												// Set the xadc pointer to point to the
																			// ADC instance address
	ConfigPtr = XAdcPs_LookupConfig(XADC_DEVICE_ID);						// set the config pointer to point to
																			// where the device configuration can be found
	XAdcPs_CfgInitialize(XAdcInstPtr, ConfigPtr, ConfigPtr->BaseAddress); 	// Initialize xadc
	XAdcPs_SetSequencerMode(XAdcInstPtr, XADCPS_SEQ_MODE_CONTINPASS);		// Set adc to sequencer mode

	calibrateControl();														// Calibrate joystick
}

/* Get state of button */
u32 getButton(){
	return XAdcPs_GetAdcData(XAdcInstPtr, BUTTON);
}

/* Get joystick X position */
u32 getJoystickX(){
	return XAdcPs_GetAdcData(XAdcInstPtr, XAXIS) - offsetX;
}

/* Get joystick Y position */
u32 getJoystickY(){
	return XAdcPs_GetAdcData(XAdcInstPtr, YAXIS) - offsetY;
}

/* Get potmeter position */
u32 getPotmeter(){
	return XAdcPs_GetAdcData(XAdcInstPtr, POTMETER);
}

/* Get offsets used to calibrate the joysticks to around (0,0) */
void calibrateControl(){
	offsetX = 0;
	offsetY = 0;
	offsetX = getJoystickX();
	offsetY = getJoystickY();
}
