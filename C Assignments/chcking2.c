/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 
Description:

Sample I/p :
Sample O/p : 
*/
#include<stdio.h>
int main()
{
	int num,bit,mask,ans;
	printf("Enter the val num: ");
	scanf("%d",&num);
	printf("Enter the val of bit to check if 1 or 0 : ");
	scanf("%d",&bit);
	mask=(1<<bit);
	printf("mask value %d:\n",mask);
	ans=(num)&&(mask);						//when converted to binary
	printf("this is the answer=%d\n",ans);
	
	
    return 0;
}