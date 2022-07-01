/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 5,7_ap_gp_hp.c
Description:
AP :
In mathematics, an arithmetic progression (AP) or arithmetic sequence is a sequence of 
numbers such that the difference between the consecutive terms is constant.
For instance, the sequence 5, 7, 9, 11, 13, 15 ... is an arithmetic progression with common difference of 2.
GP :
In mathematics, a geometric progression, also known as a geometric sequence, 
is a sequence of numbers where each term after the first is found by multiplying 
the previous one by a fixed, non-zero number called the common ratio.
For example, the sequence 2, 6, 18, 54, ... is a geometric progression with common ratio 3. 
Similarly 10, 5, 2.5, 1.25, ... is a geometric sequence with common ratio 1/2.
HP :
 In mathematics, a harmonic progression (or harmonic sequence) is a progression 
 formed by taking the reciprocals of an arithmetic progression.
Sample I/p : Enter the number: 

Positive integers say 'A', 'R' and 'N', where N > 1
where:
A = First number
R = Common difference(AP & HP), Common ratio(GP)
N = number of terms

Note:- Use %f fmt specifier to print HP series
Sample O/p : 
*/

#include<stdio.h>
int main()
{
	int num1=0,diff=0,terms=0,AP,GP,HP,i;					//initialise variables
	printf("Enter the First Number 'A':\n");
	scanf("%d", &num1);
	AP=num1;
	GP=num1;
	printf("Enter the Common Difference / Ratio 'R':\n");
	scanf("%d", &diff);
	printf("Enter the number of terms 'N':\n");
	scanf("%d", &terms);
	
	if(terms>0)
	{
		printf("AP = ");
		for(i=0;i<terms;i++)
		{
			AP=num1+(diff*i);
			if(i==(terms-1))
			{
				printf("%d ",AP);
			}
			else
			{
				printf("%d, ",AP);
			}
		}
		printf("\nGP = ");

		for(i=0;i<terms;i++)
		{	
			if(i==(terms-1))
			{
				printf("%d ",GP);
			}
			else
			{
				printf("%d, ",GP);
			}
			GP=GP*(diff);
		}
		printf("\nHP = ");
		for(i=0;i<terms;i++)
		{
			AP=num1+(diff*i);
			float HP=(float)1/AP;
			if(i==(terms-1))
			{
				printf("%f ",HP);
			}
			else
			{
				printf("%f, ",HP);
			}
		}
	}
	else
	{
		printf("Invalid input\n");
	}
return 0;
}