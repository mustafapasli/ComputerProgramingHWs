#include <stdio.h>
#define PI 3.14159

double pw(double x,int y);
int factorial(int number);
double sine(int degree, int n);
double cosine(int degree,int n);
void getInputs(int* degree, int* n, int* exit);


int 
main(){

	int x;
	int n;
	int e;

	getInputs(&x,&n,&e);

	return 0;


}

double pw(double x,int y){

	int i;
	double result;

	result = x;

	if(y == 0){
		result = 1;
	}

	if(y>0){
		for(i=1;i<y;i++){
			result *= x;
		}
	}

	if(y<0){
		for(i=-1;i>y;i--){
			result *= x;
		}
		result = 1/result;
	}

	return result;
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

double sine(int degree, int n){

	int i;
	double result;
	double radians;

	

	if(degree >= 360){
		degree = degree % 360;
	}

	if(degree<0){
		degree = degree + 360;
	}

	radians = 2 *PI * degree / 360;
	
	result = 0;

	for(i=0;i<n;i++){

		result += ((pw((-1),i)*pw(radians,(2*i+1)))/factorial(2*i+1));
	}

	return result;

}

double cosine(int degree,int n){

	int i;
	double result;
	double radians;

	if(degree >= 360){
		degree = degree % 360;
	}

	if(degree<0){
		degree = degree + 360;
	}

	radians = 2 *PI * degree / 360;
	
	result = 0;

	for(i=0;i<n;i++){

		result += ((pw((-1),i)*pw(radians,(2*i)))/factorial(2*i));
	}

	return result;

}

void getInputs(int* degree, int* n, int* exit){

	char e;

	

	scanf("%d",degree);
	scanf("%c",&e);

	if( e != 'e' ){
	
		scanf("%d",n);

		printf("sin(%d) where n is %d = %.4f\n",*degree,*n,sine(*degree,*n));
		printf("cos(%d) where n is %d = %.4f\n",*degree,*n,cosine(*degree,*n));

		*exit = 0;


	}

	*exit = 1;

	return;
	
}




