/*Modify Listing 13.1 so that it solicits the user to enter the filename 
 *and reads the user¡¯s response instead of using command-line arguments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>]

char *s_gets(char *, int);

int main() {

	FILE *fp;
	char fname[31];
	char ch;

	puts("Enter the name of the file.");
	s_gets(fname, 31);

	if ((fp = fopen(fname, "w")) == NULL) {
		fprintf(stderr, "Error to open.");
		exit(EXIT_FAILURE);
	}

	puts("TXT content.");
	while ((ch = getchar()) != EOF) {
		putc(ch,fp);
	}

	fclose(fp);

	system("pause");
	return 0;
}

char* s_gets(char *str, int num) {

	char *pstr = fgets(str, num, stdin);

	int i = 0;
	if (pstr) {
		while (str[i] != '\n' && str[i] != '\0') {
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
	
	return pstr;
}