#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void bisect(float x, float y, float *z);
void raphson(float x, float y, float z);
void bairstow(float x, float y, float z);





int main(){
	float aveErr = 0.01; //Stopping Percent
	int iter = 10; //Stopping iterations
	float xMid;
	float  xLow, xUp; // Bisection variables
	int choice, degreeEq;
	float arr[20];
	
	//Ask for the degree of the equation
	printf("What is the degree of your equation?");
	scanf("%i", &degreeEq);
	
	for(int i=0; i<degreeEq; i++){
		printf("What is the coefficient of term %i?", degreeEq);
		scanf("%.5f", &arr[i]);
	}
	
	
	while(!isDigit(choice)){
		printf("Choose a nummerical method to solve for the equation: ");
		printf("1. Bisection Method");
		printf("2. Newton Raphson Method");
		printf("3. Bairstow Method");
		scanf("%i", &choice);
	
		if(!isDigit(choice)){
			printf("Please input an integer!");
		}
	}

	
	if(choice == 1){ //Bisection method
		bisect(xLow, xUp, &xMid);
	}
	else if(choice == 2){ //Raphson method
		
	}
	else if(choice == 3){ //Bairstow method
	}
	
	return 0;	
}

void bisect(float x, float y, float *z){
	z = (x+y)/2; // Midpoint (bisecting)
	
	
	
	return;
}

void raphson(int x, int y, int z){
	
	
	
}

void bairstow(int x, int y, int z){
	
}
