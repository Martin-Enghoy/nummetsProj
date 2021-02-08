#include<stdio.h>
#include<conio.h> 
#include<math.h>


float gx(float x){
	//put g(x) here
	x = ((5.5*x) -1)/(7.5*x);
	return x;
}

int main(){
	float x0, x1, error, trueVal, cerror=0, terror=0;
	int n, ch = 0, end=0;
	char choice;
	
	printf("\nInitial Guess: ");
	scanf("%f", &x0);
	
	printf("Max number of iterations: ");
	scanf("%d", &n);
	
	printf("Stopping Error: ");
	scanf("%f", &error);
	
	printf("Is there a true value? (y,n)");
	choice = getch();
	
	if(choice == 'y' || choice== 'Y'){
		printf("\nTrue value: ");
		scanf("%f", &trueVal);
		ch = 1;
	}
	
	printf("\nIteration         Xi              g(Xi)          Ea%");
	if(ch){
		printf("        Et%");
	}
	
	for(int i=0; i<=n; i++){
		x1 = trunc(gx(x0)*100000.0)/100000.0;
		if(i==0){
			printf("\n%7d %15.5f %15.5f ", i, trunc(x0*100000.0)/100000.0, trunc(x1*100000.0)/100000.0);
		}
		else{
			printf("\n%7d %15.5f %15.5f %15.5f ", i, trunc(x0*100000.0)/100000.0, trunc(x1*100000.0)/100000.0, trunc(cerror*100000.0)/100000.0);
			if(ch){
				printf("%15.5f", trunc(terror*100000.0)/100000.0);
			}
			
		}
		if(end) return 1;
		cerror = fabs(((trunc(x1*100000.0)/100000.0)-(trunc(x0*100000.0)/100000.0))/(trunc(x1*100000.0)/100000.0)*100);
		terror = fabs(((trunc(x1*100000.0)/100000.0)-(trunc(trueVal*100000.0)/100000.0))/(trunc(x1*100000.0)/100000.0)*100);
		if(cerror<=error){
			end = 1;
		}
		x0=x1;
	}
	printf("\n\nThe root was not found, not enough iterations or solution does not converge");
}
