/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: x_pattern.c 
Description:
			Read a number from user. Let's say if number is 5, 
			you need to print numbers in pyramid pattern as shown below:

Note:- Please consider '_' as space. You need to leave space between 2 numbers
Sample I/p : Enter the number: 5
Sample O/p : 
1   5
 2 4
  3
 2 4
1   5
*/

#include<stdio.h>
int main()
{
	int num,i=0,j=0;					//initialise variables
	printf("Enter the number:");
	scanf("%d", &num);
	//printf("entered number is %d\n", num);
	
	
	for(i=1;i<=num;i++)						//running opposite loop cz we need to print numbers in descending
	{
		for(j=1;j<=num;j++)
		{
			if((i+j)==(num+1)||(i==j))
			{
				printf("%d",j);
			}
			else
			{
				printf("_");
			}
		}
		printf("\n");
	}
return 0;
}