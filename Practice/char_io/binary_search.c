#include<stdio.h>
#include<stdlib.h>

int  Guess(int *left,int *right ,int *mid)
{
	*mid = (*left + *right) / 2;
	printf("I guess %d is what you imaged!\n",*mid);
	printf("Isn't it?Please enter y or n.\n");
	return *mid;
}

void JudgeBranch(int *left, int *right, int *mid)
{
	char ch;
	int flag = 1;
	ch = getchar();

	printf("really?Let me try again!");
	printf("Is it bigger than yours?\n");

	while ((ch = getchar()) != 'y')
	{
		if (ch == 'n')
		{
			*left = *mid + 1;
			flag = 0;
			break;
		}
		else
		{
			printf("Please enter y or n.\n");
		}
		while (getchar() != '\n')
		{
			continue;
		}
	}
	if (flag)
	{
		*right = *mid;
	}
}

void Judge(int *left,int *right,int *mid,char ch)
{
	if (ch == 'n')
	{
		JudgeBranch(left, right, mid);
	}
	else
	{
		printf("Please enter y or n.\n");
	}
	while (getchar() != '\n')
	{
		continue;
	}
}

int main()
{
	printf("This is a guess integer game.\n");
	printf("Image a integer between 0 and 100 in your mind.\n");

	int left = 0, right = 100, mid = 0;
	int *left0 = &left, *right0 = &right, *mid0 = &mid;
	char ch;

	mid = Guess(left0, right0, mid0);

	while ((ch=getchar())!='y')
	{
		Judge(left0, right0, mid0,ch);
		mid = Guess(left0, right0, mid0);
	}
	printf("Done!\n");

	system("pause");
	return 0;
}