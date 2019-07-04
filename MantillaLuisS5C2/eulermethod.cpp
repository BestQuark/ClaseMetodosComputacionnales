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
	outfile.open("plotEuler.dat");


	for(int i =0; i<num;i++){
		outfile << x[i] <<" " << y[i]<< endl;
		x[i+1]= x[i] + paso;
		y[i+1] = y[i] + paso*funcp(x[i], y[i]);
	}
	
	outfile.close();


	return 0;
}



float funcp(float xx, float yy){
	return -yy;
}



