/*
 * unique_elements_in_array.c
 *
 *  Created on: Jun 13, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

int main()
{
	int array[10] , freq[10] , size , i , j , count;
	printf("Enter size of array : ");
	fflush(stdout);    fflush(stdin);
	scanf("%d",&size);

	printf("Enter Array: ");
	fflush(stdout);    fflush(stdin);
	for(i=0; i<size; i++)
	{
		scanf("%d",&array[i]);
		freq[i] = -1;
	}
	for(i=0 ; i<size; i++)
	{
		count = 1;
		for(j=i+1 ; j<size; j++)
		{
			if(array[i]==array[j])
			{
				count++;
				freq[j] = 0;
			}
		}
		if(freq[i] != 0)
		{
			freq[i] = count;
		}
	}
	printf("unique elements in the array: ");
	for(i=0; i<size ; i++)
	{
		if(freq[i] == 1)
		{
			printf("%d",array[i]);
		}
	}
   return 0;
}

