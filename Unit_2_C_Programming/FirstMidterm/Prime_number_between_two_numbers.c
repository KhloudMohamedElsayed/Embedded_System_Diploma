/*
 * Prime_number_between_two_numbers.c
 *
 *  Created on: Jun 13, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

int main()
{
	int number1 , number2 , i , j , flag;
	printf("Enter two numbers : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d %d",&number1 , &number2);

	printf("Prime numbers between %d and %d are : \n",number1,number2);
	for(i=number1 ; i<number2; ++i)
	{
		flag = 0;
		for(j=2 ; j<=i/2 ; ++j)
		{
			if(i % j == 0)
			{
				flag=1;
			}

		}
		if(flag==0)
		{
			printf("%d  ",i);
		}

	}

	return 0;
}

