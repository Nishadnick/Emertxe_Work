/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: set_clear_bit.c 
Description:
Read a number, M and N from the user. You need to check whether N th bit is set(1) or not, 
If yes, then you need to clear the M th bit of the number and print the updated value of num
Sample I/p :Enter the number : 7 
Sample O/p : 

Enter 'N': 2

Enter 'M': 4

Updated value of num is 19 
*/

#include<stdio.h>

int power(int base,int expo);
int main()
{
	int num=0,i,N,M,length,fact,deci=0;					//initialise variables	
	printf("Enter the number : \n");
	scanf("%d", &num);
	printf("Enter 'N': \n");
	scanf("%d",&N);
	printf("Enter 'M': \n");
	scanf("%d",&M);
	

	int revbina[15];
	int modbina[15];
//	printf("entered number is %d\n ", num);
	
	
	for(i=0;num>0;i++)
	{
		fact=num%2;
		revbina[i]=fact;						//convert Decimal to Binary
		num=num/2;								//but the numbers are stored in reverse
	}
	length=i;
	//printf("\n modbin");											//	printf("%d\n",length);		
	for(i=length-1;i>=0;i--)
	{	
		modbina[length-1-i]=revbina[i];			//the array is transferred to new array
//		printf(" #%d ",modbina[length-1-i]);				//to store in proper seq order
	}
//	printf(" \n\n new modbina: ");
	for(i=0;i<=length-1;i++)
	{
		if(modbina[length-1-N]==1)						//making conditional changes to the binary value
		{
			modbina[length-1-M]=0;
		}

//		printf(" #%d ",modbina[i]);				//printing the new array of binaries
	}	
	for(i=length-1;i>=0;i--)
	{
		deci=deci+power(2,i)*modbina[length-1-i];		//converting binary to decimal
	}
	printf(" \nUpdated value of num is %d ",deci);
return 0;
}
int power(int base,int expo)
	{
		int result=1;
		if(expo==0)
		{
			return result;
		}
			for(expo;expo>0;expo--)
			{
				result=result*base;
			}
		return result;
	}