/*Write a function called string_in(that takes two string pointers as arguments. 
 *If the second string is contained in the first string, 
 *have the function return the address at which the contained string begins.
 *For instance, string_in("hats", "at") would return the address of the a in hats .
 *Otherwise, have the function return the null pointer. 
 *Test the function in a complete program that uses a loop to provide input values for feeding to the function. 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *string_in(char *, char *);
char *s_gets(char *, int);

int main() {

	char str1[30];
	char str2[30];

	puts("Enter 1st str.");
	while (s_gets(str1, 30) != NULL && str1[0] != '#') {
		puts("Enter 2nd str.");
		s_gets(str2, 30);

		char *p = string_in(str1, str2);
		if (p) {
			puts(p);
		}
		else {
			puts("Error in");
		}

		puts("Enter 1st str(# to quit).");
	}

	puts("Done");
	system("pause");
	return 0;
}

char *string_in(char *p1, char *p2) {

	char *pstr = NULL;
	int i = 0, j = 0;

	if (strlen(p2) > strlen(p1)) {
		return pstr;
	}

	for (; p1[i] != '\0';i++) {
		for (j = 0; p2[j] != '\0'; j++) {
			if (p1[i + j] != p2[j]) {
				break;
			}
		}
		if (p2[j] == '\0') {
			pstr = p1 + i;
		}
	}

	return pstr;
}

char *s_gets(char *str, int num) {
	char *p = fgets(str, num, stdin);
	int i = 0;

	if (p) {
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