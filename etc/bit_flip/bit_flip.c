/*
 * =====================================================================================
 *
 *       Filename:  bit_flip.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2016 11:17:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *fp1 = NULL, *fp2 = NULL;
	unsigned char buff1[4] = {0,};
	unsigned char buff2[4] = {0,};
	unsigned long file_size1 = 0;
	unsigned long file_size2 = 0;
	unsigned long file_cmp_size = 0;
	int i = 0;
	int c = 0;
	unsigned long offset = 0;
	if(argc < 2){
		printf("Error!!!\n"); 
	}

	printf("open %s\n", argv[1]);
	printf("open %s\n", argv[2]);

	if((fp1 = fopen(argv[1], "rb")) == NULL){
		printf("file open failed %s\n", argv[1]);
		return 0;
	}
	if((fp2 = fopen(argv[2], "rb")) == NULL){
		printf("file open failed %s\n", argv[2]);
		return 0;
	}

	fseek(fp1, 0, SEEK_END);
	file_size1 = ftell(fp1);
	fseek(fp1, 0, SEEK_SET);

	fseek(fp2, 0, SEEK_END);
	file_size2 = ftell(fp2);
	fseek(fp2, 0, SEEK_SET);

	if(file_size1 >= file_size2){
		file_cmp_size = file_size2;
	}
	else{
		file_cmp_size = file_size1;
	}

	for(i = 0; i < file_cmp_size; i+=4){
		fread(buff1, 1, 4, fp1);
		fread(buff2, 1, 4, fp2);

		if(memcmp(buff1, buff2, sizeof(buff1)/sizeof(buff1[0])) != 0){
			if((((buff1[0] == 0x0) && (buff1[1] == 0x40) && (buff1[2] == 0xbd) && (buff1[3] == 0xe8)) ||
			((buff2[0] == 0x0) && (buff2[1] == 0x40) && (buff2[2] == 0xbd) && (buff2[3] == 0xe8)))){
				;
			}
			else{
				printf("addr : 0x%08x, first : 0x%02x%02x%02x%02x, second : 0x%02x%02x%02x%02x \r\n", i,
						buff1[3], buff1[2], buff1[1], buff1[0],
						buff2[3], buff2[2], buff2[1], buff2[0]);
			}
			usleep(100);
		}
	} 
	fclose(fp1);
	fclose(fp2);
}

