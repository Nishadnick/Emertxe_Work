#include <stdio.h>
#include <string.h>
#include "taghead.h"




Status validation(char *argv[], Tagdata *tager)
{
	
	tager->fptr_tag=fopen(tager->filename,"r");				//open file in 'r'
	
	if(tager->fptr_tag==NULL)
	{
		perror("fopen");
		fprintf(stderr,"ERROR: Unable to open file %s\n",tager->filename);
		return failure;
	}
	fseek(tager->fptr_tag,0,SEEK_SET);
	//fflush(tager->editinfo);
	//printf("pos now %ld\n",ftell(tager->fptr_tag));			//chking position of file ptr
	fread(tager->editinfo,3,1,tager->fptr_tag);
	//tager->editinfo[3]='\0';
	//printf("header ID string %s\n",tager->editinfo);
	if(strcmp(tager->editinfo,"ID3")==0)					//read if header ID is ID3
	{
		fread(tager->editinfo,2,1,tager->fptr_tag);
		fflush(stdout);
		//if(strcmp(tager->editinfo[0],"3")!=0)			//1st byte is 03==3 and second byte is 00==0 hence 3 0
		if((tager->editinfo[0])==3 && (tager->editinfo[1])==0)	//because in hexa value the 1st number '0' starts from 30
		{	
			//printf("version value  %d\n",tager->editinfo[0]);		//cheking if version is '0300' i.e. 3		
		}
		else
		{
			printf("ERROR: The Version is not 0300\n");
			return failure;
		}
	}
	else
	{
		printf("ERROR: The Header ID is not ID3\n");
		return failure;	
	}
	return success;
}
Status storage(Tagdata *tager)
{
	//TITLE
	fflush(stdout);
	//printf("before frame id 1 pos=%ld\n",ftell(tager->fptr_tag));
	fread(tager->editinfo,4,1,tager->fptr_tag);		//reading the frame ID
	//printf("frame id %s \n",tager->editinfo);
	tager->size_read=0;								//RE-INTITIALIZE EVERY TIME
	tager->editinfo[4]='\0';
	if(strcmp(tager->editinfo,"TIT2")==0)	
	{
		//printf("before size  pos=%ld\n",ftell(tager->fptr_tag));
		tager->size_read=getsize(tager->size_read,tager->fptr_tag,tager)-1; //cz the 1st char is blank
		//printf("the size is %d\n",tager->size_read);
		fseek(tager->fptr_tag,3, SEEK_CUR);				//get the data after skipping the 2 bytes of flag and i blank char
		fread(tager->editinfo,(tager->size_read),1,tager->fptr_tag);
		strcpy(tager->title,tager->editinfo);
		//strcpy(tager->editinfo,"    ");	
		//printf("title is %s\n",tager->title);				//provide variable here
	}
	//ARTIST
	
	//printf("before frame id 2 pos=%ld\n",ftell(tager->fptr_tag));
	fflush(stdin);
	//strcpy(tager->editinfo,"     ");
	fread(tager->editinfo,4,1,tager->fptr_tag);		//reading the frame ID
	tager->editinfo[4]='\0';						//manually limiting the size of frame ID so that it can be checking in if condition
	//printf("frame id 2 %s \n",tager->editinfo);
	//fflush(tager->editinfo);
	tager->size_read=0;								//RE-INTITIALIZE EVERY TIME
	if(strcmp(tager->editinfo,"TPE1")==0)	
	{
		//printf("before size  pos=%ld\n",ftell(tager->fptr_tag));
		tager->size_read=getsize(tager->size_read,tager->fptr_tag,tager)-1;
		//printf("size of TPE1 %d\n",tager->size_read);
		fseek(tager->fptr_tag,3, SEEK_CUR);				//get the data after skipping the 2 bytes of flag
		fread(tager->editinfo,tager->size_read,1,tager->fptr_tag);
		strcpy(tager->artist,tager->editinfo);		//provide variable here
		//printf("artist is %s\n",tager->artist);
	}
	//ALBUM
	fread(tager->editinfo,4,1,tager->fptr_tag);		//reading the frame ID
	tager->editinfo[4]='\0';			//manually limiting the size of frame ID so that it can be checking in if condition
	//printf("frame id 3 %s \n",tager->editinfo);
	//fflush(tager->editinfo);
	tager->size_read=0;								//RE-INTITIALIZE EVERY TIME
	if(strcmp(tager->editinfo,"TALB")==0)	
	{	
		tager->size_read=getsize(tager->size_read,tager->fptr_tag,tager)-1;	
		fseek(tager->fptr_tag,3, SEEK_CUR);				//get the data after skipping the 2 bytes of flag
		fread(tager->editinfo,tager->size_read,1,tager->fptr_tag);
		strcpy(tager->album,tager->editinfo);			//provide variable here
		//printf("string in album is  %s\n",tager->editinfo);
		//printf("album is %s\n",tager->album);
	}
	//YEAR
	fread(tager->editinfo,4,1,tager->fptr_tag);		//reading the frame ID
	tager->editinfo[4]='\0';		//manually limiting the size of frame ID so that it can be checking in if condition
	//fflush(tager->editinfo);
	tager->size_read=0;
	if(strcmp(tager->editinfo,"TYER")==0)	
	{
		tager->size_read=getsize(tager->size_read,tager->fptr_tag,tager)-1;
		fseek(tager->fptr_tag,3, SEEK_CUR);				//get the data after skipping the 2 bytes of flag
		fread(tager->editinfo,tager->size_read,1,tager->fptr_tag);
	//	printf("year is %s\n",tager->editinfo);
		strcpy(tager->year,tager->editinfo);			//provide variable here
		//printf("year is %s\n",tager->year);
	}
	//MUSIC
	fread(tager->editinfo,4,1,tager->fptr_tag);		//reading the frame ID
	tager->editinfo[4]='\0';			//manually limiting the size of frame ID so that it can be checking in if condition
	//fflush(tager->editinfo);
	tager->size_read=0;								//RE-INTITIALIZE EVERY TIME
	if(strcmp(tager->editinfo,"TCON")==0)	
	{
		tager->size_read=getsize(tager->size_read,tager->fptr_tag,tager)-1;
		fseek(tager->fptr_tag,3, SEEK_CUR);				//get the data after skipping the 2 bytes of flag
		fread(tager->editinfo,tager->size_read,1,tager->fptr_tag);
		strcpy(tager->music,tager->editinfo);			//provide variable here
		//printf("music is %s\n",tager->music);
	}
	//COMMENT
	fread(tager->editinfo,4,1,tager->fptr_tag);		//reading the frame ID
	tager->editinfo[4]='\0';			//manually limiting the size of frame ID so that it can be checking in if condition
	//fflush(tager->editinfo);
	tager->size_read=0;								//RE-INTITIALIZE EVERY TIME
	if(strcmp(tager->editinfo,"COMM")==0)	
	{
		tager->size_read=getsize(tager->size_read, tager->fptr_tag,tager)-1;
		fseek(tager->fptr_tag,3, SEEK_CUR);				//get the data after skipping the 2 bytes of flag
		fread(tager->editinfo,tager->size_read,1,tager->fptr_tag);
		strcpy(tager->comment,tager->editinfo);			//provide variable here
		//printf("comment is %s\n",tager->comment);
	}
	return success;
}

