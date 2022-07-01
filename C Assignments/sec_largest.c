/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: sec_largest.c
Description:Read size and array elements from the user. 
You need to find 2nd largesst element in the array without sorting or modifying the array.
You need to pass array to the function. 
U need to collect as pointer inside a function as shown below:
              int sec_largest(int *arr, int size);
In function you need to find second largest element of the array and you need to return it to the main
Sample I/p :Enter the size of the Array : 4
Enter the elements into the array: 66 22 11 3
Sample O/p : 
Second largest element of the array is 22
*/


#include <stdio.h>

int sec_largest(int *dor, int lim);

int main()
{
    int size, ret;
    
    //Read size from the user
    printf("Enter the size of the array :\n");
    scanf("%d", &size);
   
    int arr[size],i;

    printf("Read elements into the array :\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",(arr+i));		//reading the array inputs
	}
	//printf("this is the array\n");

	ret=sec_largest(arr, size);		//function call
    
	printf("Second largest element of the array is %d\n", ret);

return 0;
}

int sec_largest(int *arry, int lim)					//passing the array in the form of pointre
{
	int i, new_arr[lim],second,sec_ind;	//new_arr for the calculation of indexs large_ind,sec_ind
	int largest=*arry,large_ind=0;								//assuming first_no. = largest_no.
	//printf("\n the largest=%d",largest);
	for(i=0;i<lim;i++)
	{
		new_arr[i]=*arry;							//assigning current pointer value to array index value
		arry++;										//physically incrementing pointer position
	}
		
	for(i=0;i<lim;i++)
	{	
		if (largest<new_arr[i])						//chking if the next value is largest
		{
			largest=new_arr[i];						//if the new value is largest then make it the new largest 
			large_ind=i;							//store its index number for easy condition chk
		}
	}
	if(large_ind>0)									//this is for assigning a proper value to sec_ind
	{
		sec_ind=large_ind-1;
	}
	else
	{
		sec_ind=large_ind+1;
	}
	
	second=new_arr[sec_ind];						//using this value for second as it is readily available
	//printf("\n the largest=%d  ind=%d",largest,large_ind);
	for(i=0;i<lim;i++)
	{	
		if ((i!=large_ind)&&(new_arr[i]<largest)&&(second<new_arr[i]))
		{					//skipping the index of largest value, and chking if the chked_value<largest_value
											//and chking if the chked_value greater than assumed second value
			second=new_arr[i];				//if yes then chked_value becomes second
			sec_ind=i;
	//		printf("\n the second =%d  sec_ind=%d",second,sec_ind);
		}
	}
	return second;
}