/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: mem_manager.c
Description:
Allocate 8 consecutive bytes in memory
Provide a display menu
1. Add element
2. Remove element
3. Display element
4. Exit from the program
It should allow to add elements of different data types which data type size is less than or equal to 8
Sample I/p :
user@emertxe] ./mem_manager
Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Sample O/p : 
Test Case 1:
user@emertxe] ./mem_manager
Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 2
Enter the char : k
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
-------------------------
0 -> k
*/
#include<stdio.h> 
#include<stdlib.h> 

int main()

{
	int int_num=0, ip=100, ch=100, rem_ch=100;
	int int_flag=0,srt_flag=0,char_flag1=0,char_flag2=0,fl_flag=0,db_flag=0;
	void *ptr;
	ptr=malloc(8);
	if(ptr==NULL)
	{
		printf("Memory not Allocated");
		return 1;
	}
	
	
	do{
	printf("\nMenu :\n1. Add element \n2. Remove element \n3. Display element \n4. Exit from the program\n");
		   scanf("%d",&ch);
		printf("choice ---> %d\n",ch);
	if(ch==1)		//Add Element
	{
		printf("Enter the type you have to insert: \n1. char \n2. short \n3. int \n4. float \n5. double\n");
		scanf("%d",&ip);
		printf("input ---> %d\n",ip);
		if(ip==1 && char_flag1==0 && db_flag==0)		//Add char
		{
			printf("Enter the 1st char:");
			getchar();
			scanf("%c",((char *)ptr+0));
			//printf(" the 1st char:%c",*((char *)ptr+0));
			char_flag1=1;
			//ptr+sizeof(ptr);
		}
		
		else if(ip==1 && char_flag2==0 && char_flag1==1 && db_flag==0)		//Add char
		{
			printf("Enter the next char:");
			getchar();
			scanf("%c",((char *)ptr+1));
			//printf(" the next char:%c",*((char *)ptr+1));
			char_flag2=1;
			//ptr+sizeof(ptr);
		}
		
		else if(ip==2 && srt_flag==0 && db_flag==0)		//Add short
		{
			printf("Enter the short : ");
			scanf("%hi",((short *)ptr+1));
			//printf(" the short : %hi",*((short *)ptr+1));
			srt_flag=1;
			//srt_num=(short *)ptr[2];
		}
	
		else if(ip==3 && int_flag==0 && db_flag==0)		//Add int
		{
			printf("Enter the int :");
			scanf("%d",((int *)ptr+1));
			//printf(" the int : %i",*((int *)ptr+1));
			int_flag=1;
			//int_num=(int *)ptr[4];
		}
		
		
		else if(ip==4 && fl_flag==0 && int_flag==0 && db_flag==0)		//Add float
		{
			printf("Enter the float : ");
			scanf("%f",((float *)ptr+1));
			//printf(" the short : %f",*((float *)ptr+1));
			fl_flag=1;
			//fl_num=(float *)ptr[4];
		}
	
		else if(ip==5 && db_flag==0 && char_flag1==0 && char_flag2==0 && srt_flag==0 && int_flag==0 && fl_flag==0)	
		{											//Add double
			printf("Enter the double : ");
			scanf("%lf",((double *)ptr));
			//printf(" the short : %lf",*((float *)ptr));
			db_flag=1;
			//db_num=(double *)ptr[0];								
		}
		else										//
		{
			printf("Memory not available ");
			break;
		}
	}
	if(ch==2)										//Remove Element
	{
		if(char_flag1==1)							//show char
		{
			printf("0 (char )-> %c\n",*((char *)ptr));
		}
		if(char_flag2==1)							//show char
		{
			printf("1 (char )-> %c\n",*((char *)ptr+1));
		}
		if(srt_flag==1)								//show short
		{
			printf("2 (short )-> %hi\n",*((short *)ptr+1));
		}
		if(int_flag==1)								//show int
		{
			printf("4 (int )-> %d\n",*((int *)ptr+1));
		}
		if(fl_flag==1 && int_flag==0)				//show float
		{
			printf("4 (float )-> %f\n",*((float *)ptr+1));
		}
		if(db_flag==1)								//show double
		{
			printf("0 (double )-> %lf\n",*((double *)ptr));
		}
		printf("Enter the index value to be deleted : ");
		scanf("%d",&rem_ch); 						//index value to be removed
		
		if(rem_ch==0 && char_flag1==1)								//remove char
		{
			char_flag1=0;
		}
		else if(rem_ch==1 && char_flag2==1)		//remove char
		{		
			char_flag2=0;
		}
		else if(rem_ch==2 && srt_flag==1)							//remove short
		{	
			srt_flag=0;
		}
		else if(rem_ch==4 && int_flag==1)			//remove int
		{	
			int_flag=0;
		}
		else if(rem_ch==4 && fl_flag==1)			//remove float
		{	
			fl_flag=0;
		}
		else if(rem_ch==0 && db_flag==1)			//remove double
		{	
			db_flag=0;
		}
		printf("index %d successfully deleted.",rem_ch);
		
	}
	if(ch==3)										//Display Element
	{
		if(char_flag1==1)							//show char
		{
			printf("0 (char )-> %c\n",*((char *)ptr));
		}
		if(char_flag2==1)							//show char
		{
			printf("1 (char )-> %c\n",*((char *)ptr+1));
		}
		if(srt_flag==1)								//show short
		{
			printf("2 (short )-> %hi\n",*((short *)ptr+1));
		}
		if(int_flag==1)								//show int
		{
			printf("4 (int )-> %d\n",*((int *)ptr+1));
		}
		if(fl_flag==1 && int_flag==0)				//show float
		{
			printf("4 (float )-> %f\n",*((float *)ptr+1));
		}
		if(db_flag==1)								//show double
		{
			printf("0 (double )-> %lf\n",*((double *)ptr));
		}
	}
		
	}while(ch!=4);
	 free(ptr);
	return 0;
}

