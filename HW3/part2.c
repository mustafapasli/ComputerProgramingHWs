#include <stdio.h>

int numberOfDigit(int);

int mian(){

	int number;
	int Digit;

	
	scanf("%d",&number);

	digit = numberOfDigit(number);

	printf("number of digit %d\n",Digit );





	return 0;
}

int numberOfDigit(int number){

	int n = 1;

	while(number >= 10){

		n++;
		number = number/10;
		

	}

	return n;

}