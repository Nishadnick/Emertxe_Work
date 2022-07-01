#ifndef DECODE_H
#define DECODE_H
#include <string.h>

#include "types.h" // Contains user defined types
//------------------------------------------------DECODE----------------------------------------------//
/* 
 * Structure to store information required for
 * decoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

typedef struct _DecodeInfo
{
	 /* Stego Image Info this is source now */
    char *d_stego_image_fname;						//stego image file name
    FILE *d_fptr_stego_image;							//pointer for stego image
	
	char no_magic[2+1];				//store decoded signature to compare magic string
	char image_data[MAX_IMAGE_BUF_SIZE];			//temp storage of size [8] to store chars
   
    /* Secret File Info */
    //char *d_secret_fname;								//source secret_file name
   // FILE *d_fptr_secret;								//pointer for secret_file
   int d_extn_size;
    char d_extn_secret_file[MAX_FILE_SUFFIX+1];			//extension of the secret file
	int d_size_secret_file;							//total size of the secret_file having string
	
	
	char *decode_fname;								//filename for decoding file
	FILE *fptr_decode;							//pointer for decoded file
	
	
	/* Source Image info 
    char *src_image_fname;							//source File Name			//no use
    FILE *fptr_src_image;							//pointer for stego image	//no use
    uint image_capacity;							//Image Size				//no use
    uint bits_per_pixel;		//un used?										//no use
    char secret_data[MAX_SECRET_BUF_SIZE];			//un used?
   // long size_secret_file;///make it int
	*/

} DecodeInfo;


/* Decoding function prototype */

/* Check operation type */
OperationType check_operation_type(char *argv[]);

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo, char *argv[]);

/* Get File pointers for i/p and o/p files */
Status open_dfiles(DecodeInfo *decInfo);



/* Store Magic String */
//Status decode_magic_string(const char *magic_string, DecodeInfo *decInfo);	//without const
Status decode_magic_string(char *no_magic, DecodeInfo *decInfo);

/* Decode Extn size */
Status decode_extn_size(int size, DecodeInfo *decInfo);


/* Decode secret file extenstion */
//Status decode_secret_file_extn(const char *file_extn, DecodeInfo *decInfo);
Status decode_secret_file_extn( char *d_extn_secret_file, DecodeInfo *decInfo);

/* Decode secret file size */
Status decode_secret_file_size(int file_size, DecodeInfo *decInfo);

/* Decode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo);

/* Decode function, which does the real decoding */
Status decode_data_to_image(char *data, int size, FILE *d_fptr_stego_image, DecodeInfo *decInfo);

/* Decode a byte into LSB of image data array */
Status decode_byte_to_lsb(char data, char *image_buffer);

/* Decode int to LSB */
Status decode_size_to_lsb(int size, char *image_buffer);



/*
/* check capacity 		/					//not req for decoding
Status check_capacity(DecodeInfo *decInfo);

/* Get image size 		/					//not req for decoding
uint get_image_size_for_bmp(FILE *fptr_image);

/* Get file size 		/						//not req for decoding
uint get_file_size(FILE *fptr);

/* Copy bmp image header 		/				//not req for decoding
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image);
/* Copy remaining image bytes from src to stego image after decoding 	/
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest);			//not req for decoding
*/
#endif
