#include <stdio.h>
#include <stdlib.h>
#include "linear_system.h"
#include <ctype.h>

int main()
{
    #if  defined(WIN32)
    system("color f3");//the system's color changes only in WINDOWS
    #endif
    int N,resp,again=0;//N is the number of equations, resp: the mode to solve equations, again:to loop the program
    char name[20];
        do{

        printf("\n\n\n\n\n\t\t******SOLVE LINEAR SYSTEM EQUATION*******\n\n\n");

        printf("Enter your name: ");
        fgets(name,20,stdin);
        do
        {
            printf("\nEnter the number of your matrix %s",name);
            scanf("%d",&N);
        }   while(N<2);

        do
        {
            printf("\nWhich method do you want to use to solve the problem?\n\n1.Gauss elimination\n2.LU decomposition\n3.Exit\n");
            scanf("%d",&resp);
            switch(resp)
            {
                case 1:gauss(N);
                    break;
                case 2:lu(N);
                    break;
                case 3: exit(0);
                    break;
                default:printf("You have entered a wrong value %s\n",name);
                    break;
            }
        }while(resp<=0||resp>2);

        printf("\n\n To continue press '1' otherwise press \" another character\"\n");
        scanf("%d",&again);

       } while(again == 1);
        printf("\nThanks for have used our program %s!!!\n\n",name);
  return 0;
}
