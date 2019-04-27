#include<stdio.h>
#include<stdlib.h>

void flashbackSort(double *arr,int n)
{
	for (int i = 0, j = n-1; i < n / 2; i++, j--)
	{
		double temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

int main()
{
	double arr[5] = { 1,2,3,4,5 };

	flashbackSort(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		printf(" *%lf", arr[i]);
	}

	system("pause");
	return 0;
}