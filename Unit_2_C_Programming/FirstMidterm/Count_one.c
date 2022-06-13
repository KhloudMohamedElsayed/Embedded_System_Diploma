/*
 * Count_one.c
 *
 *  Created on: Jun 13, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

int CountOne(int number);

int main()
{
    int number;
    printf("Enter a number: ");
    fflush(stdout);     fflush(stdin);
    scanf("%d",&number);

    printf("%d", CountOne(number));

    return 0;
}

int CountOne(int number)
{
	int count = 0;
	while(number)
	{
		count += number&1;
		number >>=1;
	}
	return count;
}
