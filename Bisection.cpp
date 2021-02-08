#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float getCoeff(int deg, float coeff[]);
float func(float x, float coeff[], int deg);

int main(){
	
	float Xm, Xu, Xl, pXm; // Values
	float fXm, fXu, fXl; // Functions
	int degreeEq;
	float arr[21]; // array for coefficients
	float outArr[200]; // array for table printing
	int counter = 0; // For counting the array items
	int iter=0, mIter; // Stopping Parameter
	float aveErr;
	float Ea; //Average Error %
	
	
	printf("-------Bisection Method-------\n");
	printf("What is the degree of your equation? (Max: 20)\n");
	scanf("%i", &degreeEq);
	
	*arr = getCoeff(degreeEq, arr);
	
	
	//Init of Xl and Xu
	printf("What is the initial value of Xl?\n");
	scanf("%f", &Xl);
	//outArr[counter] = Xl;
	//counter++;
	
	
	printf("What is the initial value of Xu\n");
	scanf("%f", &Xu);
	//outArr[counter] = Xu;
	//counter++;
	
	
	printf("How many iterations before stopping?\n");
	scanf("%i", &mIter);
	printf("How much (percent)error can be tolerated?\n");
	scanf("%f", &aveErr);
	
	
	Xm = (Xu+Xl) / 2.0; // Midpoint (bisecting)
	
	fXl = func(Xl, arr, degreeEq);
		
	fXu = func(Xu, arr, degreeEq);
	
	fXm = func(Xm, arr, degreeEq);
	
	printf("\n\nIter #                 Xl                   Xu                   Xm                f(Xl)                f(Xu)                 f(Xm)                 %%|Ea|\n");
	printf("%6d   %18.5f   %18.5f   %18.5f   %18.5f   %18.5f   %18.5f\n", iter, trunc(Xl*100000.0)/100000.0, trunc(Xu*100000.0)/100000.0, trunc(Xm*100000.0)/100000.0, trunc(fXl*100000.0)/100000.0, trunc(fXu*100000.0)/100000.0, trunc(fXm*100000.0)/100000.0);
	
	
	for(iter=1; iter<=mIter; iter++){
		pXm = Xm; //Temp storarge for Error
		
		if((fXl*fXm) < 0){
			Xu = Xm;
		}
		else if((fXl*fXm) > 0){
			Xl = Xm;
		}
		else if((fXl*fXm) == 0){
			printf("\nThe root of the equation has been found to be: %15.5f", trunc(Xm*10.0)/10.0);
		}
		else {
			printf("\nInvalid Output....");
		}
		
		Xm = (Xu+Xl) / 2.0; // Midpoint (bisecting)
		
		fXl = func(Xl, arr, degreeEq);
		
		fXu = func(Xu, arr, degreeEq);
		
		fXm = func(Xm, arr, degreeEq);
		
		Ea = ((Xm - pXm) / Xm) * 100.0;
		
		printf("%6d   %18.5f   %18.5f   %18.5f   %18.5f   %18.5f   %18.5f  %18.5f\n", iter, trunc(Xl*100000.0)/100000.0, trunc(Xu*100000.0)/100000.0, trunc(Xm*100000.0)/100000.0, trunc(fXl*100000.0)/100000.0, trunc(fXu*100000.0)/100000.0, trunc(fXm*100000.0)/100000.0, fabs(trunc(Ea*100000.0)/100000.0)); //Output line for this recursion
		
		if(fabs(trunc(Ea*100000.0)/100000.0) <= aveErr){
			printf("Average Error has been met. Program stops at iteration #%i\n", iter);
			break;
		}
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


