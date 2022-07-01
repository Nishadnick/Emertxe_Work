/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 
Description:

Sample I/p :
Sample O/p : 
*/
#include<stdio.h>

int get_nbits(int num1, int n1);
	
int main()
{
	int num,n,ans;
	printf("Enter the number: ");
	scanf("%d", &num);
	printf("Enter number of bits: ");
	scanf("%d", &n);
	ans=get_nbits(num,n);				//when converted to binary
	printf("Result = %d\n", ans);		//good thing that %d readily prints integer value
	return 0;
}
int get_nbits(int num1, int n1)
{
	int res1;						//this is everytihng! this is the logic.
	res1=(num1&((1<<n1)-1));		//we are shifting till the required position, 
	return res1;					//then substracting by 1 so all the previous positions get populated by 1(MASK)
}									//then we & operate with this 'MASK' to get the required bits.