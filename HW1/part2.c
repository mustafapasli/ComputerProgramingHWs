/*--------------------------------------------------------------------------*/
/*																			*/
/*HW01_131044032_Mustafa_Paslı												*/
/*																			*/
/*part2.c																	*/
/*--------																	*/
/*Created on 22/02/2016 by Mustafa_Paslı 									*/
/*																			*/
/*Description 																*/
/*------------																*/
/*	The part2.c contains a program that calculates how many days the    	*/
/*	the user has lived in the world and another planet. 					*/
/*																			*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*								Icludes										*/
/*--------------------------------------------------------------------------*/

#include <stdio.h>

int main(){

	int cYear,cMonth,cDay;		/*Current Year,Month,Day 			*/
	int bYear,bMonth,bDay;		/*Birth Year,Month,Day 				*/

	int totalDate;				/* The number of days lived         */

	int hoursPlanet,daysPlanet,monthsPlanet ;/*Informations of anather planet*/
	
	int planetYears,planetMonths,planetDays ;/*The number of years,months,days 											   lived another planet   	    */

	int totalTime;             	/*The number of times lived in the world*/
	int totalPlanetDate;		/*The number of days lived in the planet*/


	printf("Please enter the current date.\n");
	
	printf("Year:\n");
	scanf("%d",&cYear);

	printf("Month:\n");
	scanf("%d",&cMonth);
	
	printf("Day:\n");
	scanf("%d",&cDay);


	printf("Please enter the birthday.\n");

	printf("Year:\n");
	scanf("%d",&bYear);

	printf("Month:\n");
	scanf("%d",&bMonth);
	
	printf("Day:\n");
	scanf("%d",&bDay);

	totalDate = ((cYear-bYear)*365)+((cMonth-bMonth)*30)+(cDay-bDay);

	printf("You have lived %d days.",totalDate);

	printf("Please enter about the time of another planet:");

	printf("How many hours is a day? ");
	scanf("%d",&hoursPlanet);

	printf("How many days in a month? ");
	scanf("%d",&daysPlanet);

	printf("How many months in a year? ");
	scanf("%d",&monthsPlanet);

	totalTime = totalDate * 24 ;

	totalPlanetDate = totalTime / hoursPlanet;

	planetYears = totalPlanetDate/ (daysPlanet * monthsPlanet);

	planetMonths = (totalPlanetDate / 10 ) % 20 ;

	planetDays= (totalPlanetDate % monthsPlanet);

	/*------------------------Printing results-------------------------------*/

	printf("If you lived in a planet where a day is %d hours,a month is %d days and a year is %d months: you were %d years, %d months and %d days old\n}" ,hoursPlanet,daysPlanet,monthsPlanet,planetYears, planetMonths,planetDays);

	
	return 0;

}


/*---------------------------------------------------------------------------*/
/*                             End of main.c 								 */
/*---------------------------------------------------------------------------*/