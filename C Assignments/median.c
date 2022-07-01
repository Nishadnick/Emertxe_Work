/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: median.c
Description:
In probability theory and statistics, a median is described 
as the number separating the higher half of a sample, a population, 
or a probability distribution, from the lower half. The median of a 
finite list of numbers can be found by arranging all the numbers from 
lowest value to highest value and picking the middle one.
Example:
 Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 5
Sample I/p :
Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 3 7 8 5
Sample O/p : 
Median of Array1 : 4
Median of Array2 : 7
Average of 2 medians : 5.5 

*/

#include<stdio.h>
int main()
{
	
	int a,b,i,j,temp;
	float medianA,medianB;
	printf("Enter the 'n' value for Array A: ");
	scanf("%d", &a);
	int arrA[a];
	printf("Enter the 'n' value for Array B: ");
	scanf("%d", &b);
	int arrB[b];

	
	printf("Enter the elements one by one for Array A: \n");
	
	for(i=0;i<a;i++)
	{
		scanf("%d", &arrA[i]);
	}
	
	printf("Enter the elements one by one for Array B: \n");
	
	for(i=0;i<b;i++)
	{
		scanf("%d", &arrB[i]);
	}

	
	for(j=0;j<a;j++)
	{
		for(i=1;i<a-j;i++)
		{
			if(arrA[i-1]>arrA[i])
			{
				temp=arrA[i-1];					//logic of swapping number to sort
				arrA[i-1]=arrA[i];
				arrA[i]=temp;
			}	
		}
	}
	for(j=0;j<b;j++)
	{
		for(i=1;i<b-j;i++)
		{
			if(arrB[i-1]>arrB[i])
			{
				temp=arrB[i-1];						//logic of swapping number to sort
				arrB[i-1]=arrB[i];
				arrB[i]=temp;
			}
		}				
	}
	
	//printing
	/*
	printf("arrA\n");
	for(i=0;i<a;i++)
	{
		printf("%d ",arrA[i]);
	}
	
	printf("\narrB\n");
	for(i=0;i<b;i++)
	{
		printf("%d ",arrB[i]);
	}
	*/
	if(a%2==0)
	{
		medianA=(float)(arrA[(a/2)-1]+arrA[(a/2)])/2;      //calculating median
	}
	else
	{
		medianA=(float)(arrA[(a-1)/2]);
	}
	printf("\n Median of Array1:%g\n",medianA);
	if(b%2==0)
	{
		medianB=(float)(arrB[(b/2)-1]+arrB[(b/2)])/2;		 //calculating median
	}
	else
	{
		medianB=(float)(arrB[(b-1)/2]);
	}
	printf("Median of Array2:%g\n",medianB);
	/*
	printf("arrA\n");
	for(i=0;i<a;i++)
	{
		printf("%d ",arrA[i]);
	}
	
	printf("\narrB\n");
	for(i=0;i<b;i++)
	{
		printf("%d ",arrB[i]);
	}
	*/
	printf("Average of 2 medians =%g",(medianA+medianB)/2);		// //calculating median of medians
return 0;	
}
	


	