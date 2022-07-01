
/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: matrix_multiplication.c
Description:
Read no.of rows and columns for 2 arrays from user and allocate the memory dynamically using malloc or calloc (Assume Matrix A and Matrix B).
Read the Matrix A and B from user.
Find the product for matrix A with matrix B amd store the result in Matrix R.
Let say Name of the matrix is A and no. Of rows = columns = 3.
Matrix A
1	2	3
1	2	3
1	2	3

Matrix B
1	2	3
1	2	3
1	2	3

Final Result :
Result = A * B
	1	2	3		1	2	3
R=	1	2	3	x	1	2	3
	1	2	3		1	2	3	
R1 = [(1 * 1) + (2 * 2) + (3 * 3)  (1 * 1) + (2 * 2) + (3 * 3)   (1 * 1) + (2* 2) + (3 * 3)]
Result matrix is
14	14 	14
14	14 	14
14	14 	14

Sample I/p :
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :

1      1     1
2      2     2
3      3     3
Sample O/p :
Product of two matrix :
14      14      14
14      14      14
14      14      14

*/


#include <stdio.h>
#include <stdlib.h>

int matrix_mul(int **, int, int, int **, int, int, int **, int, int);

int main()
{
    int **mat_A,row_A=0,col_A=0,row_B=0,col_B=0,res_col=0,res_row=0,i,j;
	int **mat_B;
	int **result;
	printf("Enter number of rows A:");
	scanf("%d",&row_A);
	printf("\nEnter number of cols A:");
	scanf("%d",&col_A);
	
	
	mat_A=(int **)malloc(sizeof(int *)*row_A);		//allocation for rows 1st
	
	for(i=0;i<row_A;i++)
		{
		*(mat_A+i)=(int *)malloc(sizeof(int)*col_A);		//allocation for cols later
		
		}
		
//	if(mat_A!=NULL)
//		printf("great success!!A\n");		//memory allocation chk
//	else
//		printf("FAIl!!A\n");
	
	printf("\nEnter values for %d x %d matrix A:\n",row_A,col_A);
	
	for(i=0;i<row_A;i++)
	{
		for(j=0;j<col_A;j++)
		{
			//printf("[%d][%d]",i,j);
			scanf("%d",&mat_A[i][j]);
			
		}
		//printf("\n");
	}
	
	
	
	printf("Enter number of rows B:");
	scanf("%d",&row_B);
	printf("\nEnter number of cols B:");
	scanf("%d",&col_B);
		
	if(row_B!=col_A)		//condition for valid matrix, hence result will have row_A x col_B
	{	
		printf("Matrix multiplication is not possible");
		return -1;
	}
	
	mat_B=(int **)malloc(sizeof(int *)*row_B);			//allocation for rows 1st
	
	for(i=0;i<row_B;i++)
		{
		*(mat_B+i)=(int *)malloc(sizeof(int)*col_B);		//allocation for cols later
		}
	
//		if(mat_B!=NULL)
//		printf("great success!!B\n");					//memory allocation chk
//	else
//		printf("FAIl!!B\n");
	
	printf("\nEnter values for %d x %d matrix B:\n",row_B,col_B);
	
	for(i=0;i<row_B;i++)
	{
		for(j=0;j<col_B;j++)
		{
			//printf("[%d][%d]",i,j);
			scanf("%d",&mat_B[i][j]);
			
		}
		
	}
	
	//if valid matrix for product then
	
	result=(int **)malloc(sizeof(int *)*row_A);			//row allocation for result matrix
		
	for(i=0;i<row_A;i++)
		{
		*(result+i)=(int *)(malloc(sizeof(int)*col_B));		//then cols allocation
		}

	
//	if(result!=NULL)
//		printf("great success!!result\n");				//memory allocation chk
//	else
//		printf("FAIL result\n");

	res_col=col_B;
	res_row=row_A;
    matrix_mul(mat_A,col_A,row_A,mat_B,col_B,row_B,result,res_col,res_row);
	
	free(mat_A);
	free(mat_B);
	free(result);
		return 0;
}

int matrix_mul(int ** mat_A, int col_A, int row_A, int ** mat_B, int col_B, int row_B, int ** result, int res_col, int res_row)
{
	int i=0,j=0,k;
	result[i][j]=0;
	for(i=0;i<row_A;i++)
	{
		for(j=0;j<col_B;j++)
		{
			for(k=0;k<col_A;k++)		//k would be used as incermentor for specific row and col
			{
				
				result[i][j]=result[i][j]+((mat_A[i][k])*(mat_B[k][j]));
				printf("	[%d][%d]=%d",i,j,result[i][j]);
			}
			
		}
		printf("\n");
	}
	
	printf("Product of two matrix :\n");
	
	for(i=0;i<row_A;i++)
	{
		for(j=0;j<col_B;j++)
		{
			printf("%d	",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}





