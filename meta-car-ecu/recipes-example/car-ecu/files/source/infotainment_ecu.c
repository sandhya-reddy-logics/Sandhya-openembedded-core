#include<stdio.h>
#include "infotainment_ecu.h"

static int display_on=0;
static int audio_playing=0;
static int volume=0;

void infotainment_init(void)
{
	display_on=1;
	audio_playing=1;
	volume=40;
	printf("[Infotainment Ecu] Initialized\n");
}
void infotainment_update(void)
{
	if(volume<100)
	{
		volume=5;
	}
	if(volume>100)
	{
		volume=100;
	}
}


void infotainment_print_status(void)
{
	printf("Infotainment Ecu\n");
	printf("Display : %s\n", display_on? "ON" : "OFF");
	printf("Audio : %s\n",audio_playing? "Playing" : "Stopped");
	printf("Volume : %d %%\n", volume);
}
