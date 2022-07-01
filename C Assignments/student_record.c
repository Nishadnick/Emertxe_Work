/*
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: student_record.c
Description:
Implement an student record which will contain 
roll no., Name of student, subject marks, average and grade.
Read number of students and declare array of structure with 
no.of students, then read number of subjects and n subject names.
Read the particulars for each student.
Roll.no
Name.
Score of each subject
Calculate the average. Based on that decide the grade.

Test Case 1:
user@emertxe] ./student_record
Enter no.of students : 2
Enter no.of subjects : 2
Enter the name of subject 1 : Maths
Enter the name of subject 2 : Science
----------Enter the student datails-------------
Enter the student Roll no. : 1
Enter the student 1 name : Nandhu
Enter Maths mark : 99
Enter Science mark : 91
----------Enter the student datails-------------
Enter the student Roll no. : 2
Enter the student 2 name : Bindhu
Enter Maths mark : 88
Enter Science mark : 78
----Display Menu----
1. All student details
2. Particular student details
Enter your choice : 2

----Menu for Particular student----
1. Name.
2. Roll no.
Enter you choice : 1
Enter the name of the student : Nandhu
Roll No.   Name           Maths         Science       Average       Grade
1              Nandhu        99               91                95                  A
Do you want to continue to display(Y/y) : n
*/

#include <stdio.h>
#include <stdlib.h>

struct Student
{
	char name[20];
	char grade;
	
	int marks[10];
	
	int roll_no;
	int avg;
		
};

