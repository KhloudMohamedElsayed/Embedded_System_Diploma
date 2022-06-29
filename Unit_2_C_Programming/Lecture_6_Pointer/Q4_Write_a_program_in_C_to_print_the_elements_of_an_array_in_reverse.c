/*
 * Q4_Write_a_program_in_C_to_print_the_elements_of_an_array_in_reverse.c
 *
 *  Created on: Jun 28, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int main()
{
	int size , i , array[15];
	int *ptr;

	ptr = &array[0];

	printf("Input the number of elements to store in the array (max 15) :");
	fflush(stdout);      fflush(stdin);
    scanf("%d",&size);

    printf("Input %d number of elements in the array : \n",size);
    fflush(stdout);      fflush(stdin);
    for(i=0 ; i<size ; i++)
    {
    	printf("element - %d : ",i+1);
    	fflush(stdout);      fflush(stdin);
    	scanf("%d",ptr);
    	ptr++;

    }

    ptr = &array[size-1];

    printf("\nThe elements of array in reverse order are : \n");
    for(i=size ; i>0 ; i--)
    {
    	printf("element - %d : %d\n",i,*ptr);
    	ptr--;
    }

  return 0;
}

