/*
 * Q3_Write_a_program_in_C_to_print_a_string_in_reverse_using_a_pointer.c
 *
 *  Created on: Jun 27, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int main()
{
	char str[50] , rev[50];
	char *pstr ,*prev;
	int i = -1;
	pstr = str;
	prev = rev;

	printf("The Alphabets are : \n");
	printf("Test Data : \n");
	printf("Input a string : ");
	fflush(stdout);   fflush(stdin);
	gets(str);

	printf("Pointer : Print a string in reverse order : \n");
	printf("----------------------------------------------\n");
	printf("Input a string : %s\n\n",str);

	while(*pstr)
	{
		pstr++;
		i++;
	}

	while(i>=0)
	{
		pstr--;
		*prev = *pstr;
		prev++;
		--i;

	}
	*prev = '\0';

	printf("Reverse of the string is : %s ",rev);
	return 0 ;
}

