
/*--------------------------------------------------------------------------*/
/*                                      */
/* HW08_131044032_Mustafa_Paslı                                             */
/*                                      */
/* main.c                                   */
/* ---------                                */
/* Created on 22/04/2016 by Mustafa_Paslı                   */
/*                                      */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                     Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#define BOARD_SIZE 8
/*---------------------------------------------------------------------------*/
/*              Function Prototypes                */
/*---------------------------------------------------------------------------*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);
int isInCheck(char* board);
int makeMove(char *board, char sc, int sr, char tc, int tr);
char getPlayer(char * board, char sc, int sr);
int addressOfArray(char col,int row);
int isWhite(char currPlayer);
int isBlack(char currPlayer);
void initBoard(char *board);
void printBoard(char *board);
void getPosition(char *col, int *row);
int isValidCell(char col,int row);
int makeMove(char *board,char sc,int sr,char tc,int tr);
int isInCheck(char *board);
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int  targetRow);
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);

int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do 
    {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n ");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
	
	printf("%s player WINS!\n", player ? "Black" : "White");
    
    return 0;
}

/*---------------------------------------------------------------------------*/
/*            Function Implementations               */
/*---------------------------------------------------------------------------*/

int isPieceMovable(char *board, char sc, int sr, char tc, int tr){

	char sourceCol = sc,targetCol =tc;
	int sourceRow =sr,targetRow = tr;

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

			if(isPawnMovable(board,sourceCol,sourceRow,targetCol,targetRow)){
				return 1;
			}else 
				return 0;
	}
	if(board[addressOfArray(sourceCol,sourceRow)] == ' '){

		return 0;
	}
	return 1;
}


int isInCheck(char *board)
{

	int i,j;
	int kingRow;        		      
	char kingCol;
	int kingStatus = 0;

    /*finding check status white player*/

		for(i=1;i<=8;i++)
		{	
			for(j=0;j<8;j++)
			{
				if(getPlayer(board,'a'+j,i) == 'K')
				{
					kingRow = i;
					kingCol = 'a' + j;
				}
			}	

		}	

		for(i=1;i<=8;i++)
		{	
			for(j=0;j<8;j++)
			{
				if(getPlayer(board,'a'+j,i)=='r' && isRookMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 1;
				}
				if(getPlayer(board,'a'+j,i)=='n' && isKnightMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 1;
				}
				if(getPlayer(board,'a'+j,i)=='b' && isBishopMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 1;
				}
				if(getPlayer(board,'a'+j,i)=='q' && isQueenMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 1;
				}
				if(getPlayer(board,'a'+j,i)=='k' && isKingMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 1;
				}
				if(getPlayer(board,'a'+j,i)=='p' && isPawnMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 1;
				}
			}
		} 

    /*finding check status black player*/

		for(i=1;i<=8;i++)
		{	
			for(j=0;j<8;j++)
			{
				if(getPlayer(board,'a'+j,i) == 'k')
				{
					kingRow = i;
					kingCol = 'a' + j;
				}
			}	

		}	

		for(i=1;i<=8;i++)
		{	
			for(j=0;j<8;j++)
			{
				if(getPlayer(board,'a'+j,i)=='R' && isRookMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 2;
				}
				if(getPlayer(board,'a'+j,i)=='N' && isKnightMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 2;
				}
				if(getPlayer(board,'a'+j,i)=='B' && isBishopMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 2;
				}
				if(getPlayer(board,'a'+j,i)=='Q' && isQueenMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 2;
				}
				if(getPlayer(board,'a'+j,i)=='K' && isKingMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 2;
				}
				if(getPlayer(board,'a'+j,i)=='P' && isPawnMovable(board,'a'+j,i,kingCol,kingRow))
				{
					kingStatus = 2;
				}
			}
		} 

		return kingStatus;	
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

char getPlayer(char * board,char sc,int sr)
{

 	return board[addressOfArray(sc,sr)];

}

int addressOfArray(char col,int row)
{

	return (8 - row)*8 + (col - 'a');
}

int isWhite(char currPlayer)
{
	if(currPlayer<='Z' && currPlayer >= 'A')
	{
		return 1;
	}
	else
		return 0;
}

int isBlack(char currPlayer)
{
	if(currPlayer <= 'z' && currPlayer >= 'a')
	{
		return 1;
	}
	else
		return 0;
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

int makeMove(char *board, char sc, int sr, char tc, int tr)
{
	char currPlayer = getPlayer(board,sc,sr);

	char board1[64];

	int i;

  /*if there is a check case,peaces play on the another board*/ 

	for(i=0;i<64;i++){
		board1[i] = board[i];
	}
	board1[addressOfArray(tc,tr)] = board1[addressOfArray(sc,sr)];
	board1[addressOfArray(sc,sr)] = ' ';

	if(isWhite(currPlayer) && isInCheck(board1) == 1){
			return 1;
		}

	if(isBlack(currPlayer) && isInCheck(board1) == 2){
			return 1;
		}


	if(isPieceMovable(board,sc,sr,tc,tr) == 0)
	{
		return 0;
	}


	if(isPieceMovable(board,sc,sr,tc,tr) == 1){
		
    /*if move is invalid*/
																		
		board[addressOfArray(tc,tr)] = board[addressOfArray(sc,sr)];
		board[addressOfArray(sc,sr)] = ' ';

    /*chech status after the moving */ 

		if(isWhite(currPlayer) && isInCheck(board) == 1){
			return 1;
		}

		if(isWhite(currPlayer) && isInCheck(board) == 2){
			return 3;
		}

		if(isBlack(currPlayer) && isInCheck(board) == 2){
			return 1;
		}

		if(isBlack(currPlayer) && isInCheck(board) == 1){
			return 3;
		}


		return 2;
	}

	return -1;
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

int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

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
  

   if(board[addressOfArray(sourceCol,sourceRow)] == 'P'){
     /* uppercase pawns movable*/

      
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