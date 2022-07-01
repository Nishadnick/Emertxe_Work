/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 1_odd_even.c
Description:In mathematics, the Fibonacci numbers or Fibonacci sequence
are the numbers in the following integer sequence  0, 1, -1, 2, -3, 5, -8, 13, -21, 34, -55, 89, -144 . . .
By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
each subsequent number is the subtraction of the previous two
Sample I/p : Enter the number: 
Sample O/p : 
Enter a number: -10
0, 1, -1, 2, -3, 5, -8
*/

#include <stdio.h>

void negative_fibonacci(int lim1, int term1, int next1, int tempo);

int main()
{
    int limit,term=0,next=1,temp=0;
    
    printf("Enter the limit : ");
    scanf("%d", &limit);
	if(limit==0)
	{
		printf("0");
	}
    else if(limit<0)
	{
		printf("0");
    negative_fibonacci(limit, term, next, temp);
	}
	else
	{
	printf("Invalid input\n");
	}
}

void negative_fibonacci(int lim1, int term1, int next1, int tempo)
{
	
	printf(", %d",next1);
	tempo=term1-(next1);
	term1=next1;
	next1=tempo;
	
	if((next1<0 && next1>=lim1)||(next1>0 && next1<=(lim1*(-1))))
	{
		negative_fibonacci(lim1, term1, next1, tempo);
	}
		
}