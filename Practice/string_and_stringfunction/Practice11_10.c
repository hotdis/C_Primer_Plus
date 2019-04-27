/*Write a function that takes a string as an argument and removes the spaces from the string. 
 *Test it in a program that uses a loop to read lines until you enter an empty line. 
 *The program should apply the function to each input string and display the result. 
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void del_blank(char *);

int main() {

	char str[100];

	puts("Enter your str.");
	while (fgets(str, 100, stdin) != NULL&&str[0]!='\n') {

		del_blank(str);
		fputs(str, stdout);

		puts("Enter you str(empty line to quit).");
	}

	puts("Done.");
	system("pause");
	return 0;
}

void del_blank(char *str) {
	int i = 0, j = 0;
	char nstr[100];

	for (; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			nstr[j++] = str[i];
		}
	}
	nstr[j] = '\0';
	strcpy(str, nstr);

}