/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: squeeze.c 
Description:
Read a string from the user. Check whether the string is Pangram or not
A pangram is a sentence containing every letter in the English Alphabet.
Example 1 : "The quick brown fox jumps over the lazy dog ” is a Pangram 
[Contains all the characters from ‘a’ to ‘z’] 
Example 2: “The quick brown fox jumps over the dog” is not a Pangram 
[Doesn’t contain all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing]

Sample I/p :
Enter the string: The quick brown fox jumps over the lazy dog
Sample O/p : 
The Entered String is a Pangram String
*/

#include <stdio.h>

int pangram(char * sentence);

int main()
{
	char sent[100];
	  printf("Enter string:");
      scanf(" %[^\n]", sent);
	  pangram(sent);
}
//A-Z 65-90
//a-z 97-122
int pangram(char * sentence)
{
	int i,j,flag=0;
	for(j=65;j<91;j++)					//checking lower range chars
	{
		for(i=0;sentence[i]!='\0';i++)
		{
		
			if(sentence[i]==32)
			{
				i++;
			}
			if(sentence[i]==j||sentence[i]==(j+32))		//just adding cost value between 'A' and 'a'
			{
				flag=1;
				break;					//whenever a char is found, we stop and chk for another
			}
			else
			{
				flag=0;					//if a char is ultimately not found then that means it does not exixt here
			}
		}
		if(flag==0)
		{
			printf("The Entered String is not a Pangram String");
			break;
		}
	}
	if(flag==1)
		{
			printf("The Entered String is a Pangram String");
			
		}
	
}