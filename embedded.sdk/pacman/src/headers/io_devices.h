/*
 * io_devices.h
 *
 *  Created on: May 1, 2019
 *      Author: jacoboffersen
 */

#ifndef SRC_HEADERS_IO_DEVICES_H_
#define SRC_HEADERS_IO_DEVICES_H_

/* Includes */
#include "xparameters.h"
#include "xadcps.h"
#include "xstatus.h"


/* Defines */

#define XADC_DEVICE_ID 		XPAR_XADCPS_0_DEVICE_ID

#define CH_6   XADCPS_CH_AUX_MIN + 6  // 22
#define CH_7   XADCPS_CH_AUX_MIN + 7  // 23
#define CH_14  XADCPS_CH_AUX_MIN + 14 // 30
#define CH_15  XADCPS_CH_AUX_MIN + 15 // 31

#define BUTTON 	 CH_6
#define XAXIS 	 CH_7
#define YAXIS 	 CH_14
#define POTMETER CH_15


void initIoDevices();

#endif /* SRC_HEADERS_IO_DEVICES_H_ */
