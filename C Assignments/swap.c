/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: swap.c
Description:
Implement swap concept with the help of macro
The type of arguments to swap will be passed as t
swap (int, x, y) where x and y are of types int.

Sample I/p :
1. Int
2. char
3. short
4. float
5. double
6. string
Enter you choice : 1
Sample O/p : 
Enter the num1 : 10
Enter the num2 : 20
After Swapping :
num1 : 20
num2 : 10
*/
#include <stdio.h>
#define SWAP(t,x,y)	\
{					\
t temp=x;			\
x=y;				\
y=temp;				\
}					\



int main()
{
    int ch=0;
	
	printf("1. Int \n2. char \n3. short\n4. float\n5. double\n6. string\nEnter you choice : ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:		//int
			{
				int x,y;
				printf("Enter the num1 : ");
				scanf("%d",&x);
				printf("Enter the num2 : ");
				scanf("%d",&y);
				SWAP(int,x,y);		//what ever we write for t place will attach to the function as Datatype in preprocessing
				printf("After Swapping :\nnum1 :%d\nnum2 :%d",x,y);
				
				break;
			}
		case 2:		//char
			{
				char x,y;
				printf("Enter the char1 : ");
				getchar();
				scanf("%c",&x);
				printf("Enter the char2 : ");
				getchar();
				scanf("%c",&y);
				SWAP(char,x,y);
				printf("After Swapping :\nchar1 :%c\nchar2 :%c",x,y);
				break;
			}
		case 3:		//short
			{
				short x,y;
				printf("Enter the short1 : ");
				scanf("%hi",&x);
				printf("Enter the short2 : ");
				scanf("%hi",&y);
				SWAP(short,x,y);
				printf("After Swapping :\nshort1 :%hi\nshort2 :%hi",x,y);
				break;
			}
		case 4:		//float
			{
				float x,y;
				printf("Enter the float1 : ");
				scanf("%f",&x);
				printf("Enter the float2 : ");
				scanf("%f",&y);
				SWAP(float,x,y);
				printf("After Swapping :\nfloat1 :%f\nfloat2 :%f",x,y);
				break;
			}
		case 5:		//double
			{
				double x,y;
				printf("Enter the double1 : ");
				scanf("%lf",&x);
				printf("Enter the double2 : ");
				scanf("%lf",&y);
				SWAP(double,x,y);
				printf("After Swapping :\ndouble1 :%lf\ndouble2 :%lf",x,y);
				break;
			}
		case 6:		//string
			{
				
				char str1[20];
				char str2[20];
				char * x=str1;
				char * y=str2;
				printf("Enter the string1 : ");
				scanf("%s",x);
				printf("Enter the string2 : ");
				scanf("%s",y);
				SWAP(char *,x,y);
				printf("After Swapping :\nstring1 :%s\nstring2 :%s",x,y);
				break;
			}
		default:
			{
				printf("\ninvalid choice");
			}
			
	}
return 0;
}
	
	
