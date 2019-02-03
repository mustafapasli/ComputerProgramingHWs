
/*--------------------------------------------------------------------------*/
/*																			*/
/* HW05_131044032_Mustafa_Paslı                                             */
/*																			*/
/* main.c    																*/
/* ---------																*/
/* Created on 02/04/2016 by Mustafa_Paslı 									*/
/*																			*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*       					     Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
/*---------------------------------------------------------------------------*/
/*							Function Prototypes  							 */
/*---------------------------------------------------------------------------*/
void emptyBuffer();
void initBoard(char *board);
void printBoard(char *board);
int isPieceMovable(char *board);
void getPosition(char *col, int *row);
int isValidCell(char col,int row);
int addressOfArray(char col,int row);
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int  targetRow);
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isPawnsMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);

int 
main(){

	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else  
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
	return 0;
}
/*---------------------------------------------------------------------------*/
/*						Function Implementations							 */
/*---------------------------------------------------------------------------*/

void emptyBuffer(){
	while ( getchar() != '\n' );
}

int isPieceMovable(char *board){

	char sourceCol,targetCol;
	int sourceRow,targetRow;

	getPosition(&sourceCol,&sourceRow);

	getPosition(&targetCol,&targetRow);

	if(isValidCell(sourceCol,sourceRow) == 0 || 
	   isValidCell(targetCol,targetRow) == 0){
		return 0;
	}

	if(board[addressOfArray(sourceCol,sourceRow)] == 'n' || 
	   board[addressOfArray(sourceCol,sourceRow)] == 'N'){

			if(isKnightMovable(board,sourceCol,sourceRow,targetCol,targetRow)){
				return 1;
			}else 
				return 0;
	}

	if(board[addressOfArray(sourceCol,sourceRow)] == 'r' || 
	   board[addressOfArray(sourceCol,sourceRow)] == 'R'){

			if(isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow)){
				return 1;
			}else 
				return 0;
	}

	if(board[addressOfArray(sourceCol,sourceRow)] == 'b' || 
	   board[addressOfArray(sourceCol,sourceRow)] == 'B'){

			if(isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow)){
				return 1;
			}else 
				return 0;
	}

	if(board[addressOfArray(sourceCol,sourceRow)] == 'q' || 
	   board[addressOfArray(sourceCol,sourceRow)] == 'Q'){

			if(isQueenMovable(board,sourceCol,sourceRow,targetCol,targetRow)){
				return 1;
			}else 
				return 0;
	}

	if(board[addressOfArray(sourceCol,sourceRow)] == 'k' || 
	   board[addressOfArray(sourceCol,sourceRow)] == 'K'){

			if(isKingMovable(board,sourceCol,sourceRow,targetCol,targetRow)){
				return 1;
			}else 
				return 0;
	}

	if(board[addressOfArray(sourceCol,sourceRow)] == 'p' || 
	   board[addressOfArray(sourceCol,sourceRow)] == 'P'){

			if(isPawnsMovable(board,sourceCol,sourceRow,targetCol,targetRow)){
				return 1;
			}else 
				return 0;
	}

	if(board[addressOfArray(sourceCol,sourceRow)] == ' '){

		return 0;
	}

	return 1;
}

void printBoard(char *board){

	int i,k;

	k = 8;

	printf("  a b c d e f g h\n");
	printf("  - - - - - - - -\n");

	for (i = 1; i < 65; ++i)
	{
		if(i%8 == 1){
			printf("%d|",k);
			--k;
		}
		printf("%c",board[i-1]);
		if(i%8 != 0){
			printf(" ");
		}

		if(i%8 == 0){
			printf("|\n");
		}
	}

}

void initBoard(char *board){

	int i;

	char firstBoard[] = {'r','n','b','q','k','b','n','r',
	   		  		     'p','p','p','p','p','p','p','p',
	    		         ' ',' ',' ',' ',' ',' ',' ',' ',
	    	 	         ' ',' ',' ',' ',' ',' ',' ',' ',
	    		         ' ',' ',' ',' ',' ',' ',' ',' ',
	     		         ' ',' ',' ',' ',' ',' ',' ',' ',			 
         		         'P','P','P','P','P','P','P','P',
          		         'R','N','B','Q','K','B','N','R'};

    for (i = 0; i < 64; ++i)
    {
    	board[i] = firstBoard[i];
    }

}

