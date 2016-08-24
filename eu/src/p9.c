#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main(void)
{
        int a=0, b=0, c=0;

        for(a = 1; a < 335; a++)
        {
                b=a+1;
                for(; b<500; b++)
                {
                                c = 1000 -a -b;
                        //if(b<a);
                        if(a+b > 667);
                        else if(c < b);
                        else
                        {
                                if(c*c == (a*a + b*b)){
                                        printf("a = %d, b = %d, c = %d, a2 = %d, b2 = %d, c2 = %d \n", a, b, c, a*a, b*b, c*c);
                                        printf("a * b * c = %d \n", a * b * c);
                                }
                        }
                }
        }

        return 0;
}

