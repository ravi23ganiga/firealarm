
#ifndef __ZONE_FEATURE__
#define __ZONE_FEATURE__

//zone function prototypes

void ZoneUpdate();
void ZoneConfigure();

//zone structure
typedef struct
{ 
	UC ucmZoneUpdate;
	UC ucmZoneValue;
	UC ucmZoneCheck;
}ZoneStruct;
 
#endif /* __ZONE_FEATURE__ */
