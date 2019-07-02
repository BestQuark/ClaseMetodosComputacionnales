
#include <iostream>
using namespace std;

int *prodEle(int*,int*);
int prodPunt(int*);


int main () {

	int primerArr[5]= {1,2,3,4,5};
	int segundArr[5] = {10,20,30,40,50};
	
	int *pointer1 = primerArr;
	int *pointer2 = segundArr;

	int *productoEl = prodEle(pointer1,pointer2);
	int productoPunt = prodPunt(productoEl);  

	cout << "El producto de elementos es:" << endl;

	for(int i=0;i<5;i++){
			cout << *productoEl << endl;
			productoEl++;
	}
	
	cout << "El producto punto es:" << endl;
	cout << productoPunt << endl;

	return 0;
}


int prod[5];
int *prodEle(int *p1, int *p2){

	
	for(int i=0; i<5; i++){
		prod[i]= *p1 * *p2;
		p1++;
		p2++;
	}

	return prod;
}

int prodPunt(int *p1){
	int rta = 0;
		for(int i=0; i<5; i++){
			rta = rta + *p1;
			p1++;		
		}

	return rta;
	
}

