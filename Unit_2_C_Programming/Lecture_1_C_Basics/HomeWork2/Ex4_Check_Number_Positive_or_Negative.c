/*
 * Ex4_Check_Number_Positive_or_Negative.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */

#include "stdio.h"
int main()
{

	float number;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%f",&number);
    if(number>0)
    {
    	printf("%.2f is positive",number);
    }
    else if(number<0)
    {
    	printf("%.2f is negative",number);
    }
    else
    {
    	printf("You entered zero");
    }
	return 0 ;
}


