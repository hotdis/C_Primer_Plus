#include<stdio.h>
#include<stdlib.h>

void copyTwoDimensionArray(double(*source)[3],double (*target)[3], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			target[i][j] = source[i][j];
		}
	}
}


int main()
{
	double source[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	double target[3][3];

	copyTwoDimensionArray(source, target, 3);

	for (double *p = &target[0][0]; p <= &target[2][2]; p++)
	{
		printf(" *%lf", *p);
	}

	system("pause");
	return 0;
}