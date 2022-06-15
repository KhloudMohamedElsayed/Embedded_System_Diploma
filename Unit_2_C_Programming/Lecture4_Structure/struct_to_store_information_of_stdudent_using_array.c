/*
 * struct_to_store_information_of_stdudent_using_array.c
 *
 *  Created on: Jun 15, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

struct S_Student{
	char name[50];
	int roll;
	float marks;
};

int main()
{
	struct S_Student student[5];
	int i;
	printf("Enter information of students: \n\n");
	fflush(stdout);    fflush(stdin);

	for(i=0 ; i<5 ; i++)
	{
		student[i].roll = i+1;
		printf("For roll number %d\n",student[i].roll);
		printf("Enter name: ");
		fflush(stdout);    fflush(stdin);
        gets(student[i].name);
        printf("Enter marks: ");
    	fflush(stdout);    fflush(stdin);
        scanf("%f",&student[i].marks);
        printf("\n");
    }

	printf("Displaying information of students: \n");
	fflush(stdout);    fflush(stdin);
    for(i=0 ; i<5 ; i++)
    {
    	printf("\nInformation for roll number %d\n",student[i].roll);
    	printf("Name: %s\n",student[i].name);
    	printf("Marks: %0.1f\n",student[i].marks);
    }
	return 0;
}

