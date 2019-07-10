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

	float inicCaso3[num];
	float posciViejaCaso3[num];
	float posciCaso3[num];
	float posciNuevCaso3[num];


	//condiciones iniciales:

	for(int i =0; i<num; i++){
			inicCaso3[i]=0;
			posciViejaCaso3[i]=0;
			posciCaso3[i]=0;

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
		for(int j = 0; j<num; j++){
			if(j==0){

				posciNuev[j]=0;
				posciNuevLibre[j] = 0; 
				posciNuevCaso3[j]=0;
			}
			else if(j==num-1){
				posciNuev[j]=0;
				posciNuevLibre[j] = kte*(posciLibre[j-1]-posciLibre[j]) + 2*posciLibre[j] - posciViejaLibre[j];
				posciNuevCaso3[j] = amplitudCentro*sin(3.0*c*i*dt*3.14159/longitud);
			}
			else{
				posciNuev[j] = aproximacion(posci[j], posciVieja[j],posci[j+1], posci[j-1],kte);
				posciNuevLibre[j] = aproximacion(posciLibre[j], posciViejaLibre[j],posciLibre[j+1], posciLibre[j-1],kte);
				posciNuevCaso3[j] = aproximacion(posciCaso3[j], posciViejaCaso3[j],posciCaso3[j+1], posciCaso3[j-1],kte);
					
			}
		}

		for(int j = 0; j<num; j++){
			posciVieja[j] = posci[j];
			posci[j]= posciNuev[j];

			posciViejaLibre[j] = posciLibre[j];
			posciLibre[j]= posciNuevLibre[j];

			posciViejaCaso3[j] = posciCaso3[j];
			posciCaso3[j]= posciNuevCaso3[j];

		}

		if(i%100==0 )
			for(int i =0; i<num;i++){
				outfile << i*dx <<" " <<inic[i] <<" " << posciNuev[i] << " "<< posciNuevLibre[i] <<" " <<posciNuevCaso3[i]<<endl;
			}
		
		
		

	}

	outfile.close();


	return 0;
}


float aproximacion(float phirn, float phidtn, float phidxp, float phidxn, float k){
	return k*(phidxp + phidxn-2*phirn) + 2*phirn - phidtn;
}





