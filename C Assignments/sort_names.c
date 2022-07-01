/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: sort_names.c
Description:
Read the N name from the user
Sort it in alphabetical order
Use 1st dynamic and 2nd static. Char (*name)[32]
No.of names should be dynamic and no.of characters should be static.
Allocate the memory dynamically for no.of names.
Sample I/p :Enter the size: 5

Enter the 5 names of length max 32 characters in each
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai
Sample O/p : 
The sorted names are:
Agra
Bengaluru
Chennai
Delhi
Kolkata
*/

#include <stdio.h>
#include <stdlib.h>

void sort_names(char ** name, int num1);

int main()
{
	int i,num=0;
	
	printf("Enter the size: ");
	scanf("%d",&num);
	
    //char(*names)[32];			//static this is wrogn because memory is alraedy allocated 
								//and 2nd allocation on its basis is just not possible for 'array type'
	char ** names;
	names=(char **)malloc(num*sizeof(char)*32);	
	printf("Enter the 5 names of length max 32 characters in each\n");
	for(i=0;i<num;i++)
	{
		
		*(names+i)=(char *)malloc(sizeof(char)*32);		//dynamic
		
		//fgets(*(names+i),32,stdin);
		printf("[%d] -> ",i);
		scanf("%s",names[i]);
		
	}
	sort_names(names, num);
	
}


void sort_names(char ** name, int num1)
{
	int i,j,place=0;
	char * teamp;
	
	for(i=0;i<=num1;i++)
	{
		for(j=i+1;j<num1;j++)
		{
			if(name[i][place]==name[j][place])		//incase the letters are common
			{
				place++;
			}
			if(name[i][place]>name[j][place])		//simple name char by char comparison
			{
				teamp=name[i];
				name[i]=name[j];
				name[j]=teamp;
			}
			place=0;
		}
	}
	
	printf("The sorted names are:\n");
	for(i=0;i<num1;i++)
	{	
		printf("%s\n",*(name+i));
	}
}