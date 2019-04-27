/*Write a file copy program that prompts the user to enter the name of a text file to act as the source file 
 *and the name of an output file.
 *The program should use the  toupper() function from ctype.h to convert all text to uppercase 
 *as it¡¯s written to the output file. 
 *Use standard I/O and the text mode.   
 */
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc,char *argv[]) {

	FILE *fp;
	char ch;
	char temp[1024];
	int i = 0;

	if ((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error");
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF) {
		if (islower(ch)) {
			temp[i++] = toupper(ch);
		}
		else {
			temp[i++] = ch;
		}
	}
	temp[i] = '\0';
	fclose(fp);

	if ((fp = fopen(argv[1], "wb")) == NULL) {
		fprintf(stderr, "Error");
		exit(EXIT_FAILURE);
	}

	for (int n = 0; n < i; n++) {
		putc(temp[n], fp);
	}

	fclose(fp);

	system("pause");
	return 0;
}