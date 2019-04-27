/*Modify and test the function in exercise 1 so that 
 *it stops after n characters or after the first blank, tab, or newline, whichever comes first. 
 *(Don¡¯t just use  scanf() .)  
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get_n_c(char *, int);

int main() {

	char *pstr;
	int size;
	puts("Enter the size of string.");
	scanf("%d", &size);
	getchar();

	pstr = (char*)malloc(sizeof(char)*(size + 1));

	get_n_c(pstr, size);
	puts(pstr);

	free(pstr);
	pstr = NULL;

	system("pause");
	return 0;
}

void get_n_c(char *pstr, int size) {
	int count = 0;
	char ch;

	puts("Enter your string.");
	for (; count < size; count++) {
		ch = getchar();
		if (ch == '\n' || ch == '\t' || ch == ' ') {
			break;
		}
		else {
			pstr[count] = ch;
		}
			
	}

	pstr[count] = '\0';
}