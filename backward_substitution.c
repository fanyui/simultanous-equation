#include <stdio.h>
#include <stdlib.h>

float *backward(float **matrix,int N)
{
    int i=N-1,j;
    float *s=(float*)malloc((N+1)*sizeof(float)),sum;



        if((matrix[N-1][N-1]==0)&&(matrix[N-1][N]==0))
           {
                s[N]=1;
                return s;
           }
        else if(((matrix[N-1][N-1]!=0)&&(matrix[N-1][N]==0))||((matrix[N-1][N-1]==0)&&(matrix[N-1][N]!=0)))
            {
                s[N]=2;
                return s;
            }
        else
        {
            s[N]=2;
            do
            {
                sum=0;
                j=N-1;

                while(j>i)
            {
                sum+=(matrix[i][j])*(s[j]);
                j--;
            }
                    if(matrix[i][i]==0)
                     {
                        if(sum==matrix[i][N])
                        {
                            s[N]=1;
                            break;

                        }
                        else
                        {
                            s[N]=0;
                            break;
                        }


                    }

                else
                {
                s[i]=(float)((matrix[i][N]-sum)/matrix[i][i]);
                i--;
                }
            }while(i>=0);
            return s;
            }
}
