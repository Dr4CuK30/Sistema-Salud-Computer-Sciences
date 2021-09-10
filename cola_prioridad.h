#ifndef COLA_PRIORIDAD_H
#define COLA_PRIORIDAD_H
#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <iomanip>

// INTEGRANTES:
// Santiago Herrera - 20191020094
// Juan Hurtado - 20191020082
// David Saldarriaga - 20191020043

using namespace std;

class ColaPrioridad{
	
	int *arreglo, lenght, posActiva, ultimoElemento;
	
	public:
		ColaPrioridad(int x){
			lenght = x;
			arreglo = new int[lenght + 1];
			ultimoElemento = 0;
		}
		
		bool insertar(int valor);
		int atender();
		void imprimirArreglo();
		bool colaLlena();
	
};

bool ColaPrioridad::insertar(int valor){
	if (colaLlena()==false){
		int pivote = valor;
		posActiva = ultimoElemento + 1;
		do{
			if(pivote > arreglo[posActiva / 2]){
				int aux = arreglo[posActiva / 2];
				arreglo[posActiva / 2] = pivote;
				pivote = aux;
			}else{
				arreglo[posActiva] = pivote;
			}
			
			
			posActiva /= 2;
		}while(posActiva / 2 > 0);
		
		ultimoElemento++;
		return true;
	}
	
	return false;
	
}

int ColaPrioridad::atender(){
	int posHijoDerecho, posHijoIzq, menor;
	posActiva = 1;
	
	while(posActiva < lenght){
		posHijoIzq = posActiva * 2;
		posHijoDerecho = (posActiva * 2) + 1;
		menor = lenght;
		
		int nuevoMayor;
		if(arreglo[posHijoDerecho] >= arreglo[posHijoIzq] || arreglo[posHijoDerecho] > arreglo[menor]){
			nuevoMayor = posHijoDerecho;
		}else if(arreglo[posHijoIzq] > arreglo[posHijoDerecho] || arreglo[posHijoIzq] > arreglo[menor]){
			nuevoMayor = posHijoIzq;
		}else{
			nuevoMayor = menor;
		}
		
		arreglo[posActiva] = arreglo[nuevoMayor];
		posActiva = nuevoMayor;
	}
	
	arreglo[ultimoElemento] = 0;
	ultimoElemento--;
	
	
}

void ColaPrioridad::imprimirArreglo(){
	
	for(int i=1; i<=ultimoElemento; i++){
		cout<<arreglo[i]<<"||"<<i<<endl;	
	}
}

bool ColaPrioridad::colaLlena(){
	if(ultimoElemento == lenght){
		return true;
	}else{
		return false;
	}
}

#endif
