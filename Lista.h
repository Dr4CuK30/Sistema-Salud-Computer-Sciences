#ifndef LISTAS_H
#define LISTAS_H
#include <iostream>
#include "ArbolBinarioOrdenado.h"

using namespace std;

template <class T>
struct Nodo {
	T value;
	Nodo<T> *sig;
};
	
template <class T>
class Lista{
	private: 
		Nodo<T> *HEAD;
		int lenght;
	public: 
		Lista(){
			HEAD = NULL;
			lenght = 0;
		}
		bool lista_vacia();
		int Tam_lista();
		void insertar_inicio(T infoNueva);
		void insertar_pos(T infoNueva, int pos);
		void intertar_final(T infoNueva);
		bool eliminar(int pos);
		T obtenerDato(int pos);
		bool modificar(T infoNueva, int pos);
};

template <class T>
bool Lista<T>::lista_vacia(){
	if(lenght>0){
		return false;
	}
	return true;
}

template <class T>
int Lista<T>::Tam_lista(){
	return lenght;
}

template <class T>
void Lista<T>::insertar_pos(T infoNueva, int pos){
	if(pos<=0){
		insertar_inicio(infoNueva);
		return;
	} else if(pos>lenght){
		intertar_final(infoNueva);
		return;
	}
	Nodo<T> *nodo_ant = HEAD;
	Nodo<T> *aux;
	Nodo<T> *nuevo = new Nodo<T>;
	nuevo->value = infoNueva;
	for(int i = 0; i<pos-2; i++){
		nodo_ant = nodo_ant -> sig;
	}
	aux = nodo_ant -> sig;
	nuevo->sig = aux;
	nodo_ant -> sig = nuevo;
	lenght++;
}

template <class T>
bool Lista<T>::modificar(T infoNueva, int pos){
	if(pos<=0 || pos>lenght){
		return false;	
	}
	Nodo<T> *nodo = HEAD;
	for(int i=1; i<pos; i++){
		nodo = nodo->sig;
	}
	nodo->value = infoNueva;
	return true;
}

template <class T>
void Lista<T>::insertar_inicio(T infoNueva){
	Nodo<T> *nuevoHEAD = new Nodo<T>;
	nuevoHEAD->value = infoNueva;
	nuevoHEAD->sig = HEAD;
	HEAD = nuevoHEAD;
	lenght++;
}

template<class T>
void Lista<T>::intertar_final(T infoNueva){
	Nodo<T> *aux = HEAD;
	Nodo<T> *nuevoNodo = new Nodo<T>;
	nuevoNodo->value = infoNueva;
	nuevoNodo->sig = NULL;
	if(aux == NULL){
		HEAD = nuevoNodo;
		lenght++;
		return;
	}
	for(int i = 1; i<lenght;i++){
		aux = aux->sig;
	} 
	aux->sig=nuevoNodo;
	lenght++;
}

template<class T>
bool Lista<T>::eliminar(int pos){
	if(pos > lenght){
		return false;
	}
	if(pos == 1){
		Nodo<T> *newHead = HEAD->sig;
		delete HEAD;
		HEAD = newHead;
		lenght--;
		return true;
	}
	Nodo<T> *antes_eliminado;
	Nodo<T> *despues_eliminado;
	antes_eliminado = HEAD;
	for(int i = 1; i<pos-1; i++){
		antes_eliminado = antes_eliminado -> sig;
	}
	despues_eliminado = antes_eliminado->sig->sig;
	delete antes_eliminado->sig;
	antes_eliminado->sig = despues_eliminado;
	lenght--;
	return true;
}

template <class T>
T Lista<T>::obtenerDato(int pos){
	
	
	Nodo<T> *nodo = HEAD;
	for(int i = 1; i<pos; i++){
		if(nodo->sig == NULL){
			cout<<"hola"<<endl;
			return nodo->value;
		}
		nodo = nodo->sig;
	}
	return nodo->value;
}

	
#endif
