#include <stdio.h>
#include <math.h>
int numberOfDigit(int);
int printNumber(int num, int borderWidth, char borderChar);
void getInputs(int* num,int* borderWidth, char* borderChar);

int main(){

	int num;
	int borderWidth;
	char borderChar;

	getInputs(&num,&borderWidth,&borderChar);
		


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

int printNumber(int num, int borderWidth, char borderChar){

	int digit;
	int i,j,k,l,m;
	int numb[5];
	int dividing;
	char ch;
	
	if(num > 99999 || num < 0){
		
		return 0;
	}

	ch = borderChar;
	
	digit = numberOfDigit(num);

	dividing = pow(10,(digit-1));

	for(m=0;m<digit;m++){
	
		numb[m] = num / dividing;
		num %= dividing;
		dividing /=10;
	}

	for(i=1;i<=borderWidth;i++){
		for(j=1;j<=borderWidth;j++){
			printf("%c",ch);
		}
		for(k=1;k<=digit*7;k++){
			printf("%c",ch);
		}
		for(j=1;j<=borderWidth;j++){
			printf("%c",ch);
		}
		printf("\n");
	}
	for(j=1;j<=borderWidth;j++){
			printf("%c",ch);
	}
	for(k=1;k<=digit*7;k++){
			printf(" ");
	}
	for(j=1;j<=borderWidth;j++){
			printf("%c",ch);
	}
	printf("\n");

/*1*/
	
	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}
	l = 0; 
	for(k=1;k<=digit;k++){
		
		
		if(numb[l] == 1){
			printf("   %c   ",ch);
		}
		if(numb[l] == 2){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 3){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 4){
			printf("  %c %c  ",ch,ch);
		}
		if(numb[l] == 5){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 6){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 7){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 8){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 9){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 0){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		l++;
	}
	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}

	printf("\n");

/*2*/
	
	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}
	l = 0; 
	for(k=1;k<=digit;k++){
		
		
		if(numb[l] == 1){
			printf("  %c%c   ",ch,ch);
		}
		if(numb[l] == 2){
			printf("    %c  ",ch);
		}
		if(numb[l] == 3){
			printf("    %c  ",ch);
		}
		if(numb[l] == 4){
			printf("  %c %c  ",ch,ch);
		}
		if(numb[l] == 5){
			printf("  %c    ",ch);
		}
		if(numb[l] == 6){
			printf("  %c    ",ch);
		}
		if(numb[l] == 7){
			printf("    %c  ",ch);
		}
		if(numb[l] == 8){
			printf("  %c %c  ",ch,ch);
		}
		if(numb[l] == 9){
			printf("  %c %c  ",ch,ch);
		}
		if(numb[l] == 0){
			printf("  %c %c  ",ch,ch);
		}		
		l++;
	}
	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}

	printf("\n");

/*3*/

	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}
	l = 0; 
	for(k=1;k<=digit;k++){
		
		
		if(numb[l] == 1){
			printf("   %c   ",ch);
		}
		if(numb[l] == 2){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 3){
			printf("   %c%c  ",ch,ch);
		}
		if(numb[l] == 4){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 5){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 6){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 7){
			printf("    %c  ",ch);
		}
		if(numb[l] == 8){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 9){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 0){
			printf("  %c %c  ",ch,ch);
		}		
		l++;
	}
	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}

	printf("\n");

/*4*/

	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}
	l = 0; 
	for(k=1;k<=digit;k++){
		
		
		if(numb[l] == 1){
			printf("   %c   ",ch);
		}
		if(numb[l] == 2){
			printf("  %c    ",ch);
		}
		if(numb[l] == 3){
			printf("    %c  ",ch);
		}
		if(numb[l] == 4){
			printf("    %c  ",ch);
		}
		if(numb[l] == 5){
			printf("    %c  ",ch);
		}
		if(numb[l] == 6){
			printf("  %c %c  ",ch,ch);
		}
		if(numb[l] == 7){
			printf("    %c  ",ch);
		}
		if(numb[l] == 8){
			printf("  %c %c  ",ch,ch);
		}
		if(numb[l] == 9){
			printf("    %c  ",ch);
		}
		if(numb[l] == 0){
			printf("  %c %c  ",ch,ch);
		}		
		l++;
	}
	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}

	printf("\n");

/*5*/

	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}
	l = 0; 
	for(k=1;k<=digit;k++){
		
		
		if(numb[l] == 1){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 2){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 3){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 4){
	    	printf("    %c  ",ch);
		}
		if(numb[l] == 5){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 6){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 7){
			printf("    %c  ",ch);
		}
		if(numb[l] == 8){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 9){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		if(numb[l] == 0){
			printf("  %c%c%c  ",ch,ch,ch);
		}
		l++;
	}
	for(j=1;j<=borderWidth;j++){
		printf("%c",ch);
	}

	printf("\n");
				



	for(j=1;j<=borderWidth;j++){
			printf("%c",ch);
	}
	for(k=1;k<=digit*7;k++){
			printf(" ");
	}
	for(j=1;j<=borderWidth;j++){
			printf("%c",ch);
	}
	printf("\n");

	for(i=1;i<=borderWidth;i++){
		for(j=1;j<=borderWidth;j++){
			printf("%c",ch);
		}
		for(k=1;k<=digit*7;k++){
			printf("%c",ch);
		}
		for(j=1;j<=borderWidth;j++){
			printf("%c",ch);
		}
		printf("\n");
	}

	return 1;

}

void getInputs(int* num,int* borderWidth, char* borderChar){

	scanf("%d",num);

	if(*num>=0){

		scanf("%d %c",borderWidth,borderChar);

		if(*num<=99999){
			printNumber(*num,*borderWidth,*borderChar);
		}

		scanf("%d",num);

	}	

}
