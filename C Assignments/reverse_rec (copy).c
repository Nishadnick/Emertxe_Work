/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: reverse_iter.c 
Description:
Read a string from user.
Implement using loops.
Do not print character by character.
NOTE : Should not use static, global variables and loops
Sample I/p :
Enter a string : Hello World
Sample O/p :
Reverse string is : dlroW olleH
*/

#include <stdio.h>

void reverse_recursive(char *str, int ind, int len);

int main()
{
    char str[30];
    int ind=0,length=0;
    printf("Enter any string : ");
    scanf("%[^\n]", str);
	
	while(str[ind]!=0)
	{
		length++;
		ind++;
	}
	ind=0;
    printf("length %d\n",length);
    reverse_recursive(str, ind, length);
    
    printf("Reversed string is %s\n", str);
}

void reverse_recursive(char *str, int ind, int len)
{
	int templ,tempf,lim;
	lim=(len-1)/2;
	printf("lim: %d\n",lim);
	printf("ind: %d\n",ind);
	printf("string %s\n",str);
	if(ind<=lim)
	{
		templ=str[ind];
		tempf=str[len-1-ind];
		//printf("templ:%c tempf:%c\n",templ,tempf);
		//printf("string %s\n",str);
		str[len-1-ind]=templ;
		str[ind]=tempf;
		ind++;
		reverse_recursive(str, ind, len);
	}
	else
	{
		return;
	}

	
}
	


