#ifndef CHANGE_ROW
#define CHANGE_ROW

int change_row(int,int,float **,float **);
void fill_matrix(float**,int);
void gauss(int);
void lu(int);
void display(float **,int,char);
float *backward(float **,int);
void forwards(float **,float **,float *,int);
float **triangular(float **,int,int,int);

#define  CONSTANT_VECTOR_FILL(matrix,b,N) printf("\nEnter the elements of the right side of the equations\n");\
                                        for(i=0;i<N;i++)\
                                        {\
                                            scanf("%f",&b[i]);\
                                            matrix[i][N]=b[i];\
                                            printf("\n");\
                                        }

#define DISPLAY_CONSTANT_VECTOR(b,N)    printf("The matrix [B] is :\n");\
                                        for(i=0;i<N;i++)\
                                            printf("%.1f\n",b[i]);


#define PRINT_RESULT(matrix,s,b,N) ; printf("\n\ncomputing.....\n\n");\
                                    if(s[N]==1)\
                                        printf("That system has infinite many solutions\n");\
                                    else if(s[N]==0)\
                                        printf("That system does not have a solution\n");\
                                    else\
                                    {\
                                       printf("The solution is:[X] =( ");\
                                        for(i=0;i<N;i++)\
                                        {\
                                            printf("%.3f, ",s[i]);\
                                            free(matrix[i]);\
                                        }\
                                        printf(")");\
                                        free(matrix);\
                                        free(b);\
                                        free(s);\
                                    }

#endif // CHANGE
