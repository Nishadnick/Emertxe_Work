#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"
//------------------------------------------------DECODE----------------------------------------------//
/* Function Definitions */

//The function calls of all the functions are written about the function definitions
//Below are the Printf to observe a function properly


		//(read_and_validate_decode_args(argv, &decInfo)					//in test_decode
Status read_and_validate_decode_args (char *argv[], DecodeInfo *decInfo)
{
	printf("\n read_and_validate_decode_argsc\n");
	if(strcmp(strstr(argv[2],"."),".bmp")==0)								//chk if file format is .bmp
	{
	//image_fname
		decInfo -> d_stego_image_fname =argv[2];							//if CLA is passed then use that
	}
	else
	{
	 return e_failure;
	}
	return e_success;
}


/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
 
		//(open_files(decInfo)
Status open_dfiles(DecodeInfo *decInfo)				
{																//d_fptr_stego_image this is the main ptr that will
	printf("\n open_dfiles() \n");								// traverse throughout the decoding elements
    // stego Src Image file										//we'll be watching its chk points closely
    decInfo->d_fptr_stego_image = fopen(decInfo->d_stego_image_fname, "r");
    // Do Error handling
    if (decInfo->d_fptr_stego_image == NULL)					//if file doesn't exixt
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open Stego file %s\n", decInfo->d_stego_image_fname);
    	return e_failure;
    }
	fseek(decInfo->d_fptr_stego_image,54,SEEK_SET);				//use fseek to skip ahead of header meta data of file
    // No failure return e_success
    return e_success;
}


//printf("\n--------------Decoding--------------------\n");
//The definitions fo the functions are written in order of execution

		
		//(decode_magic_string(decInfo -> no_magic, decInfo)
Status decode_magic_string(char * no_magic, DecodeInfo *decInfo)			//without const char *
{	//used for decoding the magic String '#*'		
	
	printf("\n decode_magic_string() \n");									//store magic string chars in no_magic
	decode_data_to_image(decInfo->no_magic, 2, decInfo->d_fptr_stego_image, decInfo);
	printf("\n no_magic= %s 	\n",decInfo->no_magic);
	printf("\n MAGIC_STRING= %s 	\n",MAGIC_STRING);
	printf("\nPTR position %ld\n",ftell(decInfo-> d_fptr_stego_image));		//PTRpos=70
	if(strcmp(decInfo->no_magic,MAGIC_STRING)==0)
	{
		return e_success;
	}
	else
	{
		return e_failure;
	}
	
}

		//(decode_extn_size(decInfo -> d_extn_size,decInfo)
Status decode_extn_size(int extn_size,DecodeInfo *decInfo)		
{	//used for decoding the length of the chars of extension of the secret file 
	
	printf("\n decode_extn_size() \n");
	char str[32];
	fread(str, 32, 1, decInfo -> d_fptr_stego_image);			//use str buffer to read the chars and traverse through ptr
	decInfo -> d_extn_size=decode_size_to_lsb(extn_size,str);			//the 32 bytes are broken to get a 4byte int						
	printf("the size of d extension is %d\n",decInfo -> d_extn_size);	//store it in d_extn_size
	printf("\nPTR position %ld\n",ftell(decInfo-> d_fptr_stego_image));	//PTRpos=102
	return e_success;
}

		//(decode_secret_file_extn( decInfo -> d_extn_secret_file, decInfo)
Status decode_secret_file_extn(char *d_extn_secret_file, DecodeInfo *decInfo)													
{	//used to decode the extension of secret file, it will be used to create 'decoded' file
	
	printf("\n decode_secret_file_extn() \n");
	decode_data_to_image(decInfo -> d_extn_secret_file, decInfo -> d_extn_size, decInfo->d_fptr_stego_image, decInfo);
	printf("checking extn str %s\n",decInfo -> d_extn_secret_file);
	printf("\nPTR position %ld\n",ftell(decInfo-> d_fptr_stego_image));	//PTRpos=134
	return e_success;
}

		
		//(decode_secret_file_size( decInfo -> d_fptr_stego_image , decInfo)
Status decode_secret_file_size(int file_size, DecodeInfo *decInfo)															
{	//used to decode the size of file data, i.e. the amount of char text encoded
	
	printf("\n decode_secret_file_size() \n");
	char str[32];
	fread(str, 32, 1, decInfo -> d_fptr_stego_image);			//size of secret file data is stored in d_size_secret_file
	decInfo->d_size_secret_file=decode_size_to_lsb(file_size,str);
	printf("the size of secret_file is %d\n",decInfo->d_size_secret_file);
	printf("\nPTR position %ld\n",ftell(decInfo-> d_fptr_stego_image));		//PTRpos=166
	return e_success;
}

		//(decode_secret_file_data(decInfo)
