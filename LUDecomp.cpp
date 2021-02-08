#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float getCoeff(int deg, float coeff[]);
float func(float x, float coeff[], int deg);

int main(){
	
	float Xm, Xu, Xl; // Values
	float fXm, fXu, fXl; // Functions
	int degreeEq;
	float arr[3][3]; // array for coefficients
	float constants[3], x[3], z[3], roots[3], lArr[3][3], uArr[3][3];
	float outArr[200]; // array for table printing
	int counter = 0,i,j; // For counting the array items
	int iter=0, mIter; // Stopping Parameter
	float tempArr[3], temp2Arr[3];
	float Ea; //Average Error %
	
	
	printf("-------LU Decomposition-------\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("row #%i, column #%i: ", i+1,j+1);
			scanf("%f", &arr[i][j]);
		}
	}
	
	for(i=0; i<3; i++){
		printf("What is the value of coefficient #%i? ", i+1);
		scanf("%f", &x[i]);
	}
	
	for(i=0; i<3; i++){
		printf("%18.5f %18.5f %18.5f  %18.5f\n", trunc(arr[i][0]*100000.0)/100000.0, trunc(arr[i][1]*100000.0)/100000.0, trunc(arr[i][2]*100000.0)/100000.0, trunc(x[i]*100000.0)/100000.0);
	}
	
	lArr[1][0] = arr[1][0] / arr[0][0]; // row 2 column 1 first 
	lArr[1][1] = 1.00; //row 2 col 2
	lArr[1][2] = 0.00; //row 2 col 3
	
	lArr[2][0] = arr[2][0] / arr[0][0]; // row 3 column 1 second
	
	
	for(i=0; i<3; i++){
		uArr[0][i] = arr[0][i];
		
		tempArr[i] = lArr[1][0] * arr[0][i];
		uArr[1][i] = arr[1][i] - tempArr[i];
		printf("-%18.5f\n", uArr[1][i]);
		
		tempArr[i] = lArr[2][0] * arr[0][i];
		uArr[2][i] = arr[2][i] - tempArr[i];
		printf("-%18.5f\n", uArr[2][i]);
	}
	
	lArr[2][1] = uArr[2][1] / uArr [1][1]; // row 3 column 2 (3rd value)
	lArr[2][2] = 1.00;
	
	uArr[2][1] = uArr[2][1] - (uArr[1][1] * lArr[2][1]);
	uArr[2][2] = uArr[2][2] - (uArr[1][2] * lArr[2][1]);
	printf("--%18.5f\n", uArr[2][2]);
	
	lArr[0][0] = 1.00;
	lArr[0][1] = 0.00;
	lArr[0][2] = 0.00;
	
	printf("----- U -----\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%18.5f ", trunc(uArr[i][j]*100000.0)/100000.0);
		}
		printf("\n");
	}
	
	printf("----- L -----\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%18.5f ", trunc(lArr[i][j]*100000.0)/100000.0);
		}
		printf("\n");
	}
	
	
	printf("----- Computing for Z -----\n\n");
	z[0] = x[0];
	z[1] = x[1] - lArr[1][0]*z[0];
	z[2] = x[2] - lArr[2][0]*z[0] - lArr[2][1]*z[1];
	
	for(i=0; i<3; i++){
		printf("Z%i = %18.5f\n", i+1, trunc(z[i]*100000.0)/100000.0);
	}
	
	printf("----- Computing for X -----\n\n");
	roots[0] = z[2] / uArr[2][2];
	roots[1] = (z[1] - uArr[1][2]*roots[0]) / uArr[1][1];
	roots[2] = (z[0] - uArr[0][1]*roots[1] - uArr[0][2]*roots[0]) / uArr[0][0];
	
	
	printf("\n\nThe Roots are.........Loading.....\n");
	counter = 1;
	for(i=2; i>=0; i--){
		printf("X%i = %18.5f\n", counter, trunc(roots[i]*100000.0)/100000.0);
		counter++;
	}
	
	return 0;
}	


float getCoeff(int deg, float coeff[]){
	
	for(int i=0; i<=deg; i++){
		if(i == deg){
			printf("Constant term: ");
			scanf("%f", &coeff[i]);
		}
		else{
			printf("Coefficient of x^%d: ", deg-i);
			scanf("%f", &coeff[i]);
		}
	}
	
	return *coeff;
}

float func(float x, float coeff[], int deg){
	float ftotal=0, tempval=0;
	for(int i=0; i<=deg; i++){
		tempval=1;
		for(int j=i; j<deg; j++){
			tempval = tempval*x;
		}
		ftotal = ftotal + (coeff[i]*tempval);
	}
	return ftotal;
}


