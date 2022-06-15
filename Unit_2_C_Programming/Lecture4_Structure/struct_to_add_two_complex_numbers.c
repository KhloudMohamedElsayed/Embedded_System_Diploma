/*
 * struct_to_add_two_complex_numbers.c
 *
 *  Created on: Jun 15, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

struct S_Number{
	float RealNumber;
	float ImaginaryNumber;
};

struct S_Number AddNumbers(struct S_Number number1 , struct S_Number number2);

int main()
{
	struct S_Number number1 , number2 , result;

	printf("For 1st complex number\n");
	fflush(stdout);    fflush(stdin);
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);    fflush(stdin);
    scanf("%f %f",&number1.RealNumber,&number1.ImaginaryNumber);

    printf("\nFor 2nd complex number\n");
    fflush(stdout);    fflush(stdin);
    printf("Enter real and imaginary respectively: ");
    fflush(stdout);    fflush(stdin);
    scanf("%f %f",&number2.RealNumber,&number2.ImaginaryNumber);

    result = AddNumbers(number1,number2);
    printf("Sum = %0.1f+%0.1fi",result.RealNumber,result.ImaginaryNumber);

	return 0;
}

struct S_Number AddNumbers(struct S_Number number1 ,struct S_Number number2)
{
	struct S_Number sum;
	sum.RealNumber = number1.RealNumber + number2.RealNumber;
	sum.ImaginaryNumber = number1.ImaginaryNumber + number2.ImaginaryNumber;
	return sum;
}
