//importamos los paquetes que usaremos
#include <iostream>
#include <fstream>
#include<cmath>
using namespace std;

//definimos las funciones que usaremos en el main

double *metodoEuler(double , double , double , double , double );
double *metodoRungeKutta4(double , double , double , double , double );
double *metodoLeapFrog(double , double , double , double , double , double , double , double , double );


//definimos las variables globales (usamos unidades de UA, Masas Solares y yrs)

double MasaSol = 1;
double MasaTierra = 0.000003003; 
double ConstanteGravit = 39.478;

double orbita = 2*3.14159;


int pasos1 = 10000;
double dt1 = orbita/pasos1;

int pasos2 = 1000;
double dt2 = orbita/pasos2;

int pasos3 = 500;
double dt3 = orbita/pasos3;

//hallamos el numero de pasos que necesitamos para cada dt para completar 20 anios 

int numeroVueltas1 =int(20/dt1);
int numeroVueltas2 =int(20/dt2);
int numeroVueltas3 =int(20/dt3);


//condiciones iniciales
double xi = 0.1163;
double yi = 0.9772;
double vxi = -6.35;
double vyi = 0.606;


int main () {

//Evolucion temporal del sistema PRIMER dt :

//condiciones iniciales para cada metodo
	
	//Euler
	double distXEuler=xi;
	double distYEuler=yi;
	double velocXEuler=vxi;
	double velocYEuler=vyi;

	//RungeKutta 4th Order
	double distXRK=xi;
	double distYRK=yi;
	double velocXRK=vxi;
	double velocYRK=vyi;

	//LeapFrog

	double leapCte = -MasaSol*ConstanteGravit/pow(sqrt(xi*xi + yi*yi),3);

	double distXLeapB=xi;
	double distYLeapB=yi;
	double velocXLeapB=vxi;
	double velocYLeapB=vyi;

	//hacemos la inicializacion del punto siguiente de leapfrog

	double distXLeap=xi + dt1*vxi;
	double distYLeap=yi + dt1*vyi;
	double velocXLeap=vxi + dt1*leapCte*xi;
	double velocYLeap=vyi + dt1*leapCte*yi;

	//Metodo de Euler
	ofstream outfile;

	outfile.open("metodoEuler1.dat");
	//en cada un o de estos fors estamos haciendo la evolucion temporal de estos sistemas y vamos imprimiendo cada paso que da
	for(int i=0; i<numeroVueltas1;i++){

		double *euler = metodoEuler(velocXEuler, velocYEuler, distXEuler, distYEuler, dt1);

		distXEuler=*euler;
		distYEuler=*(euler+1);
		velocXEuler=*(euler+2);
		velocYEuler=*(euler+3);
		
		//calculamos el momento y las energias del sistema
		double momento = distXEuler*velocYEuler - distYEuler*velocXEuler;
		double energiaU = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXEuler*distXEuler + distYEuler*distYEuler);
		double energiaK = MasaTierra*(velocXEuler*velocXEuler+velocYEuler*velocYEuler)/2;
		outfile << distXEuler << " " << distYEuler<<" " << velocXEuler << " " << velocYEuler<<" " << momento*MasaTierra<<" " << energiaU <<" " << energiaK <<" "<< dt1*i << endl;
	}

	outfile.close();



	//Metodo de Rungekutta 4th order
	outfile.open("metodoRungeKutta1.dat");

	for(int i=0; i<numeroVueltas1;i++){
		double *rk = metodoRungeKutta4(velocXRK, velocYRK, distXRK, distYRK, dt1);
		distXRK=*rk;
		distYRK=*(rk+1);
		velocXRK=*(rk+2);
		velocYRK=*(rk+3);
		//calculamos el momento y las energias del sistema
		double momento = distXRK*velocYRK - distYRK*velocXRK;
		double energiaU = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXRK*distXRK + distYRK*distYRK);
		double energiaK = MasaTierra*(velocXRK*velocXRK+velocYRK*velocYRK)/2;
		outfile << distXRK<< " " << distYRK<<" " << velocXRK<< " " << velocYRK<< " " << momento*MasaTierra << " " << energiaU <<" " << energiaK  <<" " << dt1*i << endl;
	}

	outfile.close();
	
	//Metodo de LeapFrog
	outfile.open("metodoLeapFrog1.dat");

	for(int i=0; i<numeroVueltas1;i++){

		double *lp = metodoLeapFrog(velocXLeapB,velocYLeapB,distXLeapB,distYLeapB,velocXLeap,velocYLeap,distXLeap,distYLeap, dt1);

		distXLeapB=distXLeap;
		distYLeapB=distYLeap;
		velocXLeapB=velocXLeap;
		velocYLeapB=velocYLeap;

		distXLeap=*lp;
		distYLeap=*(lp+1);
		velocXLeap=*(lp+2);
		velocYLeap=*(lp+3);
		//calculamos el momento y las energias del sistema
		double momento = distXLeap*velocYLeap - distYLeap*velocXLeap;
		double energiaU = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXLeap*distXLeap + distYLeap*distYLeap);
		double energiaK = MasaTierra*(velocXLeap*velocXLeap+velocYLeap*velocYLeap)/2;
		outfile << distXLeap<< " " << distYLeap<< " "<< velocXLeap << " " << velocYLeap <<" "<< momento*MasaTierra << " " << energiaU <<" " << energiaK <<" " << dt1*i << endl;

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

	for(int i=0; i<numeroVueltas2;i++){

		double *euler = metodoEuler(velocXEuler, velocYEuler, distXEuler, distYEuler, dt2);

		distXEuler=*euler;
		distYEuler=*(euler+1);
		velocXEuler=*(euler+2);
		velocYEuler=*(euler+3);
		//calculamos el momento y las energias del sistema
		double momento = distXEuler*velocYEuler - distYEuler*velocXEuler;
		double energiaU = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXEuler*distXEuler + distYEuler*distYEuler);
		double energiaK = MasaTierra*(velocXEuler*velocXEuler+velocYEuler*velocYEuler)/2;
		outfile << distXEuler << " " << distYEuler<<" " << velocXEuler << " " << velocYEuler<<" " << momento*MasaTierra<<" " << energiaU<<" " << energiaK <<" " << dt2*i << endl;
	}

	outfile.close();



	//Metodo de Rungekutta 4th order
	outfile.open("metodoRungeKutta2.dat");

	for(int i=0; i<numeroVueltas2;i++){
		double *rk = metodoRungeKutta4(velocXRK, velocYRK, distXRK, distYRK, dt2);
		distXRK=*rk;
		distYRK=*(rk+1);
		velocXRK=*(rk+2);
		velocYRK=*(rk+3);
		//calculamos el momento y las energias del sistema
		double momento = distXRK*velocYRK - distYRK*velocXRK;
		double energiaU = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXRK*distXRK + distYRK*distYRK);
		double energiaK = MasaTierra*(velocXRK*velocXRK+velocYRK*velocYRK)/2;
		outfile << distXRK<< " " << distYRK<<" " << velocXRK<< " " << velocYRK<< " " << momento*MasaTierra << " " << energiaU <<" " << energiaK <<" " << dt2*i << endl;
	}

	outfile.close();
	
	//Metodo de LeapFrog
	outfile.open("metodoLeapFrog2.dat");

	for(int i=0; i<numeroVueltas2;i++){

		double *lp = metodoLeapFrog(velocXLeapB,velocYLeapB,distXLeapB,distYLeapB,velocXLeap,velocYLeap,distXLeap,distYLeap, dt2);

		distXLeapB=distXLeap;
		distYLeapB=distYLeap;
		velocXLeapB=velocXLeap;
		velocYLeapB=velocYLeap;

		distXLeap=*lp;
		distYLeap=*(lp+1);
		velocXLeap=*(lp+2);
		velocYLeap=*(lp+3);
		//calculamos el momento y las energias del sistema
		double momento = distXLeap*velocYLeap - distYLeap*velocXLeap;
		double energiaU = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXLeap*distXLeap + distYLeap*distYLeap);
		double energiaK = MasaTierra*(velocXLeap*velocXLeap+velocYLeap*velocYLeap)/2;
		outfile << distXLeap<< " " << distYLeap<< " "<< velocXLeap << " " << velocYLeap <<" "<< momento*MasaTierra << " " << energiaU<<" " << energiaK  <<" " << dt2*i << endl;

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

	for(int i=0; i<numeroVueltas3;i++){

		double *euler = metodoEuler(velocXEuler, velocYEuler, distXEuler, distYEuler, dt3);

		distXEuler=*euler;
		distYEuler=*(euler+1);
		velocXEuler=*(euler+2);
		velocYEuler=*(euler+3);
		//calculamos el momento y las energias del sistema
		double momento = distXEuler*velocYEuler - distYEuler*velocXEuler;
		double energiaU = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXEuler*distXEuler + distYEuler*distYEuler);
		double energiaK = MasaTierra*(velocXEuler*velocXEuler+velocYEuler*velocYEuler)/2;
		outfile << distXEuler << " " << distYEuler<<" " << velocXEuler << " " << velocYEuler<<" " << momento*MasaTierra<<" " << energiaU<<" " << energiaK  <<" " << dt3*i << endl;
	}

	outfile.close();


	//Metodo de Rungekutta 4th order
	outfile.open("metodoRungeKutta3.dat");

	for(int i=0; i<numeroVueltas3;i++){
		double *rk = metodoRungeKutta4(velocXRK, velocYRK, distXRK, distYRK, dt3);
		distXRK=*rk;
		distYRK=*(rk+1);
		velocXRK=*(rk+2);
		velocYRK=*(rk+3);
		//calculamos el momento y las energias del sistema
		double momento = distXRK*velocYRK - distYRK*velocXRK;
		double energiaU = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXRK*distXRK + distYRK*distYRK);
		double energiaK = MasaTierra*(velocXRK*velocXRK+velocYRK*velocYRK)/2;
		outfile << distXRK<< " " << distYRK<<" " << velocXRK<< " " << velocYRK<< " " << momento*MasaTierra << " " << energiaU <<" " << energiaK <<" " << dt3*i << endl;
	}

	outfile.close();
	
	//Metodo de LeapFrog
	outfile.open("metodoLeapFrog3.dat");

	for(int i=0; i<numeroVueltas3;i++){

		double *lp = metodoLeapFrog(velocXLeapB,velocYLeapB,distXLeapB,distYLeapB,velocXLeap,velocYLeap,distXLeap,distYLeap, dt3);

		distXLeapB=distXLeap;
		distYLeapB=distYLeap;
		velocXLeapB=velocXLeap;
		velocYLeapB=velocYLeap;

		distXLeap=*lp;
		distYLeap=*(lp+1);
		velocXLeap=*(lp+2);
		velocYLeap=*(lp+3);
		//calculamos el momento y las energias del sistema
		double momento = distXLeap*velocYLeap - distYLeap*velocXLeap;
		double energiaU = -ConstanteGravit*MasaSol*MasaTierra/sqrt(distXLeap*distXLeap + distYLeap*distYLeap);
		double energiaK = MasaTierra*(velocXLeap*velocXLeap+velocYLeap*velocYLeap)/2;
		outfile << distXLeap<< " " << distYLeap<< " "<< velocXLeap << " " << velocYLeap <<" "<< momento*MasaTierra << " " << energiaU <<" " << energiaK <<" " << dt3*i << endl;

	}

	outfile.close();


	

	return 0;
}



