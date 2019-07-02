#include <iostream>
#include<cmath>
using namespace std;


int *derivada(float*,float);

float funcion(float);

int main(){
	
	float inic = 0;
	float fina = 0;
	int num = 0;

	cout << "Hallar la derivada desde " << endl;
	cin >> inic;


	cout << "hasta " << endl;
	cin >> fina;


	cout << "Y una cantidad de pasos: " << endl;
	cin >> num;

	float paso = (fina-inic)/(num-1);
	float arreg[num];
	float deriv[num];

	for(int i =0; i<num;i++){
		arreg[i]= inic + i*paso;
	}
	
	
	

	return 0;
}


float funcion(float p){
	return cos(p);
}

int *derivada(float *arreg, float h){
	
	for(int i =0; i<n; i++){
		deriv[i]= 	(funcion(*arreg + h/2)- funcion(*arreg-h/2))/h;
		arreg++;		
	}

	return deriv;		
}
