#include <stdio.h>
#include <math.h>

void oddNumber(int number);
int factorial(int number);
void isFactorial(int number);
int numberOfDigit(int number);
void narcissisticNumber(int number);

int 
main(){

	int number;
	char ch;
	char prop;

	printf("**************************************************************\n");
	printf("*                       WELCOME !                            *\n");
	printf("*  This program checks whether the given number is an odd    *\n");
	printf("*         a factorial or o narcissistic nummber              *\n");
	printf("*					            	     *\n");
	printf("**************************************************************\n");

	printf("\nPlease enter a positive integer : ");
	scanf("%d",&number);

	while(ch != 'n'){
		
		if(number <= 0){
			
			printf("The entered number is not positive.\n");
			printf("Do you want to continue (y/n)? ");
			scanf(" %c",&ch);

			if(ch == 'y'){
				printf("\nPlease enter a positive integer :");
		        scanf("%d",&number);
			}
		}

		if(number > 0){
			
			printf("Which property would you like to check?\n");
			printf("1)Odd number\n");
			printf("2)Factorial number\n");
			printf("3)Narcissistic number\n");
			printf("Please enter(1/2/3): ");
			scanf(" %c",&prop);
								
			if(prop == '1'){
				
				oddNumber(number);
				printf("Do you want to continue (y/n)? ");
				scanf(" %c",&ch);
					
				if(ch == 'y'){
						
					printf("\nPlease enter a positive integer :");
					scanf("%d",&number);
				}
			}

			if(prop == '2'){
				
				isFactorial(number);
				printf("Do you want to continue (y/n)? ");
				scanf(" %c",&ch);
				
				if(ch == 'y'){
				
					printf("\nPlease enter a positive integer :");
					scanf("%d",&number);
				}
			}

			if(prop == '3'){
				
				narcissisticNumber(number);
				printf("Do you want to continue (y/n)? ");
				scanf(" %c",&ch);
				
				if(ch == 'y'){
						
					printf("\nPlease enter a positive integer :");
					scanf("%d",&number);
				}
			}
		}	
	}


	printf("Good bye !\n");

	return 0;
	
}

void oddNumber(int number){
	
	if(number % 2 == 1 ){
		printf("%d is a odd number !\n",number);
	}
	else{
		printf("%d is not odd number !\n",number);
	}

}


int factorial(int number){

	int i;
	int fact = 1;
	
	if(number < 0){
		return -99;
	}
	else
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
			printf("%d is a factorial number !\n",number);
		}

	}

	if(factorial(i)>number){
		printf("%d is a not factorial number !\n",number);
	}


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
	}
	else{
		printf("%d is not narcissistic number !\n",number);
	}

}







