/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: combination.c
Description:
Read a string from the user, find and print all the possible combinations of given string.
Sample I/p :
Enter a string: abc
All possible combinations of given string :abc
Sample O/p : 
acb
bca
bac
cab
cba
*/
#include<stdio.h> 

void combination(char *,int ,int );
int my_strlen(char*);

int main()

{
        char str[100];
        int n,i,j;
        int res;
        printf("Enter a string: ");
		//fgets(str,sizeof(str),stdin);		//using fgets to input string cz for some reason scanf was not working
        scanf("%100[^\n]", str);    	//it is working
		//printf("new strings are:\n ");
		
        n = my_strlen(str);
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				continue;				//will not include 1st element, cz what will we compare it with right?
			}
			else 
				for(j=0;j<i;j++)			//will check only till limit of current i
				{
					if(str[i]==str[j])			//checking for repeated chars
					{
						printf("Error: please enter distinct characters.");
						return -1;		//immediatly get out of program
					}
				}
		}
       combination(str,0,n);                       
        return 0;
}

void combination(char *str2 ,int multiplier,int lim)
{
	int i,fact=1;				
	for(i=lim;i>0;i--)
	{
		fact=fact*i;		//calc factorial cz it is the number of possible combinations
	}
	
	printf("All possible combinations of given string :");
	for(i=0;i<(fact*lim);i++)
	{
		if(i%lim==0 && i!=0)
		{
			multiplier++;		//this var will help in shiftng the combination
		}
		if((i+lim)%lim==0 && i>2)		//used basically for formatting and displaying reuired length strings
		{
			printf("\n");
		}
		printf("%c",*(str2+(i+multiplier)%lim));	//actual logic for making unique combinations
	}
	
}


int my_strlen(char* str1)			//function used to claculate length of string
{
	int count=0;
	//printf("string %s",str1);
	while(*str1!='\0')
	{
		str1++;
		count++;
	}
	return count;
}