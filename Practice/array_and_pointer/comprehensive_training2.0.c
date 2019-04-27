#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int arr[SIZE] = { 0 };
int count = 0;

void add_to_end(int value)
{
	arr[count] = value;
	count++;
}

void add_to_front(int value)
{
	int i = count;

	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	
	arr[0] = value;
	count++;
}

void remove_index(int index)
{
	
	for (int i = index; i < count-1; i++)
	{
		arr[i] = arr[i + 1];
	}

	count--;
}

void remove_value(int value)
{
	
	for (int i = 0; i < count; i++)
	{
		while (arr[i] == value)
		{
			remove_index(i);

			if (count == 0)
			{
				break;
			}
		}	
	}
}

int count_value(int value)
{
	int num = 0;

	for(int i=0;i<count;i++)
	{
		if (arr[i] == value)
		{
			num++;
		}
	}

	return num;
}

int get_mode()
{
	int mode = arr[0];
	int modeFreq = count_value(mode);

	for (int i = 1; i < count; i++)
	{
		if (count_value(arr[i]) > modeFreq)
		{
			mode = arr[i];
			modeFreq = count_value(mode);
		}
	}

	return mode;
}

void show_array()
{
	for (int i = 0; i < count; i++)
	{
		printf(" *%d", arr[i]);
	}
	
	putchar('\n');
}

int main()
{
	int flag = 1;
	int index = 0;
	int value = 0;
	while (flag||count == 99)
	{
		puts("Continue or break.");
		scanf_s("%d", &flag);

		if (flag == 1)
		{
			printf("Value:");
			scanf_s("%d", &value);
			add_to_front(value);
		}
		else if (flag == 2)
		{
			printf("Value:");
			scanf_s("%d", &value);
			add_to_end(value);
		}
		else if (flag == 3)
		{
			printf("Index:");
			scanf_s("%d", &index);

			remove_index(index);
		}
		else if (flag == 4)
		{
			printf("Value:");
			scanf_s("%d", &value);
			remove_value(value);
		}
		else if (flag == 5)
		{
			printf("Value:");
			scanf_s("%d", &value);
			printf("Num : %d", count_value(value));
		}
		else if (flag == 6)
		{
			get_mode();
		}
		else;

		show_array();
	}


	system("pause");
	return 0;
}