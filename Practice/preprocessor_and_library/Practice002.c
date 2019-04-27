/*The ANSI library features a  clock()  function with this description: 
 *#include <time.h> 
 *clock_t clock (void);   
 *
 *Here, clock_t is a type defined in time.h. 
 *The function returns the processor time, which is given in some implementation-dependent units. 
 *(If the processor time is unavailable or cannot be represented, the function returns a value of  -1 .)
 *
 *However, CLOCKS_PER_SEC , also defined in  time.h , is the number of processor time units per second. 
 *Therefore, dividing the difference between two return values of  clock()  by 
 *CLOCKS_PER_SEC  gives you the number of seconds elapsed between the two calls.
 *Typecasting the values to  double  before division enables you to get fractions of a second. 
 *Write a function that takes a  double  argument representing a desired time delay and 
 *772 Chapter 16 The C Preprocessor and the C Library
 *then runs a loop until that amount of time has passed. Write a simple program that tests the function.   
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(double);

int main() {
	double ptime = (double)clock();
	
	delay(4.321);

	double atime = (double )clock();

	double time_0 = (atime - ptime) / CLOCKS_PER_SEC;

	printf("%0.5lf\n", time_0);

	system("pause");
	return 0;
}

void delay(double time_0) {
	double ptime = (double)clock();
	double atime;

	while (((atime = (double)clock()) - ptime) / CLOCKS_PER_SEC < time_0);

}