//implementamos los 3 metodos

double *metodoEuler(double velX, double velY, double posX, double posY, double h ){

	double cte = -MasaSol*ConstanteGravit/pow(sqrt(posX*posX + posY*posY),3);
	//definimos una nueva lista con su respectivo pointer
	static double avance[4];
	double *p = avance;
	//hallamos el avance de posicion en cada direccion dado por la velocidad que tiene 
	double dX =  h*velX;
	double dY =  h*velY;
	//hallamos el avance en velocidad de cada direccion la cual sigue la ecucacion de la fuerza gravitacional
	double dVX = cte*h*posX;
	double dVY = cte*h*posY;
	//llenamos la lista que queremos devolver
	avance[0]= posX + dX;
	avance[1]= posY + dY;
	avance[2]= velX + dVX;
	avance[3]= velY + dVY;

	return p;

}

double *metodoRungeKutta4(double velX, double velY, double posX, double posY, double h ){

	double cte1 = -MasaSol*ConstanteGravit/pow(sqrt(posX*posX + posY*posY),3);
	//definimos una nueva lista con su respectivo pointer
	static double avance[4];
	double *p = avance;
	//definimos nuestras nuevas pendientes de velocidad y posicion
	double k1X = velX;
	double k1Y = velY;
	double k1VX = cte1*posX;
	double k1VY = cte1*posY;
	//calculamos con las pendientes nuevas el avance en posicion y velocidad hasta la mitad del paso dt
	double nuevX1 = posX + h*k1X/2;
	double nuevY1 = posY + h*k1Y/2;
	double nuevVX1 = velX + h*k1VX/2;
	double nuevVY1 = velY + h*k1VY/2;
	//actualizamos nuestra posicion en la ecucacion de fuerza gravitacional para hallar otra pendiente
	double cte2 = -MasaSol*ConstanteGravit/pow(sqrt(nuevX1*nuevX1 + nuevY1*nuevY1),3);
	//repetimos este proceso usando una nueva pendiente
	double k2X = nuevVX1;
	double k2Y = nuevVY1;
	double k2VX = cte2*nuevX1;
	double k2VY = cte2*nuevY1;
	//calculamos con las pendientes nuevas el avance en posicion y velocidad hasta la mitad del paso dt
	double nuevX2 = posX + h*k2X/2;
	double nuevY2 = posY + h*k2Y/2;
	double nuevVX2 = velX + h*k2VX/2;
	double nuevVY2 = velY + h*k2VY/2;
	//actualizamos nuestra posicion en la ecucacion de fuerza gravitacional para hallar otra pendiente
	double cte3 = -MasaSol*ConstanteGravit/pow(sqrt(nuevX2*nuevX2 + nuevY2*nuevY2),3);
	//repetimos este proceso usando una nueva pendiente
	double k3X = nuevVX2;
	double k3Y = nuevVY2;
	double k3VX = cte3*nuevX2;
	double k3VY = cte3*nuevY2;
	//calculamos con las pendientes nuevas el avance en posicion y velocidad dado todo el paso dt
	double nuevX3 = posX + h*k3X;
	double nuevY3 = posY + h*k3Y;
	double nuevVX3 = velX + h*k3VX;
	double nuevVY3 = velY + h*k3VY;
	//actualizamos nuestra posicion en la ecucacion de fuerza gravitacional para hallar otra pendiente
	double cte4 = -MasaSol*ConstanteGravit/pow(sqrt(nuevX3*nuevX3 + nuevY3*nuevY3),3);

	double k4X = nuevVX3;
	double k4Y = nuevVY3;
	double k4VX = cte4*nuevX3;
	double k4VY = cte4*nuevY3;
	//hallamos cuanto avanza promediando como lo indica el metodo de rungekutta
	double dX =  h*(k1X+2*k2X+ 2*k3X +k4X)/6;
	double dY =  h*(k1Y+2*k2Y+ 2*k3Y+ k4Y)/6;

	double dVX =  h*(k1VX+2*k2VX+ 2*k3VX+ k4VX)/6;
	double dVY =  h*(k1VY+2*k2VY+ 2*k3VY+ k4VY)/6;
	//llenamos el arreglo que vamos a retornar (retornamos el pointer que identifica a este arreglo)
	avance[0]= posX + dX;
	avance[1]= posY + dY;
	avance[2]= velX + dVX;
	avance[3]= velY + dVY;

	return p;

}

double *metodoLeapFrog(double velXB, double velYB, double posXB, double posYB, double velX, double velY, double posX, double posY, double h ){
	double cte = -MasaSol*ConstanteGravit/pow(sqrt(posX*posX + posY*posY),3);
	//definimos una nueva lista con su respectivo pointer
	static double avance[4];
	double *p = avance;

	//calculamos cuanto avanza la posicion y la velocidad con el metodo de leap frog
	double dX =  2*h*velX;
	double dY =  2*h*velY;

	double dVX =  2*cte*h*posX;
	double dVY =  2*cte*h*posY;
	//llenamos el arreglo que vamos a devolver
	avance[0]= posXB + dX;
	avance[1]= posYB + dY;
	avance[2]= velXB + dVX;
	avance[3]= velYB + dVY;

	return p;
}




