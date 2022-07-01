/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: third_largest.c
Description:Read size and array elements from the user. 
You need to find 3rd largest element in the array without sorting or modifying the array.
You need to pass array to the function. U need to collect array as pointer inside a function as shown below:
              int third_smallest(int *arr, int size);
In function you need to find third largest element of the array and you need to return it to the main
Sample I/p :Enter the size of the Array : 5
Enter the elements into the array: 5 1 4 2 8
Sample O/p : 
Third largest element of the array is 4
*/

#include <stdio.h>

int third_smallest(int *arry, int lim);
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
//	printf("this is the array\n");
	ret=third_smallest(arr, size);		//function call 
	printf("Third largest element of the array is %d\n", ret);
return 0;
}
int third_smallest(int *arry, int lim)					//passing the array in the form of pointre
{
	int i, new_arr[lim],second,sec_ind,third,third_ind;	//new_arr for the calculation of indexs large_ind,sec_ind
	int largest=*arry,large_ind=0;								//assuming first_no. = largest_no.

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
	//printf("\n the largest =%d  large_ind=%d\n",largest,large_ind);
	if (large_ind==(lim-1))
	{
		sec_ind=large_ind-1;
	}
	else								//this is for assigning a proper value to sec_ind
	{
		sec_ind=large_ind+1;
	}
		
	second=new_arr[sec_ind];						//using this value for second as it is readily available

	for(i=0;i<lim;i++)
	{	
		if ((i!=large_ind)&&(second<=new_arr[i])&&(second<largest))	//second<=new_arr[i] beacsue assumption can be correct
		{					//skipping the index of largest value, and chking if the chked_value<largest_value
											//and chking if the chked_value greater than assumed second value
			second=new_arr[i];				//if yes then chked_value becomes second
			sec_ind=i;
			
		}
	}
	printf("\n the second =%d  sec_ind=%d\n",second,sec_ind);
	//third
	third_ind=0;								//purposely assigning lagest for chking purpose
	if((large_ind==third_ind||sec_ind==third_ind)&&third_ind<lim)		
		//this is for assigning a proper value to third_ind
	{													//this condition albeit performing short circuit evaluation
		third_ind++;									//it will still chk both or conditions
	}
	third=new_arr[third_ind];

	for(i=0;i<lim;i++)
	{	
		if ((i!=large_ind)&&(i!=sec_ind)&&(third<=new_arr[i])&&third<second)
		{					//skipping the index of second value, and chking if the chked_value<second_value
											//and chking if the chked_value greater than assumed third value
			third=new_arr[i];				//if yes then chked_value becomes third
			third_ind=i;
	//		printf("\n the third =%d  third_ind=%d",third,third_ind);
		}
	}
	return third;
}