/*Write a program that reads input until end-of-file and echoes it to the display. 
 *Have the program recognize and implement the following command-line arguments: 
  -p    Print input as is 
  -u    Map input to all uppercase 
  -l    Map input to all lowercase 
 *Also,if there are no command-line arguments, 
 *let the program behave as if the ¨Cp argument had been used
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(int argc,char *argv[]) {
	char str[1024];
	fgets(str, 1024, stdin);

	if (argc < 2 || strcmp("-p", argv[1]) == 0) {
		fputs(str,stdout);
	}
	else if (strcmp("-u", argv[1]) == 0) {
		for (int i = 0; i < (int)strlen(str); i++) {
			putchar(toupper(str[i]));
		}
	}
	else if (strcmp("-l", argv[1]) == 0) {
		for (int i = 0; i < (int)strlen(str); i++) {
			putchar(tolower(str[i]));
		}
	}
	else;
	
	puts("Done");
	system("pause");
	return 0;
}
