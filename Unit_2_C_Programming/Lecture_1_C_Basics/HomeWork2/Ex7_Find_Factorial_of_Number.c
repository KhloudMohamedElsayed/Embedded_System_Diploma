/*
 * Ex7_Find_Factorial_of_Number.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */

#include "stdio.h"
int main()
{
	int num , i ,  fact=1;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&num);
	if(num>0)
	{
		for(i=1 ; i<=num ; i++)
		{
			fact *= i;
		}
		printf("Factorial = %d",fact);
	}
	else
	{
		printf("Error!!! Factorial of negative number doesn't exist");
	}
	return 0;
}

