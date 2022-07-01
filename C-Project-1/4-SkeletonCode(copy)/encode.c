#include <stdio.h>
#include "encode.h"
#include "types.h"
#include <string.h>
#include "common.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
 
		//get_image_size_for_bmp(encInfo -> fptr_src_image);
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
 
		//(open_files(encInfo)
Status open_files(EncodeInfo *encInfo)				
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }

    // No failure return e_success
    return e_success;
}

Status read_and_validate_encode_args (char *argv[], EncodeInfo *encInfo)
{
	if(strcmp(strstr(argv[2],"."),".bmp")==0)
	{
	//image_fname
		encInfo -> src_image_fname =argv[2];
	}
	else
	{
	 return e_failure;
	}
	
	if(strcmp(strstr(argv[3],"."),".txt")==0)
	{
	//image_fname
		encInfo -> secret_fname =argv[3];
	}
	else
	{
	 return e_failure;
	}
	
	if (argv[4] != NULL)
		encInfo -> stego_image_fname = argv[4];
	else
		encInfo -> stego_image_fname = "stego.bmp";
	
	return e_success;
}
	//also have to write a function to validate the number of command line arguments passed
		//(check_capacity(encInfo)
Status check_capacity (EncodeInfo *encInfo)					
{
	encInfo -> image_capacity = get_image_size_for_bmp(encInfo -> fptr_src_image);
	encInfo -> size_secret_file = get_file_size(encInfo -> fptr_secret);
	if(encInfo -> image_capacity > ((2 + 4 + 4 + 4 + encInfo -> size_secret_file)*8))
		return e_success;
	else
		return e_failure;
}

uint get_file_size(FILE *fptr)
{
	fseek(fptr, 0, SEEK_END);
	return ftell(fptr);
}

		//(copy_bmp_header(encInfo -> fptr_src_image, encInfo -> fptr_stego_image)
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)		
												
{
	fseek(fptr_src_image,0,SEEK_SET);
	char str[54];
	fread(str,54,1,fptr_src_image);
	fwrite(str,54,1,fptr_dest_image);
	return e_success;
}

//printf("\n--------------Encoding--------------------\n");

		//(encode_magic_string(MAGIC_STRING, encInfo)
Status encode_magic_string(char *magic_string, EncodeInfo *encInfo)		//without const char *
{																	
	encode_data_to_image(magic_string, strlen(magic_string), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
	return e_success;
}

		//(encode_extn_size(strlen(encInfo -> extn_secret_file),encInfo)
Status encode_extn_size(int size, EncodeInfo *encInfo)		
{
	char str[32];
	fread(str, 32, 1, encInfo -> fptr_src_image);
	encode_size_to_lsb(size,str);
	fwrite(str, 32, 1, encInfo -> fptr_stego_image);
	return e_success;
}

		//(encode_secret_file_extn( encInfo -> extn_secret_file , encInfo)
Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo)		
															
{
	encode_data_to_image(file_extn, strlen(file_extn), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
	return e_success;
}

		//(encode_secret_file_size( encInfo -> size_secret_file , encInfo)
Status encode_secret_file_size(int file_size, EncodeInfo *encInfo)
															
{
	char str[32];
	fread(str, 32, 1, encInfo -> fptr_src_image);
	encode_size_to_lsb(file_size,str);
	fwrite(str, 32, 1, encInfo -> fptr_stego_image);
	return e_success;
}

		//(encode_secret_file_data(encInfo)
Status encode_secret_file_data(EncodeInfo *encInfo)				
{
	char str[encInfo -> size_secret_file];
	fseek(encInfo -> fptr_secret,0,SEEK_SET);
	fread(str, encInfo -> size_secret_file, 1, encInfo -> fptr_secret);
		encode_data_to_image(str, strlen(str), encInfo -> fptr_src_image, encInfo -> fptr_stego_image, encInfo);
	return e_success;
}


	//encode_data_to_image(magic_string, strlen(magic_string), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
	//encode_data_to_image(file_extn, strlen(file_extn), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
	//encode_data_to_image(str, strlen(str), encInfo -> fptr_src_image, encInfo -> fptr_stego_image, encInfo);
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image, EncodeInfo *encInfo)
{
	int i;
	for(i=0;i<size;i++)
	{
		fread(encInfo->image_data,8,1,fptr_src_image);
		encode_byte_to_lsb(data[i], encInfo-> image_data);
		fwrite(encInfo->image_data,8,1,fptr_stego_image);
	}
}
		//encode_byte_to_lsb(data[i], encInfo-> image_data);
