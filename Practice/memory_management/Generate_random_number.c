#include<stdio.h>
#include<stdlib.h>
#define NUM 100

void get_random_num(int *);
void select_sort(int *);

int main()
{
	int *parr = (int *)malloc(sizeof(int)*NUM);

	get_random_num(parr);

	select_sort(parr);

	for (int i = 0; i < NUM; i++)
	{
		printf(" *%d", parr[i]);
	}

	system("pause");
	return 0;
}

void get_random_num(int *arr)
{
	for (int i = 0; i < NUM; i++)
	{
		arr[i] = rand() % 10;
	}
}

void select_sort(int *arr)
{

	for (int i = 0; i < NUM - 1; i++)
	{
		for (int j = i + 1; j < NUM; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}