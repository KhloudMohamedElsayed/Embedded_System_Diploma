/*
 * count_the_max_number_of_ones_between_two_zeros.c
 *
 *  Created on: Jun 13, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int counter(int number);

int main()
{
    int number;
    printf("Enter a number: ");
    fflush(stdout);     fflush(stdin);
    scanf("%d",&number);
    printf("the max number of ones between two zeros = %d ",counter(number));

	return 0;
}

int counter(int number)
{
	int num , counter=0 ,NumOfBits , NumOfOnes=0;
	for(NumOfBits=31 ; NumOfBits >= 0;NumOfBits--)
	{
		num = number >> NumOfBits ;
		if(num & 1)
		{
			counter++;
		}
		else
		{
			if(counter > NumOfOnes)
			{
				NumOfOnes = counter;
				counter=0;
			}
			else
			{
				counter=0;
			}
		}
	}
	return NumOfOnes;
}
