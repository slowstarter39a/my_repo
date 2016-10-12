/*
 * =====================================================================================
 *
 *       Filename:  lsl.c
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

int asm_lsl_ex(int x, int y)
{
	int a;

__asm__ volatile( "lsl	%[param1], %[param2], %[param3]	\n\t"
	:[param1] "=r" (a): [param2] "r" (x), [param3] "r"(y):
	);

	return a;

} 

int main(void)
{
	int lsl;
	printf("\n+-------------------+\n");
	printf("|ARM Instruction LSL|\n");
	printf("\n+-------------------+\n");

	lsl = asm_lsl_ex(3, 4);
	printf("lsl= %d\n\n", lsl);

	return 0;
}

