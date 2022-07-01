/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 3_neg_fibonacci.c
Description:
• In mathematics, the Fibonacci numbers or 
Fibonacci sequence are the numbers in the following integer sequence  
0, 1, -1, 2, -3, 5, -8, 13, -21, 34, -55, 89, -144 . . .

• By definition, the first two numbers in the Fibonacci sequence are 0 and 1, 
each subsequent number is the subtraction of the previous two
Sample I/p : Enter the number: 
Sample O/p : 
Enter a number: -10
0, 1, -1, 2, -3, 5, -8
*/

#include<stdio.h>
int main()
{
	int limit,num1=1,num2=-1,temp=0;					//initialise variables
	printf("Enter a number:\n");
	scanf("%d", &limit);
	
	if(limit<=0)
	{
		if(limit<0)
		{
			limit=limit*(-1);
		}
		printf("%d", temp);
		while (num1<=limit && num1>=(limit*(-1))) 			//reconvert number to -ve to chk the alternative case
		{
			printf(", %d", num1);	
			temp=num1-(num2);
			num1=num2;										//number swap logic
			num2=temp;
		}
	}
	else
	{
		printf("Invalid input");
	}
return 0;
}