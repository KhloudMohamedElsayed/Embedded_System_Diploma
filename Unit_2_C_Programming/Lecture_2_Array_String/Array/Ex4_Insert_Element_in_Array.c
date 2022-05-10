/*
 * Ex4_Insert_Element_in_Array.c
 *
 *  Created on: May 9, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int main()
{
	int array[100];
	int i , number_elements , location , inserted_number;
	/*Entered number of elements in array*/
	printf("Enter no of elements : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&number_elements);

	printf("Enter Elements : \n");
	fflush(stdin);    fflush(stdout);
	/*Entered elements in array*/
	for(i=0; i<number_elements; i++)
	{
		scanf("%d",&array[i]);
	}
	printf("\n");

	/* element insert in array*/
	printf("Enter the element to be inserted : ");
	fflush(stdin);    fflush(stdout);
    scanf("%d",&inserted_number);
    printf("\n");

    printf("Enter the location : ");
    fflush(stdin);    fflush(stdout);
    scanf("%d",&location);
    printf("\n");

    /*Inserting*/
    for(i= number_elements-1 ; i>0 ; i--)
    {
    	array[i+1] = array[i];
    	if(i == location-1)
    	{
    		array[i] = inserted_number;
    	}
    }

    /* Display Array*/
    for(i=0 ; i<number_elements+1 ; i++)
    {
    	printf("%d ",array[i]);
    }
	return 0;
}

