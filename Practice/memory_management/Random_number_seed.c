#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void get_random();
void count_num(int);

static int count0;
static int count1;
static int count2;
static int count3;
static int count4;
static int count5;
static int count6; 
static int count7;
static int count8;
static int count9;

int main()
{
	srand((unsigned int)time(0));


	get_random();

	printf("0 : %d\n", count0);
	printf("1 : %d\n", count1);
	printf("2 : %d\n", count2);
	printf("3 : %d\n", count3);
	printf("4 : %d\n", count4);
	printf("5 : %d\n", count5);
	printf("6 : %d\n", count6);
	printf("7 : %d\n", count7);
	printf("8 : %d\n", count8);
	printf("9 : %d\n", count9);
	printf("===================\n");

	system("pause");
	return 0;
}

void get_random()
{

	for (int i = 0; i < 1000; i++)
	{
		count_num(rand() % 10);
	}
}

void count_num(int num)
{
	switch (num)
	{
	case 0:
		count0++;
		break;

	case 1:
		count1++;
		break;

	case 2:
		count2++;
		break;

	case 3:
		count3++;
		break;

	case 4:
		count4++;
		break;

	case 5:
		count5++;
		break;

	case 6:
		count6++;
		break;

	case 7:
		count7++;
		break;

	case 8:
		count8++;
		break;

	case 9:
		count9++;
		break;
	}
}

