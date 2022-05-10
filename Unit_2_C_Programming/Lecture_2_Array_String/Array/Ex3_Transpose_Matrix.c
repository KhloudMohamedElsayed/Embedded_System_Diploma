/*
 * Ex3_Transpose_Matrix.c
 *
 *  Created on: May 9, 2022
 *      Author: KHLOUD MOHAMED
 */
#include <stdio.h>

int main()
{
	int matrix[50][50];
	int row , col  , i , j;
	printf("Enter rows and column of matrix: ");
	fflush(stdin);       fflush(stdout);
    scanf("%d %d",&row,&col);
    printf("Enter elements of matrix:\n");
	fflush(stdin);       fflush(stdout);
    /*Entered Elements*/
    for(i=0 ; i<row ; i++)
    {
    	for(j=0 ; j<col ; j++)
    	{
    		printf("Enter elements a%d%d: ",i+1,j+1);
    		fflush(stdin);       fflush(stdout);
    		scanf("%d",&matrix[i][j]);
    	}
    }

    /*Display Entered Matrix*/
    printf("Entered Matrix:\n");
	fflush(stdin);       fflush(stdout);
    for(i=0 ; i<row; i++)
    {
    	for(j=0 ; j<col ; j++)
    	{
    		printf("%d  ",matrix[i][j]);
    	}
    	printf("\n\n");
    }

    /*Transpose of Matrix*/
    printf("Transpose of Matrix:\n");
    fflush(stdin);       fflush(stdout);
    for(j=0 ; j<col ; j++)
    {
    	for(i=0 ; i<row ; i++)
    	{
    		printf("%d  ",matrix[i][j]);
    	}
    	printf("\n\n");
    }
	return 0;
}



