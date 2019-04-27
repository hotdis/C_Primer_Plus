#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void left_move(int *arr)
{
	int first = arr[0];

	for (int i = 1; i < SIZE - 1; i++)
	{
		int temp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = temp;
	}

	arr[SIZE - 1] = first;
}

void right_move(int *arr)
{
	int last = arr[SIZE - 1];

	for (int i = SIZE - 1; i > 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = temp;
	}

	arr[0] = last;
}

int main()
{
	int arr[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
	int choice = -1;

	while (choice)
	{
		puts("Enter 1 or 2.");

		while (1 != scanf("%d", &choice))
		{
			printf("Enter error!\n");
			printf("Enter again:");

			while (getchar() != '\n')
			{
				continue;
			}
		}

		switch (choice)
		{
		case 1:
			left_move(arr);
			break;
		case 2:
			right_move(arr);
			break;
		case 0:
			system("pause");
			exit(0);
			break;
		default:
			break;
		}

		for (int i = 0; i < SIZE; i++)
		{
			printf(" *%d", arr[i]);
		}
		putchar('\n');
	}

	system("pause");
	return 0;
}

