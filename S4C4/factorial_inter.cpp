#include<iostream>
using namespace std;



int main(){
	cout << "Factorial de : ";
	int num = 0;
	cin >> num;
	unsigned long long int rta = num;
	for(int i = 1; i<num; i = i+1 ){
		rta = rta*i;
	}
	cout << "El valor es: " << rta <<endl;
	return 0;
}


