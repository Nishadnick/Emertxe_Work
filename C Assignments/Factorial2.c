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
int factorial(long long int fact,int num);
int main()
{
    static int num;
    static unsigned long long int fact = 1;
	printf("\nnum is now=%d\n",num);
	if(num==0)
	{
	printf("Enter the value of N :");
	scanf("%d",&num);
	}
	printf("\nagain factorial %lld\n and num=%d  ",fact,num);
	factorial(fact,num);
}

int factorial(long long int fact,int num)
{
	if(num<0)
	{
		printf("Invalid Input");
	}
	else if (num==0)
	{
		return fact;
	}
	else if (num==1)
	{
		printf("\nFactorial of the given number is %lld",fact);
	}
	else
	{
		fact=fact*num--;
		printf("factorial %lld\n and num=%d  ",fact,num);
		return main();
	}
}
