/*Write a program that opens two files. 
 *You can obtain the filenames either by using command-line arguments or by soliciting the user to enter them. 
 *		a.Have the program print line 1 of the first file, line 1 of the second file, 
 *			line 2 of the first file, line 2 of the second file, and so on, 
 *			until the last line of the longer file (in terms of lines) is printed.      
 *		b.Modify the program so that lines with the same line number are printed on the same line. 
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1024

int main(int argc, char *argv[]) {

	FILE *fp, *fp2;
	char buf[SIZE];
	char buf2[SIZE];

	if ((fp = fopen(argv[1], "r")) == NULL || (fp2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "ERROR");
		exit(EXIT_FAILURE);
	}

	while ((feof(fp) == 0) || (feof(fp2) == 0)) {
		if (fgets(buf, 1024, fp) != NULL) {
			int len = strlen(buf);
			/*Question b */
			if (buf[len - 1] == '\n') {
				buf[len - 1] = '\0';
			}
			fputs(buf, stdout);
		}
		if (fgets(buf2, 1024, fp2) != NULL) {
			fputs(buf2, stdout);
		}
	}
	

	fclose(fp);
	fclose(fp2);

	system("pause");
	return 0;
}