/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title:  Factorial.c
Description:Read number n from user.
Validate the given number
Call main function from main for calculating factorial.
Prompt for continue option without using loop.

Sample I/p : Enter the value of N : 7
Sample O/p : Factorial of the given number is 5040
*/

#include <stdio.h>

int main()
{
    static int num;
    static unsigned long long int fact = 1;

	//printf("Enter the value of N :");
	//scanf("%d",&num);
	
	if(num<0)
	{
		printf("Invalid Input");
	}
	else if (num==0)
	{
		printf("\nFactorial of the given number is %lld",fact);
		return fact;
		
	}
	else if (num==1)					//base case
	{
		printf("\nFactorial of the given number is %lld",fact);
	}
	else								//recursive case
	{
		fact=fact*num--;
		printf("factorial %lld\n",fact);
		return main();
	}
	
}
