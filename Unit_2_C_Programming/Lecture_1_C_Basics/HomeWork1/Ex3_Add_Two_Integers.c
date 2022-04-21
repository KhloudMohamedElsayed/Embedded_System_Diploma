/*
 * Ex3_Add_Two_Integers.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */

/*C Program to Add Two Integers*/

#include "stdio.h"

int main()
{
	int num1 , num2 , sum=0;
	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	sum = num1 + num2;
	printf("Sum: %d",sum);
	return 0;
}



