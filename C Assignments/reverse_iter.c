/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: reverse_iter.c 
Description:
Read a string from user.
Implement using loops.
Do not print character by character.
Sample I/p :
Enter a string : Hello World
Sample O/p :
Reverse string is : dlroW olleH
*/

#include <stdio.h>

void reverse_iterative(char *str);

int main()
{
    char str[30];
    printf("Enter any string : ");
    scanf("%[^\n]", str); 
    reverse_iterative(str);  
    printf("Reversed string is %s\n", str);
}

void reverse_iterative(char *str)
{
	int length=0,i=0,j,templ,tempf,lim;
	
	while(str[i]!=0)
	{
	length++;
		i++;
	}
	lim=(length-1)/2;
	for(i=0;i<=lim;i++)
	{
		templ=str[i];
		tempf=str[length-1-i];
	//	printf("templ:%c tempf:%c\n",templ,tempf);
	//	printf("string %s\n",str);
		str[length-1-i]=templ;
		str[i]=tempf;
	}
		
//	printf("length %d\n",length);
//	printf("string %s\n",str);
}
	


