#include "global.h"

GlobalVar GV;

void FireAlarmInit()
{
	UC ucmIndex = 0;
	LcdInit();
	AdcInit();
	ALARM_PORT_DIR = 0x0F;
	LED_PORT_DIR = OUTPUT_PORT;
	LED_PORT = LED_PORT | LED_POWER;
	GV.ucmZoneIndex= 0;
	while(ucmIndex LT MAX_ZONE)
	{
		GV.ucmZoneVar[ucmIndex].ucmZoneCheck = ZONE_CHECK_ENABLE;
		ucmIndex++;
	}
	//Disable Interrupts
}
