/*
 * Q5_show_a_pointer_to_an_array_which_contents_are_pointer_to_structure.c
 *
 *  Created on: Jun 28, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>
struct employee{
	char name[10];
	int id;
}Employee1;

int main()
{
	struct employee emp1={"Alex",1002}, emp2={"Khloud",1003}, emp3={"Mohamed",1004};

	struct employee *array[]={&emp1,&emp2,&emp3};

	struct employee*(*Parray_emp)[3]= &array;

	printf(" Employee Name : %s \n",(*(*Parray_emp))->name);
	printf(" Employee ID :  %d \n",(*(*Parray_emp))->id);

   return 0;
}

