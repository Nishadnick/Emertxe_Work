/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 
Description:

Sample I/p :
Sample O/p : 
*/
#include<stdio.h>

int replace_nbits(int num1, int n1, int val1);
	
int main()
{
	int num,n,val,ans;
	printf("Enter the value: ");
	scanf("%d", &num);
	printf("Enter number of bits: ");
	scanf("%d", &n);
	printf("Enter the number: ");
	scanf("%d", &val);
	ans=replace_nbits(num,n,val);				//when converted to binary
	printf("Result = %d\n", ans);		//good thing that %d readily prints integer value
	return 0;
}
int replace_nbits(int num1, int n1, int val1)
{
	int ext1,ext2,mask2,res1;						
	ext1=(val1&((1<<n1)-1));	//first we extract the number of bits required from LSB of val
	mask2=~((1<<n1)-1);			//then we make a mask to use on num to clear the required number of bits from LSB
	ext2=(num1)&(mask2);		//then we clear the same number of bits from num using the said mask
	res1=(ext2)|(ext1);			//after clearing the required ibts from num we copy the required bits in its place 
	return res1;				//with the hepl of previous extracted bits
}									