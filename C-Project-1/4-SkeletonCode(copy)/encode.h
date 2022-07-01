#ifndef ENCODE_H
#define ENCODE_H

#include "types.h" // Contains user defined types

/* 
 * Structure to store information required for
 * encoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

typedef struct _EncodeInfo
{
    /* Source Image info */
    char *src_image_fname;							//source File Name
    FILE *fptr_src_image;							//pointer for stego image
    uint image_capacity;							//Image Size
	char image_data[MAX_IMAGE_BUF_SIZE];			//temp storage of size [8] to store chars
    uint bits_per_pixel;		//un used?
    

    /* Secret File Info */
    char *secret_fname;								//source secret_file name
    FILE *fptr_secret;								//pointer for secret_file
    char extn_secret_file[MAX_FILE_SUFFIX];			//extension of the secret file
    char secret_data[MAX_SECRET_BUF_SIZE];			//un used?
   // long size_secret_file;///make it int
	int size_secret_file;							//total size of the secret_file having string

    /* Stego Image Info */
    char *stego_image_fname;						//stego image file name
    FILE *fptr_stego_image;							//pointer for stego image

} EncodeInfo;


/* Encoding function prototype */

/* Check operation type */
OperationType check_operation_type(char *argv[]);

/* Read and validate Encode args from argv */
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo);

/* Perform the encoding */
Status do_encoding(EncodeInfo *encInfo);

/* Get File pointers for i/p and o/p files */
Status open_files(EncodeInfo *encInfo);

/* check capacity */							//not req for decoding
Status check_capacity(EncodeInfo *encInfo);

/* Get image size */							//not req for decoding
uint get_image_size_for_bmp(FILE *fptr_image);

/* Get file size */								//not req for decoding
uint get_file_size(FILE *fptr);

/* Copy bmp image header */						//not req for decoding
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image);

/* Store Magic String */
//Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo);	//without const
Status encode_magic_string( char *magic_string, EncodeInfo *encInfo);

/* Encode Extn size */
Status encode_extn_size(int size, EncodeInfo *encInfo);


/* Encode secret file extenstion */
//Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo);
Status encode_secret_file_extn( char *file_extn, EncodeInfo *encInfo);

/* Encode secret file size */
Status encode_secret_file_size(int file_size, EncodeInfo *encInfo);

/* Encode secret file data*/
Status encode_secret_file_data(EncodeInfo *encInfo);

/* Encode function, which does the real encoding */
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image,EncodeInfo *encInfo);

/* Encode a byte into LSB of image data array */
Status encode_byte_to_lsb(char data, char *image_buffer);

/* Encode int to LSB */
Status encode_size_to_lsb(int size, char *image_buffer);

/* Copy remaining image bytes from src to stego image after encoding */
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest);			//not req for decoding

#endif
