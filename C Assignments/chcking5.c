
#include<stdio.h>


int main()
{
	
	int num=5;
	char choice;
	do{
		num++;
		printf("%d\n",num);
		
		printf("do you continue?");
		//ch=getchar();
		scanf(" %c",&choice);
		//fflush(stdout);
	}while(choice == 'y'||choice == 'Y');
	printf("%d\n",num);
    return 0;
}