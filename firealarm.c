#include "global.h"
 

int main(void)
{
	FireAlarmInit();	//All Initialisation

	//Welcome Message
	LcdString("Sn Alarm System",1);
	LcdString(" Welcomes You",2);
	_delay_ms(1000);

	//Zone Configuration
	ZoneConfigure();
	
	while(1)	//superloop
	{
		AdcCheck();
		AlarmUpdate(); 
		SwitchProcess();
		
	}
}