int average(int ,int ,char *);
int main()
{

	int i,j,num_stu,num_sub;
	
	printf("Enter no.of students : ");
	scanf("%d",&num_stu);
	printf("\nEnter no.of subjects: ");
	scanf("%d",&num_sub);
	struct Student ss[num_stu];
	char **subs=(char **)malloc(sizeof(char *)*num_sub*20);		//double ptr cs it acts as double array 
	//char *subs[num_sub];										//storing multiple subject names i.e string    
	
	for(i=0;i<num_sub;i++)				//input subjects
	{ 
		*(subs+i)=(char *)malloc(sizeof(char)*20);				//memory allocation to each subject name
		printf("\nEnter the name of subject %d :",i+1);
			fflush(stdin);
			scanf("%s",*(subs+i));								//set of 20 bytes
		
	}
//	for(i=0;i<num_sub;i++)				//printing and chcking
//	{
//		printf("\nthe subject %s : ",subs[i]);
//	}
	
	printf("\n----------Enter the student details-------------\n");
	
	for(i=0;i<num_stu;i++)
	{
		
		printf("\nEnter the student Roll no. :");
		fflush(stdin);
		scanf("%d",&ss[i].roll_no);			//loop the strictures
		
		printf("\nEnter the student %d name :",ss[i].roll_no);
		fflush(stdin);
		scanf("%s",ss[i].name);
		for(j=0;j<num_sub;j++)
		{
			printf("\nEnter %s mark : ",subs[j]);
			scanf("%d",&ss[i].marks[j]);			//student 1 marks of sub1 and sub2
		}											//when i increments again put sub1 and sub2
	}
	
	
	printf("\n----Display Menu----\n");
	char mod='y';
	int opt,ch,sum=0,avg=0;
	
	do
	{
		printf("1. All Student Details\n2. Particular Student Details\nEnter your option: ");
	    scanf("%d", &opt);
		switch(opt)
		{
			case 1:			//all students data
				{
					printf("Printing all student data\n");
					avg=0,sum=0;
					for(i=0;i<num_stu;i++)
					{
						sum=0;
						ss[i].avg=0;
					/*	printf("Roll No.   %d  \n",ss[i].roll_no);
						printf("name	%s\n",ss[i].name);	
						for(j=0;j<num_sub;j++)
						{
							printf("%s	%d\n",subs[j],ss[i].marks[j]);
							sum=sum+ss[i].marks[j];
						}
						ss[i].avg=average(sum,num_sub,&ss[i].grade);	
						printf("name	%s\n	average=%d\n",ss[i].name,ss[i].avg);
						printf("Greade==%c\n",ss[i].grade);
					*/	
				//		Roll No.   Name           Maths         Science       Average       Grade
					printf("\n=================================================\n");	
						for(j=0;j<num_sub;j++)
						{
							sum=sum+ss[i].marks[j];			//2 loop 1 for 1st sub and 2 for next sub
						}
						//ss[i].avg=0;
						ss[i].avg=sum/num_sub;
					//	ss[i].avg=average(sum,num_sub,&ss[i].grade);
						printf("Roll no		Name	");						//1st line
						for(j=0;j<num_sub;j++)
						{
							printf("%s	",subs[j]);							//1st line	
						}
						printf("Average		Grade");						//1st line
						printf("\n");
						printf("%d		%s	",ss[i].roll_no,ss[i].name);	//2nd line
						for(j=0;j<num_sub;j++)								
						{
							printf("%d	",ss[i].marks[j]);					//2nd line	
						}
						printf("%d		%c\n",ss[i].avg,ss[i].grade);		//2nd line
						
					}
					
					break;
				}								//case 1 end
			case 2:			//particular data
				{
					printf("\n----Menu for Particular student----\n");
					printf("1. Name\n2. Roll no\nEnter your choice: ");
					scanf("%d", &ch);
					avg=0,sum=0;
					switch(ch)
					{
						case 1:				//search by name
							{
								char name[20];
								int name_len=0,flag=0,index,i=0,stu_len[num_stu];
								avg=0,sum=0;
								printf("Enter the name of the student :");
								fflush(stdin);
								scanf("%s",name);
							//	printf("%s\n",name);
								
								while(name[i]!=0)
								{
				//					printf(" name chars %c",name[i]);
									name_len++;
									i++;
								}
				//				printf("\nname_len=%d\n",name_len);
								i=0;
								
								for(i=0;i<num_stu;i++)
								{
								j=0;
									while(ss[i].name[j]!=0)
									{
									//	printf("ss[i].name chars %c",ss[i].name[j]);
										j++;
									}
								stu_len[i]=j;
				//				printf("\nstu_len[%d]=%d\n",i,stu_len[i]);
								}
							//	printf("\nstu_len=%d\n",stu_len);
								
								for(i=0;i<num_stu;i++)
								{
									ss[i].avg=0;
									if(name_len==stu_len[i])		//chk if name lenght is same
									{		
				//						printf("length same\n");
										for(j=0;j<name_len;j++)
										{
											if(name[j]==ss[i].name[j])		//chek if char by char is same
											{
				//								printf("name[%d]%c==ss[%d].name[%d]%c",j,name[j],i,j,ss[i].name[j]);
												flag=1;				//is succesfull till the end then this is it
											}								
										}
										if(flag==1)		//this shows that string was same
										{
				//							printf("name=%s  and ss[%d].name[%d]=%s",name,i,j,ss[i].name);
											index=i;	//we did everything to find this
											break;
										}
									}
										
								}
								//printf("\nindex >>>>>>>>>>>>=%d\n",index);
								if(flag==0)
								{
									printf("\nEnter correct name\n ");
									break;
								}
								/*
								printf("Roll No.   %d  \n",ss[index].roll_no);
								printf("name	%s\n",ss[index].name);
								for(j=0;j<num_sub;j++)
								{
									printf("%s	%d\n",subs[index],ss[i].marks[j]);
									sum=sum+ss[index].marks[j];
								}
								ss[index].avg=average(sum,num_sub,&ss[index].grade);
								printf("name	%s\n	average=%d\n",ss[index].name,ss[index].avg);
								printf("Grade==%c\n",ss[index].grade);
								*/
							printf("\n=================================================\n");	
								for(j=0;j<num_sub;j++)
								{
									sum=sum+ss[index].marks[j];
								}
								//ss[index].avg=0;
								ss[index].avg=sum/num_sub;
							//	ss[index].avg=average(sum,num_sub,&ss[index].grade);
								printf("Roll no		Name	");						//1st line
								for(j=0;j<num_sub;j++)
								{
									printf("%s	",subs[j]);							//1st line	
								}
								printf("Average		Grade");						//1st line
								printf("\n");
								printf("%d		%s	",ss[index].roll_no,ss[index].name);	//2nd line
								for(j=0;j<num_sub;j++)
								{
									printf("%d	",ss[index].marks[j]);					//2nd line	
								}
								printf("%d		%c\n",ss[index].avg,ss[index].grade);				//2nd line
								
								break;
							}
						case 2:					//search by Roll no
							{
								int rol_no=0,flag=0,index;
								avg=0,sum=0;
								printf("Enter Roll no. of the student :");
								scanf("%d",&rol_no);
								for(i=0;i<num_stu;i++)
								{
									if(rol_no==ss[i].roll_no)
									{
										flag=1;
										break;
									}
								}
								index=i;
								ss[index].avg=0;
								/*
									printf("Roll No.   %d  \n",ss[index].roll_no);
									printf("name	%s\n",ss[index].name);
									for(j=0;j<num_sub;j++)
									{
										printf("%s	%d\n",subs[index],ss[i].marks[j]);
										sum=sum+ss[index].marks[j];
									}
									ss[index].avg=average(sum,num_sub,&ss[index].grade);
									printf("name	%s\n	average=%d\n",ss[index].name,ss[index].avg);
									printf("Greade==%c\n",ss[index].grade);
								*/
								printf("\n=================================================\n");	
									for(j=0;j<num_sub;j++)
									{
										sum=sum+ss[index].marks[j];
									}
									ss[index].avg=sum/num_sub;
									//ss[i].avg=average(sum,num_sub,&ss[index].grade);
									printf("Roll no		Name	");						//1st line
									for(j=0;j<num_sub;j++)
									{
										printf("%s	",subs[j]);							//1st line	
									}
									printf("Average		Grade");						//1st line
									printf("\n");
									printf("%d		%s	",ss[index].roll_no,ss[index].name);	//2nd line
									for(j=0;j<num_sub;j++)
									{
										printf("%d	",ss[index].marks[j]);					//2nd line	
									}
									printf("%d		%c\n",ss[index].avg,ss[index].grade);				//2nd line
								
									break;
							}		//case 2 switch 2 ends
						}		//switch 2 ends
					}		//case 2 switch 1 ends
				}			//switch 1 ends
		
			
		printf("Do you want to continue to display(Y/y) : ");
		getchar();
		scanf("%c",&mod);
	}while(mod=='y'||mod=='Y');
	
}


int average(int sum,int num_sub,char *grade)
{
	int avg=0;
	avg=(sum/num_sub);
	//printf("\nsum %d		num_sub %d\n",sum,num_sub);
	//printf("\n avg %d	\n",avg);
	if(avg>=80)
	{
		*grade='A';
	}
	else if(avg<80 && avg>=60)
	{
		*grade='B';
	}
	else if(avg<60 && avg>=40)
	{
		*grade='C';
	}
	else if(avg<40)
	{
		*grade='D';
	}
	return avg;
	
}



