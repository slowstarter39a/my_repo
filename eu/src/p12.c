#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>


int main(void)
{
        unsigned int i = 0, j=0; 
        unsigned int sum = 0;
        unsigned int count = 0;
                //sum = 0xffffffff;

        for(i = 1; ; i++){
                sum +=i;

                printf("%x\n", sum);
//                sum--;
//                printf("%u\n", sum);

                //printf("sum = %d\n", sum);
                count = 0;
                for(j = 1 ; j <= sum ; j++)
                {
                        if( sum %j == 0){
                                count++;
                                //printf("sum = %u, j = %u\n", sum, j);
                        printf("count is %d\n", count);
                        }

                        if(count >= 500){
                                printf("the result is %d\n", sum);
                                return 0;
                        }
                }
                        if(count == 100){
                                printf("sum is %d, count = %d\n", sum, count);
                        }
                        if(count == 200){
                                printf("sum is %d, count = %d\n", sum, count);
                        }
                        if(count == 300){
                                printf("sum is %d, count = %d\n", sum, count);
                        }
                        if(count == 400){
                                printf("sum is %d, count = %d\n", sum, count);
                        }
                //sleep(1);
        }

        return 0;
}

