#include <iostream>
#include<cmath>
#include <fstream>
#include <math.h> 
using namespace std;

float aproximacion(float , float , float, float, float);
float aprox2d(float , float , float , float , float , float , float );
float gaussian(float , float , float );

int main () {
	int num = 200;
	
	//variables membrana
	
	float sigma = 0.1;

	float inicMembrana[num][num];
	float posciMembrana[num][num];
	float posciMembranaVieja[num][num];
	float posciMembranaNuev[num][num];

	float dy = 0.005;
	float amplitudGaussiana = 0.01;

	//variables cuerda

	float longitud = 1.0;
	float dx = 0.005;
	float c = 300;
	float amplitudCentro = 0.01;
	
	float tiempoFinal = 0.1;

	float dt2 = 0.02*dx*dx/(c*c);

	float kte = dt2*c*c/(dx*dx); 

	float dt = sqrt(dt2);

	int veces = int(tiempoFinal/dt);



	float inic[num];

	//caso 1 cuerda
	float posci[num];
	float posciVieja[num];
	float posciNuev[num];

	//caso 2 cuerda
	float posciLibre[num];
	float posciViejaLibre[num];
	float posciNuevLibre[num];


	//caso 3 cuerda
	float inicCaso3[num];

	float posciCaso3[num];
	float posciViejaCaso3[num];
	float posciNuevCaso3[num];


	//condiciones iniciales cuerda:

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



	//condiciones iniciales tambor:
	for(int i=0; i<num; i++){
		for(int j =0; j<num; j++){
			if(i==0 || j ==0 || i==num-1 || j==num-1){
				inicMembrana[i][j] = 0;
				posciMembrana[i][j]=0;
				posciMembranaVieja[i][j]=0;
			}else{
	
				inicMembrana[i][j] = amplitudGaussiana*gaussian(sigma, i*dx-longitud/2, j*dy-(longitud/2));
				posciMembrana[i][j]=amplitudGaussiana*gaussian(sigma, i*dx-longitud/2, j*dy-(longitud/2));
				posciMembranaVieja[i][j]=amplitudGaussiana*gaussian(sigma, i*dx-longitud/2, j*dy-(longitud/2));
			}
		}
	}


	//evolucion temporal cuerda
	ofstream outfile;
	outfile.open("posiciones.dat");
	for(int i = 0; i<veces; i++){
		for(int j = 0; j<num; j++){
			if(j==0){
				posciNuev[j]=0;
				posciNuevLibre[j] = 0; 
				posciNuevCaso3[j]=0;
			}else if(j==num-1){
				posciNuev[j]=0;
				posciNuevLibre[j] = kte*(posciLibre[j-1]-posciLibre[j]) + 2*posciLibre[j] - posciViejaLibre[j];
				posciNuevCaso3[j] = amplitudCentro*sin(3.0*c*i*dt*3.14159/longitud);
			}else{
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
		if(i%100==0){
			for(int i =0; i<num;i++){
				outfile << i*dx <<" " <<inic[i] <<" " << posciNuev[i] << " "<< posciNuevLibre[i] <<" " <<posciNuevCaso3[i]<<endl;
			}
		}
	}

	outfile.close();

	outfile.open("posicionesTambor.dat");
	

	for(int l=0; l<veces;l++){
		for(int i=0; i<num; i++){
			for(int j =0; j<num; j++){
				if(i==0 || j ==0 || i==num-1 || j==num-1){
					posciMembranaNuev[i][j]=0;
				}else{
					posciMembranaNuev[i][j] = aprox2d(posciMembrana[i][j], posciMembranaVieja[i][j], posciMembrana[i+1][j],posciMembrana[i-1][j],posciMembrana[i][j+1],posciMembrana[i][j-1],kte);
				}
			}
		}

		for(int i=0; i<num; i++){
			for(int j =0; j<num; j++){
				posciMembranaVieja[i][j] = posciMembrana[i][j];
				posciMembrana[i][j] = posciMembranaNuev[i][j]; 
			}
		}

		if(l%1000==0){
			for(int i=0; i<num; i++){
				for(int j =0; j<num; j++){
					outfile << i*dx <<" "<< j*dy <<" " <<inicMembrana[i][j] <<" " << posciMembranaNuev[i][j] <<endl;
				}
			}
		}

	}
	outfile.close();

	return 0;
}


float aproximacion(float phirn, float phidtn, float phidxp, float phidxn, float k){
	return k*(phidxp + phidxn-2*phirn) + 2*phirn - phidtn;
}


float aprox2d(float phirn, float phidtn, float phidxp, float phidxn, float phidyp, float phidyn, float k){
	return k*(phidxp + phidxn + phidyp + phidyn -4*phirn  ) + 2*phirn - phidtn;
}

float gaussian(float s, float x, float y){
	return exp(-(x*x+y*y)/(2*s*s))/(6.2832*s);
}










