#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>



int main(void)
{
	int i = 0, k = 0;;
	unsigned long sum = 0;
	unsigned int quota = 0;
	unsigned int remain = 0;
	k = 5;

	unsigned char *ten_digits[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	unsigned char *ten_digits2[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	unsigned char *hundred_digits = "hundred";
	unsigned char *thousand_digits = "thousand";
	unsigned char *and = "and";
	


	printf("Input number : ");
	scanf("%d", &k);

	for( i = 1; i <= k; i++){

		remain = i%100;
		quota = i/100;

		if(quota == 10){
			sum += strlen(ten_digits[1]);
			sum+=strlen(thousand_digits);
			printf("%s", ten_digits[1]);
			printf(" %s\n", thousand_digits);
			;
		}

		else if(remain == 0){
			sum += strlen(ten_digits[quota]);
			sum+=strlen(hundred_digits);
			printf("%s", ten_digits[quota]);
			printf(" %s\n", hundred_digits);

		} 

		else if(quota > 0){
			sum += strlen(ten_digits[quota]);
			sum+=strlen(hundred_digits);
			sum += strlen(and);
			printf("%s", ten_digits[quota]);
			printf(" %s", hundred_digits);
			printf(" %s ", and);
		}


		if(remain < 20){
			sum += strlen(ten_digits[remain]);
			printf("%s\n", ten_digits[remain]);
		}

		else{
			sum += strlen(ten_digits2[remain/10-2]);
				sum += strlen(ten_digits[remain%10 ]);

			printf("%s ", ten_digits2[remain/10-2]);
				printf("%s\n", ten_digits[remain%10]);
		} 
	}
	printf("\n"); 
	printf("sum = %lu\n", sum); 
	return 0;


}

