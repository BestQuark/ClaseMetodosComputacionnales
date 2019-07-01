#include<iostream>
#include<math.h>
using namespace std;


float funcion(float);
float integRect(float,float, int);
float integTrap(float,float, int);
float integSimp(float, float, int);


int main(){
	cout << "Integrar funcion desde: ";
	float inic = 0;
	cin >> inic;

	cout << "Integrar funcion hasta: ";
	float fina = 0;
	cin >> fina;

	cout << "Cantidad de pasos: ";
	int pasos = 0;
	cin >> pasos;

	
	cout << "El valor de la integral con rectangulos es: " << integRect(inic, fina,pasos) <<endl;

	
	cout << "El valor de la integral con trapezoides es: " << integTrap(inic, fina,pasos) <<endl;
	
	cout << "El valor de la integral con simpson es: " << integSimp(inic, fina,pasos) <<endl;
	
	return 0;
}

float funcion(float p){
	return pow(p,2.0);
}

float integRect(float a, float b, int N){
	float h = (b-a)/N;
	float p = a;
	float rta = 0;
	for(int i=0; i<N; i++){
		p = p + h;
		rta = rta + h*funcion(p);
	}
	return rta;
}

float integTrap(float a, float b, int N){

	float h = (b-a)/N;
	float k = (funcion(a)+funcion(b))/2;
	return integRect(a,b,N)-h*k;
}

float integSimp(float a, float b, int N){
	
	float p = a;
	float extr = 0;
	float inter = 0;
	if(N%2==0){
	N = N+1;
	}
	
	float h = (b-a)/(N-1);
	

	for(int i = 1; i<(N-2); i = i+2){
		p = a + i*h;
		extr = extr + funcion(p);
		inter = inter + funcion(p+h);
	}
	
	extr = extr + funcion(b-h);
	
	return h*(funcion(a)+funcion(b)+4*extr+2*inter)/3;

}





