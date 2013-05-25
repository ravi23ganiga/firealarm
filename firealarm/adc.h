
#ifndef __ADC_FEATURE__
#define __ADC_FEATURE__

//Macro Definition
#define ADC_START_CASE 	0
#define ADC_CHECK_CASE 	1

//ADC Function Prototype

void AdcInit();
void AdcStart(UC ucvAdcNo);
void AdcCheck();
void AdcZoneDangerCheck();

//LCD Structure

typedef struct
{
	UC ucmAdcState;
}AdcStruct;

#endif /* __ADC_FEATURE__ */
