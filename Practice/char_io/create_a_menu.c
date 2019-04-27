#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

float Operation0(float *, float *, float(*)(float *, float *));

void show0()
{
	printf("Enter the operation of your choice.\n");
	printf("a.add          s.subtract\n");
	printf("m.multiply     d.divide\n");
	printf("q.Quit\n");
}

float add(float *fn, float *sn)
{
	return *fn + *sn;
}

float substrat(float *fn, float *sn)
{
	return *fn - *sn;
}

float multiply(float *fn, float *sn)
{
	return (*fn) * (*sn);
}

float divide(float *fn, float *sn)
{
	return *fn / *sn;
}

char badLimits0(int *i)
{
	char ch;
	char ch0;
	if (*i > 0)
	{
		ch0 = getchar();
	}

	ch = getchar();
	while (ch != 'a'&&ch != 's'&&ch != 'm'&&ch != 'd'&&ch != 'q')
	{
		while (getchar() != '\n')
		{
			continue;
		}
		printf("Please enter a,b,c,d or q.\n");
		ch = getchar();
	}
	
	return ch;
}

void divideTest(float *sn, char ch)
{
	while (ch == 'd' && *sn == 0)
	{
		printf("The secondNum can't be 0.\n");
		printf("Please enter a new one.\n");
		scanf("%f", sn);
	}
}

void getNum(float *fn ,float *sn,char ch)
{
	printf("Enter the first num:\n");
	while (1 != scanf("%f", fn))
	{
		printf("Please enter a float.\n");
		while (getchar() != '\n')
		{
			continue;
		}
	}
	printf("Enter the second num:\n");
	while (1 != scanf("%f", sn))
	{
		printf("Please enter a float.\n");
		while (getchar() != '\n')
		{
			continue;
		}
	}
	divideTest(sn,ch);
}

float getChoice0(int *flag,float *fn,float *sn,int *i)
{
	char ch;
	float result = 0;
	
	ch = badLimits0(i);
	
	if (ch != 'q')
	{
		getNum(fn, sn, ch);
	}

	switch (ch)
	{
	case 'a':
		result = Operation0(fn, sn, add);
		break;
	case 'b':
		result = Operation0(fn, sn, substrat);
		break;
	case 'c':
		 result = Operation0(fn, sn, multiply);
		break;
	case 'd':
		result = Operation0(fn, sn, divide);
		break;
	default:
		*flag = 0;
		break;
	}
	return result;
}

float Operation0(float *fn,float *sn,float (*p)(float *,float *))
{
	float result = p(fn, sn);
	return result;
}

int main()
{
	int flag = 1, i = 0;
	float firstNum = 0, secondNum = 0, result = 0;
	int *flag0 = &flag;
	float *firstNum0 = &firstNum, *secondNum0 = &secondNum;
	int *i0 = &i;
	while (flag)
	{
		show0();
		result = getChoice0(flag0, firstNum0,secondNum0,i0);
		i++;
		if (flag)
		{
			printf("The result is %f\n", result);
		}
	}
	printf("Done.");

	system("pause");
	return 0;
}