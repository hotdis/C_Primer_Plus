/*The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1, 
 *truncating s2 or padding it with extra null characters as necessary. 
 *The target string may not be null-terminated if the length of  s2  is  n  or more.
 *The function returns  s1 . 
 *Write your own version of this function; call it  mystrncpy() .
 *Test the function in a complete program that uses a loop to provide input values for feeding to the function. 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

char * mystrncpy(char *, char *, int);
char *s_gets(char *, int);

int main() {

	char str0[SIZE];
	char str1[SIZE];
	int num;

	puts("Enter the 1st str.");
	while (s_gets(str0, SIZE)!= NULL&&str0[0]!='#') {
		puts("Enter the 2nd str.");
		s_gets(str1, SIZE);

		puts("How many characters do you wanna copy.");
		scanf_s("%d", &num);
		getchar();
		mystrncpy(str0, str1, num);

		puts(str0);
		puts(str1);

		puts("Enter the 1st str(# to quit).");
	}


	system("pause");
	return 0;
}

char * mystrncpy(char *str0, const char *str1, int num) {
	int len1 = strlen(str1);

	if (num > len1) {
		num = len1;
	}

	for (int i = 0; i < num; i++) {
		str0[i] = str1[i];
	}

	if (num <= len1) {
		str0[len1] = '\0';
	}

	return str0;
}

char *s_gets(char *pstr, int num) {
	char *p = fgets(pstr, num, stdin);

	if (p) {
		int i = 0;
		while (pstr[i] != '\0'&&pstr[i] != '\n') {
			i++;
		}

		if (pstr[i] == '\n') {
			pstr[i] = '\0';
		}
		else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}
	
	return p;
}