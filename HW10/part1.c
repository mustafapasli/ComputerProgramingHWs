/*--------------------------------------------------------------------------*/
/*																			*/
/* HW10_131044032_Mustafa_Paslı                                             */
/*																			*/
/* main.c    																*/
/* ---------																*/
/* Created on 06/05/2016 by Mustafa_Paslı 									*/
/*																			*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define STRZSIZE 30
#define MAX_STUDENTS_SIZE 100
#define MAX_LECTURER_SIZE 50
#define MAX_LECTURES_SIZE 200
#define MAX_SCHEDULES_SIZE 30
#define MAX_STUDENT_LECTURES_SIZE 500

typedef struct 
{
	int ID;
	char name[STRZSIZE];
	char surName[STRZSIZE];
}students;

typedef struct
{	
	char degree[STRZSIZE];
	int ID;
	char name[STRZSIZE];
	char surName[STRZSIZE];	
	
} lecturers;



typedef struct
{
	int code;
	char name[STRZSIZE];
	int ID;

} lectures;


typedef struct
{
	char className[STRZSIZE];
	char day[STRZSIZE];
	int startTime;
	int drtTime;
	int lctCode;

} schedules;


typedef struct 
{
	int stdntID;
	int lctCode;

}stdntLcts;



int 
main(){

	students student[MAX_STUDENTS_SIZE];
	lecturers lecturer[MAX_LECTURER_SIZE];
	lectures lecture[MAX_LECTURES_SIZE];
	schedules schedule[MAX_SCHEDULES_SIZE];
	stdntLcts stdntLct[MAX_STUDENT_LECTURES_SIZE];

	FILE *input;
	FILE *output;
	
	int studentsNumber,lecturersNumber,lecturesNumber,stdnLctsNumber,schedulesNumber;
	int i,j,k,m; /* counters */

	input = fopen("input.dat","rb+");
	output = fopen("output.txt","w");

	/*reading input binary file*/

	fread(&studentsNumber,sizeof(int),1,input);



	for(i=0;i<studentsNumber;i++){
		fread(&student[i],sizeof(students),1,input);
	}

	fread(&lecturersNumber,sizeof(int),1,input);



	for(i=0;i<lecturersNumber;i++){
		
		fread(&lecturer[i],sizeof(lecturers),1,input);
	
	}

	fread(&lecturesNumber,sizeof(int),1,input);

	

	for(i=0;i<lecturesNumber;i++){
		
		fread(&lecture[i],sizeof(lectures),1,input);
	
	}


	fread(&schedulesNumber,sizeof(int),1,input);



	for(i=0;i<schedulesNumber;i++){
		
		fread(&schedule[i],sizeof(schedules),1,input);
	
	}

	fread(&stdnLctsNumber,sizeof(int),1,input);



	for(i=0;i<stdnLctsNumber;i++){
		
		fread(&stdntLct[i],sizeof(stdntLcts),1,input);
	
	}

	/*printing informations to file*/

	fprintf(output, "Lecture-Lecturer\n");

	for(i=0;i<lecturesNumber;i++){
		fprintf(output, "%s ",lecture[i].name);

		for(j=0;j<lecturersNumber;j++){
			if(lecture[i].ID == lecturer[j].ID){	
				fprintf(output, "%s %s ",lecturer[j].name,lecturer[j].surName);
			}	
		}

		k=0;

		for(j=0;j<stdnLctsNumber;j++){	
			if(lecture[i].code == stdntLct[j].lctCode){
				k++;
			}
		}

		fprintf(output, "%d\n",k );	
	}

	fprintf(output, "\nStudent-Lecture \n" );

	for(i=0;i<studentsNumber;i++){

		k=0;

		for(j=0;j<stdnLctsNumber;j++){
			if(student[i].ID == stdntLct[j].stdntID){
				k++;
			}
		}

		fprintf(output, "%d %s %s%d\n",student[i].ID,student[i].name,student[i].surName,k);
	}

	fprintf(output, "\nStudent-Day \n" );

	for(i=0;i<studentsNumber;i++){

		m=0;

		fprintf(output, "%d %s %s",student[i].ID,student[i].name,student[i].surName);

		for(j=0;j<stdnLctsNumber;j++)
		{

			if(student[i].ID == stdntLct[j].stdntID)
			{
				for(k=0;k<schedulesNumber;k++)
				{	
					

					if(stdntLct[j].lctCode == schedule[k].lctCode)
					{
						m++;
						if(m!=1){
							fprintf(output, "," );
						}
						fprintf(output, " %s",schedule[k].day );
						
					}
				}
			}
		}

		fprintf(output, "\n" );
	
	}

	return 0;
}



