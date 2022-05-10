/*
 * Ex2_Find_Length_of_String.c
 *
 *  Created on: May 10, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int main()
{
	char arr[100];
	int num=0 , i;
	printf("Enter a string: ");
	fflush(stdin);     fflush(stdout);
	gets(arr);
	printf("\n");

	for(i=0; arr[i]!='\0'; i++)
	{
		num++;
	}
	printf("Length of string: %d",num);
	return 0;
}

