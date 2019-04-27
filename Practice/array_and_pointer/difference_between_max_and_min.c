#include<stdio.h>
#include<stdlib.h>

double differenceBetweenMaxAndMin(double *arr,int n)
{
	double min = *arr, max = *arr;

	for (int i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max - min;
}

int main()
{
	double arr[5] = { 32.1,42.3,41.9,99.9,34.1 };

	double Dvalue = differenceBetweenMaxAndMin(arr, 5);

	printf("最大值和最小值的差值：%lf", Dvalue);

	system("pause");
	return 0;
}