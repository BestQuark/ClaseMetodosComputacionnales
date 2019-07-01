#include<iostream>
#include<math.h>
using namespace std;


void primos(int, int);


int main(){
	cout << "Hallar numeros primos entre: ";
	float inic = 0;
	cin >> inic;

	cout << "y: ";
	float fina = 0;
	cin >> fina;



	
	cout << "Los numeros primos entre "<<inic <<" y "<< fina << " son: "  <<endl;
	
	primos(inic,fina);

	
	return 0;
}


void primos(int a, int b){

	for(int i = a; i<=b; i++){
		bool prim = true;
		for(int j = 2; j<=ceil(sqrt(i)); j++){
			if(i%j ==0){
				prim = false;
			}
		}
		if(prim == true){
			cout << i <<endl;
		}
	}

}
