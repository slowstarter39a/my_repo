/*
 * =====================================================================================
 *
 *       Filename:  p7.c
 *
 *    Description:  By listing the first six prime numbers: 2, 3, 5, 7, 11, and
 *    13, we can see that the 6th prime is 13.
 *
 *    What is the 10 001st prime number?
 *
 *
 *        Version:  1.0
 *        Created:  2012년 01월 25일 00시 29분 31초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jchsonez (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int result = 2;
    int divider = 3;
    int value = 3;
    int inum = 0;

    printf("Input Number :");
    scanf("%d", &inum);
    printf("inputed number is %d\n", inum);

    while(1)
    {
        divider = 3;
        value+=2;
        while(divider <= value)
        {
            if(value %divider == 0) 
            {
                if(value == divider)
                { 
                    result++;
                }
                break;
            }


            divider+=2;
        }
        if(result >= inum)
        {
            break;
        }
    }

    printf("%d prime is %d\n", inum, value);
}
