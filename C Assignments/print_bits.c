/*
name: Nishad S. Taksande
Date: 13-Jan-22
Assignment Title: print_bits.c
Description:
a. Read number num from user.
b. Read number n from user.
c. Do error checking
  -> If n is greater than integer size, assign n value as sizeof integer.
d. Print n number of bits of num from LSB end.
If num is 10 and n is 12, then print last 12 bits of binary representation of 10.
The output should be -> 0 0 0 0 0 0 0 0 1 0 1 0

Sample I/p :Enter the number: 10

Enter number of bits: 12
Sample O/p : 
Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0 

*/
#include<stdio.h>

int print_bits(int num1, int n1);
	
int main()
{
	int num,n;

	printf("Enter num, n :\n");
    scanf("%d%d", &num, &n);
	printf("Binary form of %d: ",num);
	print_bits(num,n);			
			
	return 0;
}
int print_bits(int num1, int n1)
{
	//printf("num1=%d and n1=%d\n",num1,n1);
	int i;
	for(i=0;i<n1;i++)
	{
		if(num1&(1<<n1-1-i))		//determines the position to compare
		{
			printf("1 ");			//prints 1 when bit is high
		}
		else
		{
			printf("0 ");			//prints 0 when bit is low
		}
	}
	/*
	int bit=0,j;
	printf("\nnum1=%d\n",num1);
	
	for(j=0;j<32;j++)
	{
		if(num1>=(1<<31-1-j))				//this is position checking
		{
			bit=(31-j);						//the position determines the start of significant bits
			printf("\n number of bits=%d",bit);
			break;
		}
	}
	*/
	return 0;					
}									