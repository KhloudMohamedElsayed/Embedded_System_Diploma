/*
 * Ex3_Find_The_Largest_Number_Among_Three.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */

/* Find The Largest Number Among Three Numbers*/
#include "stdio.h"
int main()
{
	float num1 , num2 , num3 , max ;
	printf("Enter three numbers: ");
	fflush(stdout);
	scanf("%f %f %f",&num1,&num2,&num3);
	if((num1>num2) && (num1>num3))
	{
		max = num1;
	}
	else if((num2>num1) && (num2>num3))
	{
		max = num2;
	}
	else
	{
		max = num3;
	}

	printf("Largest number = %.2f",max);
	return 0;
}
