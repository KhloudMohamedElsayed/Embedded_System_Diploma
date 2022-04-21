/*
 * Ex4_Multiply_two_Floating_Point_Numbers.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */

/*C Program to Multiply two Floating Point Numbers*/

#include "stdio.h"

int main()
{
	float num1 , num2 , mul;
	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f %f",&num1 ,&num2);
	mul = num1 * num2;
	printf("Product: %f",mul);

	return 0;
}
