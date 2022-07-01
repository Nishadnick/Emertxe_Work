/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 1_odd_even.c
Description:
			• The user entered number should identified whether its a odd or a even number. Mention its sign too.

Sample I/p : Enter the number: 
Sample O/p : 
Enter the value of 'n' : 0

0 is neither odd nor even
*/

#include<stdio.h>
int main()
{
	int num;					//initialise variables
	printf("Enter a number:\n");
	scanf("%d", &num);
	//printf("entered number is %d\n", num);
	
	if (num>0)											//chk if number +ve
	{
		if (num%2==0)									//chk even/odd
		{
			printf("%d is positive even number\n",num);
		}
		else
		{
			printf("%d is positive odd number\n",num);
		}
	}
	else if (num<0)										//chk if number -ve
	{
		if(num%2==0)									//chk even/odd
		{
			printf("%d is negative even number\n",num);
		}
		else
		{
			printf("%d is negative odd number\n",num);
		}
	}
	else
	{
		printf("0 is neither odd nor even\n");			//neither
	}
return 0;
}