/*Write a program that takes as command-line arguments a character and zero or more filenames. 
 *If no arguments follow the character, have the program read the standard input. 
 *Otherwise, have it open each file in turn and report how many times the character appears in each file. 
 *The filename and the character itself should be reported along with the count. 
 *Include error-checking to see whether the number of arguments is correct and whether the files can be opened. 
 *If a file can¡¯t be opened, have the program report that fact and go on to the next file. 
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

	FILE *fp;
	char ch;

	if (argc < 3) {
		puts("Too less arguments.");
		exit(EXIT_FAILURE);
	}
		
	for (int i = 2; i < argc; i++) {

		if ((fp = fopen(argv[i], "r+")) == NULL) {
			fprintf(stderr, "Can't open file %s.\n", argv[i]);
			continue;
		}
		int count = 0;

		while ((ch = getc(fp)) != EOF) {
			if (ch == argv[1][0]) {
				count++;
			}
		}
		printf("%c appears %d times.\n", argv[1][0], count);
		fclose(fp);
	}



	system("pause");
	return 0;
}