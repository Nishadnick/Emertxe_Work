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



int main()
{
	char choice;
	char str[100],k;
	do{
		
		int char_count=0,line_count=1,word_count=0,i=0;		//initialising the counters
		printf("enter a multi-line string:\n");
		
		while((k=getchar())!=EOF)		//using special function getchar() to get 1 char at a time
		{								//proceeding as long as EOF (cntrl+d) is not pressed
			str[i]=k;					//first storing the char in k and then in char array
			char_count++;
			if(str[i]=='\n')			//'\n' would mean a new line
			{
				line_count++;
			}
			if(str[i]==' '||str[i]=='\t'||str[i]=='\n')
			{		//for checking word we need to also chk if previous char before space is valid, 
								//then only it can be a word
				
				//if((str[i-1]!=' ')&&(str[i-1]!='\t')&&(str[i-1]!='\n'))
				if(((str[i-1]>='a')&&(str[i-1]<='z'))||((str[i-1]>='A')&&(str[i-1]<='Z')))
				{			//here we're chking if the previous char is an alpahbet, we can change this as we like
					word_count++;		
				}
			}
			i++;
		}
		//if((str[char_count-1]!='\n')||(str[char_count-1]!='\t')||(str[char_count-1]!=' '))
		if(((str[char_count-1]>='a')&&(str[char_count-1]<='z'))||((str[char_count-1]>='A')&&(str[char_count-1]<='Z')))
		{			//rechecking this condition because of the EOF, this condition gets ignored
			word_count++;
		}
		printf("\nCharacter count : %d\n",char_count);
		printf("\nLine count : %d\n",line_count);
		printf("\nWord count : %d\n",word_count);
		clearerr(stdin);
		
		printf("\nDo you want to continue(y/Y) :");
		
		scanf("%c",&choice);
		/*
		if(choice=='y'||choice=='Y')
		{
			continue;
		}
		else
		{
			break;
		}*/
	}while(choice == 'y' || choice == 'Y');
	return 0;
}
