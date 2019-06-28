#include<iostream>
#include<math.h>
using namespace std;


float funcion(float);
float derivadaCent(float);
float derivadaNormal(float);


int main(){
	cout << "Punto para hallar la derivada central difference de la funcion: ";
	float num = 0;
	cin >> num;
	cout << "El valor de la derivada es: " << derivadaCent(num) <<endl;
	
	cout << "Punto para hallar la derivada normalita de la funcion: ";
	float num2 = 0;
	cin >> num2;
	cout << "El valor de la derivada es: " << derivadaNormal(num2) <<endl;
	return 0;
}

float funcion(float p){
	return pow(p,2.0);
}

float derivadaNormal(float p){
	float h = 0.0001;	
	return (funcion(p+h)-funcion(p))/h;
}

float derivadaCent(float p){
	float h = 0.0001;
	return (funcion(p+h/2)-funcion(p-h/2))/h;
}
