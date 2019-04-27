#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 15

void storage_str(char *[], int);
char *s_gets(char *, int);

int main()
{
	int num;
	printf("How many words do you wish to enter ?\n");
	scanf("%d", &num);
	getchar();

	char **pstr = (char **)malloc(sizeof(char *)*num);

	storage_str(pstr, num);

	printf("Here are your words .\n");
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", pstr[i]);
	}

	system("pause");
	return 0;
}

void storage_str(char *pstr[],int num)
{
	
	for (int i = 0; i < num; i++)
	{
		char *p = (char *)malloc(sizeof(char)*SIZE);

		s_gets(p, SIZE);

		pstr[i] = p;

	}
}

char *s_gets(char *str, int n)
{
	char *p = fgets(str, n, stdin);
	
	int i = 0;
	
	while (str[i] != '\0'&&str[i] != '\n')
	{
		i++;
	}
	
	if (str[i] == '\n')
	{
		str[i] = '\0';
	}
	
	return p;

}