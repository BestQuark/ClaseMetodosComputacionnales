#include <iostream>
#include<cmath>
#include <fstream>
using namespace std;


float *aumentodepos(float , float , float , float , float );

	float tinicial = 0;
	float tfinal = 0;
	float posinic = 0;
	float velinic =0;
	float masa = 0;
	float constantek = 0;
	int num = 0;


int main () {
	

	cout << "Empezamos en tiempo " << endl;
	cin >> tinicial;


	cout << "y el sistema avanza hasta  " << endl;
	cin >> tfinal;

	cout << "La posicion inicial del resorte en metros es:" << endl;
	cin >> posinic;


	cout << "La velocidad inicial del sistema en m/s es: " << endl;
	cin >> velinic;

	cout << "La masa del objeto en kg es: " << endl;
	cin >> masa;

	cout << "La constante del resorte en N/m es: " << endl;
	cin >> constantek;

	cout << "Numero de pasos para el algoritmo: " << endl;
	cin >> num;


	float paso = (tfinal-tinicial)/(num-1);
	
	float velocidades[num];
	float posiciones[num];
	float tiempos[num];
	
	float l = -constantek/masa;

	posiciones[0] = posinic;
	velocidades[0] = velinic;
	tiempos[0] = tinicial;

	tiempos[1] = tinicial + paso;
	posiciones[1] = posinic + paso*velinic;
	velocidades[1] = velinic + paso*l*posinic;
	
	
	ofstream outfile;
	outfile.open("posicion.dat");


	for(int i =1; i<num;i++){
		outfile << tiempos[i] <<" " << posiciones[i]<<" " << velocidades[i]<< endl;
		
		float *p = aumentodepos(velocidades[i-1],velocidades[i], posiciones[i-1],posiciones[i], paso);
		velocidades[i+1]= *p;
		posiciones[i+1] = *(p+1);
		tiempos[i+1] = tiempos[i] + paso;
				
	}
	
	outfile.close();


	return 0;
}




float *aumentodepos(float velantes, float veldespues, float posantes, float posdespues, float h){
	
		float l = -constantek/masa;
		
		static float cos[2];
		float *p = cos;


		cos[0]= velantes + 2*h*l*posdespues;
		cos [1] = posantes+ 2*h*veldespues;

		return p;
		
}


