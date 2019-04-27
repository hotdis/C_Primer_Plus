#include<stdio.h>
#include<stdlib.h>

void copySomeElement(double *source,double *target, int n)
{
	for (int i = 0; i < n; i++)
	{
		target[i] = source[i];
	}
}

int main()
{
	double source[7] = { 1,2,3,4,5,6,7 };
	double target[3];

	copySomeElement(source + 2, target, 3);

	for (int i = 0; i < 3; i++)
	{
		printf(" *%lf", target[i]);
	}

	system("pause");
	return 0;
}