/*
 * Ex6_Swap_Two_Numbers.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */
/* Swap Two Numbers */

#include "stdio.h"

int main()
{
	float num1 , num2 , temp ;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&num1);

	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f",&num2);

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("\nAfter swapping, value of a = %.2f \n",num1);
	printf("After swapping, value of b = %.1f",num2);
	return 0;
}



