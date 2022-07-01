/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title:  sizeof.c
Description:
Treat &x and &x + 1 as characters address.
Both addresses difference will be sizeof x

Sample I/p :
Size of int : 4 bytes
Size of char : 1 byte
Size of float : 4 bytes
Size of double : 8 bytes
Size of unsigned int : 4 bytes
Size of long int : 8 bytes

*/
#include <stdio.h>
#include <stdlib.h>
#define SIZEOFTHE(x)		\
((char *)(&x+1)-(char *)(&x))		\
//de-refrencing whatever is at the address

int main()
{
	int i=5;
	char c='5';
	unsigned char uc='5';
	float f=5;
	double d=5;
	unsigned int ui=5;
	long int li=5;
	long double ld=5;
	long long int lli=5;
	short int si=5;
	
	//as per the warning the format specifier needs to be long int
	printf("Size of int : %lu bytes\n",SIZEOFTHE(i));
	printf("Size of char : %lu bytes\n",SIZEOFTHE(c));
	printf("Size of unsigned char : %lu bytes\n",SIZEOFTHE(uc));
	printf("Size of float : %lu bytes\n",SIZEOFTHE(f));
	printf("Size of double : %lu bytes\n",SIZEOFTHE(d));
	printf("Size of unsigned int : %lu bytes\n",SIZEOFTHE(ui));
	printf("Size of long int : %lu bytes\n",SIZEOFTHE(li));
	printf("Size of long double : %lu bytes\n",SIZEOFTHE(ld));
	printf("Size of long long int : %lu bytes\n",SIZEOFTHE(lli));
	printf("Size of short int : %lu bytes\n",SIZEOFTHE(si));
	return 0;
}
	
