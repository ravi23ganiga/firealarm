#include "global.h"

void SwitchProcess()
{
	UC ucmTemp;
 	
	ucmTemp = ALARM_PORT_INPUT;
	if(!(ucmTemp & SWITCH_ZONE_SELECT))
	{ 
		while(!(ucmTemp & SWITCH_ZONE_SELECT))
		{
			ucmTemp = ALARM_PORT_INPUT;
		}
		GV.ucmSelectedZone++;
		if(GV.ucmSelectedZone EQ MAX_ZONE)
		{
			GV.ucmSelectedZone = 0;
		}
	}

	ucmTemp = ALARM_PORT_INPUT;
	if(!(ucmTemp & SWITCH_ALARM))
	{ 
		while(!(ucmTemp & SWITCH_ALARM))
		{
			ucmTemp = ALARM_PORT_INPUT;
		}
		GV.output.ucmAlarmZone[GV.ucmSelectedZone] = !GV.output.ucmAlarmZone[GV.ucmSelectedZone];
	} 
 	
	ucmTemp = ALARM_PORT_INPUT;
	if(!(ucmTemp & SWITCH_ZONE))
	{ 
		while(!(ucmTemp & SWITCH_ZONE))
		{
			ucmTemp = ALARM_PORT_INPUT;
		}
		GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneCheck =  !GV.ucmZoneVar[GV.ucmZoneIndex].ucmZoneCheck;
		GV.output.ucmAlarmZone[GV.ucmSelectedZone] = 0;
	} 
	
}
