#include<stdio.h>
#include<stdlib.h>

void getFirstUnblankChar()
{
	char ch;
	
	while ((ch = getchar()) == ' ')
	{
		continue;
	}

	putchar(ch);

	while (getchar() != '\n')
	{
		continue;
	}
}


int main()
{
	getFirstUnblankChar();

	system("pause");
	return 0;
}