/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: getword.c
Description:
int getword(char *word)
Create a function named getword.
Function will receive the string from main
Function should return the length of the first word.
Sample I/p :
Enter the string : Welcome to Emertxe

Sample O/p :
Enter the string : Welcome to Emertxe
*/

#include <stdio.h>

int getword(char *str);

int main()
{
        int len = 0;
	    char str[100];

		printf("Enter the string : ");
		scanf(" %[^\n]", str);

		len = getword(str);

        printf("You entered %s and the length is %d\n", str, len);
}

int getword(char *str)
{
	int length=0;
	while(1)
	{
		length++;
		if((*str==' ')||(*str=='\0'))
		{
			*str='\0';
			//printf("length %d",length);
			break;
		}
		str++;
	}
	return length-1;			//becuse it even counts the last end ' ' or '\0'
}