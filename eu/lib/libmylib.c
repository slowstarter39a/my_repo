/*
 * =====================================================================================
 *
 *       Filename:  libmylib.c
 *
 *    Description:  jjjjjjjjjjjjjjj
 *
 *        Version:  1.0
 *        Created:  2012년 02월 11일 02시 41분 20초
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
#include <unistd.h>

void hello(void)
{
        printf("Hello!! Library World!\n");
}

unsigned int sum_of_power_n_under_m(int m, int n)
{
        int i = 0;
        int sum = 0;
        int power = 0;

        if((n <= 0) || (m <= 0))
        {
                return sum;
        }

        while(++i)
        {
                power = i*n;
                if(power < m)
                {
                        sum+=power;
                }
                else
                {
                        break;
                }
        }
        return sum;
}

unsigned int fibonacci(int n1, int n2, int limit)
{
        int sum = 0;
        int n3 = 0;

        if((n1%2==0) && (n1 <= limit))
        {
                sum+=n1;
        }
        if((n2%2==0) && (n2 <= limit))
        {
                sum+=n2;
        }
        while(1)
        {
                n3=n1+n2;
                if(n3 <= limit)
                {
                        if(n3%2 == 0)
                        {
                                sum+=n3;
                        }
                        n1=n2;
                        n2=n3;
                }
                else
                {
                        break;
                }
        }
        return sum;
}

int largest_prime_factor(unsigned long long input_value)
{
        int i = 2;
        int prev_value = 0;

        while(1)
        {
                if(input_value < i)
                {
                        break;
                }
                if((input_value % i) == 0)
                {
                        input_value/=i;
                        prev_value = i;
                        printf("input value = %llu, i = %d\n", input_value, i);
                }
                else
                {
                        i++;
                        printf("input value = %llu, i = %d\n", input_value, i);
                }
                usleep(10000);

        }

        printf("result = %d\n", prev_value);

        return 0;
}
