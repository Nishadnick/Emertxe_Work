/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 22_wc.c
Description:Read characters from user till EOF
If EOF received, print the character count, word count, and line count.
Code should exactly work like wc command.

Non formated function like getchar()

Sample I/p :
Hello world
Dennis Ritchie
Linux
Sample O/p : 
Character count : 33
Line count : 3
Word count : 5

*/
#include<stdio.h>
#include<string.h>

int length(char *str);

int main()
{
	char str[100];
	scanf("%99[^\n]",str);
	printf("Length of 1st word is %d\n",length(str));

	return 0;
}


int length(char *str)
{
	int len=0;
	while(*str++!='\0')
	{
		len++;
	}
	return len;
}


/*
int foo(int a);
int main() 
{ 

	int a=10;
	printf("%d\n",foo(a));
	return 0;
} 
int foo(int a)
{
	int x=0;
	x?sizeof (a):sizeof (int);
	return x;
}*/
	