#include <iostream>
#include<cmath>
#include <fstream>
using namespace std;


float *aumentodepos(float, float, float );

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

	posiciones[0] = posinic;
	velocidades[0] = velinic;
	tiempos[0] = tinicial;
	


	ofstream outfile;
	outfile.open("posicion.dat");


	for(int i =0; i<num;i++){
		outfile << tiempos[i] <<" " << posiciones[i]<<" "<< velocidades[i]<< endl;
		
		float *p = aumentodepos(velocidades[i], posiciones[i], paso);
		velocidades[i+1]= *p;
		posiciones[i+1] = *(p+1);
		tiempos[i+1] = tiempos[i] + paso;
				
	}
	//imprimimos el ultimo dato que omite el for.
	outfile << tiempos[num] <<" " << posiciones[num]<<" "<< velocidades[num]<< endl;
	
	outfile.close();


	return 0;
}




float *aumentodepos(float vel, float pos, float h){
	
		float l = -constantek/masa;
		
		static float cos[2];
		float *p = cos;

		float k1x = h*vel;
		float k1v = h*pos*l;

		float posmitad1 = pos + k1x/2;
		float velmitad1 = vel + k1v/2;

		float k2x = h*velmitad1;
		float k2v =  h*posmitad1*l;

		float posmitad2 = pos + k2x/2;
		float velmitad2 = vel + k2v/2;
	
		float k3x = h*velmitad2;
		float k3v =  h*posmitad2*l;	

		float k4x = h*(vel + k3v);
		float k4v =  h*l*(pos + k3x);	

		float promx =  (k1x+2*k2x+ 2*k3x +k4x)/6;
		float promv =  (k1v+2*k2v+ 2*k3v+ k4v)/6;

		cos[0]= vel + promv;
		cos [1] = pos+ promx;

		return p;
		
}








