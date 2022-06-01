/*
 * EX1_Check_Prime.c
 *
 *  Created on: May 31, 2022
 *      Author: KHLOUD MOHAMED
 */
#include <stdio.h>
int check_prime(int number);
int main()
{
	int i , number1 , number2 , flag;
	printf("Enter two numbers(intervals): ");
	fflush(stdout);   fflush(stdin);
	scanf("%d %d",&number1 , &number2);
	printf("Prime numbers between %d and %d are: ",number1
			, number2);
	fflush(stdout);   fflush(stdin);
	for(i=number1 + 1 ; i<number2 ; i++)
	{
		flag = check_prime(i);
		if(flag == 0)
		{
			printf("%d ",i);
		}
	}

}
int check_prime(int number)
{
	int i , flag=0;
	for(i=2 ; i<=number/2 ; i++)
	{
		if(number%i == 0 )
		{
			flag =1 ;
			break;
		}
	}
	return flag;
}
