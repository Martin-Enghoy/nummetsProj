#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int degreeEq;
	float arr[20];
	
	//Ask for the degree of the equation
	printf("What is the degree of your equation?\n");
	scanf("%i", &degreeEq);
	
	for(int i=0; i<degreeEq; i++){
		printf("What is the coefficient of term %i?\n", i+1);
		scanf("%.5f\n", &arr[i]);
	}
	return 0;
}
