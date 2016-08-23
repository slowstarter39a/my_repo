/*
 * =====================================================================================
 *
 *       Filename:  p6.c
 *
 *    Description:  The sum of the squares of the first ten natural numbers is,
 *    12 + 22 + ... + 102 = 385
 *
 *    The square of the sum of the first ten natural numbers is,
 *    (1 + 2 + ... + 10)2 = 552 = 3025
 *
 *    Hence the difference between the sum of the squares of the first ten
 *    natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 *    Find the difference between the sum of the squares of the first one
 *    hundred natural numbers and the square of the sum.
 *
 *
 *        Version:  1.0
 *        Created:  2012년 01월 25일 00시 09분 43초
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

int sop(int inum);
int pos(int inum);
int main(void)
{
    int iNum = 0;
    int r1 = 0, r2 = 0;
    printf("input number : ");
    scanf("%d", &iNum);
    printf("inputed number is %d\n",iNum);

    r1 = sop(iNum);
    r2 = pos(iNum);

    r1 = r1 - r2;
    if(r1 < 0)
    {
        r1=r1*(-1);
    }

    printf("result = %d\n", r1);

    return 0;

}


int sop(int inum)
{
    int i = 0;
    int sum = 0;
    for(i = 1; i <= inum; i++)
    {
        sum+=(i*i); 
    }
    return sum;
}
int pos(int inum)
{
    int i = 0;
    int sum = 0;
    for(i = 1; i <= inum; i++)
    {
        sum+=i; 
    }
    return sum*sum;
}
