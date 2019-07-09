#include <iostream>
#include<cmath>
#include <fstream>
using namespace std;

float aproximacion(float , float , float, float, float);

int main () {
	
	int num = 200;

	float longitud = 1.0;
	float dx = 0.005;
	float c = 300;
	float amplitudCentro = 0.01;
	
	float tiempoFinal = 0.1;

	float dt2 = 0.25*dx*dx/(c*c);

	float kte = dt2*c*c/(dx*dx); 

	float dt = sqrt(dt2);

	int veces = int(tiempoFinal/dt);

	float inic[num];
	float posciVieja[num];
	float posci[num];
	float posciNuev[num];

	float posciViejaLibre[num];
	float posciLibre[num];
	float posciNuevLibre[num];


	//condiciones iniciales:

	for(int i =0; i<num; i++){
		
		if( i*dx <= longitud/2  ){
			posciVieja[i] = amplitudCentro*2*i*dx/longitud; 
			posci[i]= amplitudCentro*2*i*dx/longitud;

			posciViejaLibre[i] = amplitudCentro*2*i*dx/longitud; 
			posciLibre[i]= amplitudCentro*2*i*dx/longitud;

			inic[i]=amplitudCentro*2*i*dx/longitud;
		}
		else if(i*dx > longitud/2){
			posciVieja[i] = 2*amplitudCentro - amplitudCentro*2*i*dx/longitud;
			posci[i]= 2*amplitudCentro - amplitudCentro*2*i*dx/longitud;

			posciViejaLibre[i] = 2*amplitudCentro - amplitudCentro*2*i*dx/longitud; 
			posciLibre[i]= 2*amplitudCentro - amplitudCentro*2*i*dx/longitud;

			inic[i]=2*amplitudCentro - amplitudCentro*2*i*dx/longitud;
		}
	}


	//evolucion temporal
	ofstream outfile;
	outfile.open("posiciones.dat");
	for(int i = 0; i<veces; i++){
		for(int i = 0; i<num; i++){
			if(i==0){

				posciNuev[i]=0;
				posciNuevLibre[i] = 0; 
			}
			else if(i==num-1){
				posciNuev[i]=0;
				posciNuevLibre[i] = kte*(posciLibre[i-1]-posciLibre[i]) + 2*posciLibre[i] - posciViejaLibre[i];
			}
			else{
				posciNuev[i] = aproximacion(posci[i], posciVieja[i],posci[i+1], posci[i-1],kte);
				posciNuevLibre[i] = aproximacion(posciLibre[i], posciViejaLibre[i],posciLibre[i+1], posciLibre[i-1],kte);
					
			}
		}

		for(int i = 0; i<num; i++){
			posciVieja[i] = posci[i];
			posci[i]= posciNuev[i];

			posciViejaLibre[i] = posciLibre[i];
			posciLibre[i]= posciNuevLibre[i];

		}

		if(i%1000==0 )
			for(int i =0; i<num;i++){
				outfile << i*dx <<" " <<inic[i] <<" " << posciNuev[i] << " "<< posciNuevLibre[i] <<endl;
			}
		
		
		

	}

	outfile.close();


	return 0;
}


float aproximacion(float phirn, float phidtn, float phidxp, float phidxn, float k){
	return k*(phidxp + phidxn-2*phirn) + 2*phirn - phidtn;
}





