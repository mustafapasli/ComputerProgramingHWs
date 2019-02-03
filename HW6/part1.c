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
void freq(char *str,int *fr);

int 
main(){

	int i;

	int fr[37];

	char str[] ={"abCd Ef ghIj kLM nopr stuv yzwxq 123 4 5 6 7 890 00 ?? |"};

	freq(str,fr);

	for (i = 0; i < 37; ++i)
	{
		printf("%d\n", fr[i]);

	}
	
	return 0;

}
/*---------------------------------------------------------------------------*/
/*						Function Implementations							 */
/*---------------------------------------------------------------------------*/

void freq(char *str,int *fr){
		
	int i;

	for(i=0;i<37;i++){
		fr[i] = 0;
	}

	for(i=0;str[i]!='\0';i++){

		if(str[i] == 'a' || str[i] =='A'){fr[0]++;}
		if(str[i] == 'b' || str[i] =='B'){fr[1]++;}
		if(str[i] == 'c' || str[i] =='C'){fr[2]++;}
		if(str[i] == 'd' || str[i] =='D'){fr[3]++;}
		if(str[i] == 'e' || str[i] =='E'){fr[4]++;}
		if(str[i] == 'f' || str[i] =='F'){fr[5]++;}
		if(str[i] == 'g' || str[i] =='G'){fr[6]++;}
		if(str[i] == 'h' || str[i] =='H'){fr[7]++;}
		if(str[i] == 'i' || str[i] =='I'){fr[8]++;}
		if(str[i] == 'j' || str[i] =='J'){fr[9]++;}
		if(str[i] == 'k' || str[i] =='K'){fr[10]++;}
		if(str[i] == 'l' || str[i] =='L'){fr[11]++;}
		if(str[i] == 'm' || str[i] =='M'){fr[12]++;}
		if(str[i] == 'n' || str[i] =='N'){fr[13]++;}
		if(str[i] == 'o' || str[i] =='O'){fr[14]++;}
		if(str[i] == 'p' || str[i] =='P'){fr[15]++;}
		if(str[i] == 'q' || str[i] =='Q'){fr[16]++;}
		if(str[i] == 'r' || str[i] =='R'){fr[17]++;}
		if(str[i] == 's' || str[i] =='S'){fr[18]++;}
		if(str[i] == 't' || str[i] =='T'){fr[19]++;}
		if(str[i] == 'u' || str[i] =='U'){fr[20]++;}
		if(str[i] == 'v' || str[i] =='V'){fr[21]++;}
		if(str[i] == 'w' || str[i] =='W'){fr[22]++;}
		if(str[i] == 'x' || str[i] =='X'){fr[23]++;}
		if(str[i] == 'y' || str[i] =='Y'){fr[24]++;}
		if(str[i] == 'z' || str[i] =='Z'){fr[25]++;}
		if(str[i] == '0' ){fr[26]++;}
		if(str[i] == '1' ){fr[27]++;}
		if(str[i] == '2' ){fr[28]++;}
		if(str[i] == '3' ){fr[29]++;}
		if(str[i] == '4' ){fr[30]++;}
		if(str[i] == '5' ){fr[31]++;}
		if(str[i] == '6' ){fr[32]++;}
		if(str[i] == '7' ){fr[33]++;}
		if(str[i] == '8' ){fr[34]++;}
		if(str[i] == '9' ){fr[35]++;}	

		if( (str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= '0' && str[i] <= '9')){

		}else 
			fr[36]++;
	}

	return;

}


