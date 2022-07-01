/*
name: Nishad S. Taksande
Date: 13-jan-21
Assignment Title: circular_right_shift.c 
Description:
Read a number num from user.
Read a number n from user.
Pass num and n to the function.
Shift num, n times (towards right).
While shifting the shifted bits should get replaced at the alternate end.
For right shifting, the shifted bits should come at left most side.
Return the new number from the function.
Print the new number.

Sample I/p :
 Enter num: -12
Enter n : 3
Sample O/p :
           Result : 10011111 11111111 11111111 11111110

*/

#include <stdio.h>

int circular_left(int, int);
int print_bits(int);

int main()
{
    int num, n, ret;
    
    printf("Enter the num:");
    scanf("%d", &num);
    
    printf("Enter n:");
    scanf("%d", &n);
    
    ret = circular_left(num, n);
    printf("answer Enter n:%d\n",ret);
    print_bits(ret);
}

int circular_left(int num1, int n1)
{
	int mask1,mask2;
	if(num1<0)
	{
		unsigned int num2=num1;
		printf("new num2=%d\n",num2);
		mask1=num2<<(32-n1);			//shifting the bits to MSB
		mask2=num2>>n1;					//removind the LSBs
	}
	else
	{
		printf("new num2=%d\n",num1);
		mask1=num1<<(32-n1);			//shifting the bits to MSB
		mask2=num1>>n1;					//removind the LSBs
	}
	return (mask1|mask2);				//combining the shifts
}
int print_bits(int ret1)
{
	int i;
	for(i=0;i<32;i++)
	{	
		if((ret1>>31-i)&1==1)			//trasnferring the bit to compare with LSB
		{
			printf("1 ");
		}
		else							//	printing the result
		{
			printf("0 ");
		}	
	}
		
}