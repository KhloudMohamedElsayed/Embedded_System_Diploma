/*
 * Calculate_square_root.c
 *
 *  Created on: Jun 13, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
#include<math.h>

int main()
{
	double number , root;
	printf("Enter a number: ");
	fflush(stdout);     fflush(stdin);
	scanf("%lf",&number);

	root = sqrt(number);

	printf("Square root of %.01f = %0.3f",number,root);
	return 0;
}

