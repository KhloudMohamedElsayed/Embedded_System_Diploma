/*
 * Ex8_Simple_Calculator.c
 *
 *  Created on: Apr 20, 2022
 *      Author: KHLOUD MOHAMED
 */

#include "stdio.h"
int main()
{
	char op;
	float num1 , num2 , result=0.0;
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdout);
	scanf("%c",&op);

	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f %f",&num1 ,&num2);

	switch(op)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		if(num1 == 0)
		{
			printf("Error \r\n");
		}
		else
		{
			result = num1 / num2;
		}
		break;
	default:
		printf("Error Operator");
		break;
	}

	if((num1==0) && (op == '/'))
	{
		printf("Error Divide");
	}
	else
	{
		printf("%.1f %c %.1f = %.1f",num1 ,op,num2,result);
	}
	return 0;
}

