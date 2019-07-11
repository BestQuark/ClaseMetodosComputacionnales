//importamos los paquetes que usaremos
#include <iostream>
#include <fstream>
using namespace std;

//definimos las funciones que usaremos en el main




//definimos las variables globales (usamos unidades de UA, Masas Solares y yrs)

float MasaSol = 1;
float ConstanteGravit = 39.478;
float distTierraSol = 1;

int main () {
	
	float distX[];
	float distY[];

	
	
	

	return 0;
}



//implementamos los 3 metodos

float *metodoEuler(float velX, float velY, float posX, float posY, float h ){

	float cte = -MasaSol*ConstanteGravit/(distTierraSol*distTierraSol*distTierraSol);
	
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

	float cte = -MasaSol*ConstanteGravit/(distTierraSol*distTierraSol*distTierraSol);
	
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
	float cte = -MasaSol*ConstanteGravit/(distTierraSol*distTierraSol*distTierraSol);
	
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




