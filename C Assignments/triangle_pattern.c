/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: pyramid_pattern.c
Description:
			Read a number from user. Let's say if number is 5, 
			you need to print numbers in triangle pattern as shown below:

Note:- Please consider '_' as space. You need to leave space between 2 numbers
Sample I/p : Enter the number: 5
Sample O/p : 

1 2 3 4 5
6       7
8    9
10 11
12
*/

#include<stdio.h>
int main()
{
	int num,num1,m=0,j=0,cnst=0,limit=0;					//initialise variables
	
	printf("Enter a number:");
	scanf("%d", &num);
	num1=num;
	cnst=num-3;										//it is actually the gradual decrease gradient
	limit=(num*2)+cnst;								//forumla to find the limit
//	printf("the limit is %d\n", limit);
	for(j=1;j<=num;j++)
		{
			if(j==num)						//
			{
				printf("%d", j);
			}
			else
			{
				printf("%d ", j);			//prints the first line
			}
		}
		printf("\n");							//this finish 1st line\n
		for(j=num+1;j<=limit-1;j++)					//k will continue the number series till its limit
		{								
			printf("%d", j);			//printing 1st number
			for(m=1;m<=((2*cnst)+1);m++)			//whole arrangement to print "_" in decresing order	
			{
				printf(" ");			//printing space [made arrangement to look presentable]
			}
			cnst--;						//manually decreasing the spaces to align the slope
			printf("%d\n", ++j);		//printing 2nd number							
		}
	printf("%d\n",limit);				//this the lone line limit				
	return 0;						//cz for int function we have to return something numbery but without any valuey
}
