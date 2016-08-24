/*
 * =====================================================================================
 *
 *       Filename:  demo_dynamic.c
 *
 *    Description:  demo_dynamic.c -- demonstrate dynamic loading and use of
 *    the "hello" routine
 *
 *        Version:  1.0
 *        Created:  2012년 02월 10일 00시 15분 46초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jchsonez (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <dlfcn.h>
#include <stdio.h>

typedef void (*simple_demo_function)(void);

int main(void)
{
    const char *error;
    void *module;
    simple_demo_function demo_function;

    module = dlopen("libhello.so", RTLD_LAZY);

    if(!module)
    {
        fprintf(stderr, "Couldn't open libhello.so : %s\n", dlerror());
        exit(1);
    }

    dlerror();
    demo_function=dlsym(module, "hello");
    if((error=dlerror()))
    {
        fprintf(stderr, "Couldn't find hello : %s\n", error);
        exit(1);
    }

    (*demo_function)();

    dlclose(module);

    return 0;
}


