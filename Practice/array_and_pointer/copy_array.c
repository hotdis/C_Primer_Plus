#include<stdio.h>
#include<stdlib.h>

void copyArray0(double sourceArr[], double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = sourceArr[i];
		printf(" 0*%lf", arr[i]);
	}
	printf("\n");
}

void copyArray1(double sourceArr[], double arr[], int n)
{
	for (double *p = arr; p < arr + n; p++)
	{
		*p = *sourceArr++;
		printf(" 0*%lf", *p);
	}
	printf("\n");
}

void copyArray2(double sourceArr[], double arr[], double *p)
{
	for (; sourceArr < p; sourceArr++)
	{
		*arr = *sourceArr;
		printf(" 0*%lf", *arr);
	}
	printf("\n");
}

int main()
{
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double target0[5];
	double target1[5];
	double target2[5];

	copyArray0(source, target0, 5);
	copyArray1(source, target1, 5);
	copyArray2(source, target2, source + 5);

	system("pause");
	return 0;
}

