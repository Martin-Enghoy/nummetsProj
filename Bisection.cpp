#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


float func(float x, float coeff[], int deg);

int main(){
	
	float Xm, Xu=0.00000, Xl=0.00000; // Values
	float fXm = 0.00000, fXu = 0.00000, fXl = 0.00000; // Functions
	int degreeEq;
	double arr[20]; // array for coefficients
	double outArr[200]; // array for table printing
	int counter = 0; // For counting the array items
	int iter = 10; // Stopping Parameter
	float Ea; //Average Error %
	
	
	printf("What is the degree of your equation?\n");
	scanf("%i", &degreeEq);
	
	
	// Accepting Coefficients of the equation
	for(int i=0; i<degreeEq; i++){
		if(i==0){
			printf("What is the coefficient of the constant?\n");
			scanf("%f", &arr[i]);
		}
		else {
			printf("What is the coefficient of term %i?\n", i);
			scanf("%f", &arr[i]);
		}
	}
	
	//Init of Xl and Xu
	if(Xl == 0 && Xu == 0){
	printf("What is the initial value of Xl?\n");
	scanf("%f", &Xl);
	outArr[counter] = Xl;
	counter++;
	
	
	printf("What is the initial value of Xu\n");
	scanf("%f", &Xu);
	outArr[counter] = Xu;
	counter++;
	}
	
	Xm = (Xu+Xl)/2; // Midpoint (bisecting)
	outArr[counter] = Xm;
	counter++;
	
	for(int j=0; j<degreeEq; j++){ // Recursion for value of function Xu
		fXu = fXu + (arr[j]*pow(Xu,j));
	}
	outArr[counter] = fXu;
	counter++;
	
	for(int k=0; k<degreeEq; k++){ // Recursion for value of function Xl
		fXl = fXl + (arr[k]*pow(Xl,k));
	}
	outArr[counter] = fXl;
	counter++;
	
	for(int l=0; l<degreeEq; l++){ // Recursion for value of function Xm
		fXm = fXm + (arr[l]*pow(Xm,l));
	}
	outArr[counter] = fXm;
	counter++;
	
	
	
	printf("%.5f   %.5f   %.5f   %.5f   %.5f   %.5f\n", Xl, Xu, Xm, fXl, fXu, fXm); //Output line for this recursion
	
	if((fXu*fXm) < 0){
		Xu = Xm;
	}
	else if((fXu*fXm) > 0){
		Xl = Xm;
	}
	else if((fXu*fXm) == 0){
		printf("\nThe root of the equation has been found to be: %.5f", Xm);
	}
	else {
		printf("\nInvalid Output....");
	}
	
	
	
	
	
	return 0;
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


