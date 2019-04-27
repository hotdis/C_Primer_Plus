#include<stdio.h>
#include<stdlib.h>

int func();

int main()
{

	int count;

	for (int i = 0; i < 5; i++)
	{
		count = func();
	}

	printf("Function has been called %d times.\n", count);

	system("pause");
	return 0;
}

int func()
{
	static int count = 0;

	count++;

	return count;
}