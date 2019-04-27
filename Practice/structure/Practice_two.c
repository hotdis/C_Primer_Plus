#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/*Air infomation */
#define AIRLINE 4
#define SEATNUM 12
#define LEN 20

/*Flight number */
#define AIR0 "102"
#define AIR1 "311"
#define AIR2 "444"
#define AIR3 "519"

char showmenu();
struct airline *show_line(struct airline []);
void show_num_ety(const struct plane []);
void list_ety(const struct plane[]);
void assign_data(struct plane[]);
void delete_data(struct plane[]);

char *s_gets(char *, int);
void eatline();

struct plane {
	int number;
	int flag;

	char fname[LEN];
	char lname[LEN];
};

struct airline {
	struct plane info[SEATNUM];
	char number[LEN];
};

int main()
{
	system("color 3");
	
	char choice;
	struct airline airinfo[AIRLINE];
	struct airline *sp = NULL;
	
	/* Number flights */
	strcpy(airinfo[0].number, AIR0);
	strcpy(airinfo[1].number, AIR1);
	strcpy(airinfo[2].number, AIR2);
	strcpy(airinfo[3].number, AIR3);

	
	
	for (int i = 0; i < AIRLINE; i++)
	{
		for (int j = 0; j < SEATNUM; j++)
		{
			/*Number seats for each flight */
			airinfo[i].info[j].flag = 0;
			
			/*Set each seat empty */
			airinfo[i].info[j].number = j;
		}
	}

	while (1)
	{
		sp = show_line(airinfo);

		while ((choice = showmenu()) != 'f')
		{
			switch (choice)
			{
			case 'a':
				show_num_ety(sp->info);
				break;
			case 'b':
				list_ety(sp->info);
				break;
			case 'c':

				break;
			case 'd':
				assign_data(sp->info);
				break;
			case 'e':
				delete_data(sp->info);
				break;
			default:;
			}
		}
	}

	system("pause");
	return 0;
}

struct airline *show_line(struct airline info[])
{

	char str[LEN];

	puts("To select a flight.(q to quit)"); 

	while (s_gets(str, LEN) != NULL)
	{
		for (int i = 0; i < AIRLINE; i++)
		{
			if (strcmp(str, info[i].number) == 0)
			{
				return &info[i];
			}

			if (strcmp(str, "q") == 0)
			{
				system("pause");
				exit(0);
			}
		}

		puts("THIS IS NO FLIGHT.");
		puts("To select again.");
	}
}

char showmenu()
{

	puts("To choose a function , enter its letter label.");
	puts("a)Show number of empty seats .");
	puts("b)Show list of empty seats .");
	puts("c)Show alphabetical list of seats .");
	puts("d)Assign a customer to a seat assignment .");
	puts("e)Delete a seat assignment .");
	puts("f)Quit .");

	char ch = getchar();
	ch = (char )towlower(ch);

	eatline();

	while (strchr("abcdef", ch) == NULL)
	{
		puts("Please enter a,b,c,d,e or f.");
		char ch = getchar();
		ch = (char )towlower(ch);	
	}

	return ch;
}

void show_num_ety(const struct plane info[])
{
	int num = 0;
	for (int i = 0; i < SEATNUM; i++)
	{
		if (info[i].flag == 0)
		{
			num++;
		}
	}

	puts("================================");
	printf("Now there is %d empty seat(s).\n", num);
	puts("================================");
}

void list_ety(const struct plane info[])
{
	int count = 0;
	puts("================================");
	for (int i = 0; i < SEATNUM; i++)
	{
		if (info[i].flag == 0)
		{
			count++;
			printf("Empty seat NO.%-2d number is %d\n", count, info[i].number);
		}
	}
	puts("================================");
}

void assign_data(struct plane info[])
{
	int tickets = 0;

	printf("Enter the number of tickets you wanna buy.\n");
	while (1 != scanf("%d", &tickets) || tickets < 1 || tickets > SEATNUM)
	{
		eatline();
		puts("Enter an integer.");
		printf("And tickets must less than 0 and more than %d\n", SEATNUM);
	}
	puts("Now there are the list of empty seats.");
	list_ety(info);

	for (int i = 0; i < tickets; i++)
	{
		int num = 0;

		printf("Enter the %d number.",i);
		scanf("%d", &num);
		eatline();
		
		puts("Enter your first name.");
		s_gets(info[num].fname, LEN);
		puts("Enter your last name.");
		s_gets(info[num].lname, LEN);

		info[num].flag = 1;
	}
}

char *s_gets(char *str, int num)
{
	char *p = fgets(str, num, stdin);

	if (p)
	{
		int i = 0;
		while (str[i] != '\n'&&str[i] != '\0')
		{
			i++;
		}

		if (str[i] == '\n')
		{
			str[i] = '\0';
		}
		else if (str[i] == '\0')
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	return p;
}

void delete_data(struct plane info[])
{
	char str[LEN];
	int num, i;

	puts("Enter the number that you wanna t delete a seat assignment.");
	scanf("%d", &num);
	eatline();

	for ( i = 0; i < SEATNUM; i++)
	{
		if (num == info[i].number)
		{
			break;
		}
	}

	puts("Please enter your firstname to confirm the deletion.");
	s_gets(str, LEN);

	if (strcmp(str, info[i].fname))
	{
		puts("=== NO SIR .YOU CANNOT CHANGE THE DATA! ===");
	}
	else
	{
		info[i].flag = 0;
		puts("=========   Succeed   =========");
	}
}

void eatline()
{
	while (getchar() != '\n')
	{
		continue;
	}
}