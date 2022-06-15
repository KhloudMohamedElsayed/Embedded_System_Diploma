/*
 * find_area_of_a_circle_passing_arguments_to_macros.c
 *
 *  Created on: Jun 15, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<Stdio.h>

#define P 3.1415
#define area(r) (P*(r)*(r))

int main()
{
	int radius ;
	float AreaOfCircle;

	printf("Enter the radius: ");
	fflush(stdout);   fflush(stdin);
	scanf("%d",&radius);

	AreaOfCircle = area(radius);

	printf("Area = %0.2f",AreaOfCircle);

	return 0;
}

