#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>



int main(void)
{
        unsigned int i = 0, j = 0;
        unsigned int temp= 0;
        unsigned count=0, value = 0, max_count = 0;

        for(i = 1; i <= 1000000; i++){
                temp = i;
                count = 0;
                for(;temp != 1;){
                        if(temp & 1){
                                temp = 3*temp +1;
                        }
                        else{
                                temp/=2;
                        }
                        count++;
                }
                if(count > max_count){
                        max_count = count;
                        value = i;
                }
        } 

        printf("value %d, count = %d\n", value, count);
        return 0;
}

