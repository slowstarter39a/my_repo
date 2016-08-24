#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>



int main(void)
{
	unsigned char product[1000] = {0,};
	int i = 0, j=0, k = 0;;
	int carry = 0, prev_msb = 0, msb = 0;
	unsigned long temp = 1;
	product[0] = 1;
	k = 5;
	unsigned long sum = 0;

	printf("Input number : ");
	scanf("%d", &k);

	for( j = 0; j < k; j++){
		for( i = 0; i <= prev_msb; i++){
			temp = product[i];
			temp *= 2;
			temp += carry;
			carry = 0;
			product[i] = temp %10;
			if(temp/10){
				carry = 1;
				msb = i+1;
				if(prev_msb == 0)prev_msb = msb;
				else if(prev_msb < msb) prev_msb = msb;
			}
		}
	}

	for(i =prev_msb; i>=0; i--){
		//printf("i = %d, product[%d]= %d, ", i, i, product[i]); 
		printf("%d",  product[i]); 
		sum += product[i];
	}
	printf("\n"); 
	printf("sum = %lu\n", sum); 
	return 0;


#if 0

	printf("Input number : ");
	scanf("%d", &k);

	for( i = 1; i <= k; i++){
		for( j = 0; j < 1000; j++){
			product[j] += carry;
			//carry = 0;
			temp = 0;
			if(product[j] != 0){ 
				temp = product[j];
			}
//			else{
//				break;
//			}
			if(carry == 0){
				temp*=2;
			}
			carry = 0;
			//printf("%d, product[j] = %d\n", temp, product[j]);
			product[j] = (temp & 0xff);
			if(temp > 0xff){
				carry = 1;
			}
		} 
	}

	for(i =0; i<k; i++){
		printf("i = %d, product[%d]= %d, \n", i, i, product[i]); 
		if(product[i] != 0){
			break;
		}
	}
	return 0;

#endif


}

