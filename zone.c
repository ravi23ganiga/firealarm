#include "global.h"

void ZoneConfigure()
{
	LcdClear();
	LcdString("Z1: N , Z2: N",1);
	LcdString("Z3: N , Z4: N",2);
	LED_PORT = LED_PORT & (~ LED_ERROR);  
 
}

void ZoneUpdate()
{
/*
	UC ucmIndex = 0;
	while(ucmIndex LT MAX_ZONE)
	{
		if(GV.ucmZoneVar[ucmIndex].ucmZoneUpdate  EQ ZONE_UPDATE)
		{
			ZoneAlarmOn();
			LED_PORT = LED_PORT | LED_ERROR;
			ZoneLcdUpdate();
		}
		ucmIndex++;
	}
	*/
}
