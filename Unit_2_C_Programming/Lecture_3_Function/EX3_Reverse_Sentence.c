/*
 * EX3_Reverse_Sentence.c
 *
 *  Created on: May 31, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
void reverse();
int main()
{
	printf("Enter a sentence: ");
	fflush(stdout);       fflush(stdin);
	reverse();

	return 0;
}

void reverse()
{
	char c ;
	scanf("%c",&c);
	if(c != '\n')
	{
		reverse();
		printf("%c",c);
	}

}

