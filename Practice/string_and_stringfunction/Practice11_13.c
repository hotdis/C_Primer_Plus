/*Write a program that echoes the command-line arguments in reverse word order. 
 *That is, if the command-line arguments are see you later, the program should print later you see.    
 */
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]) {

	if (argc < 2) {
		fprintf(stderr,"Too less arguments.");
		exit(EXIT_FAILURE);
	}

	for (int i = 1,j = argc - 1; i < j; i++,j--) {
		char *pstr = argv[i];
		argv[i] = argv[j];
		argv[j] = pstr;

	}

	for (int i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}

	system("pause");
	return 0;
}