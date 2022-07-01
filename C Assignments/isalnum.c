/*
name: Nishad S. Taksande
Date: 13-Jan-22
Assignment Title: isalnum.c
Description:
c-type library functions check whether ch, 
which must have the value of an unsigned char or EOF, 
falls into a certain character class according to the current locale.
isalnum() - checks for an alphanumeric character; 
it is equivalent to (isalpha(c) || isdigit(c)).
Sample I/p : Enter the character: a
Sample O/p : The character 'a' is an alnum character.
*/
#include<stdio.h>

int my_isalnum(char);

int main()
{
    char ch;
    int ret;
    printf("Enter the character:");
    scanf("%c", &ch);
    ret = my_isalnum(ch);
    /*
        Based on return value, print whether ch is alphanumeric or not
    */
	return 0;
}

int my_isalnum(char ch)
{
	if((ch>=48&&ch<=57)||(ch>=65&&ch<=90)||(ch>=97&&ch<=112))
	{						//ASCII ranges for numbrs, small letters and capital characters
		printf("Entered character is alphanumeric character");
	}
	else
	{
		printf("Entered character is not alphanumeric character");
	}
}
