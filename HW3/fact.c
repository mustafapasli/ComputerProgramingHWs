#include <stdio.h>

int factorial(int number);
void isFactorial(int number);


int 
main(){

	int number;



	printf("Enter a number");

	scanf("%d",&number);		

	isFactorial(number);

	return 0;
}


int factorial(int number){

	int i;
	int fact = 1;
	if(number < 0){
		return -99;
	}else

		for(i=1;i<=number;i++){

			fact = fact * i;
		}

	return fact;
}

void isFactorial(int number){

	int i = 0;
	

	while(factorial(i)<number){

		i+=1;

		if(factorial(i)==number){
			printf("%d number is factorial number !\n",number);
		}

	}

	if(factorial(i)>number){
		printf("%d number is not factorial number !\n",number);
	}


}