/*Finding index of array from column and row*/ 

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
	int i;
	
	int targetValue = 0;

	/*Finding the located can go kinght and the testing target rows and column is in there */

	for (i=2;i>-3;--i){
   		if(i==2){
   			if(sourceCol-1 == targetCol && sourceRow+i == targetRow){targetValue = 1;}
   			if(sourceCol+1 == targetCol && sourceRow+i == targetRow){targetValue = 1;}
   		}
   		if(i==1){
   			if(sourceCol-2 == targetCol && sourceRow+i == targetRow){targetValue = 1;}
   			if(sourceCol+2 == targetCol && sourceRow+i == targetRow){targetValue = 1;}
   		}
   		if(i==-1){
   			if(sourceCol-2 == targetCol && sourceRow+i == targetRow){targetValue = 1;}
   			if(sourceCol+2 == targetCol && sourceRow+i == targetRow){targetValue = 1;}
   		}
   		if(i==-2){
   			if(sourceCol-1 == targetCol && sourceRow+i == targetRow){targetValue = 1;}
   			if(sourceCol+1 == targetCol && sourceRow+i == targetRow){targetValue = 1;}
   		}

   	/* Checking the  piece is valid in the target rows and columns */

   	if(board[addressOfArray(sourceCol,sourceRow)] == 'N' && 
   	   board[addressOfArray(targetCol,targetRow)] >  'A' && 
   	   board[addressOfArray(targetCol,targetRow)] <  'Z'){

   		targetValue = 0;
   		}

   	if(board[addressOfArray(sourceCol,sourceRow)] == 'n' && 
   	   board[addressOfArray(targetCol,targetRow)] >  'a' && 
   	   board[addressOfArray(targetCol,targetRow)] <  'z'){

   		targetValue = 0;
   		}

   	}

   	return targetValue;
}

int addressOfArray(char col,int row){

	return (8 - row)*8 + (col - 'a');
}

int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

   int i;
   int targetValue = 0;

   /*Finding the located can go rook and the testing target rows and column is in there */

   if(targetCol == sourceCol || targetRow ==sourceRow){
      targetValue = 1;
   }

   if(targetValue == 0){
      return targetValue;
   }

   /*Testing is there a piece in between target and source location*/ 

   if(sourceRow > targetRow){
      for(i=sourceRow-1;i>targetRow;--i){
         if(board[addressOfArray(sourceCol,i)] != ' '){
            targetValue = 0;
         }
      }
   }

   if(targetRow > sourceRow){
      for(i=sourceRow+1;i<targetRow;++i){
         if(board[addressOfArray(sourceCol,i)] != ' '){
            targetValue = 0;
         }
      }
   }

   if(sourceCol > targetCol){
      for(i=sourceCol-1;i>targetCol;--i){
         if(board[addressOfArray(i,sourceRow)] != ' '){
            targetValue = 0;
         }
      }
   }

   if(targetCol > sourceCol){
      for(i=sourceCol+1;i<targetCol;++i){
         if(board[addressOfArray(i,sourceRow)] != ' '){
            targetValue = 0;
         }
      }
   }

   /* Checking the  piece is valid in the target rows and columns */


   if(board[addressOfArray(sourceCol,sourceRow)] == 'R' && 
         board[addressOfArray(targetCol,targetRow)] >  'A' && 
         board[addressOfArray(targetCol,targetRow)] <  'Z'){

         targetValue = 0;
         }

   if(board[addressOfArray(sourceCol,sourceRow)] == 'r' && 
         board[addressOfArray(targetCol,targetRow)] >  'a' && 
         board[addressOfArray(targetCol,targetRow)] <  'z'){

         targetValue = 0;
         }
  
   if(board[addressOfArray(sourceCol,sourceRow)] == 'q' && 
         board[addressOfArray(targetCol,targetRow)] >  'a' && 
         board[addressOfArray(targetCol,targetRow)] <  'z'){

         targetValue = 0;
         }      
   if(board[addressOfArray(sourceCol,sourceRow)] == 'Q' && 
         board[addressOfArray(targetCol,targetRow)] >  'A' && 
         board[addressOfArray(targetCol,targetRow)] <  'Z'){

         targetValue = 0;
         }

   return targetValue;

}

