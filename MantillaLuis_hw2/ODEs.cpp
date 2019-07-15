//importamos los paquetes que usaremos
#include <iostream>
#include <fstream>
#include<cmath>
using namespace std;

//definimos las funciones que usaremos en el main

float *metodoEuler(float , float , float , float , float );
float *metodoRungeKutta4(float , float , float , float , float );
float *metodoLeapFrog(float , float , float , float , float , float , float , float , float );


//definimos las variables globales (usamos unidades de UA, Masas Solares y yrs)

float MasaSol = 1;
float MasaTierra = 3.003; //falta *10^-6
float ConstanteGravit = 39.478;

float orbita = 2*3.14159;


int pasos1 = 10000;
float dt1 = orbita/pasos1;

int pasos2 = 1000;
float dt2 = orbita/pasos2;

int pasos3 = 500;
float dt3 = orbita/pasos3;



float numeroVueltas = 20;

//condiciones iniciales
float xi = 0.1163;
float yi = 0.9772;
float vxi = -6.35;
float vyi = 0.606;


int main () {

//Evolucion temporal del sistema PRIMER dt :

//condiciones iniciales para cada metodo
	
	//Euler
	float distXEuler=xi;
	float distYEuler=yi;
	float velocXEuler=vxi;
	float velocYEuler=vyi;

	//RungeKutta 4th Order
	float distXRK=xi;
	float distYRK=yi;
	float velocXRK=vxi;
	float velocYRK=vyi;

	//LeapFrog

	float leapCte = -MasaSol*ConstanteGravit/pow(sqrt(xi*xi + yi*yi),3);

	float distXLeapB=xi;
	float distYLeapB=yi;
	float velocXLeapB=vxi;
	float velocYLeapB=vyi;

	float distXLeap=xi + dt1*vxi;
	float distYLeap=yi + dt1*vyi;
	float velocXLeap=vxi + dt1*leapCte*xi;
	float velocYLeap=vyi + dt1*leapCte*yi;

	//Metodo de Euler
	ofstream outfile;

	outfile.open("metodoEuler1.dat");

	for(int i=0; i<pasos1*numeroVueltas;i++){

		float *euler = metodoEuler(velocXEuler, velocYEuler, distXEuler, distYEuler, dt1);

		distXEuler=*euler;
		distYEuler=*(euler+1);
		velocXEuler=*(euler+2);
		velocYEuler=*(euler+3);
		
		float momento = distXEuler*velocYEuler - distYEuler*velocXEuler;
		float energia = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXEuler*distXEuler + distYEuler*distYEuler);
		outfile << distXEuler << " " << distYEuler<<" " << velocXEuler << " " << velocYEuler<<" " << momento*MasaTierra<<" " << energia <<" " << dt1*i << endl;
	}

	outfile.close();



	//Metodo de Rungekutta 4th order
	outfile.open("metodoRungeKutta1.dat");

	for(int i=0; i<pasos1*numeroVueltas;i++){
		float *rk = metodoRungeKutta4(velocXRK, velocYRK, distXRK, distYRK, dt1);
		distXRK=*rk;
		distYRK=*(rk+1);
		velocXRK=*(rk+2);
		velocYRK=*(rk+3);

		float momento = distXRK*velocYRK - distYRK*velocXRK;
		float energia = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXRK*distXRK + distYRK*distYRK);
		outfile << distXRK<< " " << distYRK<<" " << velocXRK<< " " << velocYRK<< " " << momento*MasaTierra << " " << energia <<" " << dt1*i << endl;
	}

	outfile.close();
	
	//Metodo de LeapFrog
	outfile.open("metodoLeapFrog1.dat");

	for(int i=0; i<pasos1*numeroVueltas;i++){

		float *lp = metodoLeapFrog(velocXLeapB,velocYLeapB,distXLeapB,distYLeapB,velocXLeap,velocYLeap,distXLeap,distYLeap, dt1);

		distXLeapB=distXLeap;
		distYLeapB=distYLeap;
		velocXLeapB=velocXLeap;
		velocYLeapB=velocYLeap;

		distXLeap=*lp;
		distYLeap=*(lp+1);
		velocXLeap=*(lp+2);
		velocYLeap=*(lp+3);

		float momento = distXLeap*velocYLeap - distYLeap*velocXLeap;
		float energia = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXLeap*distXLeap + distYLeap*distYLeap);
		outfile << distXLeap<< " " << distYLeap<< " "<< velocXLeap << " " << velocYLeap <<" "<< momento*MasaTierra << " " << energia <<" " << dt1*i << endl;

	}

	outfile.close();


//Evolucion temporal del sistema SEGUNDO dt :

