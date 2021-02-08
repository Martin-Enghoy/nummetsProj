#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <math.h>

using namespace std;



double func(double x) {
	double ans = trunc((pow(x,2)) - (17*x) +70);	
	return ans;	
}

double trunc(double val){
	double temp = 100000.0*val;
	int new_val = temp;
	double conv = (new_val+0.0)/100000.0;
	return conv;
} 

int main() {
	double x1, x2, x3, Ea;
	double funcA, funcB, funcC=100;
	int i=1, width=25; 
    char sep = ' ';

	cout << fixed;
    cout << setprecision(5);

	cout << "Enter x-1: ";
	cin >> x1;
	funcA = func(x1);
	cout << "Enter x0: ";
	cin >> x2;
	funcB = func(x2);

    //FIRST ITR
	x3 = trunc(x2 - ((funcB*(x2-x1))/(funcB-funcA)) + 0.0);
	funcC = func(x3);
	Ea = trunc(abs((x3-x2)/(x3+0.0)+0.0)*100);
    cout << setw(width) << setfill(sep) << "iter" <<  setw(width) << setw(width) << setfill(sep) << "xi-1" << setw(width) << setfill(sep) << "f(xi-1)" << setw(width) << setfill(sep) << "Error %\n";
    cout << setw(width) << setfill(sep) << i <<  setw(width) << setfill(sep) << x1 << setw(width) << setfill(sep) << funcA << setw(width) << setfill(sep) << Ea<< "\n";
    i+=2;

    //SECOND ITR
    x1 = x2;
	x2 = x3;
	funcA = funcB;
	funcB = funcC;
    x3 = trunc(x2 - ((funcB*(x2-x1))/(funcB-funcA)) + 0.0);
	funcC = func(x3);
	Ea = trunc(abs((x3-x2)/(x3+0.0)+0.0)*100);
    cout << setw(width) << setfill(sep) << i-1 <<  setw(width) << setfill(sep) << x1 << setw(width) << setfill(sep) << funcA << setw(width) << setfill(sep) << Ea;
    cout<< endl;
    x1 = x2;
	x2 = x3;
	funcA = funcB;
	funcB = funcC;

    //REMAINING ITR
	while(!(Ea <= 0.003)  && !(abs(funcC) <= 0.005)) {
		x3 = trunc(x2 - ((funcB*(x2-x1))/(funcB-funcA)) + 0.0);
		funcC = func(x3);
		Ea = trunc(abs((x3-x2)/(x3+0.0)+0.0) * 100);
        cout << setw(width) << setfill(sep) << i <<  setw(width) << setfill(sep) << x1 << setw(width) << setfill(sep) << funcA << setw(width) << setfill(sep) << Ea;
        cout <<endl;
		
		x1 = x2;
		x2 = x3;
		funcA = funcB;
		funcB = funcC;
		i++;
		
		if (i==11) break;
		if (Ea == 0.00000) break;
	}
}
