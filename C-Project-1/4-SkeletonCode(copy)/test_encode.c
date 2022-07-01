#include <stdio.h>
#include <string.h>
#include "common.h"
#include "encode.h"
#include "decode.h"
#include "types.h"


int main(int argc, char **argv)
{
	
    if (check_operation_type(argv) == e_encode)
	{
		printf("selected encoding\n");
		EncodeInfo encInfo;									//Important Sturcture variable
		
		if(argc>5||argc<4)
		{
			printf("Error: Invalid number of Arguments for Encoding\n");	
			return -1;
		}
		if(read_and_validate_encode_args(argv, &encInfo) == e_success)
		{
			printf("read_and_validate_encode_args is SUccess\n");
			
			printf("Started Encoding\n");
			if(do_encoding(&encInfo) == e_success)
			{
				printf("\n---------Completed Encoding--------\n");
			}
			else
			{
				printf("\n------------Encoding Failed----------\n");
				return -1;
			}
			
		}
		else
		{
			printf("read_and_validate_encode_args is Failure\n");
				return -1;
		}
	}
	else if (check_operation_type(argv) == e_decode)
	{
		printf("selected decoding\n");				//start here
		DecodeInfo decInfo;
		
		if(argc>4||argc<3)
		{
			printf("Error: Invalid number of Arguments for Decoding\n");	
			return -1;
		}
		if(read_and_validate_decode_args(argv, &decInfo) == e_success)
		{
			printf("read_and_validate_decode_args is SUccess\n");
			
			printf("Started Decoding\n");
			if(do_decoding(&decInfo, argv) == e_success)
			{
				printf("\n---------Completed Decoding--------\n");
			}
			else
			{
				printf("\n------------Decoding Failed----------\n");
				return -1;
			}
			
		}
		else
		{
			printf("read_and_validate_decode_args is Failure\n");
				return -1;
		}

	}
	else
	{
		printf("invalid option\n for Encoding: ./a.out -e beatuitful.bmp secret.txt stego.bmp \n for Decoding: ./a.out -d stego.bmp decode.txt");
	}
    return 0;
}
OperationType check_operation_type(char *argv[])
{
	if(strcmp(argv[1],"-e")==0)		//chk 1st argument argv[1]..chk if its '-e' if true the value is 0
		return e_encode;
	else if(strcmp(argv[1],"-d")==0)
		return e_decode;
	else
		return e_unsupported;
}
	
	
	
	
	
	
	
	
	