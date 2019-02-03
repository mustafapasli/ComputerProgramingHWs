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

int 
main(){

	
	char haystack[] ={"mustafa"};
	char needle[] = {"fa"} ;

	printf("%s\n",haystack );

	printf("%s\n",matcher(haystack,needle));
	
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

	/*int i,j;
	int haystackSize= 0;
	int needleSize = 0;
	int flag;

	while(needle[needleSize] != '\0'){
		needleSize++;
	}

	while(haystack[haystackSize] != '\0'){
		haystackSize++;
	}

	for(i=0;i<=haystackSize - needleSize; i++){
		
		flag = 1;

		if(haystack[i] == needle[0]){
			for(j=0;j<needleSize;j+=2){
				
				if(flag){
					if(haystack[i+j] == needle[j]){
						flag = 1;
			

					}else{
					    flag = 0;
					}
				}
				
				if(flag == 1){
				haystack[i] ='-';
				return &needle[0];
				 
				}	
			}
			
		}
	}

	return &needle[needleSize+1];
	
	*/

