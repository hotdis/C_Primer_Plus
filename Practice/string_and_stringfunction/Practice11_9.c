/*Write a function that replaces the contents of a string with the string reversed. 
 *Test the function in a complete program that uses a loop to provide input values for feeding to the function. 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void switchover(char *);
char *s_gets(char *, int);

int main() {

	char str[20];

	puts("Enter a str.");
	while (s_gets(str, 20) != NULL && str[0] != '#') {
		switchover(str);
		puts(str);

		puts("Enter a str(# to quit).");
	}

	puts("Done.");
	system("pause");
	return 0;
}

void switchover(char *str) {
	for (int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
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