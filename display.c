#include <stdio.h>

void display(float **matrix,int N,char index)
{
    int i,j;
    if(index==1)
    printf("Your matrix [A]=");
    if(index==2)
        printf("\nYour matrix [L]=");
    if(index==3)
         printf("\nYour matrix [U]=");
    for(i =0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("\t%.2f",matrix[i][j]);
        printf("\n\t\t");
    }
}
