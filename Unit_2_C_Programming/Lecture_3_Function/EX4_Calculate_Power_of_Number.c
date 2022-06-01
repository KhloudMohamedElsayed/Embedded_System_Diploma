/*
 * EX4_Calculate_Power_of_Number.c
 *
 *  Created on: May 31, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int power(int number , int ToPower);
int main()
{
	int number , ToPower;
	printf("Enter base number: ");
	fflush(stdout);     fflush(stdin);
	scanf("%d",&number);

	printf("Enter power number(Positive integer): ");
	fflush(stdout);     fflush(stdin);
	scanf("%d",&ToPower);

	printf("%d ^ %d = %d",number,ToPower,power(number,ToPower));
	return 0 ;

}

int power(int number , int ToPower)
{
	if(ToPower==0)
		return 1;
	else if(ToPower==1)
		return number;
	else
		return (number * power(number,ToPower-1));
}
