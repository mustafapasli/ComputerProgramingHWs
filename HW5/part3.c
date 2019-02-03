#include <stdio.h>
#include <math.h>

int addressOfArray(char col,int row);
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isPawnsMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);

int 
main(){

	char sourceCol = 'a';
	int sourceRow= 2;

	char targetCol = 'a';
	int targetRow = 3;

	


	char board[64] = {'r','n','b','q','k','b','n','r',
	   		  	      ' ','p',' ',' ',' ','p','p','p',
	    		         ' ','R',' ',' ','p',' ',' ',' ',
	    	 	         ' ',' ',' ','b',' ',' ',' ',' ',
	    		         ' ',' ',' ',' ',' ',' ',' ',' ',
	     		         'p','p',' ',' ',' ',' ',' ',' ',			 
         		      'P','P','P','P','P','P','P','P',
          		      'R','N','B','Q','K','B','N','R'};

   printf("move is %d\n",isPawnsMovable(board,sourceCol,sourceRow,targetCol,targetRow));                  


	return 0;

}
int addressOfArray(char col,int row){

	return (8 - row)*8 + (col - 'a');
}

int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

	int i;
	
	int targetValue = 0;


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

   if(targetCol == sourceCol || targetRow ==sourceRow){
      targetValue = 1;
   }

   if(targetValue == 0){
      return targetValue;
   }

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


   /*for(i=1;i<9;++i){
      if(sourceCol == targetCol && i == targetRow){
         targetValue = 1;
      }
      if('a' + i -1 == targetCol && sourceRow == targetRow){
         targetValue = 1;
      }
   }
   */

   return targetValue;

}

int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

   int targetValue = 0;

   int i;

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

   if(isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow) ||
      isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow)){

      targetValue = 1;
   }


   return targetValue;
}

int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){


   int targetValue = 0;

   int i,j;

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




   /*

   if(sourceCol +1 == targetCol && sourceRow +1 == targetRow){targetValue = 1;}
   if(sourceCol +1 == targetCol && sourceRow -1 == targetRow){targetValue = 1;}
   if(sourceCol -1 == targetCol && sourceRow +1 == targetRow){targetValue = 1;}
   if(sourceCol -1 == targetCol && sourceRow -1 == targetRow){targetValue = 1;}
   if(sourceCol +1 == targetCol && sourceRow == targetRow){targetValue = 1;}
   if(sourceCol -1 == targetCol && sourceRow == targetRow){targetValue = 1;}
   if(sourceCol == targetCol && sourceRow +1 == targetRow){targetValue = 1;}
   if(sourceCol == targetCol && sourceRow -1 == targetRow){targetValue = 1;}


   */

   return targetValue;

}

int isPawnsMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow){

   int targetValue = 0;
   int i;

   if(board[addressOfArray(sourceCol,sourceRow)] == 'p'){
      for(i=-1;i<2;++i){
         if(sourceCol +i == targetCol && sourceRow -1 == targetRow){
            targetValue = 1;
         }
      }

      if(targetValue == 0){
         return targetValue;
      }

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
      for(i=-1;i<2;++i){
         if(sourceCol +i == targetCol && sourceRow +1 == targetRow){
            targetValue = 1;
         }
      }

      if(targetValue == 0){
         return targetValue;
      }

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


