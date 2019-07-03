#include <iostream>
#include<cmath>
#include <fstream>
using namespace std;


float *derivada(float*,float,int);

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
	
	float *l = derivada(arreg, paso, num);

		

	ofstream outfile;
	outfile.open("valores.dat");


	for(int i =0; i<num;i++){
		outfile << *(l+i) <<" " << funcion(arreg[i]) <<" " <<arreg[i]<< endl;
	}
	
	outfile.close();
	

	return 0;
}


float funcion(float p){
	return cos(p);
}

float *derivada(float *arre, float h,int n){

	static float *derivs = new float[n];

	for(int i =0; i<n; i++){
		*(derivs+i)= (funcion(*(arre+i) + h/2)- funcion(*(arre+i)-h/2))/h;
		
	}

	return derivs;		
}
