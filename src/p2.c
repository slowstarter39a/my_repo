#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

typedef unsigned int (*fn_fibonacci)(int, int, int);
int main(void)
{
    const char *error;
    void *module;
    fn_fibonacci fn_fib;

    int limit_num = 0;
    int a = 0, b = 0;
    int result = 0;

    printf("Input Limit Number :");
    scanf("%d", &limit_num);

    printf("Input two number :");
    scanf("%d %d",&a, &b);

    module = dlopen("libmylib.so", RTLD_LAZY);

    if(!module)
    {
        fprintf(stderr, "Couldn't open libmylib.so : %s\n", dlerror());
        exit(1);
    }

    dlerror();
    fn_fib = (unsigned int(*)(int, int, int))dlsym(module, "fibonacci");
    if((error=dlerror()))
    {
        fprintf(stderr, "Couldn't find hello : %s\n", error);
        exit(1);
    }

    result = fn_fib(a, b, limit_num);

    printf("sum = %d\n", result);

    dlclose(module);

    return 0;
}

