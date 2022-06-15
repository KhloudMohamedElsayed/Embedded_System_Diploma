/*
 * struct_to_store_information_of_student.c
 *
 *  Created on: Jun 15, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

struct S_Student{
	char m_Name[50];
	int m_RollNumber;
	float m_Mark;
};

int main()
{
	struct S_Student Student;

	printf("Enter information of students: \n\n");
	fflush(stdin);    fflush(stdout);

	printf("Enter name: ");
	fflush(stdin);    fflush(stdout);
    gets(Student.m_Name);

    printf("Enter roll number: ");
    fflush(stdin);    fflush(stdout);
    scanf("%d",&Student.m_RollNumber);

    printf("Enter marks: ");
    fflush(stdin);    fflush(stdout);
    scanf("%f",&Student.m_Mark);

    printf("\nDisplaying Information \n");
    fflush(stdin);    fflush(stdout);

    printf("name : %s\n",Student.m_Name);
    printf("Roll : %d\n",Student.m_RollNumber);
    printf("Marks : %0.2f\n",Student.m_Mark);



	return 0;
}

