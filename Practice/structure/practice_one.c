
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define CSIZE 4

char *s_gets(char *, int);
void takeinfo(struct student *);
void average(struct student *);
void showinfo(struct student *);

struct name {
	char fname[12];
	char lname[12];
};

struct student {
	struct name sb;
	double grade[3];
	double aver;
};

int main()
{
	struct student record[CSIZE]; 

	takeinfo(record);
	average(record);
	showinfo(record);

	system("pause");
	return 0;
}

void takeinfo(struct student *record)
{
	for (int i = 0; i < CSIZE; i++)
	{
		printf("Now number %d \n", i);
		printf("Enter your first name.\n");
		s_gets((record + i)->sb.fname, 12);
		printf("Enter your last name.\n");
		s_gets((record + i)->sb.lname, 12);

		printf("Enter your grades.\n");
		scanf("%lf%lf%lf", &((record + i)->grade[0]), &((record + i)->grade[1]), &((record + i)->grade[2]));
		printf("=====================\n");
		getchar();
	}

}

void average(struct student *record)
{
	for (int i = 0; i < CSIZE; i++)
	{
		double sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += ((record + i)->grade[j]);
		}

		(record + i)->aver = sum / 3;
	}
}

void showinfo(struct student *re)
{
	for (int i = 0; i < CSIZE; i++)
	{
		printf("Dear %s %s:\n", (re + i)->sb.fname, (re + i)->sb.lname); 
		printf("Your grades.\n");
		for (int j = 0; j < 3; j++)
		{
			printf(" *%lf\n", (re + i)->grade[j]);
		}
		printf("Your average of 3 sources : %lf\n", (re + i)->aver);

		printf("=======================\n");
	}
}

char *s_gets(char *st, int num)
{
	char *pt = fgets(st, num, stdin);
	int i = 0;

	if (pt)
	{
		while (st[i] != '\0'&&st[i] != '\n')
		{
			i++;
		}

		if (st[i] == '\n')
		{
			st[i] = '\0';
		}

		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	return pt;
}