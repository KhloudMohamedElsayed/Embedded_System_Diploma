/*
 * EX2_Calculate_Factorial.c
 *
 *  Created on: May 31, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
int factorial(int number);
int main()
{
 int num , result;
 printf("Enter an positive integer: ");
 fflush(stdout);    fflush(stdin);
 scanf("%d",&num);
 result = factorial(num);
 printf("Factorial of %d = %d ",num,result);
 fflush(stdout);    fflush(stdin);
 return 0 ;
}
int factorial(int number)
{
	if(number!=1)
	  return number * factorial(number-1);

}

