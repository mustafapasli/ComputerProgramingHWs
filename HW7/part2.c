#include <stdio.h>

int recursivePol(char * str,int i, int size);

int 
main(){

	printf("%d\n",recursivePol("abcba",0,4));



	return 0;

}

int recursivePol(char * str,int i, int size){

	int isPol = 0;

	if(i >= size){
		isPol = 1;
	}else if(str[i] ==str[size]){
		i++;
		size--;
		isPol = recursivePol(str,i,size);
	}
	else if( str[i] != str[size]){
		isPol = 0;
	}



	return isPol;
}



