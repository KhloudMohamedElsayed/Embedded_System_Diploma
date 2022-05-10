/*
 * Ex3_Reverse_String.c
 *
 *  Created on: May 10, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[100] , temp;
	int len , i;
	printf("Enter the string : ");
	fflush(stdin);     fflush(stdout);
	gets(arr);

	/*Reversing String*/
	len=strlen(arr);
    for(i=0 ; i<len/2 ; i++)
    {
    	temp = arr[i];
    	arr[i] = arr[len-i-1];
    	arr[len-i-1] = temp;
    }
    printf("Reverse string is : %s",arr);

	return 0;
}
