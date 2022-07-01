/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: median.c
Description:
In probability theory and statistics, variance measures how far a set of numbers is spread out. 
A variance of zero indicates that all the values are identical. Variance is always non-negative: 
a small variance indicates that the data points tend to be very close to the mean (expected value) 
and hence to each other, while a high variance indicates that the data points are very spread out 
around the mean and from each other.
Example:
x(input)                D = X - Mean                   D2
9                          -11                                   121
12                        -8                                     64
15                        -5                                     25
18                        -2                                     4
20                         0                                     0
22                         2                                     4
23                         3                                     9
24                         4                                     16
26                         6                                     36
31                         11                                   121
Sum = 200                                                  Sum = 400
Mean = (sum of x) / size
where : size = Number of items in the input
Formula to calculate the variance:
sigma = (sum of D2 ) / size
Sample I/p :
Enter the no.of elements : 10
Sample O/p : 
Enter the 10 elements:
[0] -> 9
[1] -> 12
[2] -> 15
[3] -> 18
[4] -> 20
[5] -> 22
[6] -> 23
[7] -> 24
[8] -> 26
[9] -> 31
Variance is 40.000000

*/

#include <stdio.h>
#include<stdlib.h> 
float variance(int *, int);

int main()
{
    int size,i;
	printf("Enter the no. of elements:");
	scanf("%d",&size);
	int *vptr;									//for start of array
	vptr=(int *)malloc(sizeof(vptr)*size);		//allocating the memory according to the size requireements
	printf("\nEnter the 10 elements:\n");
	
	variance(vptr, size);
	return 0;
}

float variance(int *vptr1, int size1)
{
	int i;
	float sigma=0,squre=0,sq=0,toto=0,mean,D=0;
	for(i=0;i<size1;i++)
	{
		printf("[%d] -> ",i);
		scanf("%d",((int *)vptr1+i));	//for scannig the user values
		toto=toto+*(vptr1+i);			//immediately adding them
	}
	mean=(float)toto/size1;				//mean=total/size
	for(i=0;i<size1;i++)
	{
		D=(float)(*(vptr1+i)-mean);		//D=values-mean
		sq=sq+D*D;						//adding the sqares of D
	}
	
	sigma=(float)(sq/size1);			//as the variance formula
	printf("Variance is %f",sigma);
	return 0;
}



