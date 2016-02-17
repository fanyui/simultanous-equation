#include <stdio.h>
#include <stdlib.h>

void fill_matrix(float **matrix,int N)//Here we take the coefficients of each equations

{
    int i,j;

            printf("\nEnter the coefficient of your equations line by line\n");
            for(i =0;i<N;i++)
            {
                matrix[i]=(float*)malloc((N+1)*sizeof(float));
                for(j =0;j<N;j++)
                    scanf("%f",&matrix[i][j]);
                printf("\n");
            }
}
