/*Design and test a function that reads the first word from a line of input into an array and 
 *discards the rest of the line. It should skip over leading whitespace. 
 *Define a word as a sequence of characters with no blanks, tabs, or newlines in it.
 */
#include<stdio.h>
#include<stdlib.h>

void get_word(char *, int);

int main() {

	char pstr[6];

	get_word(pstr, 6);	
	puts(pstr);

	system("pause");
	return 0;
}

void get_word(char *pstr,int num) {
	char ch;
	int count = 0;

	while ((ch = getchar()) != '\n') {
		if (ch >= 'a'&&ch <= 'z') {
			if (count >= num) {
				pstr[num - 1] = '\0';
				return;
			}
			pstr[count++] = ch;
		}
		else {
			continue;
		}
	}

	pstr[count] = '\0';

}