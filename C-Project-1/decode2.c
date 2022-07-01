#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"
//------------------------------------------------DECODE----------------------------------------------//
/* Function Definitions */

		//(read_and_validate_decode_args(argv, &decInfo)				//in test_decode
Status read_and_validate_decode_args (char *argv[], DecodeInfo *decInfo)
{
	printf("\n read_and_validate_decode_args \n");
	if(strcmp(strstr(argv[2],"."),".bmp")==0)
	{
	//image_fname
		decInfo -> d_stego_image_fname =argv[2];
		printf("%s",decInfo -> d_stego_image_fname);//
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
{
	printf("\n open_dfiles \n");
    // stego Src Image file
    decInfo->d_fptr_stego_image = fopen(decInfo->d_stego_image_fname, "r");
	
    // Do Error handling
    if (decInfo->d_fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open Stego file %s\n", decInfo->d_stego_image_fname);
    	return e_failure;
    }

	fseek(decInfo->d_fptr_stego_image,54,SEEK_SET);
    // No failure return e_success
    return e_success;
}


//printf("\n--------------Decoding--------------------\n");

		//(decode_magic_string(MAGIC_STRING, decInfo)
		//(decode_magic_string(*decInfo)
Status decode_magic_string(char * no_magic, DecodeInfo *decInfo)		//without const char *
{							
	printf("\n decode_magic_string \n");
	decode_data_to_image(decInfo->no_magic, 2, decInfo->d_fptr_stego_image, decInfo);
	printf("checking the char %c	%d\n",no_magic[0],no_magic[0]);
	printf("checking the char %c	%d\n",no_magic[1],no_magic[1]);
	printf("checking the magicstr %s	\n",decInfo->no_magic);
	if(strcmp(decInfo->no_magic,MAGIC_STRING)==0)
	{
		return e_success;
	}
	else
	{
		return e_failure;
	}
	
}

		//(decode_extn_size(strlen(decInfo -> extn_secret_file),decInfo)
		//(decode_extn_size(decInfo -> d_extn_size,decInfo)
Status decode_extn_size(int extn_size,DecodeInfo *decInfo)		
{
	printf("\n decode_extn_size \n");
	char str[32];
	fread(str, 32, 1, decInfo -> d_fptr_stego_image);
	extn_size=decode_size_to_lsb(extn_size,str);
	//fwrite(str, 32, 1, decInfo -> fptr_stego_image);
	printf("the size of extension is %d\n",extn_size);
	printf("the size of extension is %d\n",decInfo->d_extn_size);
	return e_success;
}

		//(decode_secret_file_extn( decInfo -> extn_secret_file , decInfo)
		//(decode_secret_file_extn( decInfo -> d_extn_secret_file, decInfo)
Status decode_secret_file_extn(char *file_extn, DecodeInfo *decInfo)													
{
	printf("\n decode_secret_file_extn \n");
	decode_data_to_image(file_extn, decInfo->d_extn_size, decInfo->d_fptr_stego_image, decInfo);
	printf("checking the char %c\n",file_extn[0]);
	printf("checking the char %c\n",file_extn[1]);
	printf("checking the extn str %s\n",file_extn);
	return e_success;
}

		//(decode_secret_file_size( decInfo -> size_secret_file , decInfo)
		//(decode_secret_file_size( decInfo -> d_fptr_stego_image , decInfo)
Status decode_secret_file_size(int file_size, DecodeInfo *decInfo)															
{
	printf("\n decode_secret_file_size \n");
	char str[32];
	fread(str, 32, 1, decInfo -> d_fptr_stego_image);
	decode_size_to_lsb(file_size,str);
	printf("the size of secret_file is %d",file_size);
	//fwrite(str, 32, 1, decInfo -> fptr_stego_image);
	return e_success;
}

		//(decode_secret_file_data(decInfo)
	
Status decode_secret_file_data(DecodeInfo *decInfo)				
{
	printf("\n decode_secret_file_data \n");
	char str[decInfo -> d_size_secret_file];
	fseek(decInfo -> fptr_decode,0,SEEK_SET);
	fread(str, decInfo -> d_size_secret_file, 1, decInfo -> d_fptr_stego_image);
	
	decode_data_to_image(str, decInfo -> d_size_secret_file, decInfo -> d_fptr_stego_image, decInfo);
	fwrite(str, decInfo -> d_size_secret_file, 1, decInfo -> fptr_decode);
	return e_success;
}
	//decode_data_to_image(magic_string, strlen(magic_string), decInfo->fptr_src_image, decInfo->fptr_stego_image, decInfo);
	//decode_data_to_image(file_extn, strlen(file_extn), decInfo->fptr_src_image, decInfo->fptr_stego_image, decInfo);
	//decode_data_to_image(str, strlen(str), decInfo -> fptr_src_image, decInfo -> fptr_stego_image, decInfo);
	
	//decode_data_to_image(decInfo->no_magic, 2, decInfo->d_fptr_stego_image, decInfo);
	//decode_data_to_image(file_extn, decInfo->d_extn_size, decInfo->fptr_stego_image, decInfo);
	//decode_data_to_image(str, decInfo -> d_size_secret_file, decInfo -> fptr_stego_image, decInfo);
Status decode_data_to_image(char *data, int size, FILE *d_fptr_stego_image, DecodeInfo *decInfo)
{
	printf("\n decode_data_to_image \n");
	int i;
	for(i=0;i<size;i++)
	{
		fread(decInfo->image_data,8,1,d_fptr_stego_image);
		data[i]=decode_byte_to_lsb(data[i], decInfo-> image_data);
		printf("checking  char  %c\n",data[i]);
		//fwrite(decInfo->image_data,8,1,fptr_stego_image);
	}
	printf("checking string  %s\n",data);
}
		//decode_byte_to_lsb(data[i], decInfo-> image_data);
Status decode_byte_to_lsb(char data, char *image_buffer)
{
	printf("\n decode_byte_to_lsb \n");
	int i;
	data=0;//??needed
	for(i=0;i<8;i++)
	{
		data=(data<<1)|(image_buffer[i] & 0x01);      
	}
}
		//decode_size_to_lsb(size,str);
		//decode_size_to_lsb(file_size,str);
Status decode_size_to_lsb(int size, char *image_buffer)//GENERIC (int *size?
{
	printf("\n decode_size_to_lsb \n");
	int i;
	size=0;//??needed
	for(i=0;i<32;i++)
	{
		size=(size<<1)|(image_buffer[i] & 0x01);  
	}
	return size;
}

Status filecmp(DecodeInfo *decInfo)
{
	printf("\n filecmp \n");
	fclose(decInfo->d_fptr_stego_image);
	decInfo -> d_fptr_stego_image=fopen(decInfo->d_stego_image_fname,"r");
	fclose(decInfo->fptr_decode);
	decInfo -> fptr_decode=fopen(decInfo->decode_fname,"r");
	char string1[decInfo->d_size_secret_file];
									
	fseek(decInfo->fptr_decode, 0, SEEK_END);
									 
	char string2[ftell(decInfo->fptr_decode)];
	fread(string1, decInfo->d_size_secret_file, 1, decInfo -> d_fptr_stego_image);
	fread(string2, ftell(decInfo->fptr_decode), 1, decInfo -> fptr_decode);
	if(strcmp(string1, string2)==0)
	{
		return e_success;
	}
	else
	{
		return e_failure;
	}
}

Status do_decoding(DecodeInfo *decInfo, char * argv[])
{	
	if(open_dfiles(decInfo) == e_success)///out of do_decoding hdece *decInfo
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
					//printf("%s\n",decInfo -> extn_secret_file);
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
							//check if both files have same data
							if(filecmp(decInfo)==e_success)
							{
								printf("Decoded message from secret_file is correct\n");
							}
							else
							{
								printf("Decoded message is wRONG\n");		
							}			
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
	
	
	
	
	
	
	