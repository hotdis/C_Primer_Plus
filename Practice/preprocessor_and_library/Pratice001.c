/*The harmonic mean of two numbers is obtained by taking the inverses of the two numbers, 
 *averaging them, and taking the inverse of the result. 
 *Use a  #define  directive to define a macro ¡°function¡± that performs this operation. 
 *Write a simple program that tests the macro.
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

#define HARMONIC_MEAN(X,Y) (1/(((1/X)+(1/Y))/2))

int main()
{
	double x = 0, y = 0;

	puts("Enter two double type digits : ");
	while (2 == scanf("%lf%lf", &x, &y))
	{
		if (x == 0 || y == 0)
		{
			puts("Enter error.X or Y can't be zero.");
			continue;
		}

		printf("The harmonic mean : %0.2lf\n", HARMONIC_MEAN(x, y));
		puts("Enter two double type digits(q to quit.) : ");
	}

	puts("Done.");

	system("pause");
	return 0;
}