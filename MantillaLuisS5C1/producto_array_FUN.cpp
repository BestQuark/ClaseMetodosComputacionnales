
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
			cout << *(productoEl+i) << endl;	
	}
	
	cout << "El producto punto es:" << endl;
	cout << productoPunt << endl;

	return 0;
}



int *prodEle(int* p1, int* p2){
	static int prod[5];
	int *p;
	p = prod;

	for(int i=0; i<5; i++){
		prod[i]= *(p1+i) * *(p2+i);
	}
	return p;
}

int prodPunt(int *pp1){
	int rta = 0;
		for(int i=0; i<5; i++){
			rta = rta + *(pp1+i);		
		}

	return rta;
	
}

