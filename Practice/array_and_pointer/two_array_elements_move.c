#include<stdio.h>
#include<stdlib.h>
#define LIM 5
#define SIZE 5

void row_move(int(*arr)[SIZE])
{
	int last[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		last[i] = arr[0][i];
	}
	//copy elements of the first row

	for (int i = 1; i < LIM; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[i - 1][j];
			arr[i - 1][j] = temp;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		arr[LIM - 1][i] = last[i];
	}
}

int main()
{
	int flag = 1;
	int arr[LIM][SIZE] = {
							{0,0,0,0,0},
							{1,1,1,1,1},
							{2,2,2,2,2},
							{3,3,3,3,3},
							{4,4,4,4,4}
							};
	
	while (flag)
	{
		puts("Continue or break.");
		scanf_s("%d", &flag);

		row_move(arr);

		for (int i = 0; i < LIM; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				printf(" *%d", arr[i][j]);
			}
			putchar('\n');
		}
	}

	system("pause");
	return 0;
}