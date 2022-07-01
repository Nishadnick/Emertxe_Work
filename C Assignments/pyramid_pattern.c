/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: pyramid_pattern.c
Description:
			Read a number from user. Let's say if number is 5, 
			you need to print numbers in pyramid pattern as shown below:

Note:- Please consider '_' as space. You need to leave space between 2 numbers
Sample I/p : Enter the number: 5
Sample O/p : 
5
4 5
3 4 5
2 3 4 5
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5
*/

#include<stdio.h>
int main()
{
	int num,i=0,j=0;					//initialise variables
	//printf("Enter a number:\n");
	scanf("%d", &num);
	//printf("entered number is %d\n", num);
	for(i=num;i>0;i--)						//running opposite loop cz we need to print numbers in descending
	{
		for(j=i;j<=num;j++)					//using the values of previous variable to pre-increment 
		{									//our current variable to print till the limit
			if(j==num)						//just to remove the trailing '_'
			{
				printf("%d", j);
			}
			else
			{
				printf("%d ", j);			//using '_' inplace of ' ' just cz its a ""requirement""
			}
		}
		printf("\n");
	}
	for(i=2;i<=num;i++)						//starting the new loop with old variables name just beacuse we can
	{										//initialised it from 2 cz 
		for(j=i;j<=num;j++)					//the 2nd smaller pyramid will always start from 2
		{									//priting the pre-incremented varaible till the limit
			if(j==num)
			{
				printf("%d", j);
			}
			else
			{
				printf("%d ", j);
			}
		}
		printf("\n");						//this is for new line
	}
	return 0;						//cz for int function we have to return something numbery but without any valuey
}
