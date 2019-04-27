/*Write a program that echoes the command-line arguments in reverse word order.
 *That is, if the command-line arguments are see you later ,the program should print later you see.    
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc,char *argv[]) {

	double base, result;
	int mi;

	if (argc < 2) {
		fprintf(stderr, "Error");
		exit(EXIT_FAILURE);
	}

	base = atof(argv[1]);
	mi = atoi(argv[2]);

	result = pow(base, mi);
	printf("result is %lf\n", result);

	system("pause");
	return 0;
}