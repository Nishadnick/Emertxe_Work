/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 06_prime.c
Description:
In mathematics, the sieve of Eratosthenes, one of a number of prime number sieves,
is a simple, ancient algorithm for finding all prime numbers up to any given limit. 
It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, 
starting with the multiples of 2.
The sieve of Eratosthenes is one of the most efficient ways to find all of the smaller primes. 
It is named after Eratosthenes of Cyrene, a Greek mathematician.
Sample I/p :Enter the value of 'n' : 20
Sample O/p : 
The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
*/

#include<stdio.h>
int main()
{
	int i,j,num;
	
	printf("enter a limit\n");
	scanf("%d", &num);
	int arr[num];				//initialising array with n+1 elements
	
	for(i=0;i<(num);i++)
	{							
		arr[i]=i+1;				//assigning array numbers same as the index numbers 
	}							// a[0]=1 , a[1]=2, ..a[98]=99, a[99]=100
	printf("printing array \n");
	for(i=0;i<(num);i++)
	{
		printf("%d ", arr[i]);		//just printing the array
	}
	
	printf("\nprime\n");
	printf("\n arr[0] %d   arr[1] %d   num=%d \n",arr[0],arr[1],num);
	
								//just like last time problem is when i=2 then program stops
								//when i=1 then program runs but it gives undesirable result
	for(i=1;i<(num);i++)		//starting with i=2 cz else line no.46 will make everything zero
	{
		if(arr[i]!=0)			//we're hoping to assign multiples of i as 0, 
		{						//and index number is same as actual number
			
			for(j=i;j<(num);j++)	//here we start j=i so that cz we don't even need 
			{						//to chk previous numbers after i has incremented eq. 2*5=5*2
				arr[(j*i)-1]=0;			//this is i*2, i*3, i*4, circulating through multiple of a number at a time
			}						//as i=2, 3, 4, 5...
		}
	}								//at the end of this all the composite multiples should become 0
	
	printf("\nprinting array modified \n");
	for(i=0;i<(num);i++)
	{
		printf("%d ", arr[i]);			//printing new array with composite numbers as zero 
	}
return 0;
}
	
	