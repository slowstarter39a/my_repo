/*
 * =====================================================================================
 *
 *       Filename:  p5.c
 *
 *    Description: 2520 is the smallest number that can be divided by each of
 *    the numbers from 1 to 10 without any remainder.
 *
 *    What is the smallest positive number that is evenly divisible by all of
 *    the numbers from 1 to 20?
 *
 *
 *        Version:  1.0
 *        Created:  2012년 01월 24일 16시 23분 41초
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

struct Quota{
    int quota;
    struct Quota *next;
};

struct Remainder{
    int remainder;
    struct Remainder *prev;
    struct Remainder *next;
};

struct Remainder *head = NULL, *tail = NULL;
struct Quota *quota_head=NULL, *quota_tail=NULL;
void cal_least_common_multiple(int iNum); 

int main(void)
{
    int iNum = 0;
    printf("Input Number : ");
    scanf("%d", &iNum);
    printf("Inputed number is %d\n", iNum);

    cal_least_common_multiple(iNum); 

    printf("Finished!\n");


    return 0;
}

void cal_least_common_multiple(int iNum)
{
    int i = 0;
    int divider = 2;
    int max_remainder = iNum;
    int value_divide_2 = 0;
    int result = 1;

    for(i =1 ; i <= iNum; i++)
    {
        struct Remainder *r1 = new Remainder;
        r1->remainder = i;

        if(head ==NULL)
        {
            head = r1;
            tail = r1;
            r1->prev = NULL;
            r1->next = NULL;
        }
        else
        {
            r1->prev=tail;
            r1->next=NULL;
            tail->next = r1;
            tail=r1;
        }
    }

    while(1)
    {
        value_divide_2 = 0;
        tail = head;
        max_remainder = tail->remainder;
        while(tail != NULL)
        {
            if(max_remainder < tail->remainder)
            {
                max_remainder = tail-> remainder;
            }

            if((tail->remainder%divider == 0) && (tail-> remainder / divider != 0))
            {
                tail->remainder/=divider;
                value_divide_2++;
            }
            tail=tail->next;
        }
        if(value_divide_2 != 0)
        {
            struct Quota *q1 = new Quota;
            //printf("q1 = %p\n", q1);
            q1->quota = divider;
            if(quota_head ==NULL)
            {
                quota_head = q1;
                quota_tail = q1;
                q1->next = NULL;
            }
            else
            {
                q1->next=NULL;
                quota_tail->next = q1;
                quota_tail=q1;
            } 
        }
        if(value_divide_2 <2)
        {
            divider++;
        }
        if(max_remainder < divider)
        {
            break;
        }

    }

    tail = head;
    for(i=0; i< iNum; i++)
    {
        if(tail != NULL)
        {
            head=tail;
            if(head != NULL)
            {
//                if(head->next != NULL)
//                {
                    tail=head->next;
//                }
                delete head;
                head=NULL;
            }
        }
        else
        {
            break;
        }
    } 
    quota_tail = quota_head;
    for(i = 0; i < iNum; i++)
    {
        quota_head= quota_tail;
        if(quota_tail!= NULL)
        {
//            if(quota_head->next != NULL)
//            {
                quota_tail=quota_head->next;
                result*= quota_head->quota;

//            }
//            printf("quota_head = %p\n", quota_head);
            delete quota_head;
            quota_head=NULL;

        }
        else
        {
            break;
        }
    }
    printf("result = %d\n", result);
}
