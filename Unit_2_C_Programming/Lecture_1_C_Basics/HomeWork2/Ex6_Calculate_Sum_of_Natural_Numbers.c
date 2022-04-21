/*
 * Ex6_Calculate_Sum_of_Natural_Numbers.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */
#include "stdio.h"
int main()
{
	int num ,i , sum=0 ;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&num);
	for(i=1 ; i<=num ; i++)
	{
		sum += i;

	}
	printf("Sum = %d " ,sum );
	return 0;
}

