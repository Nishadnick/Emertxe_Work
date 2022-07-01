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
	
	printf("Enter the value of 'n' : ");
	scanf("%d", &num);
	if(num>1)
	{
		int arr[num+1];				//initialising array with n+1 elements
	
		for(i=0;i<(num+1);i++)
		{
			arr[i]=i;				//assigning array numbers same as the index numbers 
		}							// a[0]=0 , a[1]=1, ..a[99]=99, a[100]=100
		
		
	
		for(i=2;i<(num+1);i++)		//starting with i=2 cz else line no.46 will make everything zero
		{
			if(arr[i]!=0)			//we're hoping to assign multiples of i as 0, 
			{						//and index number is same as actual number
			
				for(j=i;j<(num+1),(j*i)<(num+1);j++)	//here we start j=i so that cz we don't even need 
				{						//to chk previous numbers after i has incremented eq. 2*5=5*2
					arr[j*i]=0;			//this is i*2, i*3, i*4, circulating through multiple of a number at a time
				}						//as i=2, 3, 4, 5...
			}
		}								//at the end of this all the composite multiples should become 0
	
		printf("\nThe primes less than or equal to %d are : ", num);
		printf("%d", arr[2]);
		for(i=3;i<(num+1);i++)
		{
			if(arr[i]>0)
			printf(", %d", arr[i]);			//printing new array with composite numbers as zero 
		}
	}
	else
	{
		printf("Please enter a positive number which is > 1\n");
	}
	return 0;
}
	
	