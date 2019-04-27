/*Modify the program in Listing 13.3 so that each word is numbered according to the order in which 
 *it was added to the list, starting with 1 Make sure that, when the program is run a second time,
 *new word numbering resumes where the previous numbering left off.
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

static int count = 0;

int main(int argc,char *argv[]) {

	FILE *fp;
	char word[26];
	char ch;

	if ((fp = fopen(argv[1], "a+")) == NULL) {
		fprintf(stderr, "Error");
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') {
			count++;
		}
	}

	rewind(fp);

	puts("Enter words(# to quit).");
	while (fscanf(stdin,"%s", word) == 1 && word[0] != '#') {
		count++;
		fprintf(fp, "%s %d\r\n", word,count);
	}

	fclose(fp);

	system("pause");
	return 0;
}
