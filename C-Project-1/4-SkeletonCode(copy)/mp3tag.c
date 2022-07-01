#include <stdio.h>
#include <string.h>
#include "taghead.h"





int main(int argc, char **argv)
{
	Tagdata tager;					//structure data creatde with typedef
	long pos;	
	//printf("args %d\n",argc);	
	//else if(argv[1]==NULL)
	if(argc<2)				//if incorrect no f args passed then error
	{
	
		printf("\n----------------------------------------------------------------\n");
		printf("\nERROR: ./a.out: INVALID ARGUMENTS\n");
		printf("\nUSAGE: \n");
		printf("TO VIEW please pass: ./a.out -v filename.mp3\n");
		printf("TO EDIT please pass: ./a.out -e -t/-a/-A/-m/-y/-c new_string filename.mp3\n");
		printf("TO GET HELP please pass: ./a.out: --help\n");
		printf("\n----------------------------------------------------------------\n");
	}
	else if(strcmp(argv[1],"--help")==0)			//Help menu
	{
		printf("\n--------------------------------HELP MENU--------------------------------\n");
		printf("1. -v -> To view mp3 file contents\n");
		printf("2. -e -> To edit mp3 file contents\n");
		printf("\t 2.1. -t -> edit song title\n");
		printf("\t 2.2. -a -> edit artist name\n");
		printf("\t 2.3. -A -> edit album name\n");
		printf("\t 2.4. -y -> edit year\n");
		printf("\t 2.5. -m -> edit content\n");
		printf("\t 2.6. -c -> edit comment\n");
		printf("\n----------------------------------------------------------------\n");
	}
	
	else if(strcmp(argv[1],"-v")==0)				//View menu
	{
		if(strcmp(strstr(argv[2],"."),".mp3")==0)		//chcking if file is .mp3
		{
			tager.filename=argv[2];						//storing in 'filename'
			if(validation(argv, &tager)==success)
			{
				printf("Validation completed\n");		//Header id is ID3 and version is '3', mp3 file is open in 'r'
		
				printf("Fptr pos=%ld\n",ftell(tager.fptr_tag));
				fseek(tager.fptr_tag, 5, SEEK_CUR);		//seek to 10th postion
			
				printf("before value storage pos=%ld\n",ftell(tager.fptr_tag));
				printf("\n--------------------SELECTED VIEW DETAILS--------------------------------\n");
				printf("\n------------MP3 TAG READER AND EDITOR FOR ID3v2-------------------\n\n");
				if(storage(&tager)==success)			//this stores all the data in variables
				{
					display(&tager);
					
				}
				else									//failure while assigning values
				{
					return failure;
				}
			}
			else										//file opening error
			{
				return failure;
			}
		}
		else											//file is not mp3
		{
			return failure;
		}
		
		//function to display the mp3 file data
		printf("\n----------------------------------------------------------------\n");
	}
	else if(strcmp(argv[1],"-e")==0)		//get into edit mode
	{
		printf("\n--------------------SELECTED EDIT DETAILS--------------------------------\n");
		printf("\n------------MP3 TAG READER AND EDITOR FOR ID3v2-------------------\n");
		fseek(tager.fptr_tag,0,SEEK_SET);
		fseek(tager.fptr_tag,10,SEEK_CUR);
		printf("\n----------------------------------------------------------------\n");//will be end of every operation
		if(strcmp(argv[2],"-t")==0)
		{
			
			//function to edit the title
			if(strcmp(chkframe(&tager),"TALB")==0)
			{
				
				//change the variable
			}
			else
			{
			
			}
	
			printf("\n----------------------------------------------------------------\n");
		}
		if(strcmp(argv[2],"-a")==0)
		{
			//function to edit the artist
			printf("\n----------------------------------------------------------------\n");
		}
		if(strcmp(argv[2],"-A")==0)
		{
			//function to edit the Album
			printf("\n----------------------------------------------------------------\n");
		}
		if(strcmp(argv[2],"-y")==0)
		{
			//function to edit the year
			printf("\n----------------------------------------------------------------\n");
		}
		if(strcmp(argv[2],"-m")==0)
		{
			//function to edit the content/music
			printf("\n----------------------------------------------------------------\n");
		}
		if(strcmp(argv[2],"-c")==0)
		{
			//function to edit the comment
			printf("\n----------------------------------------------------------------\n");
		}
	}
	
}