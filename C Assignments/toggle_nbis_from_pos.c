/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: toggle_nbis_from_pos.c
Description:

Sample I/p :
Sample O/p : 
*/
#include<stdio.h>

int toggle_nbits_from_pos(int num1, int bits1, int pos1);
	
int main()
{
	int num,bits,pos,ans;
	printf("Enter the number: ");
	scanf("%d", &num);
	printf("Enter number of bits: ");
	scanf("%d", &bits);
	printf("Enter the pos: ");
	scanf("%d", &pos);
	

	ans=toggle_nbits_from_pos(num,bits,pos);				//when converted to binary
	printf("Result = %d\n", ans);		//good thing that %d readily prints integer value
	return 0;
}
int toggle_nbits_from_pos(int num1, int bits1, int pos1)
{
	int res1,mask1,mask2,mask3,mask4,ext1,ext2,ext3;						
	
	ext1=num1>>(pos1-bits1+1);			//shift number to LSB position
	
	mask1=((1<<bits1)-1);				//mask for 3 bits
	ext2=ext1&mask1;				//take out the required bits
	mask2=(~ext2)&(mask1);			//compliment the bits and take out the required number of bits
	mask3=mask2<<(pos1-bits1+1);		//shift the required number of bits to the position of replacement
	mask4=~(mask1<<(pos1-bits1+1));	//create a mask by shifting the required number of bits to clear the bits
	ext3=(num1)&(mask4);			//clear the required number of bits which need to be replaced
	
	res1=(ext3)|(mask3);			//copy the required bit to the required position

	return res1;					
}									