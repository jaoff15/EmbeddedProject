/*
 * io_devices.c
 *
 *  Created on: May 1, 2019
 *      Author: jacoboffersen
 */


#include "../headers/io_devices.h"

static XAdcPs XAdcInst;      /* XADC driver instance */


static XAdcPs *XAdcInstPtr;

void initIoDevices(){
	XAdcPs_Config *ConfigPtr;

	XAdcInstPtr = &XAdcInst;

	ConfigPtr = XAdcPs_LookupConfig(XADC_DEVICE_ID);

	XAdcPs_CfgInitialize(XAdcInstPtr, ConfigPtr, ConfigPtr->BaseAddress);

	XAdcPs_SetSequencerMode(XAdcInstPtr, XADCPS_SEQ_MODE_CONTINPASS);

	void calibrateControl();
}

u32 getButton(){
	return XAdcPs_GetAdcData(XAdcInstPtr, BUTTON);
}

u32 getJoystickX(){
	return XAdcPs_GetAdcData(XAdcInstPtr, XAXIS);
}

u32 getJoystickY(){
	return XAdcPs_GetAdcData(XAdcInstPtr, YAXIS);
}

u32 getPotmeter(){
	return XAdcPs_GetAdcData(XAdcInstPtr, POTMETER);
}
