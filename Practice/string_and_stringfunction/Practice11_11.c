/*Write a program that reads in up to 10 strings or to EOF,whichever comes first. 
 *Have it offer the user a menu with five choices: 
 *print the original list of strings,  
 *print the strings in ASCII collating sequence, 
 *print the strings in order of increasing length, 
 *print the strings in order of the length of the first word in the string, and quit. 
 *Have the menu recycle until the user enters the quit request. 
 *The program, of course, should actually perform the promised tasks. 
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define NUM 5

char menu_and_choice();
void show_strs(char **);
void ascii_sort(char **);
void length_sort(char **);
void fword_sort(char **);
int str_char(const char *, char);
char *s_gets(char *, int);

int main() {

	char *pstr[NUM];
	char *p[NUM];
	char ch;

	for (int i = 0; i < NUM; i++) {
		pstr[i] = (char *)malloc(sizeof(char) * 100);
		p[i] = pstr[i];
		
		printf("Enter the %d str.\n", i + 1);
		s_gets(pstr[i], 100);
	}

	while ((ch = menu_and_choice()) != 'q') {
		switch (ch) {
		case 'a':
			show_strs(pstr);
			break;
		case 'b':
			ascii_sort(p);
			break;
		case 'c':
			length_sort(p);
			break;
		case 'd':
			fword_sort(p);
			break;
		default:;

		}

		while (getchar() != '\n') {
			continue;
		}
		system("cls");
	}

	for (int i = 0; i < 5; i++) {
		free(pstr[i]);
	}

	puts("Done.");
	system("pause");
	return 0;
}

char menu_and_choice() {
	char ch;
	
	puts("=============================================================================");
	puts("a)print the original list of strings.");
	puts("b)print the strings in ASCII collating sequence.");
	puts("c)print the strings in order of increasing length.");
	puts("d)print the strings in order of the length of the first word in the string.");
	puts("q)quit.");
	puts("=============================================================================");
	
	puts("Enter your choice");
	scanf("%c", &ch);
	getchar();
	while (str_char("abcdq", ch) == 0) {
		printf("%c is not include the options.\n", ch);
		puts("Enter your choice");
		scanf("%c", &ch);
		getchar();
	}

	return ch;
}

void show_strs(char **pstr) {
	for (int i = 0; i < NUM; i++) {
		puts(pstr[i]);
	}
}

void ascii_sort(char **pstr) {
	for (int i = 0; i < NUM - 1; i++) {
		for (int j = i; j < NUM; j++) {
			if (pstr[i][0] > pstr[j][0]) {
				char *temp = pstr[j];
				pstr[j] = pstr[i];
				pstr[i] = temp;
			}
		}
	}

	show_strs(pstr);
}

void length_sort(char **pstr) {
	for (int i = 0; i < NUM - 1; i++) {
		for (int j = i; j < NUM; j++) {
			if (strlen(pstr[i]) > strlen(pstr[j])) {
				char *temp = pstr[i];
				pstr[i] = pstr[j];
				pstr[j] = temp;
			}
		}
	}
	show_strs(pstr);
}

void fword_sort(char **pstr) {
	int count[NUM] = { 0 };

	for (int i = 0; i < NUM; i++) {
		for (int j = 0; pstr[i][j] != '\n'; j++) {
			if (pstr[i][j] != ' ') {
				count[i]++;
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < NUM - 1; i++) {
		for (int j = i; j < NUM; j++) {
			if (count[i] > count[j]) {
				char *temp = pstr[i];
				pstr[i] = pstr[j];
				pstr[j] = temp;
			}
		}
	}
	show_strs(pstr);
}

int str_char(const char *str, char ch) {
	int flag = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ch) {
			flag = 1;
		}
	}
	
	return flag;
}

char *s_gets(char *str, int num) {
	char *p = fgets(str, num, stdin);
	if (p) {

		int i = 0;
		while (str[i] != '\0'&&str[i] != '\n') {
			i++;
		}
		
		if (str[i] == '\n') {
			str[i] = '\0';
		}
		else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}
	return p;
}