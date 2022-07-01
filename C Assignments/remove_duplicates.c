/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: sec_largest.c
Description:
Read size and elements into the array. After reading the input, 
you need to pass array to the function. In function, 
you need to remove duplicates/copy non-duplicate elements into new array.
You need to print he final output in main
Please use the prototype given below:
void fun(int *arr1, int size, int *arr2, int *new_size);
Sample I/p :
Enter the size: 5

Enter elements into the array: 5 1 3 1 5
Sample O/p :
After removing duplicates: 5 1 3
*/

#include <stdio.h>

void fun(int *arr1, int size, int *arr2, int new_size);

int main()
{
      int size, i;
	static int new_size;
    
    printf("Enter the size of the array : ");
    scanf("%d", &size);
   
    int arr[size],arr2[size];
    
    printf("Enter the %d elements\n",size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);		//scanning the values
    }

	
	fun(arr,size,arr2,new_size);


}
void fun(int *arr1, int size, int *arr2, int new_size)
{
	int i,j;
	for (i=0;i<(size);i++)
	{
		for (j=i+1;j<size;j++)
		{
			if(arr1[i]==arr1[j])
			{					//replacing duplicate elements with 0
				arr1[j]=0;
			}
		}
	}
	
	for(i=0;i<size;i++)
	{
		if(arr1[i]>0)
		{
			arr2[new_size++]=arr1[i];		//filling new array with remanining elements
		}
	}
printf("\nAfter removing duplicates:");
	for (i=0;i<new_size;i++)
    {
       printf("%d ", arr2[i]);		//printing the values
    }
	
}