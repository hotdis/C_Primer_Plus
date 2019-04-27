#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int *make_array(int, int);
void show_array(const int *, int);

int main()
{
	int elem, val;
	int *p;

	printf("Enter the number of elements : ");
	while (1 == scanf("%d", &elem) && elem > 0)
	{

		printf("Enter the initialization values : ");
		scanf("%d", &val);

		p = make_array(elem, val);
		show_array(p, elem);

		free(p);

		printf("Enter the number of elements : ");
	}

	system("pause");
	return 0;
}

int *make_array(int elem, int val)
{
	int *parr = (int *)malloc(sizeof(int) * elem);

	if (parr == NULL)
	{
		printf("Allocation address failed.\n");
		exit(EXIT_FAILURE);
	}

	for (int *p = parr; p < parr + elem; p++)
	{
		*p = val;
	}

	return parr;
}

void show_array(const int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" *%d", arr[i]);
	}

	putchar('\n');
}