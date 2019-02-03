/*--------------------------------------------------------------------------*/
/*																			*/
/* HW07_131044032_Mustafa_Paslı                                             */
/*																			*/
/* main.c    																*/
/* ---------																*/
/* Created on 15/04/2016 by Mustafa_Paslı 									*/
/*																			*/
/*--------------------------------------------------------------------------*/

#include <stdio.h>
/*---------------------------------------------------------------------------*/
/*							Function Prototypes  							 */
/*---------------------------------------------------------------------------*/
int recursivePal(char * str,int i, int size);
int isPolindrome(char * str);

int 
main(){

	char str[40] = "ab c 12 3ba";

	printf("%d\n",isPolindrome(str) );

	return 0;

}

/*---------------------------------------------------------------------------*/
/*						Function Implementations							 */
/*---------------------------------------------------------------------------*/

/*Cleaning the other characters from letters */

int isPolindrome(char * str){

	int strSize = 0;
	int i;
	int j = 0;
	int str1Size = 0;

	while(str[strSize] != '\0'){
		strSize++;
	}

	for(i=0;i<strSize;i++){

		if( (str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ){

			if(str[i] < 97){
				
				str[i] = str[i] + 32;
			}

			str[j] = str[i];

			j++;
		}
	}

	str[j] = '\0';

	while(str[str1Size] != '\0'){
		str1Size++;
	}

	printf("%s\n",str);

	return recursivePal(str,0,str1Size-1);
}

/*Recursive finder palindrome*/

int recursivePal(char * str,int i, int size){



	int isPal = 0;

	if(i >= size){
		isPal = 1;
	}else if(str[i] ==str[size]){
		i++;
		size--;
		isPal = recursivePal(str,i,size);
	}
	else if( str[i] != str[size]){
		isPal = 0;
	}

	return isPal;
}





