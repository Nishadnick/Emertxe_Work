/*
name: Nishad S. Taksande
Date: 13-Jan-22
Assignment Title: isblank.c 
Description:
c-type library functions check whether ch, 
which must have the value of an unsigned char or EOF, 
falls into a certain character class according to the current locale.
isblank() - checks for a blank character; that is, a space or a tab.
Sample I/p : Enter the character: a
Sample O/p : The character ' ' is a blank character.
*/
#include<stdio.h>

int isblank(int);

int main()
{
    char ch;
    int ret;
    printf("Enter the character:");
    scanf("%c", &ch);
    ret = isblank(ch);
    /*
        Based on return value, print whether ch is alphanumeric or not
    */
	return 0;
}

int isblank(int ch1)
{
	if(ch1==32||ch1==9||ch1==10)
	{
		printf("Entered character is a blank character");
	}
	else
	{
		printf("Entered character is not blank character");
	}
}
