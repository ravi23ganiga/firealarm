
#ifndef __GLOBAL_FEATURE__
#define __GLOBAL_FEATURE__

//required header files

#include <avr/io.h>
#include <util/delay.h>
#include "general/typedef.h"
#include "firealarm/init.h"
#include "firealarm/lcd.h"
#include "firealarm/adc.h"
#include "firealarm/zone.h"
#include "firealarm/output.h"
#include "firealarm/switch.h"

//required macros

#define EQ ==
#define GT >
#define LT <

#define INITIAL_VALUE 0

#define FIRE_THRESHOLD 		150
#define HEAT_THRESHOLD		150
#define MAX_ZONE			4

#define ZONE_UPDATE 		1
#define ZONE_NO_UPDATE 		0
#define ZONE_CHECK_ENABLE	1
#define ZONE_CHECK_DISABLE	0

#define ALARM_PORT_DIR 		DDRC
#define ALARM_PORT 			PORTC
#define ALARM_PORT_INPUT	PINC
#define ALARM_ZONE_1	(1 << 0)
#define ALARM_ZONE_2	(1 << 1)
#define ALARM_ZONE_3	(1 << 2)
#define ALARM_ZONE_4	(1 << 3)
#define LED_PORT_DIR	DDRB
#define LED_PORT		PORTB
#define LED_ERROR		(1 << 0)
#define LED_POWER 		(1 << 1)


//Global Structure

typedef struct
{ 
	ZoneStruct ucmZoneVar[4];
	UC ucmZoneIndex;
	UC ucmSelectedZone;
	LcdStruct ucmLcdVar;
	AdcStruct ucmAdcVar; 
	OutputStruct output;
}GlobalVar;



//extern declaration

extern GlobalVar GV;

#endif /* __GLOBAL_FEATURE__ */
