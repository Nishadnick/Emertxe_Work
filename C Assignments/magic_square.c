/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: magic_square.c 
Description:
In recreational mathematics, a magic square is an arrangement of distinct numbers (i.e. each number is used once), usually integers, in a square grid, where the numbers in each row, and in each column, and the numbers in the main and secondary diagonals, all add up to the same number
A magic square has the same number of rows as it has columns, and in conventional math notation, "n" stands for the number of rows (and columns) it has. Thus, a magic square always contains n2 numbers, and its size (the number of rows [and columns] it has) is described as being "of order n".
Example: if n = 3, the magic square
8	1	6
3	5	7
4	9	2
Read an odd number n from user.
Do error checking.
Check the number is odd or not.
If not, continue step a.
Create an n X n matrix.
Insert 1 to (n * n) numbers into matrix.
Arrange the numbers in such a way that, adding the numbers in any direction, either row wise column wise or diagonal wise, should result in same answer.
Allocate the memory dynamically using calloc.
Sample I/p :
Enter a number: 3
Sample O/p :
8	1	6
3	5	7
4	9	2


Sample I/p :
Enter a number: 5
Sample O/p :
17  24  1   8   15
23  5   7   14  16
4   6   13  20  22
10  12  19  21  3
11  18  25  2   9
*/

#include <stdio.h>
#include <stdlib.h>

void magic_square(unsigned int **, int);

int main()
{
    unsigned int ** iptr;		//2d array
	int i,j,size;
	printf("Enter a number: ");
	scanf("%d",&size);
	if(size<0)
	{
		printf("Error : Please enter only positive odd numbers");
		return -1;
	}
	
	else if(size%2!=1)
	{
		printf("Error : Please enter only positive odd numbers");
		return -1;
	}
	//iptr=calloc(sizeof(int),(size));		//allocation of rows
	iptr=malloc(sizeof(iptr)*(size));
	if((iptr)==NULL)
		{
			printf("Memory not allocated");
			return 1;
		}

	for(i=0;i<size;i++)
	{
		//*(iptr+i)=calloc(sizeof(int),(size));		//allocation for cols space for each row
		*(iptr+i)=malloc(sizeof(iptr)*(size));
		if(*(iptr)==NULL)
		{
			printf("Memory not allocated");
			return 1;
		}
	}
	//for(i=0;i<size;i++)
	//	for(j=0;j<size;j++)
	//		iptr[i][j]=0;
	
	//iptr[0][0]=0;
	magic_square(iptr, size);
free(iptr);
return 0;
}

void magic_square(unsigned int ** iptr, int size)
{
	int i=0,j=size/2,k=0,num=size*size;		//i and j have the intiailisation special
	//printf("at [0][0]  %d\n",iptr[0][1]);
	for(k=1;k<=num;k++)
	{
		//printf("chk i=%d j=%d k=%d\n",i,j,k);			//condition chks
		if(iptr[i][j]==0)			//normally when value is not populated
		{
			iptr[i][j]=k;
			//printf("set i=%d j=%d k=%d\n",i,j,k);		//condition chks
			i--;
			j++;
			//printf("next i=%d j=%d k=%d\n",i,j,k);		//condition chks
			if(i>size-1)		//these are general condition for boundry chks
			{
				i=0;
			}
			if(j>size-1)
			{
				j=0;
			}	
			if(i<0)
			{
				i=size-1;
			}
			if(j<0)
			{
				j=size-1;
			}
		}
		else				//incase value is already present
		{
		//	printf("err i=%d j=%d k=%d\n",i,j,k);//condition chks
			i++;			//there are the condition for boundry chks for this perticular operation
			if(i>size-1)
			{
				i=0;
			}
			if(j>size-1)
			{
				j=0;
			}	
			if(i<0)
			{
				i=size-1;
			}
			if(j<0)
			{
				j=size-1;
			}
		//these are the actual repairing steps incase a number pre-exist
			i++;
			j--;
			k--;
			if(i>size-1)			//these are the conditional for boundry chks for other variables
			{
				i=0;
			}
			if(j>size-1)
			{
				j=0;
			}	
			if(i<0)
			{
				i=size-1;
			}
			if(j<0)
			{
				j=size-1;
			}
			
		}
		
	}
	printf("\n");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%4d",iptr[i][j]);
		}
		printf("\n");
	}

}






