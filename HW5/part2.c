#include <stdio.h>

int isPieceMovable(char *board);
void getPosition(char *col, int *row);
int isValidCell(char col,int row);
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int addressOfArray(char col,int row);


int 
main(){

	char board[64] = {'r','n','b','q','k','b','n','r',
	   		  		     'p','p','p','p','p','p','p','p',
	    		         ' ',' ',' ',' ',' ',' ',' ',' ',
	    	 	         ' ',' ',' ',' ',' ',' ',' ',' ',
	    		         ' ',' ',' ',' ',' ',' ',' ',' ',
	     		         ' ',' ',' ',' ',' ',' ',' ',' ',			 
         		         'P','P','P','P','P','P','P','P',
          		         'R','N','B','Q','K','B','N','R'};

	isPieceMovable(board);

	return 0;

}



int isPieceMovable(char *board){

	char sourceCol,targetCol;
	int sourceRow,targetRow;

	getPosition(&sourceCol,&sourceRow);
	
	printf("%c%d ", sourceCol,sourceRow );

	getPosition(&targetCol,&targetRow);

	printf("%c%d\n",targetCol,targetRow);

	printf("is valid source %d\n",isValidCell(sourceCol,sourceRow));

	printf("is valid target %d\n",isValidCell(targetCol,targetRow));

	if(board[addressOfArray(sourceCol,sourceRow)] == 'n' || 
	   board[addressOfArray(sourceCol,sourceRow)] == 'N'){

		if(isKnightMovable(board,sourceCol,sourceRow,targetCol,targetRow)){
			
			return 1;

		}
	}

	

	return 1;

}

void getPosition(char *col, int *row){

	scanf(" %c%d",col,row);
}

int isValidCell(char col,int row){

	if(row < 1 || row > 8){
		return 0;
	}

	if(col < 'a' || col > 'h'){
		return 0;
	}

	return 1;

}

int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

	return 1;
}

int addressOfArray(char col,int row){

	return (8 - row)*8 + (col - 'a');
}


