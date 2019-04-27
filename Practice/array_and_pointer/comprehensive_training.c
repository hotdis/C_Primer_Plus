#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void initializtionSource(double (*source)[5], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("�����%d�������ֵ��\n", i);
		for (int j = 0; j < 5; j++)
		{
			printf("��%d��ֵ��", j);
			scanf("%lf", &source[i][j]);
		}
	}
}

double averageEveryArray(double (*source)[5])
{
	double sum = 0;

	for (int i = 0; i < 5; i++)
	{
		sum += *(*source + i);
	}

	return sum / 5;
}

double average(double (*source)[5], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sum += source[i][j];
		}
	}
	return sum / 15;
}

double selectMax(double(*source)[5])
{
	double max = **source;
	for (double *p = &source[0][0]; p <= &source[2][4]; p++)
	{
		if (max < *p)
		{
			max = *p;
		}
	}
	return max;
}

int main()
{
	double source[3][5] = { 0 };
	
	initializtionSource(source, 3);

	for (int i = 0; i < 3; i++)
	{
		printf("��%d�������ƽ��ֵ��%lf\n", i, averageEveryArray(source + i));
	}

	double ave = average(source, 3);
	printf("����Ԫ�ص�ƽ��ֵ��%lf\n", ave);
	
	double max = selectMax(source);
	printf("Ԫ�ص����ֵ��%lf\n", max);


	system("pause");
	return 0;
}