#include <stdio.h>
#define PI 3.14


int areaofRectangle(int width, int height);
int perimeterOfRectangle(int width,int height);
double areaofCircle(int radius);
double perimeterOfCircle(int radius);

int main() {

	int width,height;
	int radius;

	printf("Please enter the width of the rectangle:");
	scanf("%d",&width);

	printf("Please enter the height of of the rectangle:");
	scanf("%d",&height);

	printf("The area of the rectangle is: %d\n",areaofRectangle(width,height));
	printf("The perimeter of the rectangle is: %d\n",perimeterOfRectangle(width,height));

	printf("Please enter the width of the square:");
	scanf("%d",&width);

	printf("The area of the square is: %d\n",areaofRectangle(width,width));
	printf("The perimeter of the square is: %d\n", perimeterOfRectangle(width,width));

	printf("Please enter the radius of the circle:");
	scanf("%d",&radius);

	printf("The area of the circle is: %f\n",areaofCircle(radius));
	printf("The perimeter of the circle is: %f\n",perimeterOfCircle(radius));




	
	return 0;

}

int areaofRectangle(int width,int height){
	return(width*height);
}

int perimeterOfRectangle(int width,int height){
	return(width+width+height+height);
}

double areaofCircle(int radius){
	return (PI * radius * radius);
}

double perimeterOfCircle(int radius){
	return(2 * PI * radius);
}