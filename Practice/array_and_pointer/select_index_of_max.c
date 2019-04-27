#include<stdio.h>
#include<stdlib.h>

int selectIndexOfMax(double *arr , int n )
{
	double max = *arr;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}

int main()
{
	double arr[6] = { 3.3,56.4,54.3,44.4,34.9 };

	int index = selectIndexOfMax(arr, 6);

	printf("最大值的下标为：%d", index);

	system("pause");
	return 0;
}