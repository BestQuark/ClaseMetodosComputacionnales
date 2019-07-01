#include<iostream>
using namespace std;



int main(){
	cout << "Factorial de : ";
	int num = 0;
	cin >> num;
	int rta = num;
	for(int i = num-1; i>0; i = i-1 ){
		rta = rta*i;
	}
	cout << "El valor es: " << rta <<endl;
	return 0;
}


