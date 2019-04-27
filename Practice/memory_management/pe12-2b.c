#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"pe12-2a.h"

int main()
{
	int mode;

	printf("Enter 0 for metric mode ,1 for US mode : ");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		setmode(mode);
		get_info();
		show_info();

		printf("Enter 0 for metric mode ,1 for US mode : ");
		scanf("%d", &mode);
	}



	system("pause");
	return 0;
}