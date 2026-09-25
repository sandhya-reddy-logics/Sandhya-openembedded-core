#include<stdio.h>
#include "engine_ecu.h"


static int engine_rpm=0; //using static because these should available with in this file only so I used static here
static int engine_temperature=0;
static int engine_running=0;

void engine_init(void)
{
	engine_rpm=800;
	engine_temperature=90;
	engine_running=1;
	printf("[ENGINE ECU] Initialized\n");
}
void engine_update(void)
{
	if(engine_running)
	{
		engine_rpm=+100;
		if(engine_rpm>3000)
		engine_rpm=1500;
	}
}
void engine_print_status(void)
{
	printf("Engine Ecu Status\n");
	printf("RPM=%d\n",engine_rpm);
	printf("Temperature=%d C\n",engine_temperature);
	printf("Status=%s\n",engine_running ? "Running" : "Stopped");

}
