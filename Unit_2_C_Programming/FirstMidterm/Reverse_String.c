/*
 * Reverse_String.c
 *
 *  Created on: Jun 13, 2022
 *      Author: KHLOUD MOHAMED
 */


#include<stdio.h>
#include<string.h>
int main()
{
	char name[100] , reverse[100];
	int length , i , index , start , end;
	printf("Enter name: ");
	fflush(stdout);   fflush(stdin);
	gets(name);

	length = strlen(name);
	index = 0;
	start = length - 1 ;
	end = length - 1 ;
	while(start>0)
	{
		if(name[start] == ' ')
		{
			i = start + 1 ;
			while(i <= end )
			{
				reverse[index] = name[i];
				i++;
				index++;
			}
			reverse[index++] = ' ';
			end = start - 1 ;
		}
		start--;
	}
	for(i=0 ; i<=end; i++)
	{
		reverse[index] = name[i];
		index++;
	}
	reverse[index] = '\0';
	printf("name : %s\n",name);
	printf("reverse name : %s ",reverse);
	return 0;
}

