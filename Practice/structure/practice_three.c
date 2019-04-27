#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 15
#define CLEN 8
#define NUM 5

void init_card(struct card[]);
void show_card(const struct card[]);

struct id {
	char fname[LEN];
	char lname[LEN];

	char mname[LEN];
};

struct card {
	struct id one;

	char number[CLEN];
};


int main()
{
	struct card att[NUM];

	init_card(att);
	show_card(att);

	system("pause");
	return 0;
}

void init_card(struct card att[])
{
	att[0] = {
		{"Frank","CC"},
		"3482713"
	};
	att[1] = {
		{"Candy","Cate","Mist"},
		"3562453"
	};
	att[2] = {
		{"Put","Gess","Lee"},
		"3585948"
	};
	att[3] = {
		{"Dick","Cate","Bran"},
		"3562fs3"
	};
	att[4] = {
		{"Fuck","Gess"},
		"3235948"
	};
}

void show_card(const struct card att[])
{
	for (int i = 0; i < NUM; i++)
	{
		printf("%s %s ", att[i].one.fname, att[i].one.lname);
		if (strlen(att[i].one.mname))
		{
			printf("%c.", att[i].one.mname[0]);
		}
		printf(" --- %s\n", att[i].number);
	}
}