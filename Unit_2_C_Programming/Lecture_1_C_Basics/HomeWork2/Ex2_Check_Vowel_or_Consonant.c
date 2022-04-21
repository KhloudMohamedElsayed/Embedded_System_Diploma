/*
 * Ex2_Check_Vowel_or_Consonant.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */

/* Check Vowel Or Consonant */
#include "stdio.h"

int main()
{
	char character ;
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c",&character);

	if((character == 'a') || (character == 'A') ||(character == 'e') ||
			(character == 'E') ||(character == 'i') || (character == 'I')
			||(character == 'o') || (character == 'O') ||
			(character == 'u') || (character == 'U') )
	{
		printf("%c is a vowel",character);
	}
	else
	{
		printf("%c is a consonant",character);
	}
	return 0;
}



