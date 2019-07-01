#include<iostream>
using namespace std;


unsigned long long int fact(int);



int main(){
	cout << "Factorial de : ";
	int num = 0;
	cin >> num;
	cout << "El valor es: " << fact(num) <<endl;
	return 0;
}

unsigned long long int fact(int n){

	if(n>1){
		return fact(n-1)*n;
	}else if (n=1){
		return 1;
	}
}