int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

   int targetValue = 0;

   int i;

    /*Finding the located can go bishop and the testing target rows and column is in there */

   for(i=1;i<8;i++){

      if(sourceRow+i == targetRow && sourceCol+i == targetCol){
         targetValue = 1;

      }
      if(sourceRow-i == targetRow && sourceCol-i == targetCol){
         targetValue = 1;

      }
      if(sourceRow+i == targetRow && sourceCol-i == targetCol){
         targetValue = 1;

      }
      if(sourceRow-i == targetRow && sourceCol+i == targetCol){
         targetValue = 1;

      }

   }

   if(targetValue == 0){
      return targetValue;
   }

   /*Testing is there a piece in between target and source location*/ 

   for(i=1;i<fabs(targetRow - sourceRow);i++){
      
      if(targetRow>sourceRow && targetCol > sourceCol){         
         if(board[addressOfArray(sourceCol+i,sourceRow+i)] != ' '){
            targetValue = 0;
         }
      }
      
      if(targetRow<sourceRow && targetCol<sourceCol){      
         if(board[addressOfArray(sourceCol-i,sourceRow-i)] != ' '){
            targetValue = 0;
         }
      }
      
      if(targetRow>sourceRow && targetCol<sourceCol){      
         if(board[addressOfArray(sourceCol-i,sourceRow+i)] != ' '){
            targetValue = 0;
         }
      }
      
      if(targetRow<sourceRow && targetCol > sourceRow){   
         if(board[addressOfArray(sourceCol+i,sourceRow-i)] != ' '){
            targetValue = 0;
         }
      }
         
   }

  	/* Checking the  piece is valid in the target rows and columns */

   if(board[addressOfArray(sourceCol,sourceRow)] == 'B' && 
         board[addressOfArray(targetCol,targetRow)] >  'A' && 
         board[addressOfArray(targetCol,targetRow)] <  'Z'){

         targetValue = 0;
         }

   if(board[addressOfArray(sourceCol,sourceRow)] == 'b' && 
         board[addressOfArray(targetCol,targetRow)] >  'a' && 
         board[addressOfArray(targetCol,targetRow)] <  'z'){

         targetValue = 0;
         }
 
    if(board[addressOfArray(sourceCol,sourceRow)] == 'q' && 
         board[addressOfArray(targetCol,targetRow)] >  'a' && 
         board[addressOfArray(targetCol,targetRow)] <  'z'){

         targetValue = 0;
         }      

   if(board[addressOfArray(sourceCol,sourceRow)] == 'Q' && 
         board[addressOfArray(targetCol,targetRow)] >  'A' && 
         board[addressOfArray(targetCol,targetRow)] <  'Z'){

         targetValue = 0;
         }  

   return targetValue; 
}

int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

   int targetValue = 0;

   /*to combine the bishop and rook functions for queen movable */

   if(isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow) ||
      isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow)){

      targetValue = 1;
   }


   return targetValue;
}


int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

   int targetValue = 0;

   int i,j;

    /*Finding the located can go king and the testing target rows and column is in there */

   for(i=-1;i<2;++i){
      for(j=-1;j<2;j++){
         if(sourceCol+i == targetCol && sourceRow+j == targetRow){
            targetValue = 1;
         }
      }
   }

   if(targetValue == 0){
      return targetValue;
   }

  	/* Checking the  piece is valid in the target rows and columns */

   if(board[addressOfArray(sourceCol,sourceRow)] == 'K' && 
         board[addressOfArray(targetCol,targetRow)] >  'A' && 
         board[addressOfArray(targetCol,targetRow)] <  'Z'){

         targetValue = 0;
         }

   if(board[addressOfArray(sourceCol,sourceRow)] == 'k' && 
         board[addressOfArray(targetCol,targetRow)] >  'a' && 
         board[addressOfArray(targetCol,targetRow)] <  'z'){

         targetValue = 0;
         }

   return targetValue;

}

int isPawnsMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

   int targetValue = 0;
   int i;

   /* lowercase pawns movable*/

   if(board[addressOfArray(sourceCol,sourceRow)] == 'p'){
      

    /*Finding the located can go pawn and the testing target rows and column is in there */

      for(i=-1;i<2;++i){
         if(sourceCol +i == targetCol && sourceRow -1 == targetRow){
            targetValue = 1;
         }
      }

      if(targetValue == 0){
         return targetValue;
      }

      /* Checking the  piece is valid in the target rows and columns */

      if((sourceCol -1 == targetCol && sourceRow - 1 == targetRow) || 
         (sourceCol +1 == targetCol && sourceRow - 1 == targetRow)){
         if((board[addressOfArray(targetCol,targetRow)] <= 'h' &&
             board[addressOfArray(targetCol,targetRow)] >= 'a') ||
             board[addressOfArray(targetCol,targetRow)] == ' '){
               targetValue = 0;
               return targetValue;
         }

      }   

      if(sourceCol == targetCol && sourceRow -1 == targetRow ){
         if(board[addressOfArray(targetCol,targetRow)] != ' '){               targetValue = 0;
            return targetValue;
         }
      }   
      
   }

	/* uppercase pawns movable*/

   if(board[addressOfArray(sourceCol,sourceRow)] == 'P'){
      
   	/*Finding the located can go pawn and the testing target rows and column is in there */
     
      for(i=-1;i<2;++i){
         if(sourceCol +i == targetCol && sourceRow +1 == targetRow){
            targetValue = 1;
         }
      }

      if(targetValue == 0){
         return targetValue;
      }

       /* Checking the  piece is valid in the target rows and columns */

      if((sourceCol -1 == targetCol && sourceRow + 1 == targetRow) || 
         (sourceCol +1 == targetCol && sourceRow + 1 == targetRow)){
         if((board[addressOfArray(targetCol,targetRow)] <= 'H' &&
             board[addressOfArray(targetCol,targetRow)] >= 'A') ||
             board[addressOfArray(targetCol,targetRow)] == ' '){
               targetValue = 0;
               return targetValue;
         }

      }   

      if(sourceCol == targetCol && sourceRow +1 == targetRow ){
         if(board[addressOfArray(targetCol,targetRow)] != ' '){               targetValue = 0;
            return targetValue;
         }
      }   

      
   }

   return targetValue;

}





    