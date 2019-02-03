/*--------------------------------------------------------------------------*/
/*																			*/
/* HW09_131044032_Mustafa_Paslı                                             */
/*																			*/
/* main.c    																*/
/* ---------																*/
/* Created on 29/04/2016 by Mustafa_Paslı 									*/
/*																			*/
/*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

typedef struct{
	char name[100][25];
	int pops[100];
	int kmSquares[100];
	int numberOfSoldiers[100];
	char neighbors[100][10][25];
}country;

/*---------------------------------------------------------------------------*/
/*							Function Prototypes  							 */
/*---------------------------------------------------------------------------*/
int recursiveD(country countries,char *findingName,char *findingName2);

int 
main(){

	country countries;

	char switchCase;
	char findingName[25];
	char findingName2[25];


	int i = 0;
	int j = 0;
	
	int finishNeighborVelue = 0;
	
	int maxNumberOfSoldiers = 0;
	int maxWidthOfCountry  = 0;


	int indexOfName;
	int strongIndex;

	int k,l,m,n;

	/* Reset struct values*/

	for(i=0;i<100;i++){
		strcpy(countries.name[i],"-1");
		countries.pops[i] = -1;
		countries.kmSquares[i] = -1;
		countries.numberOfSoldiers[i] = -1;
		
		for(j=0;j<10;j++){
			strcpy(countries.neighbors[i][j],"-1");
		}
	}

	i=0;
	j=0;



	printf("Make your choice:\n");

	scanf(" %c",&switchCase);

	while(switchCase != 'e'){
		
		switch(switchCase){
			case 'a':
			
			if(i<100){

				scanf("%s",countries.name[i]);
				scanf("%d",&countries.pops[i]);				
				scanf("%d",&countries.kmSquares[i]);				
				scanf("%d",&countries.numberOfSoldiers[i]);				
				
				scanf("%d",&finishNeighborVelue);
				
				if(finishNeighborVelue != -1){
						scanf("%s",countries.neighbors[i][j]);
					}

				while(finishNeighborVelue != -1){
					
					j++;

					scanf("%d",&finishNeighborVelue);

					if(finishNeighborVelue != -1){
						scanf("%s",countries.neighbors[i][j]);
					}
					
					if(finishNeighborVelue == -1){
						j=0;
					}

					if(j==9){
						finishNeighborVelue = -1;
						j = 0;
					}

				}

			i++;
			finishNeighborVelue = 0;
			}

			break;

			case 'b':

			maxNumberOfSoldiers = 0;
			indexOfName = 0;
			strongIndex = 0;

			scanf("%s",findingName);

		
			/*finding index of country in struct*/
			
			for(k=0;k<100;k++){
				if(strcmp(countries.name[k],findingName)==0){
					maxNumberOfSoldiers = countries.numberOfSoldiers[k];
					indexOfName = k;
					strongIndex = k;

				}
			}

			/*finding neighbors of country in the struct and compare the values*/ 

			for(k=0;k<100;k++){
				for(l=0;l<10;l++){
					
					if(strcmp(countries.name[k],
						countries.neighbors[indexOfName][l])==0){
						
						if(countries.numberOfSoldiers[k]>maxNumberOfSoldiers){
							maxNumberOfSoldiers=countries.numberOfSoldiers[k];
							strongIndex = k;
						}

						/*finding neighbors of neighbors of country in the struct and compare the values*/


						for(m=0;m<100;m++){
							for(n=0;n<10;n++){
								if(strcmp(countries.name[m],countries.neighbors[k][n])==0){

									if(countries.numberOfSoldiers[m]>maxNumberOfSoldiers){
										maxNumberOfSoldiers=countries.numberOfSoldiers[m];
										strongIndex = m;
									}
								}
							}
						}
					}
				}
			}

			printf("%s\n",countries.name[strongIndex]);


			break;

			case 'c':

			maxWidthOfCountry = 0;
			indexOfName = 0;
			strongIndex = 0;

			scanf("%s",findingName);
			/*finding index of country in struct*/
			for(k=0;k<100;k++){
				if(strcmp(countries.name[k],findingName)==0){
					maxWidthOfCountry = countries.kmSquares[k];
					indexOfName = k;
					strongIndex = k;

				}
			}

			/*finding neighbors of country in the struct and compare the values*/ 


			for(k=0;k<100;k++){
				for(l=0;l<10;l++){
					
					if(strcmp(countries.name[k],countries.neighbors[indexOfName][l])==0){
						if(countries.kmSquares[k]>maxWidthOfCountry){
							maxWidthOfCountry=countries.kmSquares[k];
							strongIndex = k;
						}
						/*finding neighbors of neighbors of country in the struct and compare the values*/

						for(m=0;m<100;m++){
							for(n=0;n<10;n++){
								if(strcmp(countries.name[m],countries.neighbors[k][n])==0){

									if(countries.kmSquares[m]>maxWidthOfCountry){
										maxWidthOfCountry=countries.kmSquares[m];
										strongIndex = m;
									}
								}
							}
						}
					}
				}
			}
			printf("%s\n",countries.name[strongIndex]);

			break;
			case 'd':

			scanf("%s",findingName);
			scanf("%s",findingName2);

			printf("%d",recursiveD(countries,findingName,findingName2));

			break;
			default:printf("wrong character\n");
		}
		printf("Make your choice:\n");

		scanf(" %c",&switchCase);
	}

	return 0;
}

/*---------------------------------------------------------------------------*/
/*						Function Implementations							 */
/*---------------------------------------------------------------------------*/

int recursiveD(country countries,char *sourceName,char *targetName){

	int k,l ,indexOfName;

	int totalPops = 0;

	for(k=0;k<100;k++){
		if(strcmp(countries.name[k],sourceName)==0){
			indexOfName = k;
		}
	}

	if(indexOfName ==99){

		return 0;;
	}

	printf("%d\n",indexOfName );
	
	for (k=0;k<10;k++){

		if(strcmp(countries.neighbors[indexOfName][k],targetName)==0){
			for(l=0;l<100;l++){
				if(strcmp(countries.name[l],countries.neighbors[indexOfName][k])==0){
					printf("ACCESSIBLE\n");
					return countries.pops[l];
				}

			}
		}
	}
	

		
	for(k=0;k<10;k++){	
		
		totalPops += recursiveD(countries,countries.neighbors[indexOfName][k],targetName);

	}



	return totalPops;
	

	
}



