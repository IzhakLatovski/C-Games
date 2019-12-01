#include <stdio.h>

#define FIZZ_NUMBER 3
#define BUZZ_NUMBER 5
#define SIZE 100

int main()
{
	unsigned int counter=1;

	for(counter=1 ; counter<SIZE ; counter++) {
		if((counter%FIZZ_NUMBER)==0 && (counter%BUZZ_NUMBER)==0) {
			printf("\033[1;35m");
			printf("FizzBuzz , ");
			printf("\033[0m");
		} else if(counter%FIZZ_NUMBER==0) {
			printf("\033[0;32m");
			printf("Fizz , ");
			printf("\033[0m");
		} else if(counter%BUZZ_NUMBER==0) {
			printf("\033[0;32m");
			printf("Buzz , ");
			printf("\033[0m");
		} else {
			printf("%u , ",counter);
		}
	}

	return 0;
}
