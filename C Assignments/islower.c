/*
name: Nishad S. Taksande
Date: 13-Jan-22
Assignment Title: : islower.c
Description:
c-type library functions check whether ch, 
which must have the value of an unsigned char or EOF, 
falls into a certain character class according to the current locale.
islower() - checks for a lower case alphabet whether entered character is between 'a' to 'z'.
Sample I/p : Enter the character: a
Sample O/p : Entered character is lower case alphabet
*/
#include<stdio.h>

int islower(int);

int main()
{
    char ch;
    int ret;
    printf("Enter the character:");
    scanf("%c", &ch);
    ret = islower(ch);
    /*
        Based on return value, print whether ch is alphanumeric or not
    */
	return 0;
}

int islower(int ch1)
{
	if(ch1>=97&&ch1<=122)
	{
		printf("Entered character is lower case alphabet");
	}
	else
	{
		printf("Entered character is not lower case alphabet");
	}
}
