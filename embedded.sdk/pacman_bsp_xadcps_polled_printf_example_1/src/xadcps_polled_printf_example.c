

#include "xparameters.h"
#include "xadcps.h"
#include "xstatus.h"
#include "stdio.h"
#include "xil_printf.h"
#include "sleep.h"


#define XADC_DEVICE_ID 		XPAR_XADCPS_0_DEVICE_ID
#define CH_6   XADCPS_CH_AUX_MIN + 6  // 22
#define CH_7   XADCPS_CH_AUX_MIN + 7  // 23
#define CH_14  XADCPS_CH_AUX_MIN + 14 // 30
#define CH_15  XADCPS_CH_AUX_MIN + 15 // 31



#define MS_100  100000

/**************************** Type Definitions ******************************/


/***************** Macros (Inline Functions) Definitions ********************/

#define printf xil_printf /* Small foot-print printf function */

/************************** Function Prototypes *****************************/

static int XAdcPolledPrintfExample(u16 XAdcDeviceId);

/************************** Variable Definitions ****************************/

static XAdcPs XAdcInst;      /* XADC driver instance */


int main(void)
{

	int Status;

	/*
	 * Run the polled example, specify the Device ID that is
	 * generated in xparameters.h.
	 */
	Status = XAdcPolledPrintfExample(XADC_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		xil_printf("adcps polled printf Example Failed\r\n");
		return XST_FAILURE;
	}
	xil_printf("Successfully ran adcps polled printf Example\r\n");
	return XST_SUCCESS;
}


int XAdcPolledPrintfExample(u16 XAdcDeviceId)
{
	int Status;
	XAdcPs_Config *ConfigPtr;


	XAdcPs *XAdcInstPtr = &XAdcInst;

	printf("\r\nEntering the XAdc Polled Example. \r\n");

	/*
	 * Initialize the XAdc driver.
	 */
	ConfigPtr = XAdcPs_LookupConfig(XAdcDeviceId);
	if (ConfigPtr == NULL) {
		return XST_FAILURE;
	}
	XAdcPs_CfgInitialize(XAdcInstPtr, ConfigPtr, ConfigPtr->BaseAddress);

	/*
	 * Self Test the XADC/ADC device
	 */
	Status = XAdcPs_SelfTest(XAdcInstPtr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}


	XAdcPs_SetSequencerMode(XAdcInstPtr, XADCPS_SEQ_MODE_CONTINPASS);


	u32 counter = 0;
	u16 rawData;


	while(1){
		printf("counter  %4lu\r\n",(unsigned int)(counter++));

		rawData = XAdcPs_GetAdcData(XAdcInstPtr, CH_6);
		printf("CH6 \t %4u\r\n",(unsigned int)(rawData));

		rawData = XAdcPs_GetAdcData(XAdcInstPtr, CH_7);
		printf("CH7 \t %4u\r\n",(unsigned int)(rawData));

		rawData = XAdcPs_GetAdcData(XAdcInstPtr, CH_14);
		printf("CH14 \t %4u\r\n",(unsigned int)(rawData));

		rawData = XAdcPs_GetAdcData(XAdcInstPtr, CH_15);
		printf("CH15 \t %4u\r\n",(unsigned int)(rawData));

		usleep(MS_100);
	}


	printf("Exiting the XAdc Polled Example. \r\n");

	return XST_SUCCESS;
}

