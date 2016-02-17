#include <stdio.h>
#include <stdlib.h>

int change_row(int j,int M, float **matrix,float **lower)//j is the row to change
{
float i;//i will help to swap the value of the row j.
          int k,u;//u is the row whereby j will be change


            u=j;

        while(u<M-1&&matrix[u][j]==0)//here we search if the column has a pivot by look below the leading diagonal of the column
        {
            u++;
        }

        if(u<M-1)//if the column has the pivot we interchange these rows there
        {
            for(k=0;k<M;k++)
            {
                    i=lower[u][k];
                    lower[u][k]=lower[j][k];
                    lower[j][k]=i;

                    i=matrix[j][k];
                    matrix[j][k]=matrix[u][k];
                    matrix[u][k]=i;


            }
            for(k=0;k<M-1;k++)
                for(j=0;j<M-1;j++)
                    if(j==k)
                        lower[k][k]=1;
                    if(k<j)
                        lower[k][j]=0;

            return 1;// return 1 if the column has a pivot position else we return 0
        }
            for(k=0;k<M-1;k++)
                for(j=0;j<M-1;j++)
                    if(j==k)
                        lower[k][k]=1;
                    if(k<j)
                        lower[k][j]=0;
        return 0;
}
