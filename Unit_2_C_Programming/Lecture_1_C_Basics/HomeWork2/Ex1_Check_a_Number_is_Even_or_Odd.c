/*
 * Ex1_Check_a_Number_is_Even_or_Odd.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */

/* Check a Number is Even or Odd*/
#include "stdio.h"

int main()
{
	int number;
	printf("Enter an integer you want to check: ");
	fflush(stdout);
	scanf("%d",&number);

	if(number%2 == 0)
	{
		printf("%d is even",number);
	}
	else
	{
		printf("%d is odd",number);
	}
	return 0;
}


