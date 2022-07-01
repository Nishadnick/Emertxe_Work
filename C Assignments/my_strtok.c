/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: Read string1 and string2 from user.
Call my_strtok (string1, string2);
Should treat string2 as delimitter in string1 and should return 1 st field.
If you call again my_strtok (NULL, string2), it should return second field
in string1 treating string2 as delimitter.
Description:
Read a string from user.
Implement using loops.
Do not print character by character.
Sample I/p :
Enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
Enter string2 : ;./-:
Sample O/p :
Tokens :
Bangalore
Chennai
Kolkata
Delhi
Mumbai
*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char * strtok,  char *delim);

int main()
{
    char str[500], delim[50];
    
    printf("Enter the string  : ");
    scanf("%s", str);
    
    __fpurge(stdout);
 
    printf("Enter the delimeter : ");
    scanf("%s", delim);
    __fpurge(stdout);
    
    char *token = my_strtok(str, delim);		//this is the first call to word
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
		
        token = my_strtok(NULL, delim);		//next call
    }
	return 0;
}

char *my_strtok(char *strtok,  char *delim)
{
	
	int i=0,j=0;
	//char *ans;
	static char *ptr=0;				//this will be used for jumpinf the pointer place for every word
	static int flag = 0;			//this to deterine the end of last word
	//static int count;
	
	
    //IF flag is set
    if(flag)
    {
	flag = 0;				//if end is reached then return NULL
	return NULL;
    }
	
	//from 2nd call in while from main()
	if (strtok == NULL)		
	{
		//simply jump to the place of new word with pointer
		 strtok = ptr;	
	}
	//ptr=strtok;
	
	for(i=0;strtok[i]!=0;i++)
	{
		
		for(j=0;delim[j]!=0;j++)
		{
			//printf("for block: %c and i=%d\n", strtok[i],i);
			//if((strtok[i]>='a' && strtok[i]<='z')||(strtok[i]>='A' && strtok[i]<='Z'))
			
			if(strtok[i]==delim[j])
			{
				//if delimiter found then make it \0
				strtok[i]='\0';			
				//new value of jumping pointer is 1 place ahead
				ptr=strtok+i+1;			
				//printf("i=%d 	after ptr =%s\n",i, ptr);
			
				if(*strtok!=0)
				{
					//printf("return strtok ptr =%s\n",strtok);
					
					//return the start address of word
					return strtok;		
				}
				else
				{
					strtok=ptr;			//original pointer jumping to new word place
					i--;				//rechecking the present place char
				}
			}
		}
	}
	if(*strtok!=0)			//this is for the last iterated word
	{
		flag = 1;			
		return strtok;		//return the start address of word
	}
	
	//printf("	Answer=%s\n", ptr);
	return NULL;
}