/*
 * sum_numbers_from_1_to_100.c
 *
 *  Created on: Jun 13, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

int i=0 , sum=0;
int main()
{
	if(i<=100)
	{
		sum += i ;
		i++;
		main();
	}
	if(i == 101)
	{
		printf("sum numbers from 1 to 100 = %d",sum);
		i=102;
	}
   return 0;
}
