/*
 * Ex2_Print_a_Integer_Entered_by_a_User.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */

/* C Program to Print a Integer Entered by a User*/

#include "stdio.h"

int main()
{
	int number;
	printf("Enter a integer: ");
	fflush(stdout);
	scanf("%d",&number);
	printf("You entered: %d",number);

	return 0 ;
}



