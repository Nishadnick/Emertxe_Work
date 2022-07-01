
/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: my_itoa.c
Description:
int itoa(int n, char *s)
Convert integer n into a string and store the string in s.
Return the length of string from the function.
Sample I/p :
Enter the number : 1234
Sample O/p : 
Integer to string is 1234
*/
#include <stdio.h>

int my_itoa(int num, char *str);

int main()
{
    int num;
    char str[10];
    
    printf("Enter the number:");

	if(scanf("%d", &num)==1)			//very imp. if number is not found at start, then this is false
	{
		my_itoa(num, str);
	}
	else
	{
		str[0]='0';
		str[1]='\0';
	}
	
    printf("Integer to string is %s", str);
}

int my_itoa(int num, char *str)
{
	int i=0,length=0,arr[50],digit,flag=0;
	if(num<0)
	{
		flag=1;
		num=num*-1;
	}
	
	while(num>0)
	{
		digit=num%10;			//take the full number and extract digits 1by1
		num=num/10;				//reduce the original number by a power of 10
		arr[i]=digit;			//save the digits in int array
		i++;
	}
	length=i;					//the amount traveresed would be the length of number

	if(flag==1)
	{
		length=i+1;
		str[0]='-';
	
		for(i=1;i<length;i++)
		{								//incase of negetive no. we adjust the position
			str[length-i]=arr[i-1]+48;	//48-57 we convert the number to its ascii char value
		}
		str[length]='\0';				//attach null char to limit the string
	}
	else
	{
		for(i=0;i<length;i++)
		{
			str[length-1-i]=arr[i]+48;	//48-57 we convert the number to its ascii char value
		}
		str[length]='\0';	
	}
	return 0;
}