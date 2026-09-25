#include<stdio.h>
#include "hvac_ecu.h"

static int cabin_temperature=28;
static int set_temperature=22;
static int ac_on=0;

void hvac_init(void)
{
	cabin_temperature=28;
	set_temperature=22;
	ac_on=0;
	printf("[HVAC ECU] Initialized\n");
}
void hvac_update(void)
{
	if(cabin_temperature>set_temperature)
	{
		ac_on=1;
		cabin_temperature--;
		if(cabin_temperature<=set_temperature)
		{
			cabin_temperature=set_temperature;
			ac_on=0;
		}
	}
	else
	{
		ac_on=0;
	}
}
void hvac_print_status(void)
{
	printf("HVAC ECU\n");
	printf("Cabin Temperature : %d C\n", cabin_temperature);
	printf("Set Temperature : %d C\n", set_temperature);
	printf("AC Status : %s\n",ac_on? "ON" : "OFF");
}
