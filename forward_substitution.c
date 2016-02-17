#include <stdio.h>
#include <stdlib.h>

void forwards(float **lower,float **matrix,float *b,int N)
{
    float sum;
    int i=0,j;

        matrix[0][N]=b[0];//the loop below will perform the forward substitution

        do
       {
            i++;
            sum=0;
            j=0;
           while(j<i)
           {
               sum+=(lower[i][j])*(matrix[j][N]);
               j++;
           }
            matrix[i][N]=matrix[i][N]-sum;

       }while(i<N-1);
}


