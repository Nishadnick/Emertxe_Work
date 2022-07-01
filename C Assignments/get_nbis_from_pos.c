/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: get_nbis_from_pos.c
Description:

Sample I/p :
Sample O/p : 
*/
#include<stdio.h>

int get_nbits_from_pos(int num1, int n1, int pos1);
	
int main()
{
	int num,n,pos,ans;
	printf("Enter the number: ");
	scanf("%d", &num);
	printf("Enter number of bits: ");
	scanf("%d", &n);
	printf("Enter the pos: ");
	scanf("%d", &pos);
	ans=get_nbits_from_pos(num,n,pos);				//when converted to binary
	printf("Result = %d\n", ans);		//good thing that %d readily prints integer value
	return 0;
}
int get_nbits_from_pos(int num1, int n1, int pos1)
{
	int res1,mask1,ext1;						
	
	ext1=num1>>(pos1-n1+1);		//1st e decide how much the whole number needs to be shifted 
	mask1=((1<<n1)-1);			//so the required extraction will start from LBS
	res1=(ext1)&(mask1);		//then we & operate with the mask we created
	return res1;					
}									