/*Write a program that sequentially displays onscreen all the files listed in the command line.
 *Use argc to control a loop.
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

	FILE *fp;
	char ch;

	if (argc < 2) {
		printf("Too less argument.");
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++) {
		if ((fp = fopen(argv[i], "rb")) == NULL) {
			fprintf(stderr, "ERROR");
			return 0;
		}

		while ((ch = getc(fp)) != EOF) {
			putchar(ch);
		}
		putchar('\n');
	}

	printf("=========Done=========\n");

	system("pause");
	return 0;
}