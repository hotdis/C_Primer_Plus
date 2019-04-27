#include<stdio.h>
#include<stdlib.h>

void showElement(int(*source)[5], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf(" *%d", source[i][j]);
		}
	}
	printf("\n");
}

void doubleElement(int(*source)[5], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			source[i][j] *= 2;
			printf(" *%d", source[i][j]);
		}
	}
	printf("\n");
}

int main()
{
	int source[3][5] = { {1,2,3,4,5},{6,7,8,9,0},{11,22,33,44,55} };

	showElement(source, 3);
	doubleElement(source, 3);

	system("pause");
	return 0;
}