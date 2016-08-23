#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

typedef int (*fn_largest_prime_factor)(unsigned long long);

int main(void)
{
        unsigned long long input_value = 0;
        const char *error;
        void *module;
        fn_largest_prime_factor fn_prime_factor;
        module = dlopen("lib/libmylib.so", RTLD_LAZY);

        if(!module)
        {
                fprintf(stderr, "Couldn't open libmylib.so : %s\n", dlerror());
                exit(1);
        }

        dlerror();
        fn_prime_factor= (int(*)(unsigned long long ))dlsym(module, "largest_prime_factor");
        if((error=dlerror()))
        {
                fprintf(stderr, "Couldn't find hello : %s\n", error);
                exit(1);
        }


        //scanf("input_value = %lld", &input_value);
        scanf("%lld", &input_value);

        printf("input value = %llu\n", input_value);
        fn_prime_factor(input_value);

        dlclose(module);

        return 0;
}

