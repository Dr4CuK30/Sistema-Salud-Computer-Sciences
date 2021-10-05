#include <cstdlib>
#include <iostream>

#ifndef COLA_H     
#define COLA_H 

using namespace std;

template<class T>
struct nodoCola{
  T dato;
  nodoCola<T> *sig;
};


template<class T>
class Cola{
	nodoCola<T> *cab,*fin;
	int tamano = 0;
    
	public: 
		
		Cola(){
			cab=fin=NULL;
			tamano = 0;
		}
		
      void push(T);
      T pop();
      bool ColaVacia();
      int getSize();
 };

template<class T>
void Cola<T>::push(T i){
     nodoCola<T> *nuevo = new nodoCola<T>;
     
     nuevo->dato=i;
     nuevo->sig= NULL;
     
     if (cab==NULL) {
	 	cab=nuevo;
	 }
     else{
	 	fin->sig = nuevo;
		}
     fin=nuevo;
     tamano++;
}

template<class T>
T Cola<T>::pop(){
	T x;
    nodoCola<T> *aux = cab; 
    
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    tamano--;
    return x;
}

template<class T>
bool Cola<T>::ColaVacia(){
     
	return (cab==NULL);
}

template<class T>
int Cola<T>::getSize(){
	return tamano;
}

#endif
