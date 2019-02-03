/*--------------------------------------------------------------------------*/
/*																			*/
/*HW01_131044032_Mustafa_Paslı												*/
/*																			*/
/*part1.c																	*/
/*--------																	*/
/*Created on 05/03/2016 by Mustafa_Paslı 									*/
/*																			*/
/*Description 																*/
/*------------																*/
/*	The part1.c contains simple program that calculates the overall			*/
/*	grade of the students.													*/
/*																			*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*								Icludes										*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>

int main(){

	double fMW,sMW,tMW;		/*First,second,third midterm weight	*/
	double fHW,sHW;			/*First,second homework weight		*/
	double eW;				/*Final exam weight					*/

	double fMG,sMG,tMG;		/*First,second,third midterm grade	*/
	double fHG,sHG;			/*First,second homework grade		*/
	double eG;				/*Final exam grade					*/

	double fG;				/*Final grade						*/


/*						Input Output Functions 								*/


	printf("Please enter the 1. midterm weight: ");
	scanf("%lf",&fMW);

	printf("Please enter the 2. midterm weight: ");
	scanf("%lf",&sMW);
                             
	printf("Please enter the 3. midterm weight: ");
	scanf("%lf",&tMW);

	printf("Please enter the 1. homework weight: ");
	scanf("%lf",&fHW);

	printf("Please enter the 2. homework weight: ");
	scanf("%lf",&sHW);

	printf("Please enter the final exam weight: ");
	scanf("%lf",&eW);

	printf("Please enter the 1. midterm grade: ");
	scanf("%lf",&fMG);

	printf("Please enter the 2. midterm grada: ");
	scanf("%lf",&sMG);

	printf("Please enter the 3. midterm grada: ");
	scanf("%lf",&tMG);

	printf("Please enter the 1. homework grada: ");
	scanf("%lf",&fHG);

	printf("Please enter the 2. homework grada: ");
	scanf("%lf",&sHG);


	printf("Please enter the final exam grada: ");
	scanf("%lf",&eG);

	/*						Final grade calculation							*/

	fG = (fMG*fMW/100)+(sMG*sMW/100)+(tMG*tMW/100)+(fHG*fHW/100)+(sHG
		*sHW/100)+(eG*eW/100);

	/* 							Printing result								 */

	printf("Your final grade is; %f",fG);





	return 0;

}

/*---------------------------------------------------------------------------*/
/*                             End of main.c 								 */
/*---------------------------------------------------------------------------*/
