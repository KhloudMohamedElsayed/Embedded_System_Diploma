/*
 * Ex5_Find_ASCII_Value_of_a_Character.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */


/* Find ASCII value of a Character*/

#include "stdio.h"

int main()
{
	char character;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&character);
	printf("ASCII value of %c = %d",character,character);
	return 0;
}


