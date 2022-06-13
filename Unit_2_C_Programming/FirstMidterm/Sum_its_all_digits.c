/*
 * Sum_its_all_digits.c
 *
 *  Created on: Jun 12, 2022
 *      Author: KHLOUD MOHAMED
 */

#include<stdio.h>
int main()
{
	int number , rem , sum=0;
	printf("Enter a number: ");
	fflush(stdout);    fflush(stdin);
	scanf("%d",&number);

	while(number!=0)
	{
		rem = number % 10;
		sum += rem;
		number = number/10 ;

	}
	printf("sum = %d",sum);

	return 0;
}
