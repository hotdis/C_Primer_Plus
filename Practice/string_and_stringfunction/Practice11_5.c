/*Design and test a function that searches the string specified by the first function 
 *parameter for the first occurrence of a character specified by the second function parameter. 
 *Have the function return a pointer to the character if successful, 
 *and a null if the character is not found in the string. 
 *(This duplicates the way that the library strchr()  function works.) 
 *Test the function in a complete program that uses a loop to provide input values for feeding to the function.
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char *get_position(char *, char);

int main() {

	char *str = { "abcdefghijklmnopqrstuvwxyz" };
	char ch;

	puts("Enter a char you wanna search.");
	while (1 == scanf("%c", &ch) && ch != '#') {
		while (getchar() != '\n') {
			continue;
		}

		if (get_position(str, ch)) {
			puts("Yes.");
		}
		else {
			puts("No");
		}
		puts("Enter a char you wanna search(# to quit).");
	}

	system("pause");
	return 0;
}


char *get_position(char *pstr, char ch) {
	char *p = NULL;
	
	for (int i = 0; pstr[i] != '\n'; i++) {
		if (pstr[i] == ch) {
			p = pstr + i;
		}
	}

	return p;
}