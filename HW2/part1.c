#include <stdio.h>

void calculateLastGrade();

int main () {

	calculateLastGrade();
	calculateLastGrade();
	calculateLastGrade();

	return 0;


}

void calculateLastGrade(){

	double midtermWeight,midtermGrade;
	double homeworkWeight,homeworkGrade;
	double finalExamWeight,finalExamGrade;
	double finalGrade;

	printf("Please enter the 1. midterm weight:");
	scanf("%lf",&midtermWeight);

	printf("Please enter the 1. homework weight:");
	scanf("%lf",&homeworkWeight);

	printf("Please enter the final exam weight:");
	scanf("%lf",&finalExamWeight);

	printf("Please enter the 1. midterm grade:");
	scanf("%lf",&midtermGrade);

	printf("Please enter the 1. homework grade:");
	scanf("%lf",&homeworkGrade);

	printf("Please enter the final exam grade:");
	scanf("%lf",&finalExamGrade);

	finalGrade = (midtermGrade*midtermWeight/100) + (homeworkGrade
		*homeworkWeight/100) + (finalExamGrade*finalExamWeight/100);

	printf("Your final grade is: %f\n",finalGrade);



}