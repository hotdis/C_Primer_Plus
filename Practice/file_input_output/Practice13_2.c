/*Write a file-copy program that takes the original filename and the copy file from the command line.
 *Use standard I/O and the binary mode, if possible.   
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

	FILE *fps, *fpc;
	char ch;

	if (argc < 3) {
		printf("Too less argement count.");
	}

	if ((fps = fopen(argv[1], "rb")) == NULL || (fpc = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Error");
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fps)) != EOF) {
		putc(ch, fpc);
	}

	fclose(fps);
	fclose(fpc);

	system("pause");
	return 0;
}