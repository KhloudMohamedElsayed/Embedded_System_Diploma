/*
 * Ex1_Sum_Two_Matrix.c
 *
 *  Created on: May 9, 2022
 *      Author: KHLOUD MOHAMED
 */
#include <stdio.h>
int main()
{
	float matrix1 [2][2];
	float matrix2 [2][2];
	float Sum_matrix [2][2];
	int i , j;
	printf("Enter the elements of 1st matrix\n");
	fflush(stdin);  fflush(stdout);
	for(i=0 ; i<2 ; i++)
	{
		for( j=0 ; j<2 ; j++)
		{
			printf("Enter a%d%d: ", i+1 , j+1);
			fflush(stdin);  fflush(stdout);
			scanf("%f",&matrix1[i][j]);
		}
	}

	printf("Enter the elements of 2st matrix\n");
	fflush(stdin);  fflush(stdout);
	for( i=0 ; i<2 ; i++)
	{
		for( j=0 ; j<2 ; j++)
		{
			printf("Enter a%d%d: ", i+1 , j+1);
			fflush(stdin);  fflush(stdout);
			scanf("%f",&matrix2[i][j]);
		}
	}

	printf("\nSum of Matrix \n");
	fflush(stdin);  fflush(stdout);
	for(i=0 ; i<2 ; i++)
	{
		for(j=0 ; j<2 ; j++)
		{
			 Sum_matrix[i][j] = matrix1[i][j] +matrix2[i][j] ;
			printf("%0.1f    ", Sum_matrix[i][j]);

		}
		printf("\n");
	}


	return 0 ;
}



