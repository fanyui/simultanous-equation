#include <stdio.h>
#include <stdlib.h>
#include "linear_system.h"

float **triangular(float **matrix,int N,int M,int aug)//aug which have value (1 or 0) inform if we are performing Gauss or LU
{
float **lower= (float**)malloc(N*sizeof(float*)), x;
int i,j,u,index;


        for(i =0;i<N;i++)//allocate memory for the lower triangular matrix and initialize it to zero
            lower[i]=(float*)calloc((N+1),sizeof(float));


        for(i=1;i<N;i++)//we start to make the matrix (or augmented matrix) triangular at row 1
        {
            u=i;
            j=i-1;//we start a column i-1 after each iteration of the "for" loop above
            index=1;

            if(matrix[j][j]==0)//if a member of the diagonal="0" we try to change the row
                index= change_row(j,M,matrix,lower);

            if(index==1)//if the row is changed we combine the new row j by the row below
            {
                do
                {
                    x= (float) ((-matrix[i][j])/matrix[j][j]);// the coefficient of proportionality among row the leading diagonal of row j and the element of row below on the same column

                    if(i>j)
                        lower[i][j]=-x;//we put the coefficient of proportionality in the lower triangular

                    while(j<M-aug)//"M-aug" correspond to the number of column of the matrix(or augmented matrix)
                    {
                        matrix[i][j]=(float) ((x*matrix[u-1][j])+matrix[i][j]);//Put all the entries below the pivot position to be 0
                        j++;
                    }
                    i++;
                    j=u-1;
                }while(i<N);
                i=u;//the variable u helps as a copy of variable i which change during the implementation above
            }
            if(aug==1)//if we are doing LU decomposition we print the L&U matrix in each iteration of the "for" loop
            {
                printf("\nStep_%d\n",i);
                display(lower,N,2);
                display(matrix,N,3);
            }
        }

return lower;
}
