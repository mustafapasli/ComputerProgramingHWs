#include <stdio.h>

void oddNumber(int number);

int 
main(){

	int number;

	printf("Enter a number");

	scanf("%d",&number);

	oddNumber(number);

	return 0;

}

void oddNumber(int number){
	
	if(number % 2 == 1 ){
		printf("%d is a odd number !",number);
	}else{
		printf("%d is not odd number !",number);
	}

}

