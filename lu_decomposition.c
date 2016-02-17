#include <stdio.h>
#include <stdlib.h>
#include "linear_system.h"

void lu(int N)
{
   float **matrix,**lower,*s,*b;//The last column of matrix will contains our constant vector, lower contain The lower triangular matrix
                                //s is the solution vector
   int i,yes;

        matrix=(float**)malloc(N*sizeof(float*));
        b=(float*)malloc(N*sizeof(float));
        s=(float*)malloc(N*sizeof(float));
        lower =(float**)malloc(N*sizeof(float*));

        do
        {
            fill_matrix(matrix,N);
            display(matrix,N,1);
            printf("\n Do you want to change the matrix?\n1.Yes\n2.No\n");
            scanf("%d",&yes);
        }while(yes==1);
        do
        {
            CONSTANT_VECTOR_FILL(matrix,b,N)
            DISPLAY_CONSTANT_VECTOR(b,N)
            printf("\n Do you want to change the element of the right side?\n1.Yes\n2.No\n");
            scanf("%d",&yes);
        }while(yes==1);
        lower=triangular(matrix,N,N+1,1);
        forwards(lower,matrix,b,N);
        s=backward(matrix,N);
        PRINT_RESULT(matrix,s,b,N)
        free(lower);
}
