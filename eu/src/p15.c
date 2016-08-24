#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>



int main(void)
{

	unsigned long long temp = 0, temp1 = 0;;
	unsigned long long i=0, j=0;

	temp=1;
	for(i = 21; i <= 39;i+=2)
	{
		temp *= i; 
	}

	for(i=1; i<=10; i++)
	{
		temp*=2;
		temp/=i;
	}

	printf("i = %llx, temp = %llu, \n", i, temp ); 
	return 0;
}

