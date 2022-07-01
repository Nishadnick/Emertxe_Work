/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: fragments.c
Description:
Implement fragments using array of pointers.
Rows are static and columns are dynamic. Fixed no.of rows and columns will vary for each row.
Example:
Read no.of rows from user and allocate the memory statically for rows.
Read no.of columns for each row and allocate the memory dynamically.
Let us Assume, Row = 3.
Row[0] = 4 columns, Row[1] = 3 columns and Row[2] = 5 columns.
While allocating the memory for columns you have allocate for no.of columns + 1 dynamically.
After that read the values from user and calculate the average for each row seperatly and store that average in that extra memory block which you added while allocating the memory.
Example is given below.Then sort the array based on the average.
Print the output on the screen.
Pictorial representation of the assignment

Sample I/p :
Test case 1:
user@emertxe] ./fragmentsEnter
Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1

Sample O/p : 
Before sorting output is:

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

After sorting output is:

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

*/
#include <stdio.h>
#include<stdlib.h> 
void fragments(int *, float **,int);

int main()
{
    int i,j,rows,col;
	printf("Enter no.of rows :");
	scanf("%d",&rows);
	int *cols_in_row=(int *)malloc(sizeof(int)*rows);		//cols_in_row contains number of cols in each row
	for(i=0;i<rows;i++)
	{													//row[0] row[1] row[2]
		printf("Enter no of columns in row[%d]: ",i);
		scanf("%d",(cols_in_row+i));						//these are the column values
	}
	//making double pointer because col_arr[no. of cols_in_row][values in a coulmns at a row]
	float **col_arr=malloc((sizeof(float *)*rows));		
	
	
	printf("\n number of cols in a row\n");
	for(i=0;i<rows;i++)
	{
		*(col_arr+i)=(float *)malloc((*(cols_in_row+i)+1)*sizeof(float));
	}
	for(i=0;i<rows;i++)
	{
		//while scanning we will add a sum and get a mean @end
		float sum=0;
		printf("Enter %d values for row[%d]:",*(cols_in_row+i),i);
		for(j=0;j<*(cols_in_row+i);j++)
		{
			scanf("%f",(*(col_arr+i)+j));
			sum=sum+*(*(col_arr+i)+j);			//double dereferencing to get the value
		}
			*(*(col_arr+i)+j)=sum/(*(cols_in_row+i));	// here j=*(cols_in_row+i)
	}														//so we can save last element as mean value
	
	printf("\nBefore sorting output is:\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<=*(cols_in_row+i);j++)
		{
			printf("%f	",*(*(col_arr+i)+j));
		}
		printf("\n");
	}	
	
	fragments(cols_in_row, col_arr, rows);
	
	return 0;
}

void fragments(int * cols_in_row, float ** col_arr, int rows)			//swap and print
{
	//printf("Function is start");
	int i,j;
	float *swap,temp;
	
	for(i=0;i<rows;i++)
	{
		for(j=i+1;j<rows;j++)
		{
			if(*(*(col_arr+i)+*(cols_in_row+i))>*(*(col_arr+j)+*(cols_in_row+j)))
			{
				//*swap=*(*(col_arr+i+1)+(cols_in_row+i)));
				//*(*(col_arr+i+1)+(cols_in_row+i)))=*(*(col_arr+i)+(cols_in_row+i));
				//*(*(col_arr+i)+(cols_in_row+i))=*swap;
				swap=*(col_arr+i);
				*(col_arr+i)=*(col_arr+j);
				*(col_arr+j)=swap;
				
				temp=*(cols_in_row+i);
				*(cols_in_row+i)=*(cols_in_row+j);
				*(cols_in_row+j)=temp;
			}	
		}
	}
	printf("After sorting output is:\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<=*(cols_in_row+i);j++)
		{
			printf("%f	",*(*(col_arr+i)+j));
			
		}
		printf("\n");
	}
	
}