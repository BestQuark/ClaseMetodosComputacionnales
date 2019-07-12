#include <iostream>
#include<cmath>
#include <fstream>
#include <math.h> 
using namespace std;

float evol(float , float , float , float , float , float );


int main(){

	float nu = 0.0001;
	float lado = 1;
	float dx = 0.01;
	int grilla = int(lado/dx);
	
	float temp[grilla][grilla];
	float tempNueva[grilla][grilla];

	float tempPer[grilla][grilla];
	float tempNuevaPer[grilla][grilla];

	float tempAb[grilla][grilla];
	float tempNuevaAb[grilla][grilla];

	float tempBon[grilla][grilla];
	float tempNuevaBon[grilla][grilla];

	
	float dt = 0.1*dx*dx/nu;

	float cte = dt*nu/(dx*dx);
	
	float tiempoTotal = 2500;
	int veces = int(2500/dt);

	float tempPromedio[veces];
	float tempPromedioPer[veces];
	float tempPromedioAb[veces];


	//condiciones iniciales
	for(int i =0; i<grilla; i++){
		for(int j=0; j<grilla; j++){
			
			if(i*dx<=0.8 && i*dx>=0.6 && j*dx<=0.6 && j*dx>=0.4){
				temp[i][j] = 100;
				tempPer[i][j]=100;
				tempAb[i][j]=100;
				tempBon[i][j] = 100;
			}
			else{
				temp[i][j]= 50;
				tempPer[i][j]=50;			
				tempAb[i][j]=50;
				tempBon[i][j]= 50;			
			}
		}
	}

	ofstream outfile;
	outfile.open("temps.dat");
	
	//evolucion temporal
	
	for(int l=0; l<veces;l++){
		float tempMean = 0;
		float tempMeanPer = 0;
		float tempMeanAb =0;
		if(l==0 || l*dt==100 || l==veces-1){
			for(int i =0; i<grilla; i++){
				for(int j=0; j<grilla; j++){
					outfile << i*dx << " "<<j*dx <<" "<<temp[i][j]<<" "<<tempPer[i][j]<< " "<<tempAb[i][j]<< " "<< tempBon[i][j] <<endl;	
				}
			}
		}
	
		for(int i =0; i<grilla; i++){
			for(int j=0; j<grilla; j++){
			
				if(i==0 || j==0 || i==grilla-1 || j==grilla-1){
					int inNew = i-1;
					int ipNew = i+1;
					int jnNew = j-1;
					int jpNew = j+1;

					int inN = i-1;
					int ipN = i+1;
					int jnN = j-1;
					int jpN = j+1;

					if(i==0){inNew = grilla-1; inN=i;}
					if(i==grilla-1){ipNew = 0; ipN=i;}
					if(j==0){jnNew = grilla-1; jnN =j;}
					if(j==grilla-1){jpNew = 0; jpN = j;}

					tempNueva[i][j] = 50;
					tempNuevaBon[i][j] = evol(tempBon[i][j], tempBon[ipNew][j], tempBon[inNew][j], tempBon[i][jpNew], tempBon[i][jnNew], cte);
					tempNuevaPer[i][j]= evol(tempPer[i][j], tempPer[ipNew][j], tempPer[inNew][j], tempPer[i][jpNew], tempPer[i][jnNew], cte);
					tempNuevaAb[i][j]= evol(tempAb[i][j], tempAb[ipN][j], tempAb[inN][j], tempAb[i][jpN], tempAb[i][jnN], cte);
				}
				else{
					tempNueva[i][j]= evol(temp[i][j], temp[i+1][j], temp[i-1][j], temp[i][j+1], temp[i][j-1], cte);
					tempNuevaPer[i][j]= evol(tempPer[i][j], tempPer[i+1][j], tempPer[i-1][j], tempPer[i][j+1], tempPer[i][j-1], cte);
					tempNuevaAb[i][j]= evol(tempAb[i][j], tempAb[i+1][j], tempAb[i-1][j], tempAb[i][j+1], tempAb[i][j-1], cte);
					if(i*dx<=0.8 && i*dx>=0.6 && j*dx<=0.6 && j*dx>=0.4){
						tempNuevaBon[i][j]=100;
					}
					else{
						tempNuevaBon[i][j]= evol(tempBon[i][j], tempBon[i+1][j], tempBon[i-1][j], tempBon[i][j+1], tempBon[i][j-1], cte);			
					}	
				}				
			}
		}
		for(int i =0; i<grilla; i++){
			for(int j=0; j<grilla; j++){
				tempMean = tempMean + temp[i][j];
				tempMeanPer = tempMeanPer + tempPer[i][j];
				tempMeanAb = tempMeanAb + tempAb[i][j];
				temp[i][j] = tempNueva[i][j];
				tempPer[i][j] = tempNuevaPer[i][j];
				tempAb[i][j] = tempNuevaAb[i][j];
				tempBon[i][j] = tempNuevaBon[i][j];
			}
		}
		tempPromedio[l]=tempMean/(grilla*grilla);
		tempPromedioPer[l] = tempMeanPer/(grilla*grilla);
		tempPromedioAb[l]=tempMeanAb/(grilla*grilla);
	}
	outfile.close();

	outfile.open("temperaturaMean.dat");
	
	for(int l=0; l<veces;l++){
		outfile<< tempPromedio[l] <<" " <<tempPromedioPer[l] <<" "<<tempPromedioAb[l]<< endl;
	}

	outfile.close();
	
	return 0;
}

float evol(float temprn, float tempxp, float tempxn, float tempyp, float tempyn, float k){
	return k*(tempxp+tempxn+tempyp+tempyn-4*temprn)+temprn;
}
