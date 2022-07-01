/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: check_parity.c
Description:
Read a number from the user. Check number of set bits in a given number. 
If number of set bits is odd, then Bit parity is odd. Similarly,
If number of set bits is even, then Bit parity is even. 
For example, If num = 7, number of set bits = 3 which is odd number, 
so bit parity is odd. Similarly, if num = 3, number of set bits = 2, 
bit parity should be even
Sample I/p :Enter the number : 7 
Sample O/p : 
Number of set bits = 3

Bit parity is Odd

No, entered number is not a perfect number
*/

#include<stdio.h>
int main()
{
	int num=0,i,length,fact,count=0;					//initialise variables	
	printf("Enter the number : \n");
	scanf("%d", &num);
	int bina[15];
//	printf("entered number is %d\n ", num);
	
	for(i=0;num>0;i++)
	{
		fact=num%2;
		bina[i]=fact;
		num=num/2;
	}
	length=i;
	printf("%d\n",length);
	for(i=length-1;i>=0;i--)
	{
		if(bina[i]==1)
			count++;
		printf("%d ",bina[i]);
	}
printf("Number of set bits = %d\n",count);
	if(count%2==0)
	{
		printf("Bit parity is Even");
	}
	else
	{
		printf("Bit parity is Odd");
	}
return 0;
}