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
	int num,lshift,rshift,left,right;
	printf("Enter the number \n");
	scanf("%d",&num);
	printf("enter the no. of lshift \n");
	scanf("%d",&lshift);
	printf("enter the no. of rshift \n");
	scanf("%d",&rshift);
	
	left=(num<<lshift);
	printf("left=%d\n",left);
	right=(num>>rshift);
	printf("right=%d\n",right);
	
	
    return 0;
}