#include<stdio.h>
#include<stdlib.h>

int main()
{
	char ch;
	int count = 0;

	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
		count++;
	}

	printf("Article has %d chars\n", count);

	system("pause");
	return 0;
}