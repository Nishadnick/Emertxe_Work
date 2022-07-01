/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title:10_which_day.c
Description:
			Suppose, in a week let us assume first day is 'Sunday', then second day will be 'Monday' and so on. 
			If first day is 'Monday' then the second day will be 'Tuesday' and so on.
Sample I/p : Positive integer say 'N'. Where 1 <= 'N' <= 365.
      1 <= Starting day <= 7
      Option to set the first day.
Sample O/p : 
Where start_day = Wednesday
       Nth day = 5
       5th day of the year is Monday
*/

#include<stdio.h>
int main()
{
	int num,day,newday;					//initialise variables
	printf("Enter the value of 'n' : ");
	scanf("%d", &num);
	if(num>0&&num<=365)
	{
		printf("Choose First Day :\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");
		printf("Enter the option to set the first day : ");
		scanf("%d", &day);
		if(day>0&&day<=7)
		{
			if(num>7)
			{
			num=num%7;
			}
			newday=num+day-1;	
			if(newday>7)
			{
				newday=newday%7;
			}
			switch(newday)
			{
			case 1:
				printf("The day is Sunday\n");
			break;
			case 2:
				printf("The day is Monday\n");
			break;
			case 3:
				printf("The day is Tuesday\n");
			break;
			case 4:
				printf("The day is Wednesday\n");
			break;
			case 5:
				printf("The day is Thursday\n");
			break;
			case 6:
				printf("The day is Friday\n");
			break;
			case 7:
				printf("The day is Saturday\n");
			break;
			default:
				printf("Error");

			}
		}
		else
		{
			printf("Error: Invalid input, first day should be > 0 and <= 7\n");
		}
	}	
	else
	{
		printf("Error: Invalid Input, n value should be > 0 and <= 365\n");
	}
return 0;
}