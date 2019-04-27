/*Write a program that takes two command-line arguments.
 *The first is a string; the second is the name of a file. 
 *The program should then search the file, printing all lines containing the string. 
 *Because this task is line oriented rather than character oriented, use fgets() instead of getc() . 
 *Use the standard C library function strstr() to search each line for the string. 
 *Assume no lines are longer than 255 characters.  
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *s_gets(char *, int);
void eat_lines();

int main() {
	char smode[20];
	char ssource[256];
	char fname[26];
	int count = 0;

	FILE *fp;
	
	puts("Select a file to open.");
	scanf("%19s", fname);
	eat_lines();

	if ((fp = fopen(fname, "r+")) == NULL) {
		fprintf(stderr, "ERROR");
		exit(EXIT_FAILURE);
	}

	puts("what string do you wanna get.");
	while (s_gets(smode, 20) != NULL&&smode[0]!=' ') {
		rewind(fp);
		while (fgets(ssource, 256, fp) != NULL) {
			if (strstr(ssource, smode)) {
				fputs(ssource, stdout);
				count++;
			}
		}
		printf("Total %d.\n", count);
		count = 0;
		puts("what string do you wanna get(SPACE to quit).");
	}
	
	fclose(fp);
	puts("Done");
	system("pause");
	return 0;
}

char *s_gets(char *str, int num) {
	char *pstr = fgets(str, num, stdin);
	int i = 0;

	if (pstr) {
		while (str[i] != '\n'&&str[i] != '\0') {
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

	return pstr;
}

void eat_lines() {
	while (getchar() != '\n') {
		continue;
	}
}