/*--------------------------------------------------------------------------*/
/*																			*/
/* HW06_131044032_Mustafa_Paslı                                             */
/*																			*/
/* main.c    																*/
/* ---------																*/
/* Created on 02/04/2016 by Mustafa_Paslı 									*/
/*																			*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>

/*---------------------------------------------------------------------------*/
/*							Function Prototypes  							 */
/*---------------------------------------------------------------------------*/
char* matcher(char* haystack,char* needle);
int count(char* str,char* substr);

int 
main(){

	char str[] = {"ececece"};
	char substr[] = {"ece"};


	printf("%d\n",count(str,substr));

	return 0;

}
/*---------------------------------------------------------------------------*/
/*						Function Implementations							 */
/*---------------------------------------------------------------------------*/
char* matcher(char* haystack,char* needle){

	int i,j,firstOccur;
	int haystackSize= 0;
	int needleSize = 0;

	while(needle[needleSize] != '\0'){
		needleSize++;
	}

	while(haystack[haystackSize] != '\0'){
		haystackSize++;
	}

	if(needleSize > haystackSize){
	    return NULL;
	}
	
	
	i=0;
	j=0;

	while(haystack[i] != '\0'){

		while(haystack[i] != needle[0] && haystack[i] != '\0'){
			i++;
		}

	    
		if(haystack[i] == '\0'){
			return NULL;
		}
		
		firstOccur = i;

		while(haystack[i] == needle[j] && haystack[i] != '\0' && needle[j] != '\0'){
			i+=2;
			j+=2;

			
			if(j>=needleSize){
				return &haystack[firstOccur];
			}

			if(haystack[i] == '\0'){
				return NULL;
			}
			
		
	
		}

		if(needle[j] ==  '\0'){
			return &haystack[firstOccur];
		}
		
		i = firstOccur + 1;
		j= 0;

	}

	return NULL;

}

int count(char* str,char* substr){

	int repeat = 0;

	int size = 0;
	
	char *str1;
		
	while(str[size] != '\0'){
		size++;
	}
	
    str1 = matcher(str,substr);

    while(str1 != NULL){
    	repeat++;

    	str1 = matcher(&str1[1],substr);


    }

  	

     

	return repeat;
}