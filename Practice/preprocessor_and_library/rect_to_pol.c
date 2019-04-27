#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define RECT_TO_POLE (180 / (4 * atan(1)))

typedef struct rect_v {
	double x;
	double y;
}RECT,*PRECT;

typedef struct pole_V {
	double magnitude;
	double angle;
}POLE,*PPOLE;

POLE rect_to_pole(PRECT);

int main()
{
	RECT input;
	POLE output;

	printf("Enter X and Y.(Or q to quit.)\n");
	while (2 == scanf("%lf%lf", &input.x, &input.y))
	{
		output = rect_to_pole(&input);
		printf("Magnitude = %0.2lf,Angle = %0.2lf\n", output.magnitude, output.angle);

		printf("Enter X and Y.(Or q to quit.)\n");
	}
	system("pasue");
	return 0;
}

POLE rect_to_pole(PRECT input)
{
	POLE output;

	output.magnitude = sqrt(input->x*input->x + input->y*input->y);
	output.angle = atan2(input->y, input->x)*RECT_TO_POLE;

	return output;
}