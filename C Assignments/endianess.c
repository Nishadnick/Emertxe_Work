/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: endianess.c
Description:Check the memory assigning order of variables for 
checking whether little endian or big endian machine
    Little Endian:
           --------------
           Say int i = 10; gets stored in memory at
           1000
           1001
           1002
           1003
           where 1000 contains LSB of i and 1003 contains MSB of i
           char *ptr = &i; the ptr will now contain 1000

           Big Endian:
           -----------
           Say int i = 10; gets stored in memory at
           1000
           1001
           1002
           1003
           where 1000 contains MSB of i and 1003 contains LSB of i
           char *ptr = &i; the ptr will now contain 1000

Read 2 byte or 4 byte data according to given size(short or Int). 
Swap the bytes and convert the given data to Big Endian 
Sample I/p : Enter the size: 2
Enter any number in Hexadecimal: ABCD
Sample O/p : After conversion CDAB
*/

#include <stdio.h>

int main()
{
    int i,num,size,s=0;

	printf("Enter the size: \n");
	scanf("%d",&size);
	
	printf("Enter any number in Hexadecimal: ");
	scanf("%X",&num);
	

	unsigned char * cptr;			//taking unsigned char pointer so the value remains positive throughout
	char temp1;
	char temp2;
	cptr=(char *)&num;				//making the int pointer into char pointer so byte by byte access is possible 

	for(i=0;i<=size/2;i++)
	{
		/*
		temp2=*(cptr+i);				//1st element is temp
		temp1=*(cptr+(size/2)-i);		//last element in temp	
		//temp1=*(cptr+(size-1)-i);
		//printf("*(cptr+(size-1)-i) == %x\n",*(cptr+(size-1)-i));
		printf("*(cptr+(size-1)-i) == %x\n",*(cptr+(size/2)-i));
		
		*(cptr+(size/2)-i)=temp2;
		//*(cptr+(size-1)-i)=temp1;
		*(cptr+i)=temp1;				//swap elements
		printf("*(cptr+i) == %x\n",*(cptr+i));
		*/
		//printf("%X",cptr[i]);
		temp2=cptr[i];		//ultimately using array cz easy to explain
		temp1=cptr[size-1-i];
		cptr[i]=temp2;
		cptr[size-1-i]=temp1;
		
	}
	printf("After conversion ");
	for(i=0;i<size;i++)
	{
		//printf("(cptr+%d) %X\n",i,*(cptr+i));		//printing the char pointer after changes
		printf("%02X",cptr[i]);					//padding of 0 to make 2char display
	}
	return 0;
}



