#include<stdlib.h>
#include<math.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;



double trunc(double x){
	double temp = 100000.0*x;
	int truncate = temp;
	double ans = (truncate+0.0)/100000.0;
	return ans;
} 
void input(int x, double eq[14][16]){ // PARAMETERS (NUMBER OF EQUATIONS, MATRIX)
	double ans;
	for(int i=0; i<x; i++){ //LOOP TO SAVE MATRICES
		cout<< "\nEQUATION: ";
		cout<< i+1;
		cout<< "\n";
		for(int j=0; j<x; j++){	
			cout<< "INPUT X";
			cout<< j+1;
			cout<< ": ";
			cin>> ans;
			eq[i][j] = trunc(ans);
		
		}
		cout<< "INPUT Z: ";
		cin>> ans;
		eq[i][x] = trunc(ans);
	}
}
void disp(double eq[14][16], int num){
	 cout << fixed;
     cout << setprecision(5);
	for(int i=0; i<num; i++) {
		cout<<"\n[";
      for(int j=0; j<=num; j++) {
         cout<< eq[i][j];
		 cout<< " ";
		 if(j==2){
			 cout<< ": ";
		 }
      }
		cout<<"]";
   }
}
void swap(double eq[14][16], int num, int step, int x){
	double temp[14][16];
	//COPY TO TEMP ARRAY
	for(int j=step-1; j<=x; j++){
		temp[step-1][j] = eq[step-1][j];
	}
	for(int n=step-1; n<=x; n++){
		temp[num][n]= eq[num][n];
	}

	//SWAP
	for(int j=step-1; j<=x; j++){
		eq[step-1][j] = temp[num][j];
	
	}
	for(int n=step-1; n<=x; n++){
		eq[num][n]= temp[step-1][n];
	}
}
void pivot(double eq[14][16], int num, int step){
	bool check=true;
	if(step==1){
		for(int i=1; i<num-1; i++){
			check=true;
			if(abs(eq[0][0]) < abs(eq[i][0])) { //COMPARE 1 TO 2
				if(abs(eq[i][0]) < abs(eq[i+1][0])){ // COMPARE 2 TO 3
					check=false;
				}
				if(abs(eq[0][0]) < abs(eq[i+1][0]) && !check){ //COMPARE 1 TO 3
					swap(eq, i+1, step, num); //SWAP 1 TO 3
					break;
				}
				swap(eq, i, step, num); //SWAP 1 TO 2
				break;
			}
			else if(abs(eq[0][0]) < abs(eq[i+1][0])){ // COMPARE 1 TO 3
					swap(eq, i+1, step, num); // SWAP 1 TO 3 
					break;
				}
		}
	}

	if(step==2){
		for(int i=2; i<num; i++){
		if(abs(eq[1][1]) < abs(eq[i][1])) {
			if(abs(eq[1][1]) < abs(eq[i+1][1])){
					swap(eq, i+1, step, num);
					break;
				}
				swap(eq, i, step, num);
				break;
		}
		}
	}
	
}
void oper(double eq[14][16], double temp[14][16], int step, int num, int i){
	double x3;
	x3=temp[0][1];
	for(int m=0; m<=num; m++){
		temp[i][m] = trunc(eq[i][m] * x3);
		if(m==num){
			break;
		}
	}
	for(int n=0; n<=num; n++){
		eq[step+1][n] = trunc(eq[step+1][n] - temp[i][n]) ;
		}

}
void frwrd(double eq[14][16], int num, int step, int itr, int count){
	double x1,x2,x3,x4,x5;
	double temp[14][16];
	for(int i=step-1; i<num-1; i++){
		for(int j=step-1; j<num; j++){
			if(eq[i+1][itr]!=0 && itr<num-1 ){
				x1 = eq[i][count];
				x2 = eq[itr+1][count];
				temp[0][1] = x2/x1; 
				oper(eq, temp, itr, num, i);
				disp(eq,num); 
				cout<< "\n";
				itr+=1;
			}
			
		}
			count+=1;
	}
}		
void backwrd(double eq[14][16], int num){
	double unkwn[14]={0};
	double x=0.0;
	for(int i=num-1; i>=0; i--){
		x=0.0;
		for(int j=0; j<num; j++){
				x+=trunc(eq[i][j]*unkwn[j]);
		}
		unkwn[i]=trunc((eq[i][num]-x)/eq[i][i]);
		cout<< "\nX";
		cout<< i+1;
		cout<< ": ";
		cout<< unkwn[i];
	}

}
	



int main()
{
	int num=3;
	int perm_num;
	int step=1;
	int itr=0;
	int count=0;
	double eq[14][16];
	perm_num=num;
	input(num,eq);
	cout<< "\nInitial Matrix: ";
	disp(eq,num);
	cout<< "\n\nPivot";
	pivot(eq,num,step);
	disp(eq, perm_num);
	cout<< "\n\nForward Elimination";
	frwrd(eq, perm_num,step, itr, count);
	cout<< "\n\nPivot";
	pivot(eq, perm_num, step+1);
	disp(eq, perm_num);
	cout<< "\n\nForward Elimination";
	frwrd(eq, perm_num,step+1, itr+1, count+1);
	cout<< "\n\nUnknowns:";
	backwrd(eq, perm_num);

}