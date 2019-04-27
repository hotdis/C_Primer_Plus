/*Write a function called is_within() that takes a character and a string pointer as its two function parameters. 
 *Have the function return a nonzero value (true) if the character is in the string and zero (false) otherwise. 
 *Test the function in a complete program that uses a loop to provide input values for feeding to the function. 
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int is_within(char, const char *);

int main() {

	const char *pstr = "this is c ,yes you can learn it well.";
	char ch;

	puts("# to quit .");
	while (1 == scanf("%c", &ch) && ch != '#') {
		while (getchar() != '\n') {
			continue;
		}
		
		int flag = is_within(ch, pstr);
		printf("%c result %d.\n", ch,flag);
		puts("# to quit .");
	}

	puts("Done");
	system("pause");
	return 0;
}

int is_within(char ch, const char *pstr) {

	int flag = 0;
	
	for (int i = 0; pstr[i] != '\0'; i++) {
		if (pstr[i] == ch) {
			flag = 1;
			break;
		}
	}

	return flag;
}