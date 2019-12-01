#include <stdio.h>

#define FIZZ_NUMBER 3
#define BUZZ_NUMBER 5
#define SIZE 100

int main()
{
	unsigned int counter=1;

	for(counter=1 ; counter<SIZE ; counter++) {
		if((counter%FIZZ_NUMBER)==0 && (counter%BUZZ_NUMBER)==0) {
			printf("FizzBuzz , ");
		} else if(counter%FIZZ_NUMBER==0) {
			printf("Fizz , ");
		} else if(counter%BUZZ_NUMBER==0) {
			printf("Buzz , ");
		} else {
			printf("%u , ",counter);
		}
	}

	return 0;
}