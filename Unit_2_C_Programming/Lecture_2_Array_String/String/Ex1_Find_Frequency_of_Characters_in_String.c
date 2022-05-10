/*
 * Ex1_Find_Frequency_of_Characters_in_String.c
 *
 *  Created on: May 10, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int main()
{
	char arr[100] , c;
    int num=0 , i ;
    printf("Enter a string: ");
    fflush(stdin);     fflush(stdout);
    gets(arr);
    printf("\n");

    printf("Enter a character to find frequency:");
    fflush(stdin);     fflush(stdout);
    scanf("%c",&c);
    printf("\n");

    for(i=0 ; arr[i]!='0' ; i++)
    {
    	if(arr[i] == c)
    	{
    		num++;
    	}
    }
    printf("Frequency of %c = %d",c,num);
	return 0;
}

