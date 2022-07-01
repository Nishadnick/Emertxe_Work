/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: sec_largest.c
Description:
Read n and n no.of elements from user and store them into an array.
Run a loop for printing the elements in sorted order.
Sample I/p :Enter the size : 5
Enter 5 elements 
10 1 3 8 -1
Sample O/p : 
After sorting: -1 1 3 8 10
Original array values 10 1 3 8 -1
*/

#include <stdio.h>

void print_sort(int* arry, int lim);

int main()
{
    int size, iter;
    
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the %d elements\n",size);
    for (iter = 0; iter < size; iter++)
    {
        scanf("%d", &arr[iter]);		//scanning the values
    }
	
    print_sort(arr, size);
}

void print_sort(int* arry, int lim)
{
	int i,j,count[lim],iter=0;
	printf("the elements \n");
	for (i = 0; i<lim; i++)				//holding 1 value
    {
	iter=0;								//==>>  here we are re-intializating the count value for each new no.
	  	for (j = 0; j<lim; j++)			//iterating to compae 1 value with whole array
    	{
			 if(arry[i]>arry[j])			//checking that a number is bigger than how many elements
			 iter++;						//using the count of numnber which is the  
    	}									//count of a number is bigger than how many elements
		count[i]=iter;						//making a separate array where we just store these values
	}									
	printf("After sorting:");
	for (j = 0; j<lim; j++)
    {										//double iterating to compare number within array
		for (i = 0; i<lim; i++)
    	{
	  		if(count[i]==j)					//checking the least count an a particular index
			printf(" %d",arry[i]);			//simply printing the value at that index
 		}
	}
	printf("\nOriginal array values");
	for (j = 0; j<lim; j++)
	{
		printf(" %d",arry[j]);
	}
}