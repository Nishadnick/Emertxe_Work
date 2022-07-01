/*
name: Nishad S. Taksande
Date: 13-Jan-22
Assignment Title: : ispunct.c 
Description:
c-type library functions check whether ch, 
which must have the value of an unsigned char or EOF, 
falls into a certain character class according to the current locale.
ispunct() - checks  for  any  printable character which is not a space or an alphanumeric character.
Sample I/p : Enter the character: a
Sample O/p : Entered character is not punctuation character
*/
#include<stdio.h>

int ispunct(int);

int main()
{
    char ch;
    int ret;
    printf("Enter the character:");
	//getchar();
    scanf("%c", &ch);
    ret = ispunct(ch);
    /*
        Based on return value, print whether ch is alphanumeric or not
    */
	return 0;
}

int ispunct(int ch1)
{
	if((ch1>=33&&ch1<=47)||(ch1>=58&&ch1<=64)||(ch1>=91&&ch1<=96)||(ch1>=123&&ch1<=126))
	{
		printf("Entered character is punctuation character");
	}
	else
	{
		printf("Entered character is not punctuation character");
	}
}
