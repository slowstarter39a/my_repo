/*
 * =====================================================================================
 *
 *       Filename:  mov.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2016 03:51:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int asm_mov_ex(int x, int y);

__asm__ (".global asm_mov_ex	\n\
		asm_mov_ex:	\n\
		mov r0, r1	\n\
		mov pc, lr	\n\
		");

int main(void)
{
	int mov;
	printf("\n+-------------------+\n");
	printf("|ARM Instruction MOV|\n");
	printf("\n+-------------------+\n");

	mov = asm_mov_ex(2, 3);
	printf("mov = %d\n\n", mov);

	return 0;
}

