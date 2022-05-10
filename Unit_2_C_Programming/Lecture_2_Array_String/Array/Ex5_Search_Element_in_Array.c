/*
 * Ex5_Search_Element_in_Array.c
 *
 *  Created on: May 9, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int main()
{
	int array[100];
	int number_elements , i , number_Search;
	printf("Enter no of elements : ");
	fflush(stdin);   fflush(stdout);
    scanf("%d",&number_elements);

    for(i=0 ; i<number_elements ; i++)
    {
    	scanf("%d",&array[i]);
    }
    printf("\n");

    printf("Enter the elements to be searched : ");
    fflush(stdin);   fflush(stdout);
    scanf("%d",&number_Search);
    printf("\n");

    for(i=0 ; i<number_elements ; i++)
    {
    	if(array[i]==number_Search)
    	{
    		printf("Number found at the location = %d",i+1);
    	}

    }
	return 0 ;
}

