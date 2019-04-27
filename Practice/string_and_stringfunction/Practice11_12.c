/*Write a program that reads input up to EOF and reports the number of words, 
 *the number of uppercase letters, 
 *the number of lowercase letters,
 *the number of punctuation characters, 
 *and the number of digits. 
 *Use the  ctype.h family of functions.
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main() {
	char ch;
	int big = 0, small = 0, word = 1, num = 0, pun = 0;

	puts("Enter a string.");
	while ((ch = getchar()) != EOF) {
		if (isupper(ch)) {
			big++;
		}
		else if (islower(ch)) {
			small++;
		}
		else if (isblank(ch)) {
			word++;
		}
		else if (ispunct(ch)) {
			pun++;
		}
		else if (isdigit(ch)) {
			num++;
		}
	}

	printf("word :%d\n", word);
	printf("uppercase letters :%d\n", big);
	printf("lowercase letters :%d\n", small);
	printf("punctuation chars :%d\n", pun);
	printf("digit :%d\n", num);

	system("pause");
	return 0;
}