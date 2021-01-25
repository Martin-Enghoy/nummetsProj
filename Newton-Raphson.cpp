#include<stdio.h>
#include<math.h>

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

void out(float x){
	printf("\n\nRoot = %15.5f", trunc(x*10.0)/10.0);
}

int main(){
	float fcoeff[20], dcoeff[20];
	int fdeg, ddeg, mIter, iter=0;
	float x0, fx, fpx, x1, e, se, sfx, sfpx;
	//deriv (coeff);
	printf("Newton Raphson Method\n");
	
	printf("Degree of the function (20 max): ");
	scanf("%d", &fdeg);
	
	printf("\nFunction\n");
	*fcoeff = getCoeff(fdeg, fcoeff);
	
	printf("\nDerivative of the function\n");
	ddeg = fdeg-1;
	*dcoeff = getCoeff(ddeg, dcoeff);
	
	printf("\nInitial Guess: ");
	scanf("%f", &x0);
	
	printf("Max number of iterations: ");
	scanf("%d", &mIter);
	
	printf("\nStopping Criteria (0 if not applicable)");
	printf("\n<= Error: ");
	scanf("%f", &se);
	
	printf("f(x): ");
	scanf("%f", &sfx);
	
	printf("f'(x): ");
	scanf("%f", &sfpx);
	
	printf("\n\nIter #             x                f(x)               f'(x)              %%|Ea|\n");
	fx = func(x0, fcoeff, fdeg);
	fpx = func(x0, dcoeff, ddeg);
	printf("%6d %18.5f%18.5f %18.5f\n", iter, trunc(x0*100000.0)/100000.0, trunc(fx*100000.0)/100000.0, fabs(trunc(fpx*100000.0)/100000.0));
	for(iter=1; iter<mIter; iter++){
		x1 = x0-(fx/fpx);
		fx = func(x1, fcoeff, fdeg);
		fpx = func(x1, dcoeff, ddeg);
		e = (x1-x0)/x1*100.0;
		printf("%6d %18.5f%18.5f %18.5f %18.5f\n", iter, trunc(x1*100000.0)/100000.0, trunc(fx*100000.0)/100000.0, trunc(fpx*100000.0)/100000.0, fabs(trunc(e*100000.0)/100000.0));
		x0=x1;
		if(sfx!=0 && fx<=sfx) {
			out(x1);
			return 1;
		}
		else if(sfpx!=0 && fpx<=sfpx){
			out(x1); 
			return 1;
		}
		else if(se!=0 && fabs(e)<=se){
			out(x1); 
			return 1;
		} 
		
	}
	printf("The root was not found, not enough iterations or solution does not converge");
	
}
