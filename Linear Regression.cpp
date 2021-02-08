#include<stdio.h>
#include<math.h>


float getxy(float xArr[], float yArr[], float xyArr[], float n){
	for(int i=0; i<n; i++){
		xyArr[i] = trunc(xArr[i] * yArr[i]*100000.0)/100000.0;
	}
	return *xyArr;
}

float getxx(float xArr[], float xxArr[], float n){
	for(int i=0; i<n; i++){
		xxArr[i] = trunc(xArr[i] * xArr[i]*100000.0)/100000.0;
	}
	return *xxArr;
}

float getsum(float arr[], float n){
	float sum=0.0;
	for(int i=0; i<n; i++){
		sum = trunc((sum + arr[i])*100000.0)/100000.0;
	}
	return sum;
}

float getypred(float a0, float a1, float x){
	float y;
	y = a0 + (a1*x);
	return y;
}

int main(){
	float xArr[50], yArr[50], xyArr[50], xxArr[50], a1, a0, ypred, err, errTotal, n;
	
	
	printf("How many data points to be entered (Max 50)? ");
	scanf("%f", &n);
	printf("\n\n");
	for(int i=0; i<n; i++){
		printf("Data Point %d\n", i+1);
		printf("x:  ");
		scanf("%f", &xArr[i]);
		printf("y:  ");
		scanf("%f", &yArr[i]);
	}
	
	*xxArr = getxx(xArr, xxArr, n);
	*xyArr = getxy(xArr, yArr, xyArr, n);
	
	
	a0 = trunc((((getsum(xxArr, n)*getsum(yArr, n))-(getsum(xArr, n)*getsum(xyArr, n)))/((n*getsum(xxArr, n)-(getsum(xArr, n)*getsum(xArr, n)))))*100000.0)/100000.0;
	a1 = trunc((((n*getsum(xyArr, n))-(getsum(xArr, n)*getsum(yArr, n)))/((n*getsum(xxArr, n)-(getsum(xArr, n)*getsum(xArr, n)))))*100000.0)/100000.0;
	
	
	printf("\na0: %.5f\n", a0);
	printf("a1: %.5f", a1);
	
	printf("\n\n  dp             x                y               x^2             xy             y-pred          Error\n");
	printf("-------------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<n; i++){
		ypred = trunc(getypred(a0, a1, xArr[i])*100000.0)/100000.0;
		err = trunc(((yArr[i]-ypred)*(yArr[i]-ypred))*100000.0)/100000.0;
		errTotal = errTotal + err;
		printf("%4d %19.5f %15.5f %15.5f %15.5f %15.5f %15.5f\n", i, trunc(xArr[i]*100000.0)/100000.0, trunc(yArr[i]*100000.0)/100000.0, trunc(xxArr[i]*100000.0)/100000.0, 
		trunc(xyArr[i]*100000.0)/100000.0, trunc(ypred*100000.0)/100000.0, trunc(err*100000.0)/100000.0);
	}
	printf("\nSummation %14.5f %15.5f %15.5f %15.5f", getsum(xArr, n), getsum(yArr, n), getsum(xxArr, n), getsum(xyArr, n));
	
	printf("\n\nMSE: %.5f", trunc(errTotal/n*100000.0)/100000.0);
	
	printf("\n\nLinear Regression Eqution: %.5f + %.5fx", a0, a1);
	
}
