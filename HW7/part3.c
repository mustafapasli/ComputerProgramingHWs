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
#include <math.h>
#define PI 3.1415
/*---------------------------------------------------------------------------*/
/*							Function Prototypes  							 */
/*---------------------------------------------------------------------------*/
double radianAngle(double angle);

int reflection(int angle);

int randNumber(int angle);

int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth);

int 
main(){
	
	printf("%d\n",kickDisc(10,20,2,135,1,10));

	return 0;

}


/*---------------------------------------------------------------------------*/
/*						Function Implementations							 */
/*---------------------------------------------------------------------------*/


int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth){


	int isGoal = 1; 

	if(kickAngle>175 || kickAngle < 5){
		isGoal = 0;

		return isGoal;		
	}

	/*RECURSİVE CASE*/

	if(kickAngle > 90 && 
		wallHeight > (ballCenterX)*fabs(tan(radianAngle(kickAngle)))){
		

		wallHeight = wallHeight - (wallWidth-ballCenterX)*fabs(tan(radianAngle(kickAngle)));

		ballCenterX = 0;

		kickAngle = reflection(kickAngle);

		isGoal =  kickDisc(wallWidth,wallHeight,ballCenterX,kickAngle,ballRadius,goalWidth);		
	}

	if(kickAngle <= 90 && 
	    wallHeight > (wallWidth-ballCenterX)*fabs(tan(radianAngle(kickAngle)))){
		

		wallHeight = wallHeight - (wallWidth-ballCenterX)*fabs(tan(radianAngle(kickAngle)));

		ballCenterX = 0;

		kickAngle = reflection(kickAngle);

		isGoal =  kickDisc(wallWidth,wallHeight,ballCenterX,kickAngle,ballRadius,goalWidth);		
	}

	/* BASE CASE */

	if(wallHeight < (wallWidth-ballCenterX)*fabs(tan(radianAngle(kickAngle)))){
		
		if(((ballCenterX+wallHeight-ballRadius/fabs(tan(radianAngle(reflection(kickAngle)))))<((wallWidth+goalWidth)/2))          
			                              && 
		   ((ballCenterX+wallHeight-ballRadius/fabs(tan(radianAngle(reflection(kickAngle)))))>((wallWidth-goalWidth)/2))){
		
			isGoal = 1;

		}else
			isGoal = 0;
		
	}

	return isGoal;

}

double radianAngle(double angle){

	return (2 * PI * angle) / 360;
}

int reflection(int angle){

	return angle + (((randNumber(angle))%10)-5);
}

int randNumber(int angle){

	srand(angle);

	return rand();

}


