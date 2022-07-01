/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: sec_largest.c
Description:
Input string:
Pointers         are      sharp           knives.
Output String:
Pointers are sharp knives.
Blank can be spaces or tabs. (replace with single space).
Sample I/p :
Enter the string with more spaces in between two words
Pointers     are               sharp     knives.

Sample O/p :
Pointers are sharp knives.
*/

#include <stdio.h>

void replace_blank(char *str1);

int main()
{
    char str[150];
    
   // printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);
    
    replace_blank(str);
   printf("%s", str);
 
}

void replace_blank(char *str)	
{
	int i=0,j=i,count=0,length=0;
	//printf("string:\n%s\n", str);

		
	while(str[i+1]!='\0')			//we are using \0 to specify end hence to include \0 
	{								//by traversing i till string end we extra increment i
		if(str[i]=='\t')
		   {
		   		str[i]=' ';			//if there is ever a TAB found then we immediately replace it
		   }
		if((str[i]==' ')&&(str[i+1]==' '))	//at certain position we encounter ' ' and even next element is ' '
		{
			j=i;					//i is used for traversing string so we use another variable j
			while(str[j]!='\0')		//now j will start performing the replacement  till the end
			{
				//printf("%d j loop:%c\n",j,str[j]);
				str[j]=str[j+1];	//we leftshift alll the elements and as j+1 can reach \0 
				j++;				//so even \0 is used in replacement
			}
			i--;					//beacuse a replacement was performed, we jump back 1 step to re-iterate
			//printf("%d i inside:%c\n",i,str[i]);
		}
		//printf("%d i outside:%c\n",i,str[i]);
	i++; 					//i continues string traversing, even if it transferred its value to j
	}
		
	//printf("%s\n",str);
}