Status decode_secret_file_data(DecodeInfo *decInfo)				
{	//used to decode the secret message in chars
	
	printf("\n decode_secret_file_data() \n");								//buffer to store the processing data
	char str[(decInfo -> d_size_secret_file)+1];							//size+1 to accomodate the '\0'
	fseek(decInfo -> fptr_decode,0,SEEK_SET);								//fptr_decode position is set @beginning
	decode_data_to_image(str, decInfo -> d_size_secret_file, decInfo -> d_fptr_stego_image, decInfo);
	printf("Secret string = %s\n",str);
	fwrite(str, decInfo -> d_size_secret_file, 1, decInfo -> fptr_decode);	//write to the decoded.txt with fptr_decode
	printf("\nPTR position %ld\n",ftell(decInfo-> d_fptr_stego_image));		//PTRpos=366
	return e_success;
}

	//decode_data_to_image(decInfo->no_magic, 2, decInfo->d_fptr_stego_image, decInfo);
	//decode_data_to_image(file_extn, decInfo->d_extn_size, decInfo->fptr_stego_image, decInfo);
	//decode_data_to_image(str, decInfo -> d_size_secret_file, decInfo -> fptr_stego_image, decInfo);
Status decode_data_to_image(char *data, int size, FILE *d_fptr_stego_image, DecodeInfo *decInfo)
{
	printf("\n decode_data_to_image() \n");
	int i=0;
	for(i=0;i<size;i++)
	{
		fread(decInfo->image_data,8,1,d_fptr_stego_image);				//8 bytes are read and sent for LSB extaction
		data[i]=decode_byte_to_lsb(data[i], decInfo-> image_data);		//each char preared is stored at an index
	}
	data[size]=0;														//end it with '\0'
}
		//decode_byte_to_lsb(data[i], decInfo-> image_data);
Status decode_byte_to_lsb(char data, char *image_buffer)
{		//used to convert into chars
	
	int i;
	data=0;//??needed
	for(i=0;i<8;i++)
	{
		fflush(stdout);										//lSB of the byte is taken and left shifted to accomodate
		data=(data<<1)|(image_buffer[i] & 0x01);      			// the new LSB, this is done 8 times to create a char
	}
	//printf(" data  %c \n",data);							//chk for each char data
	return data;													//1 char returned
}
		
		//decode_size_to_lsb(file_size,str);
Status decode_size_to_lsb(int size, char *image_buffer)
{	//used to convert into chars
	
	printf("\n decode_size_to_lsb() \n");
	int i;
	size=0;
	for(i=0;i<32;i++)
	{
		size=(size<<1)|(image_buffer[i] & 0x01);  			 //lSB of the byte is taken and left shifted to accomodate
	}														 // the new LSB, this is done 32 times to create 1 int
	//printf(" size  %d \n",size);
	return size;											 //integer number is returned
}

Status do_decoding(DecodeInfo *decInfo, char * argv[])
{	
	if(open_dfiles(decInfo) == e_success)
	{
		printf("Open Files is a Success\n");
		if(decode_magic_string(decInfo -> no_magic, decInfo) == e_success)
		{
			printf("Decoded magic string position and it is found\n");
			if(decode_extn_size(decInfo -> d_extn_size,decInfo) == e_success)
			{
				printf("Decoded the extn_size\n");
				if(decode_secret_file_extn( decInfo -> d_extn_secret_file, decInfo) == e_success)
				{
					printf("Decoded the secret_file extn\n");
					
					//create decoded.txt
					if (argv[3] != NULL)
					{
						decInfo -> decode_fname = argv[3];
					}
					else
					{
						char name[8]="decoded";
						//decInfo -> decode_fname = name+(decInfo -> d_extn_secret_file);
						strcpy(decInfo -> decode_fname,"decoded");
						strcat(decInfo -> decode_fname,decInfo -> d_extn_secret_file);
					}
					decInfo->fptr_decode = fopen(decInfo->decode_fname, "w");
					if(decode_secret_file_size( decInfo -> d_size_secret_file , decInfo) == e_success)
					{
						printf("Decoded the secret_file Size\n");
						if(decode_secret_file_data(decInfo)==e_success)
						{
							printf("Decoded the secret_file Data into decoded.txt\n");
									
						}
						else
						{
							printf("Failure to decode secret file Data\n");
							return e_failure;
						}						
					}
					else
					{
						printf("Failure to decode secret file Size\n");
						return e_failure;
					}							
				}
				else
				{
					printf("Failure to decode secret file extn\n");
					return e_failure;
				}			
			}
			else
			{
					printf("Failure to decode extn_size\n");
					return e_failure;
			}		
		}
		else
		{
			printf("Magic String not found\n");
			return e_failure;
		}		
	}
	else
	{
		printf("Open Files is a Failure\n");
		return e_failure;
	}
	return e_success;
}
	
	
	
	
	
	
	