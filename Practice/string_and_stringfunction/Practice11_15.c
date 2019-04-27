/*Use the character classification functions to prepare an implementation of atoi() ; 
 *have this version return the value of 0 if the input string is not a pure number.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int myatoi(const char *);

int main() {
	const char *str = "555";
	int result = 0;

	result = myatoi(str);
	printf("Standing by >>> %d <<< Compelete\n", result);
	puts("Done");

	system("color 4");
	system("pause");
	return 0;
}

int myatoi(const char *str) {
	int itg = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (0 == isdigit(str[i])) {
			itg = 0;
			break;
		}
		else {
			itg = itg * 10 + (str[i] - '0');
		}
	}
	return itg;
}