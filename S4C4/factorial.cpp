#include<iostream>
using namespace std;

int fact(int);



int main(){

	cout << "El valor de 7 factorial es:" << fact(7) <<endl;
	cout << "El valor de 77 factorial es:" << fact(77) <<endl;
	
	return 0;
}

int fact(int n){

	if(n>1){
		return fact(n-1)*n;
	}else if (n=1){
		return 1;
	}
}
