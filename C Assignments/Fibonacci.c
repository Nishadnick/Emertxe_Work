/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 1_odd_even.c
Description:In mathematics, the Fibonacci numbers or Fibonacci sequence 
are the numbers in the following integer sequence 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . . 
OR 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . .

By definition, the first two numbers in the Fibonacci sequence are 0 and 1, 
each subsequent number is the sum of the previous two
Sample I/p : Enter the number: 
Sample O/p : 
Enter a number: 10
0, 1, 1, 2, 3, 5, 8
*/

#include <stdio.h>

void positive_fibonacci(int lim1, int term1, int next1, int tempo);

int main()
{
    int limit,term=0,next=1,temp=0;
    
    printf("Enter the limit : ");
    scanf("%d", &limit);
	if(limit==0)
	{
		printf("0");
	}
    else if(limit>0)
	{
		printf("0");
    positive_fibonacci(limit, term, next, temp);		//the function call
	}
	else
	{
	printf("Invalid input\n");
	}
}

void positive_fibonacci(int lim1, int term1, int next1, int tempo)
{
	
	printf(", %d",next1);
	tempo=next1+term1;
	term1=next1;
	next1=tempo;
	
	if(next1<=lim1)			//this acts as the base condition, when it fails, the program simply stops
	{
		positive_fibonacci(lim1, term1, next1, tempo);		//the recurring function
	}
	
}