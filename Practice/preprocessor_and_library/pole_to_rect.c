/*Polar coordinates describe a vector in terms of magnitude and the counterclockwise angle from the x-axis to the vector.
 *Rectangular coordinates describe the same vector in terms of x and y components (see F igure 16.3). 
 *Write a program that reads the magnitude and angle (in degrees) of a vector and then displays the x and y components.
 *The relevant equations are these:  x = r cos A    y = r sin A   
 *To do the conversion, use a function that takes a structure containing the polar coordinates and returns a structure containing the rectangular coordinates 
 *(or use pointers to such structures, if you prefer). 
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define POLE_TO_RECT ((4 * atan(1)) / 180)

typedef struct pole {
	double length;
	double angle;

}POLE;

typedef struct rect {
	double x;
	double y;

}RECT;

RECT pole_to_rect(POLE);

int main()
{
	POLE pole_v;
	RECT rect_v;

	puts("Enter a length and a angle in the pole.");
	while (2 == scanf("%lf%lf", &pole_v.length, &pole_v.angle))
	{
		rect_v = pole_to_rect(pole_v);
		printf("(In the rect) X : %0.2lf\tY : %0.2lf\n", rect_v.x, rect_v.y);

		puts("Enter a length and a angle in the pole(q to quit ).");
	}

	puts("Done");

	system("pause");
	return 0;
}

RECT pole_to_rect(POLE pole_v)
{
	RECT rect_v;

	rect_v.x = pole_v.length * cos(pole_v.angle * POLE_TO_RECT);
	rect_v.y = pole_v.length * sin(pole_v.angle * POLE_TO_RECT);

	return rect_v;
}