//condiciones iniciales para cada metodo
	
	//Euler
	distXEuler=xi;
	distYEuler=yi;
	velocXEuler=vxi;
	velocYEuler=vyi;

	//RungeKutta 4th Order
	distXRK=xi;
	distYRK=yi;
	velocXRK=vxi;
	velocYRK=vyi;

	//LeapFrog

	distXLeapB=xi;
	distYLeapB=yi;
	velocXLeapB=vxi;
	velocYLeapB=vyi;

	distXLeap=xi + dt2*vxi;
	distYLeap=yi + dt2*vyi;
	velocXLeap=vxi + dt2*leapCte*xi;
	velocYLeap=vyi + dt2*leapCte*yi;
	//Metodo de Euler

	outfile.open("metodoEuler2.dat");

	for(int i=0; i<pasos2*numeroVueltas;i++){

		float *euler = metodoEuler(velocXEuler, velocYEuler, distXEuler, distYEuler, dt2);

		distXEuler=*euler;
		distYEuler=*(euler+1);
		velocXEuler=*(euler+2);
		velocYEuler=*(euler+3);

		float momento = distXEuler*velocYEuler - distYEuler*velocXEuler;
		float energia = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXEuler*distXEuler + distYEuler*distYEuler);
		outfile << distXEuler << " " << distYEuler<<" " << velocXEuler << " " << velocYEuler<<" " << momento*MasaTierra<<" " << energia <<" " << dt2*i << endl;
	}

	outfile.close();



	//Metodo de Rungekutta 4th order
	outfile.open("metodoRungeKutta2.dat");

	for(int i=0; i<pasos2*numeroVueltas;i++){
		float *rk = metodoRungeKutta4(velocXRK, velocYRK, distXRK, distYRK, dt2);
		distXRK=*rk;
		distYRK=*(rk+1);
		velocXRK=*(rk+2);
		velocYRK=*(rk+3);

		float momento = distXRK*velocYRK - distYRK*velocXRK;
		float energia = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXRK*distXRK + distYRK*distYRK);
		outfile << distXRK<< " " << distYRK<<" " << velocXRK<< " " << velocYRK<< " " << momento*MasaTierra << " " << energia <<" " << dt2*i << endl;
	}

	outfile.close();
	
	//Metodo de LeapFrog
	outfile.open("metodoLeapFrog2.dat");

	for(int i=0; i<pasos2*numeroVueltas;i++){

		float *lp = metodoLeapFrog(velocXLeapB,velocYLeapB,distXLeapB,distYLeapB,velocXLeap,velocYLeap,distXLeap,distYLeap, dt2);

		distXLeapB=distXLeap;
		distYLeapB=distYLeap;
		velocXLeapB=velocXLeap;
		velocYLeapB=velocYLeap;

		distXLeap=*lp;
		distYLeap=*(lp+1);
		velocXLeap=*(lp+2);
		velocYLeap=*(lp+3);

		float momento = distXLeap*velocYLeap - distYLeap*velocXLeap;
		float energia = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXLeap*distXLeap + distYLeap*distYLeap);
		outfile << distXLeap<< " " << distYLeap<< " "<< velocXLeap << " " << velocYLeap <<" "<< momento*MasaTierra << " " << energia <<" " << dt2*i << endl;

	}

	outfile.close();

//Evolucion temporal del sistema TERCER dt :

//condiciones iniciales para cada metodo
	
	//Euler
	distXEuler=xi;
	distYEuler=yi;
	velocXEuler=vxi;
	velocYEuler=vyi;

	//RungeKutta 4th Order
	distXRK=xi;
	distYRK=yi;
	velocXRK=vxi;
	velocYRK=vyi;

	//LeapFrog

	distXLeapB=xi;
	distYLeapB=yi;
	velocXLeapB=vxi;
	velocYLeapB=vyi;

	distXLeap=xi + dt3*vxi;
	distYLeap=yi + dt3*vyi;
	velocXLeap=vxi + dt3*leapCte*xi;
	velocYLeap=vyi + dt3*leapCte*yi;
	//Metodo de Euler

	outfile.open("metodoEuler3.dat");

	for(int i=0; i<pasos3*numeroVueltas;i++){

		float *euler = metodoEuler(velocXEuler, velocYEuler, distXEuler, distYEuler, dt3);

		distXEuler=*euler;
		distYEuler=*(euler+1);
		velocXEuler=*(euler+2);
		velocYEuler=*(euler+3);

		float momento = distXEuler*velocYEuler - distYEuler*velocXEuler;
		float energia = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXEuler*distXEuler + distYEuler*distYEuler);
		outfile << distXEuler << " " << distYEuler<<" " << velocXEuler << " " << velocYEuler<<" " << momento*MasaTierra<<" " << energia <<" " << dt3*i << endl;
	}

	outfile.close();


	//Metodo de Rungekutta 4th order
	outfile.open("metodoRungeKutta3.dat");

	for(int i=0; i<pasos3*numeroVueltas;i++){
		float *rk = metodoRungeKutta4(velocXRK, velocYRK, distXRK, distYRK, dt3);
		distXRK=*rk;
		distYRK=*(rk+1);
		velocXRK=*(rk+2);
		velocYRK=*(rk+3);

		float momento = distXRK*velocYRK - distYRK*velocXRK;
		float energia = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXRK*distXRK + distYRK*distYRK);
		outfile << distXRK<< " " << distYRK<<" " << velocXRK<< " " << velocYRK<< " " << momento*MasaTierra << " " << energia <<" " << dt3*i << endl;
	}

	outfile.close();
	
	//Metodo de LeapFrog
	outfile.open("metodoLeapFrog3.dat");

	for(int i=0; i<pasos3*numeroVueltas;i++){

		float *lp = metodoLeapFrog(velocXLeapB,velocYLeapB,distXLeapB,distYLeapB,velocXLeap,velocYLeap,distXLeap,distYLeap, dt3);

		distXLeapB=distXLeap;
		distYLeapB=distYLeap;
		velocXLeapB=velocXLeap;
		velocYLeapB=velocYLeap;

		distXLeap=*lp;
		distYLeap=*(lp+1);
		velocXLeap=*(lp+2);
		velocYLeap=*(lp+3);

		float momento = distXLeap*velocYLeap - distYLeap*velocXLeap;
		float energia = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXLeap*distXLeap + distYLeap*distYLeap);
		outfile << distXLeap<< " " << distYLeap<< " "<< velocXLeap << " " << velocYLeap <<" "<< momento*MasaTierra << " " << energia <<" " << dt3*i << endl;

	}

	outfile.close();


	

	return 0;
}



