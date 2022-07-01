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
	int num,i=0,j=0,a,b,k,m,n;					//initialise variables
	printf("Enter a number:\n");
	scanf("%d", &num);
	printf("entered number is %d\n", num);
	
	
	for(i=1;i<=(num/2)+1;i++)						//running opposite loop cz we need to print numbers in descending
	{
		a=i;
		b=num+1-i;
		printf("value of i is %d   ",i);
		for(k=1;k<i;k++)
		{
			printf("_");					//printing 1st space
		}
//		if(a<b)
		{
			printf("%d",a);					//printing 2nd number
		}						//printing 1st number
		for(j=num-i;j>i;j--)
		{
			printf("_");					//printing 2nd space
		}
		if(a<b)
		{
			printf("%d",b);					//printing 2nd number
		}
		printf("\n");
	}
	
	for(m=(num/2);m>0;m--)
	{
		a=m;
		b=num+1-m;
		for(k=1;k<m;k++)
		{
			printf("_");					//printing 1st space
		}
		printf("%d",m);						//printing 1st number
		for(j=num-m;j>m;j--)
		{
			printf("_");					//printing 2nd space
		}
		if(a<b)
		{
			printf("%d",b);					//printing 2nd number
		}
		printf("\n");
	}
	return 0;						//cz for int function we have to return something numbery but without any valuey
}
