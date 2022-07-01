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

int my_print(char *said);

int ptr_print(char *seya);

int main()
{
	
int size;
char say[50];
char *cptr;
	cptr=say;		//for char array cptr=&say will give error 
printf("Enter a String?\n");
	scanf("%s",say);
		
	//	printf("%s\n",say);
	//size=
	
	my_print(say);

		ptr_print(cptr);
	
return 0;
}

int my_print(char *said)				//this is when direct array name is passed as pointer
{
	printf("my_print this is string %s\n",said);		//this is said for %s
	
	while((*said)!='\0')
	{
		printf("%c\n",*said++);			//this is *said for %c
	}
}

int ptr_print(char *seya)				//this is when proper pointer is made with array name and it is passed
{
	printf("ptr_print this is string %s\n",seya);		//this is said for %s
	
	while((*seya)!='\0')
	{
		printf("%c\n",*seya++);			//this is *said for %c
	}
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
	