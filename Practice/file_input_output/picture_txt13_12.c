/*Create a text file consisting of 20 rows of 30 integers. 
 *The integers should be in the range 0¨C9 and be separated by spaces. 
 *The file is a digital representation of a picture, 
 *with the values 0 through 9 representing increasing levels of darkness. 
 *Write a program that reads the contents of the file into a 20-by-30 array of  int s. 
 *In a crude approach toward converting this digital representation to a picture,  
 *have the program use the values in this array to initialize a 20-by-31 array of char s, 
 *with a 0 value corresponding to a space character, a 1 value to the period character,  
 *and so on, with each larger number represented by a character that occupies more space. 
 *For example, you might use  #  to represent 9. 
 *The last character (the 31st) in each row should be a null character, making it an array of 20 strings. 
 *Have the program display the resulting picture 
 *(that is, print the strings) and also store the result in a text file. 
 *For example, suppose you start with this data:
  0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0  
  0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0  
  0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0  
  0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0  
  0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0  
  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0  
  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0  
  5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
  8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8  
  9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9  
  8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8 
  5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5  
  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0  
  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0  
  0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0  
  0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0  
  0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0  
  0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0 
  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0  
  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0   
 
 *For one particular choice of output characters, the output looks like this: 
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 30
#define COLUMNS 32
#define WRITEIN

void writein_randomdata();
void show_picture();

int main() {
	srand((unsigned int)time(0));

#ifndef WRITEIN
	writein_randomdata();
#else
	show_picture();
#endif

	system("pause");
	return 0;
}

void writein_randomdata() {
	FILE *fp;
	char picture[ROWS][COLUMNS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS - 2; j++) {
			picture[i][j] = rand() % 10 + '0';
		}
		picture[i][COLUMNS - 2] = '\n';
		picture[i][COLUMNS - 1] = '\0';
	}

	if ((fp = (fopen("picture.txt", "w+"))) == NULL) {
		fprintf(stderr, "Error");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < ROWS; i++) {
		fputs(picture[i], fp);
	}
}

void show_picture() {

	FILE *fp;
	char picture[ROWS][COLUMNS];
	char ch;

	if ((fp = fopen("picture.txt", "r+")) == NULL) {
		fprintf(stderr, "ERROR");
		exit(EXIT_FAILURE);
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
}