#include <stdio.h>
//#include <math.h>

int powor(int a, int b)
{
    int i = 0;
    int res = 1;

    for(i = 0; i<b; i++)
    {
        res = res*a;
    }

    return res;
}


int main(void)
{
    int result = 0;
    int i = 0;
    int i1 = 999;
    int i2 = 999;
    int array[6] = {0};
    int prev_result = 0;

    for(i1 = 999; i1 >=100; i1--)
    {
        for(i2 = 999; i2 >=100; i2--)
        {
            result = i1 * i2;
            printf("i1=%d, i2 = %d, result = %d\n", i1, i2, i1*i2);

            if(result < prev_result)
            {
                break;
            }
            for(i = 1; i < 7; i++)
            {
                //if(i==1)
                {
                    array[i-1] = (result/powor(10, i-1))%10;
                }
//                else
//                {
//                    array[i-1] = (result/(10*(i-1)))%10;
//
//                }
                usleep(100);
            }
        if(array[5] == array[0] &&
                array[4] == array[1] &&
                array[3] == array[2])
        {
            prev_result = result;
            break;
        }

        }
    }

    printf("prev result = %d\n", prev_result);



    return 0;
}




