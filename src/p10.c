#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main(void)
{
        int a=0, b=0, c=0;
        int i = 0; 
        unsigned long long sum = 2;

        printf("Input number :\n");
        scanf("%d", &a);

        for(i = 3; i < a; i++)
        {
                for(b = 2; b<= i; b++)
                {
                        if((i % b == 0) && (i/b) != 1)break;
                        else if(i % b == 0)
                        {
                                sum += i;
                                printf("i = %d\n", i);
                        }
                } 
        }

        printf("sum = %llu\n", sum);

        return 0;
}

