#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>

float getCoeff(int deg, float coeff[]);
float func(float x, float coeff[], int deg);
float getRoots(float x, float y, float roots[]);

int main(){
	
	float r, s, prevR, prevS, deltaR, deltaS; // Values
	float fXm, fXu, fXl; // Functions
	float bArr[21], cArr[21]; //Arrays for storing b and c
	int degreeEq=0,i,j;
	float arr[20]; // array for coefficients
	float outArr[200]; // array for table printing
	//float rArr[21], sArr[21];
	int counter = 0; // For counting the array items
	int iter=0, mIter; // Stopping Parameter
	float errR, errS, aveErr; //Average Error %
	float roots[2];
	
	while(degreeEq<3){
		printf("-------Bairstow Method-------\n");
		printf("What is the degree of your equation? (Max: 20)\n");
		scanf("%i", &degreeEq);
		if(degreeEq<3){
			printf("Please input a degree greater than or equal to 3");
		}
	}
	
	
	*arr = getCoeff(degreeEq, arr);
	
	
	//Init of r and s
	printf("What is the initial value of r?\n");
	scanf("%f", &r);
	//rArr[0] = r;
	//outArr[counter] = Xl;
	//counter++;
	
	
	printf("What is the initial value of s?\n");
	scanf("%f", &s);
	//sArr[0] = s;
	//outArr[counter] = Xu;
	//counter++;
	
	
	printf("How many iterations before stopping?\n");
	scanf("%i", &mIter);
	printf("How much (percent)error can be tolerated?\n");
	scanf("%f", &aveErr);	
	
	
	printf("\n               r                   s                   deltaR                   deltaS                   errR%%                   errS%%\n");
		printf("%18.5f %18.5f %18.5f %18.5f\n", trunc(r*100000.0)/100000.0, trunc(s*100000.0)/100000.0, trunc(deltaR*100000.0)/100000.0, trunc(deltaS*100000.0)/100000.0);
	
	for(iter=1; iter<=mIter; iter++){
		printf("\n\nIteration #%i\n", iter);
		prevR = r;
		prevS = s;
		
		bArr[0] = arr[0]; 
		//printf("%18.5f\n", arr[0]);
		//printf("%18.5f\n", bArr[0]);
		bArr[1] = arr[1] + r*bArr[0];
		//printf("%18.5f\n", bArr[1]);
		cArr[0] = bArr[0];
		//printf("%18.5f\n", cArr[0]);
		cArr[1] = bArr[1] + r*cArr[0];
		//printf("%18.5f\n", cArr[1]);
		for(i=2; i<degreeEq; i++){
			bArr[i] = arr[i] + r*bArr[i-1] + s*bArr[i-2];
			//printf("-%18.5f\n", bArr[i]);
			//printf("--%18.5f\n", bArr[i-1]);
			//printf("---%18.5f\n", bArr[i-2]);
			cArr[i] = bArr[i] + r*cArr[i-1] + s*cArr[i-2];
			//printf("-%18.5f\n", cArr[i]);
			//printf("--%18.5f\n", cArr[i-1]);
		}
		
		counter = degreeEq;
		printf("----- B -----\n");
		for(j=0; j<=degreeEq; j++){
			printf("B%i: %18.5f\n", counter, trunc(bArr[j]*100000.0)/100000.0);
			counter--;
		}
		printf("\n\n");
		counter = degreeEq;
		printf("----- C -----\n");
		for(j=0; j<=degreeEq; j++){
			printf("C%i: %18.5f\n", counter, trunc(cArr[j]*100000.0)/100000.0);
			counter--;
		}
		printf("\n");
		
		deltaR = (-bArr[degreeEq-1] - (cArr[degreeEq-3]*-bArr[degreeEq])/cArr[degreeEq-2])/(cArr[degreeEq-2] - (cArr[degreeEq-1]*cArr[degreeEq-2])/cArr[degreeEq-2]);
		deltaS = (-bArr[degreeEq] - (cArr[degreeEq-1]*deltaR)) / cArr[degreeEq-2];
		
		r = prevR + deltaR;
		s = prevS + deltaS;
		
		
		errR = ((r - prevR) / r) * 100.0;
		errS = ((s - prevS) / s) * 100.0;
		
		printf("             r                 s                 deltaR               deltaS            errR%%            errS%%\n");
		printf("%18.5f %18.5f %18.5f %18.5f %18.5f %18.5f\n", trunc(r*100000.0)/100000.0, trunc(s*100000.0)/100000.0, trunc(deltaR*100000.0)/100000.0, trunc(deltaS*100000.0)/100000.0, fabs(trunc(errR*100000.0)/100000.0), fabs(trunc(errS*100000.0)/100000.0));
		
		if(errR <= aveErr && errS <= aveErr){
			printf("The Average Error has been met. The program stops at iteration #%i\n", iter);
			*roots = getRoots(r,s,roots);
			//if(roots[])
			
			if(isinf(roots[0]) && isinf(roots[1])){
				printf("Both roots are infite (indeterminate.\n)");
			} else if(isinf(roots[0])){
				printf("The first root is infinite (indeterminate).\n");
			} else if(isinf(roots[1])){
				printf("The first root is infinite (indeterminate).\n");
			} else {
			printf("The roots are %18.5f and %18.5f\n", roots[0], roots[1]);
			}
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

float getRoots(float x, float y, float roots[]){
	
	roots[0] = (x + sqrt(pow(x,2)+(4.00*y))) / 2.00;
	
	roots[1] = (x - sqrt(pow(x,2)+(4.00*y))) / 2.00;
	
	return *roots;
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


