#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"pe12-2a.h"

static int mode;
static int distance;
static double fuel;
static double consumption;

void setmode(int st)
{
	if (st == 0)
	{
		mode = 0;
	}

	if (st == 1)
	{
		mode = 1;
	}

}

void get_info()
{
	printf("Enter the distance oftraveled in kilometers : ");
	while (1 != scanf("%d", &distance))
	{
		printf("Enter error,try again : ");
	}

	if (mode == 0)
	{
		printf("Enter fuel consumed in liters : ");
		scanf("%lf", &fuel);
	}

	if (mode == 1)
	{
		printf("Enter fuel consumed in gallons : ");
		scanf("%lf", &fuel);
	}
}

void show_info()
{
	if (mode == 0)
	{
		consumption = fuel * distance * 0.1;
		printf("Fuel consumption is %lf liters per 100 km.\n", consumption);
	}

	if (mode == 1)
	{
		consumption = fuel * distance * 0.2;
		printf("Fuel consumption is %lf gallons per 100 km.\n", consumption);
	}
}