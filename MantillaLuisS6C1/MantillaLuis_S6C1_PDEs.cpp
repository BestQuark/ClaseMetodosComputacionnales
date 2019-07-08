#include <iostream>
#include<cmath>
#include <fstream>
using namespace std;

float avanzo(float , float , float);

int main () {
	
	int num = 0;
	float velocidad = 1.0;
	float tiempoTrans = 0;

	cout << "Numero de puntos para el algoritmo" << endl;
	cin >> num;

	cout << "Tiempo que ha pasado" << endl;
	cin >> tiempoTrans;


	float paso = (2)/(num-1);
	float dt =paso*0.25/velocidad;
	
	float posci[num];
	float posciNuev[num];


	//condiciones iniciales:

	for(int i =0; i<num; i++){
		
		if( (i*paso<=1,25) && (i*paso>=0,75)){
			posci[i]= 2;
		}
		else{
			posci[i]= 1;
		}
	}


	posciNuev[0]=1;
	posciNuev[num-1]= 1;

	float cte = velocidad*dt/paso;

	//tiempo transcurrido

	

	for(float tiempo =0; tiempo<tiempoTrans;tiempo = tiempo +dt){
		for(int i = 1; i<num-1; i++){
			posciNuev[i] = avanzo(posci[i], posci[i-1],cte);
		}

		for(int i = 0; i<num; i++){
			posci[i] = posciNuev[i];
		}

	}

	ofstream outfile;
	outfile.open("posicion.dat");
	for(int i =0; i<num;i++){
			outfile << posci[i] <<endl;
					
	}			

	outfile.close();


	return 0;
}


float avanzo(float valNow, float valAtras, float k){
	return k*(valNow - valAtras) + valNow;
}













