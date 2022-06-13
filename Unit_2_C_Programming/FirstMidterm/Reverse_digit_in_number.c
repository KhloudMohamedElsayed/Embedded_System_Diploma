/*
 * Reverse_digit_in_number.c
 *
 *  Created on: Jun 13, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

int main()
{
	int num , number , x=0;
	printf("Enter a number :");
	fflush(stdout);     fflush(stdin);
	scanf("%d",&number);

	num = number;
	while(number!=0)
	{
		x = x * 10;
		x = x + number%10;
		number = number/10;

	}

	printf("Reverse of the number %d = %d",num,x);
	return 0;
}

