/*
 * write_the_output_of_this_program.c
 *
 *  Created on: Jun 15, 2022
 *      Author: KHLOUD MOHAMED
 */

#include<stdio.h>
union job{
	char name[32];
	float salary;
	int worker_no;
}u;

struct job1{
	char name[32];
	float salary;
	int worker_no;
}s;

int main()
{
	printf("size of union=%d",sizeof(u));
	printf("\nsize of structure =%d",sizeof(s));

	return 0;
}
