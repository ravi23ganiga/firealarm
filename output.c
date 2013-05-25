#include "global.h"

void AlarmUpdate()
{ 
	if(GV.output.ucmLedError)
	{
		LED_PORT = LED_PORT | LED_ERROR;
	}
	else
	{
		LED_PORT = LED_PORT & (~ LED_ERROR);
	} 
	 
 	if(GV.output.ucmAlarmZone[0])
 	{
	 	ALARM_PORT = ALARM_PORT | ALARM_ZONE_1;
 	}
	else
	{
		ALARM_PORT = ALARM_PORT & (~ALARM_ZONE_1);
	}
 	if(GV.output.ucmAlarmZone[1])
 	{
	 	ALARM_PORT = ALARM_PORT | ALARM_ZONE_2;
 	}
	else
	{
		ALARM_PORT = ALARM_PORT & (~ALARM_ZONE_2);
	}
	if(GV.output.ucmAlarmZone[2])
 	{
	 	ALARM_PORT = ALARM_PORT | ALARM_ZONE_3;
 	}
	else
	{
		ALARM_PORT = ALARM_PORT & (~ALARM_ZONE_3);
	}
	if(GV.output.ucmAlarmZone[3])
 	{
	 	ALARM_PORT = ALARM_PORT | ALARM_ZONE_4;
 	}
	else
	{
		ALARM_PORT = ALARM_PORT & (~ALARM_ZONE_4);
	} 
	
}
