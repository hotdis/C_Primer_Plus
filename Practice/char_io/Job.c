#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void show()
{
	printf("*****************************************************************\n");
	printf("\n");
	printf("Enter the number corresponding to the desired pay rate or action!\n");
	printf("\n");
	printf("*****************************************************************\n");
	printf("a) $8.75 / hr        b) $9.33 / hr\n");
	printf("c) $10.00 / hr       d) $11.20 / hr\n");
	printf("q) Quit\n");
}

char badLimits(int *i)
{
	int ch = 0;
	int chBlank = 0;
	
	if (*i > 0)
	{
		chBlank = getchar();
	}

	ch = getchar();
	
	while (ch != 'a'&&ch != 'b'&&ch != 'c'&&ch != 'd'&&ch != 'q')
	{
		while (getchar() != '\n')
		{
			continue;
		}
		printf("Please enter a,b,c,d or q.\n");
		ch = getchar();
		
	}
	return ch;
}

void Opretion(double salary)
{
	double Time = 0;
	double TotalWage = 0;
	double tax = 0;
	printf("Working hours:\n");
	while (1 != scanf("%lf", &Time) || Time<=0)
	{
		printf("Please enter an integer:\n");
	}
	if (Time > 40)
	{
		Time *= 1.5;
	}
	TotalWage = Time * salary;
	if (TotalWage <= 300)
	{
		tax = TotalWage * 0.15;
	}
	else if (TotalWage <= 450 || TotalWage > 300)
	{
		tax = 45 + (TotalWage - 300)*0.2;
	}
	else
	{
		tax = 45 + 30 + (TotalWage - 450)*0.25;
	}
	printf("Total wage : %lf\n", TotalWage);
	printf("Tax : %lf\n", tax);
	printf("Net income : %lf\n", TotalWage - tax);
	printf("Enter another choice.\n");
}

void getChoice(int *flag,int *i)
{
	char ch;
	printf("Enter your choice.\n");
	ch = badLimits(i);
	switch (ch)
	{
	case 'a':
		Opretion(8.75);
		break;
	case 'b':
		Opretion(9.33);
		break;
	case 'c':
		Opretion(10.00);
		break;
	case 'd':
		Opretion(11.20);
		break;
	default:
		*flag = 0;
		break;
	}
}

int main()
{
	int flag = 1;
	int i = 0;
	
	while (flag)
	{
		show();
		getChoice(&flag,&i);
		i++;
	}

	printf("Done!\n");

	system("pause");
	return 0;
}