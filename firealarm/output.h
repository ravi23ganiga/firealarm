
#ifndef __OUTPUT_FEATURE__
#define __OUTPUT_FEATURE__

//macros declaration

#define MAX_ZONE 4

//output function prototypes


void AlarmUpdate();

//output structure

typedef struct
{
	UC ucmLedError;
	UC ucmAlarmZone[MAX_ZONE];
}OutputStruct;

#endif /* __OUTPUT_FEATURE__ */
