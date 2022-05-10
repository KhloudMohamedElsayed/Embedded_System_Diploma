/*
 * Ex2_Calculate_Average_Using_Arrays.c
 *
 *  Created on: May 9, 2022
 *      Author: KHLOUD MOHAMED
 */
#include <stdio.h>
int main()
{
	int size;
    float array[100];
    float average = 0.0;
    printf("Enter the numbers of data: ");
    fflush(stdin);     fflush(stdout);
    scanf("%d",&size);
    for(int i=0 ; i<size ; i++)
    {
    	printf("%d. Enter number: ",i+1);
    	fflush(stdin);     fflush(stdout);
    	scanf("%f",&array[i]);
    }

    for(int j=0 ; j<size ; j++)
    {
    	average += array[j];
    }
    average /= size;
    printf("Average = %.2f",average);
	return 0 ;

}


