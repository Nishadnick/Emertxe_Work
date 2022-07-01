/*
name: Nishad S. Taksande
Date: 13-jan-21
Assignment Title: replace_nbits_from_pos.c 
Description:
Read number num from user.
Read number val from user.
Read number a from user.
Read number b from user(a <= b <=31)
Do error checking
Check b is within limit or not.
Call replace_nbits_from_pos function by passing val, b - a + 1, b and num as arguments.
replace_nbits_from_pos(num, a, b, val);
Print the new value of i.
Prompt for continue option.

Sample I/p :
Enter the value of 'num' : 11
Enter the value of 'a' : 3
Enter the value of 'b' : 5
Enter the value of 'val': 174
Sample O/p : Result : 158
*/
#include<stdio.h>


int replace_nbits_from_pos(int num1, int a1, int b1, int val1);

int main()
{
    int num, a, b, val, res = 0;
	
	printf("Enter num, a, b, and val:");
    scanf("%d%d%d%d", &num, &a, &b, &val);
	
	res = replace_nbits_from_pos(num, a, b, val);
	printf("Result = %d\n", res);
	/*
	do
	{
		char opt='y';
		printf("Enter num, a, b, and val:");
    	scanf("%d%d%d%d", &num, &a, &b, &val);
		if((a>0&&a<=31)&&(b>a&&b<=31))		//whole checkng if no.is in range
		{
			res = replace_nbits_from_pos(num, a, b, val);
		}
		else
		{
			printf("Error\n");
			printf("Enter num, a, b, and val:");
    		scanf("%d%d%d%d", &num, &a, &b, &val);
		}
    printf("Result = %d\n", res);
		
	printf("\ndo you want to continue?  press y/n ");
		getchar();
		scanf("%c",&opt);
								//input needed to continue
		if(opt=='y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	
	while(1);
*/
}
int replace_nbits_from_pos(int num1, int a1, int b1, int val1)
{
		int bits1=(b1-a1+1),res;
		res=(val1&(~(((1<<bits1)-1)<<bits1)))|((num1&((1<<bits1)-1))<<bits1);
		return res;		
}
// mask1=((1<<bits1)-1))<<bits1			made and trasnferred to position used to extract bits from LSB
// mask2=(~(((1<<bits1)-1)<<bits1))		made and trasnferred to position used to clearthe required bits