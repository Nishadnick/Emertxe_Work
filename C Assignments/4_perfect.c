/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 4_perfect.c
Description:
• In number theory, a perfect number is a positive integer that is equal to the 
sum of its proper positive divisors, that is, the sum of its positive divisors 
excluding the number itself (also known as its aliquot sum).

• Equivalently, a perfect number is a number that is half the sum of all of its 
positive divisors (including itself).
Sample I/p : Enter the number: 
Sample O/p : 
Enter a number: 10

No, entered number is not a perfect number
*/

#include<stdio.h>
int main()
{
	int num=0,sum=0,i;					//initialise variables
	printf("Enter a number:\n");
	scanf("%d", &num);
	//printf("entered number is %d: ", num);
	if(num<0)
	{
		printf("Error : Invalid Input, Enter only positive number");
	}
	else
	{
	for(i=1;i<num;i++)										
	{
		if(num%i==0)
		{
			sum+=i;
		}
	}
	if(num==sum)
	{
		printf("Yes, entered number is perfect number\n");
	}
	else
	{
		printf("No, entered number is not a perfect number\n");
	}
	}
return 0;
}