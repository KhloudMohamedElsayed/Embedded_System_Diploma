/*
 * Q2_Write_a_program_in_C_to_print_all_the_alphabets_using_a_pointer.c
 *
 *  Created on: Jun 27, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int main()
{
	char alphabets[27] , *p;
	int x;

	p = alphabets;


	for(x=0 ; x<26 ; x++)
	{
		*p = x + 'A';
		 p++;
	}
	p = alphabets;

	printf("All The Alphabets are : \n");
	for(x=0 ; x<26 ; x++)
	{

		printf("%c ",*p );
		p++;
	}

	return 0;
}