Status encode_byte_to_lsb(char data, char *image_buffer)
{
	int i;
	for(i=0;i<8;i++)
	{
		image_buffer[i]=(image_buffer[i] & 0xFE)|((data >> (7 - i)) & 1);       /////
	}
}
		//encode_size_to_lsb(size,str);
		//encode_size_to_lsb(file_size,str);
Status encode_size_to_lsb(int size, char *image_buffer)//GENERIC
{
	int i;
	for(i=0;i<32;i++)
	{
		image_buffer[i]=(image_buffer[i] & 0xFE)|((size >> (31 - i)) & 1);
	}
}

		//(copy_remaining_img_data(encInfo -> fptr_src_image, encInfo -> fptr_stego_image)
Status copy_remaining_img_data(FILE *fptr_src_image, FILE *fptr_dest_image)
									
{
	char ch;
	while(fread(&ch,1,1,fptr_src_image)>0)
	{
		fwrite(&ch,1,1,fptr_dest_image);
	}
	return e_success;
}

Status do_encoding(EncodeInfo *encInfo)
{
	if (open_files(encInfo) == e_success)
	{
		printf("Open Files is a Success\n");
		if(check_capacity(encInfo)==e_success)
		{
			printf("Check capacity is Success\n");
			if(copy_bmp_header(encInfo -> fptr_src_image, encInfo -> fptr_stego_image)==e_success)
			{
				printf("Copied bmp header successfully\n");
				if(encode_magic_string(MAGIC_STRING, encInfo) == e_success)
				{
					printf("Encoded magic string successfully\n");
					strcpy(encInfo -> extn_secret_file, strstr(encInfo -> secret_fname,"."));
					//printf("%s\n",encInfo -> extn_secret_file);
					if(encode_extn_size(strlen(encInfo -> extn_secret_file),encInfo) == e_success)
					{
						printf("Encoded the extn_size\n");
						if(encode_secret_file_extn( encInfo -> extn_secret_file , encInfo) == e_success)
						{
							printf("Encoded the secret_file extn\n");
							if(encode_secret_file_size( encInfo -> size_secret_file , encInfo) == e_success)
							{
								printf("Encoded the secret_file Size\n");
								if(encode_secret_file_data(encInfo)==e_success)
								{
									printf("Encoded the secret_file Data\n");
									if(copy_remaining_img_data(encInfo -> fptr_src_image, encInfo -> fptr_stego_image)==e_success)
									{
										printf("Copied Remainaing Data\n");					
									}
									else
									{
										printf("Failure to Copy Remainaing Data \n");
										return e_failure;
									}	
								}//
								else
								{
									printf("Failure to encode secret file Data\n");
									return e_failure;
								}						
							}
							else
							{
								printf("Failure to encode secret file Size\n");
								return e_failure;
							}							
						}
						else
						{
							printf("Failure to encode secret file extn\n");
							return e_failure;
						}			
					}
					else
					{
						printf("Failure to encode extn_size\n");
						return e_failure;
					}		
				}
				else
				{
					printf("Failure to Encode Magic String\n");
					return e_failure;
				}
			}
			else
			{
				printf("failure to copy bmp header \n");
				return e_failure;/////
			}
		}
		else
		{
			printf("Check capacity is Failure\n");
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
	
	
	
	
	
	
	