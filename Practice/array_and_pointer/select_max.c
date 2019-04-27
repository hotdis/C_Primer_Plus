#include<stdio.h>
#include<stdlib.h>

int selectMax(int *arr,int n)
{
	int max = *arr;
	for (int i = 1; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

int main()
{
	int arr[5] = { 3,4,5,4,54 };

	int max = selectMax(arr, 5);

	printf("最大值为：%d\n", max);

	system("pause");
	return 0;
}