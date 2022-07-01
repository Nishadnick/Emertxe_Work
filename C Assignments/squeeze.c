/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: squeeze.c 
Description:
Read two strings s1 and s2 from user.
Remove the characters in s1 that matches with s2.
Input string:
string 1: Dennis Ritchie
string 2: Linux
Output String:
After squeeze s1: Des Rtche
Should not use extra array or the pointer
Sample I/p :
Enter s1 : Dennis Ritchie
Enter s2 : Linux
Sample O/p : 
After squeeze s1 : Des Rtche
*/


#include <stdio.h>
#include <stdio_ext.h>
void squeeze(char*, char*);

int main()
{
    char str1[30], str2[30];
    
    printf("Enter string1:");
    scanf(" %[^\n]", str1);
    

    printf("Enter string2:");
    scanf(" %[^\n]", str2);
   
    squeeze(str1, str2);
    
    printf("After squeeze s1 : %s\n", str1);
    
}

void squeeze(char* string1, char* string2)
{
	int i,j,k=j;
	for(i=0;string2[i]!='\0';i++)		//1st string
	{
		for(j=0;string1[j]!='\0';j++)		//2nd string to compare
		{
			if(string2[i]==string1[j])		//checking chars of 1st string with each char of 2nd string
			{	
				k=j;						//assigning new index to iterate  to chk as old index needed to move forward
				while(string1[k]!='\0')		//chk for end of ist string
				{
					string1[k]=string1[k+1];	//replace next char with previous till this strings end
					k++;						//go to next eleent after the exchange
				}
				j--;							//re iterate the same char to check for double or tripple chars
			}
			
		}
	}
	//string[]
	
	//printf("After squeeze s1 : %s",string1);
}