/*
 * Reverse_array.c
 *
 *  Created on: Jun 13, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

void reverse(int size , int a[]);

int main()
{
	int array[100] , i , size;
	printf("Enter The Size of Array: ");
	fflush(stdout);    fflush(stdin);
	scanf("%d",&size);

	printf("Enter Array: ");
	fflush(stdout);    fflush(stdin);
    for(i=0 ; i<size ; i++)
    {
    	scanf("%d",&array[i]);
    }

    reverse(size,array);
	return 0;
}

void reverse(int size , int a[])
{
	printf("Array After Reverse: ");
	fflush(stdout);    fflush(stdin);
    for(int i=size-1 ; i>=0 ; i--)
    {
    	printf("%d  ",a[i]);
    }
}