int getsize(int size, FILE *ptr,Tagdata *tager)
{
	int i;
	size=0;
	fread(tager->editinfo,sizeof(int),1,ptr);
	for(i=0;i<4;i++)
	{
		fflush(stdout);	
		size=(size<<8)|(tager->editinfo[i]);		
		//size<<8;										//1byte=8bits hence >>8
	}
	return size;
}
	
	
Status chkframe(Tagdata *tager, char *str, char *argv[])
{
	tager->size_read=0;								//RE-INTITIALIZE EVERY TIME
	fread(tager->editinfo,4,1,tager->new_fptr);					//frame ID
	tager->editinfo[4]='\0';						//for comparing frame ID manually atatching '\0' is imp
	//printf("chkframe %s and pos %ld\n",tager->editinfo,ftell(tager->new_fptr));
	
	if(strcmp(tager->editinfo,str)==0)
	{
		//change data
		//printf("chkframe %s and pos %ld\n",tager->editinfo,ftell(tager->new_fptr));
		tager->size_read=getsize(tager->size_read, tager->new_fptr,tager)-1;		//get size seek 4 bytes
		//printf("size is %d\n",tager->size_read);	
		fseek(tager->new_fptr,3,SEEK_CUR);					// seek 3 bytes for flag and a black char						
		fwrite(argv[3],tager->size_read,1,tager->new_fptr);
		//printf("chkframe %s and pos %ld\n",tager->editinfo,ftell(tager->new_fptr));
		
		return success;
	}
	else
	{
		//printf("ELSE %s and pos %ld\n",tager->editinfo,ftell(tager->new_fptr));	
		tager->size_read=getsize(tager->size_read, tager->new_fptr,tager)-1;		//get size
		//printf("size is %d\n",tager->size_read);
		fseek(tager->new_fptr,3,SEEK_CUR);
		fseek(tager->new_fptr,tager->size_read,SEEK_CUR);
		//printf("ELSE %s and pos %ld\n",tager->editinfo,ftell(tager->new_fptr));
		chkframe(tager, str, argv);
		//return -1;
	}
}
	
Status display(Tagdata *tager)
{
		printf(" TITLE  	:	%s\n",tager->title);
		printf(" ARTIST 	:	%s\n",tager->artist);
		printf(" ALBUM  	:	%s\n",tager->album);
		printf(" YEAR   	:	%s\n",tager->year);
		printf(" MUSIC  	:	%s\n",tager->music);
		printf(" COMMENT	:	%s\n",tager->comment);
}
