/*Design and test a function that fetches the next n characters from input (including blanks, tabs, and newlines), 
 *storing the results in an array whose address is passed as an argument.  
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int get_n_c(char *,int);

int main() {

	int size = 0;
	char *pstr;

	puts("Enter the size of a string.");
	scanf("%d", &size);

	pstr = (char *)malloc(sizeof(char)*(size + 1));

	printf("Total char %d\n", get_n_c(pstr,size));
	puts(pstr);

	free(pstr);
	pstr = NULL;

	system("pause");
	return 0;
}

int get_n_c(char *pstr,int size) {
	int count = 0;

	while (getchar() != '\n') {
		continue;
	}

	for (; count < size; count++) {
		pstr[count] = getchar();
	}
	pstr[size] = '\0';

	return count;
}