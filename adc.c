#include "global.h"

void AdcInit()
{
	ADMUX = 0b01100000;
	ADCSRA = 0b10000100;
}
void AdcStart(UC ucvAdcNo)
{
	ADMUX = 0x60 | ucvAdcNo;
	ADCSRA |= 1 << ADSC; 
 }

void AdcCheck()
{
	switch(GV.ucmAdcVar.ucmAdcState)
	{
		case ADC_START_CASE://0
			if(GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneCheck EQ ZONE_CHECK_ENABLE)
			{
				AdcStart(2 * GV.ucmZoneIndex); 
				GV.ucmAdcVar.ucmAdcState++;
			}
			else
			{
				GV.ucmAdcVar.ucmAdcState++;
			}
			break;
		
		case ADC_CHECK_CASE: //1
			if(GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneCheck EQ ZONE_CHECK_ENABLE)
			{
				if(ADCSRA & (1 << ADIF))
				{
					ADCSRA |= 1 << ADIF;
					GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneValue = ADCH;
					if(GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneValue GT FIRE_THRESHOLD)
					{
						AdcZoneDangerCheck();
						//GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneUpdate = ZONE_UPDATE;
					} 
					GV.ucmZoneIndex++;
 					if(GV.ucmZoneIndex EQ MAX_ZONE)
  					{
	 					GV.ucmZoneIndex = 0;
	 				}		
				    GV.ucmAdcVar.ucmAdcState++;
				}
			}
			else
			{ 
 				GV.ucmZoneIndex++;
 				if(GV.ucmZoneIndex EQ MAX_ZONE)
  				{
	 				GV.ucmZoneIndex = 0;
	 			}
				GV.ucmAdcVar.ucmAdcState++;
			}

			break;

 		default:
			GV.ucmAdcVar.ucmAdcState = 0;
			break;
	}
}

void AdcZoneDangerCheck()
{
 	AdcStart((2 * GV.ucmZoneIndex) + 1);
 	while(!(ADCSRA & (1 << ADIF))) ;
  	ADCSRA |= 1 << ADIF;
	GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneValue = ADCH;
 	if(GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneValue GT HEAT_THRESHOLD)
 	{
 		//AdcZoneDangerCheck();
 		GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneUpdate = ZONE_UPDATE;
		GV.output.ucmAlarmZone[GV.ucmZoneIndex] = 1; 
		GV.output.ucmLedError = 1;
 	} 	 
	else
	{
		GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneUpdate = ZONE_NO_UPDATE; 
		GV.output.ucmAlarmZone[GV.ucmZoneIndex] = 0;
		GV.output.ucmLedError = 0;
	}
}
