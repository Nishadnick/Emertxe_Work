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

int main(long long int fact,int num;)		//main () to be recurred hence we already chk by passing args
{
    static int num;							//special statics will not die till the end. here num is already ==0
    static unsigned long long int fact = 1; //initializing ths static cz we need it too till the end
	if(num==0)							//very imp. condition to read IP from user only once 
	{
	printf("Enter the value of N :");

	scanf("%d",&num);

		if(num==0)						//if user implicitly still IPs 0 then this is the answer
		{
		printf("Factorial of the given number is 0\n");
		}
	}
	if(num<0)						
	{
		printf("Invalid Input\n");
	}
//	else if (num==0)		//unnecessary
//	{
//		printf("here num %d",num);
//		return fact;
//	}
	else if (num==1)					//base case to end it all
	{
		printf("Factorial of the given number is %lld\n",fact);
	}
	else if (num>1)							//any IP would be >0 hence we use this for our benefit
	{									//this is our main recurring case
		fact=fact*num--;
		//printf("value of num :%d",num);
	//	printf("factorial %lld\n",fact);
		return main(fact,num);			//recurring main() by actually passing the values to the beginning
	}								//the statics won't affect or interfear, only 'num' is used for condition chk
	
}
