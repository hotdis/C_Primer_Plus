#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

double *new_d_array(int n, ...);
void show_array(const double[], int);

int main() {
	
	double *p1;
	double *p2;

	p1 = new_d_array(3, 1.2, 2.2, 3.2);
	p2 = new_d_array(2, 4.2, 5.2);

	show_array(p1, 3);
	show_array(p2, 2);

	free(p1);
	free(p2);

	system("pause");
	return 0;
}

double *new_d_array(int n, ...) {
	va_list ap;
	va_start(ap,n);

	double *parr = (double *)malloc(sizeof(double)*n);

	for (int i = 0; i < n; i++) {
		parr[i] = va_arg(ap, double);
	}
	va_end(ap);

	return parr;
}

void show_array(const double ar[], int n) {
	for (int i = 0; i < n; i++) {
		printf("*%0.2lf ", ar[i]);
	}

	putchar('\n');
}
