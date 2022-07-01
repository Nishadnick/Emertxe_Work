#ifndef TAGINFO
#define TAGINFO

typedef struct Tag_data
{
	char title[30];			//TIT2
	char artist[30];		//TPE1
	char album[30];			//TALB
	char comment[30];		//COMM
	
	char year[5];			//TYER	//using 1 pointer buffer will lead to concatenation of next content hence 1more byte
	char music[30];			//TCON
	
	//char editinfo[60];
	char *editinfo;
	FILE *fptr_tag;
	FILE *new_fptr;
	char *filename;
	int size_read;
}Tagdata;

typedef enum
{
	success,			//here values would be 0 and 1 resp
	failure			//but these values would be useful to compare with if condition eg if(success==success)
} Status;				//and successful termiation will also be 'return success' i.e. as return 0


Status validation(char *argv[], Tagdata *tager);

Status storage(Tagdata *tager);

int getsize(int size, FILE *ptr,Tagdata *tager);
	
Status display(Tagdata *tager);
	
Status chkframe(Tagdata *tager, char *str, char *argv[]);


#endif