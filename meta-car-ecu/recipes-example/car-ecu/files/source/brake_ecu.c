#include<stdio.h>
#include "brake_ecu.h"

static int vehicle_speed=0;
static int brake_pressure=0;
static int brake_active=0;

void brake_init(void)
{
	vehicle_speed=60;
	brake_pressure=0;
	brake_active=0;
	printf("[Break Ecu] Initialized\n");
}

void brake_update(void)
{
	if(vehicle_speed>0)
	{
		vehicle_speed=-5;

		if(vehicle_speed<0)
		{
			vehicle_speed=0;
		}
	}
	if(vehicle_speed<20)
	{
		brake_active=1;
		brake_pressure=40;
	}
	else
	{
		brake_active=0;
		brake_pressure=0;
	}
}

void brake_print_status(void)
{
	printf("Brake Ecu\n");
	printf("Vehicle Speed : %d Km/h\n", vehicle_speed);
	printf("Brake Pressure : %d %%\n", brake_pressure);
	printf("Status : %s\n", brake_active? "Braking" : "Normal");
}
