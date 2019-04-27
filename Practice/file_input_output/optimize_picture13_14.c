/* Digital images, particularly those radioed back from spacecraft, 
 *may have glitches. Add a de-glitching function to programming exercise 12. 
 *It should compare each value to its immediate neighbors to the left and right, above and below. 
 *If the value differs by more than 1 from each of its neighbors, 
 *replace the value with the average of the neighboring values. 
 *You should round the average to the nearest integer value. 
 *Note that the points along the boundaries have fewer than four neighbors, so they require special handling
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define ROWS 30
#define COLUMNS 31

int main() {

	char picture_s[ROWS][COLUMNS];
	FILE *fp;
	char ch;

	if ((fp = fopen("picture.txt", "r+")) == NULL) {
		fprintf(stderr,"ERROR");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < ROWS; i++) {
		fgets(picture_s[i], COLUMNS, fp);
	}

	for (int i = 1; i < ROWS; i++) {
		for (int j = 1; j < COLUMNS - 1; j++) {
			if (picture_s[i][j] - 4 > \
				picture_s[i - 1][j] + picture_s[i][j - 1] + picture_s[i + 1][j] + picture_s[i][j + 1]) {
				picture_s[i][j] = \
					(picture_s[i - 1][j] + picture_s[i][j - 1] + picture_s[i + 1][j] + picture_s[i][j + 1]) / 4;
			}
		}
	}

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\0') {
			continue;
		}
		switch (ch) {
		case '1':
			putchar('1');
			break;
		case '2':
			putchar('2');
			break;
		case '3':
			putchar('3');
			break;
		case '4':
			putchar('4');
			break;
		case '5':
			putchar('5');
			break;
		case '6':
			putchar('6');
			break;
		case '7':
			putchar('7');
			break;
		case '8':
			putchar('8');
			break;
		case '9':
			putchar('9');
			break;
		case '0':
			putchar('0');
			break;
		}
		if (ch == '\n') {
			putchar('\n');
		}
	}

	fclose(fp);

	system("pause");
	return 0;
}