//implementamos los 3 metodos

float *metodoEuler(float velX, float velY, float posX, float posY, float h ){

	float cte = -MasaSol*ConstanteGravit/pow(sqrt(posX*posX + posY*posY),3);
	
	static float avance[4];
	float *p = avance;

	float dX =  h*velX;
	float dY =  h*velY;

	float dVX = cte*h*posX;
	float dVY = cte*h*posY;

	avance[0]= posX + dX;
	avance[1]= posY + dY;
	avance[2]= velX + dVX;
	avance[3]= velY + dVY;

	return p;

}

float *metodoRungeKutta4(float velX, float velY, float posX, float posY, float h ){

	float cte = -MasaSol*ConstanteGravit/pow(sqrt(posX*posX + posY*posY),3);
	
	static float avance[4];
	float *p = avance;

	float k1X = velX;
	float k1Y = velY;
	float k1VX = cte*posX;
	float k1VY = cte*posY;

	float nuevX1 = posX + h*k1X/2;
	float nuevY1 = posY + h*k1Y/2;
	float nuevVX1 = velX + h*k1VX/2;
	float nuevVY1 = velY + h*k1VY/2;

	float k2X = nuevVX1;
	float k2Y = nuevVY1;
	float k2VX = cte*nuevX1;
	float k2VY = cte*nuevY1;

	float nuevX2 = posX + h*k2X/2;
	float nuevY2 = posY + h*k2Y/2;
	float nuevVX2 = velX + h*k2VX/2;
	float nuevVY2 = velY + h*k2VY/2;

	float k3X = nuevVX2;
	float k3Y = nuevVY2;
	float k3VX = cte*nuevX2;
	float k3VY = cte*nuevY2;

	float nuevX3 = posX + h*k3X;
	float nuevY3 = posY + h*k3Y;
	float nuevVX3 = velX + h*k3VX;
	float nuevVY3 = velY + h*k3VY;

	float k4X = nuevVX3;
	float k4Y = nuevVY3;
	float k4VX = cte*nuevX3;
	float k4VY = cte*nuevY3;
	
	float dX =  h*(k1X+2*k2X+ 2*k3X +k4X)/6;
	float dY =  h*(k1Y+2*k2Y+ 2*k3Y+ k4Y)/6;

	float dVX =  h*(k1VX+2*k2VX+ 2*k3VX +k4VX)/6;
	float dVY =  h*(k1VY+2*k2VY+ 2*k3VY+ k4VY)/6;

	avance[0]= posX + dX;
	avance[1]= posY + dY;
	avance[2]= velX + dVX;
	avance[3]= velY + dVY;

	return p;

}

float *metodoLeapFrog(float velXB, float velYB, float posXB, float posYB, float velX, float velY, float posX, float posY, float h ){
	float cte = -MasaSol*ConstanteGravit/pow(sqrt(posX*posX + posY*posY),3);
	
	static float avance[4];
	float *p = avance;

	float dX =  2*h*velX;
	float dY =  2*h*velY;

	float dVX =  2*cte*h*posX;
	float dVY =  2*cte*h*posY;

	avance[0]= posXB + dX;
	avance[1]= posYB + dY;
	avance[2]= velXB + dVX;
	avance[3]= velYB + dVY;

	return p;
}




