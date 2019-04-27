/*Write a program that opens a text file whose name is obtained interactively. 
 *Set up a loop that asks the user to enter a file position. 
 *The program then should print the part of the file starting at that 
 *position and proceed to the next newline character. 
 *Let negative or nonnumeric input terminate the user-input loop. 
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {

	FILE *fp;
	char fname[25];
	long num;
	char ch;
	
	puts("Select your file.");
	scanf("%24s", fname);

	if ((fp = fopen(fname, "r+")) == NULL) {
		fprintf(stderr, "ERROR");
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0L, SEEK_END);
	printf("File has %d char total.\n", ftell(fp));

	puts("Enter a position.");
	while (1 == scanf("%ld", &num)) {
		rewind(fp);
		fseek(fp, num, SEEK_SET);

		while ((ch = getc(fp)) != '\n'&& ch != EOF) {
			putc(ch, stdout);
		}

		puts("\nEnter a position(q to quit).");
	}

	fclose(fp);

	puts("Done");

	system("pause");
	return 0;
}