/*
 * struct_to_add_two_distance.c
 *
 *  Created on: Jun 15, 2022
 *      Author: KHLOUD MOHAMED
 */
#include<stdio.h>

struct S_Distance{
	int feet;
	float inch;
}distance1,distance2,sum;

int main()
{
	printf("Enter information for 1st distance\n");
	fflush(stdout);    fflush(stdin);

	printf("Enter feet: ");
	fflush(stdout);    fflush(stdin);
    scanf("%d",&distance1.feet);

    printf("Enter inch: ");
    fflush(stdout);    fflush(stdin);
    scanf("%f",&distance1.inch);

    printf("\nEnter information for 2nd distance\n");
    fflush(stdout);    fflush(stdin);

    printf("Enter feet: ");
    fflush(stdout);    fflush(stdin);
    scanf("%d",&distance2.feet);

    printf("Enter inch: ");
    fflush(stdout);    fflush(stdin);
    scanf("%f",&distance2.inch);

    sum.feet = distance1.feet + distance2.feet;
    sum.inch = distance1.inch + distance2.inch;

    if(sum.inch > 12.0)
    {
    	sum.inch = sum.inch - 12.0;
    	++sum.feet;
    }
    printf("\n sum of distance = %d\'-%0.1f\"",sum.feet,sum.inch);
    return 0;
}

