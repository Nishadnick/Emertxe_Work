/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: squeeze.c 
Description:
Suppose k = 3 (say taking 3 distinct characters ).
Let 3 distinct characters be a , b, c.
Suppose ‘n’ is the string length to be formed using ‘k’ distinct words.
Let n be 6
The string should be formed in such a way that there should not be any consecutive repetitions of the strings.
Sample I/p :
Enter the number characters C : 3
Enter the Length of the string N : 6
Enter 3 distinct characters : a b c
Sample O/p : 
Possible NRPS is abcbca
*/

#include <stdio.h>

void nrps(char *, int, int);

int main()
{
    //read the input from the user
    
    //function call to pass input to the function
	int i,j,k,C,N;
	char str1[50];
	printf("Enter the number characters C : ");		//number of letters to use
	scanf("%d",&C);
	printf("Enter the Length of the string N : ");		//total length to make
	scanf("%d",&N);
	printf("Enter 3 distinct characters :" );		//the actual charcters to use
	
	//printf("Possible NRPS is abcbca");
	
	for(i=0;i<C;i++)
	{	
		scanf(" %c",&str1[i]);
	}
	
	
	for(i=0;i<C;i++)
	{											//need validation
		if(i==0)
		{
			continue;		//leaving the first char 
		}
		else
		{
			for(j=0;j<i;j++)		//iterate  the number of chars to check all previous chars
			{
				if(str1[i]!=str1[j])		//to check if the chars are repeated
				{
					continue;
				}
				else
				{
					printf("Error : Enter distinct characters");
					return -1;
				}
			}	
		}
	}
	nrps(str1,C,N);
}
	void nrps(char *str1, int C, int N)
	{
		int i, multiplier=0;
		printf("Possible NRPS is ");
		for (i=0;i<N;i++)
		{
			if(i%C!=0 && i!=0)	//this is the logic to increase the multiplier everytime number of chars is reached
			{
				 multiplier++;
				//printf("\n");
			}
			printf("%c ",*(str1+(i+multiplier)%C));	//the logic to circulate the chars in the range and reshuffle
		}
	}
    