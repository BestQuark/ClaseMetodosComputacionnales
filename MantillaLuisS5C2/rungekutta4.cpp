#include <iostream>
#include<cmath>
#include <fstream>
using namespace std;


float funcp(float,float);


int main () {
	
	float inic = 0;
	float fina = 0;
	float condin = 0;
	int num = 0;

	cout << "Resolver desde " << endl;
	cin >> inic;


	cout << "hasta " << endl;
	cin >> fina;

	cout << "Condicion inicial y(0): " << endl;
	cin >> condin;


	cout << "Y una cantidad de pasos: " << endl;
	cin >> num;



	float paso = (fina-inic)/(num-1);
	
	float x[num];
	float y[num];

	x[0] = inic;
	y[0] = condin;
	

	ofstream outfile;
	outfile.open("plotRunge4.dat");


	for(int i =0; i<num;i++){
		outfile << x[i] <<" " << y[i]<< endl;
		
		float k1 = paso*funcp(x[i], y[i]);
		float k2 = paso*funcp(x[i]+paso/2, y[i] + k1/2);
		float k3 = paso*funcp(x[i]+paso/2, y[i] + k2/2);			
		float k4 = paso*funcp(x[i]+paso, y[i] + k3);

		float prom =  (k1+2*k2+2*k3+k4)/6;
		x[i+1]= x[i] + paso;
		y[i+1] = y[i] + prom;
	}
	
	outfile.close();


	return 0;
}



float funcp(float xx, float yy){
	return -yy;
}



