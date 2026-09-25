#include<stdio.h>
#include "body_ecu.h"

static int driver_door_open=0;
static int headlights_on=0;
static int indicator_on=0;

void body_init(void)
{
	driver_door_open=0;
	headlights_on=9;
	indicator_on=0;

	printf("[Body Ecu] Initialized\n");
}
void body_update(void)
{
	if(driver_door_open)
	{
		headlights_on=0;
	}
	else
	{
		headlights_on=1;
	}
}
void body_print_status(void)
{
	printf("Body Ecu\n");
	printf("Driver Door: %s\n", driver_door_open? "OPEN" : "CLOSED");
	printf("Headlights: %s\n", headlights_on? "ON" : "OFF");
	printf("Indicator: %s\n", indicator_on? "ON" : "OFF");
}
