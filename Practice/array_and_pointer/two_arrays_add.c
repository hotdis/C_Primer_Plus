#include<stdio.h>
#include<stdlib.h>

void add(int *source0, int *source1, int *target, int n)
{
	for (int i = 0; i < n; i++)
	{
		target[i] = source0[i] + source1[i];
	}
}

int main()
{
	int source0[4] = { 1,2,3,4 };
	int source1[4] = { 2,3,4,5 };
	int target[4] = { 0 };

	add(source0, source1, target, 4);

	for (int i = 0; i < 4; i++)
	{
		printf(" *%d", target[i]);
	}

	system("pause");
	return 0;
}
