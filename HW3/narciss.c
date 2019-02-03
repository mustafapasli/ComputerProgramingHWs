#include <stdio.h>
#include <math.h>

int numberOfDigit(int number);
void narcissisticNumber(int number);
int 
main(){

	int number;

	printf("Enter a number");

	scanf("%d",&number);

	narcissisticNumber(number);

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

void narcissisticNumber(int number){

	int narciss = 0;	

	int number2 = number;

	while(number2 != 0){
		narciss = narciss + pow(number2%10,numberOfDigit(number));
		number2 /=10; 
	}

	if(narciss == number){
		printf("%d is narcissistic number !\n",number);
	}else{
		printf("%d is not narcissistic number !\n",number);
	}

}




