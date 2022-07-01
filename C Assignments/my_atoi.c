/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 22_wc.c
Description:int my_atoi(const char *s)
The function will recieve a string and covert the number stored in the string into exact integer number.
Return the number.

Non formated function like getchar()

Sample I/p :
Enter a numeric string: 12345
Sample O/p : 
String to integer is 12345
*/
#include <stdio.h>

int my_atoi(const char *word);

int main()
{
    char str[20];
    
    printf("Enter a numeric string : ");
    scanf("%s", str);
    
    printf("String to integer is %d\n", my_atoi(str));
}

int my_atoi(const char *word)
{
	int num=0, digit=0,flag=1;
	if(*word=='-')
	{
		flag=-1;
		*word++;
	}
	else if(*word=='+')
	{
		*word++;
	}
	while((*word!='\0')&&(*word>='0')&&(*word<='9'))
	{
		digit=*word-48;
		num=num*10+digit;
		*word++;
	}
		return num*flag;
		
}
