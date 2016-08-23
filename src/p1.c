#include <stdio.h>
#include <stdlib.h>

#include <dlfcn.h>

typedef unsigned int(*simple_demo_function)(int, int);

int main(void)
{
    int i = 0;
    int sum1 = 0, sum2=0; 
    const char *error;
    void *module;
    simple_demo_function demo_function;
    int max_num = 0;
    int a = 0, b = 0;

    printf("Input Max Number :");
    scanf("%d", &max_num);

    printf("Input two number :");
    scanf("%d %d",&a, &b);

    module = dlopen("libmylib.so", RTLD_LAZY);

    if(!module)
    {
        fprintf(stderr, "Couldn't open libmylib.so : %s\n", dlerror());
        exit(1);
    }

    dlerror();
    demo_function=(unsigned int(*)(int,int))dlsym(module, "sum_of_power_n_under_m");
    if((error=dlerror()))
    {
        fprintf(stderr, "Couldn't find hello : %s\n", error);
        exit(1);
    }

    sum1 = 0;
    sum1 += (*demo_function)(max_num, a);

    printf("sum1 of %d power = %d\n", a, sum1);


    sum2 = 0;
    sum2 += (*demo_function)(max_num, b);

    printf("sum2 of %d power = %d\n", b, sum2);

    sum1+=sum2;

    sum2 = 0;
    sum2 += (*demo_function)(max_num, a*b);

    printf("sum2 of %d power = %d\n", a*b, sum2);

    sum1-=sum2;

    printf("The result is %d\n", sum1);

    dlclose(module);

    return 0; 
}

    
