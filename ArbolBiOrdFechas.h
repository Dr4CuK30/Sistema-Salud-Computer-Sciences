#ifndef ARBOLF_H
#define ARBOLF_H

#include <iostream>
#include <string>
#include "Fecha.h"

using namespace std;


struct NodoArbolFechas {
    NodoArbolFechas *izquierda;
    NodoArbolFechas *derecha;
    int clave;
    Fecha valor;
};

class ArbolBiOrdFechas {
    NodoArbolFechas *raiz;
private:
    string etiqueta;
    int tamArbol;

public:
	
    ArbolBiOrdFechas() {
        raiz = NULL;
        this->etiqueta = etiqueta;
        this->tamArbol = 0;
    }
    bool arbolVacio();

    void insertarNodo(int dato, Fecha valor);

    bool eliminarNodo(int dato);
    Fecha getInfo(int id);
    NodoArbolFechas *organizarNodo(NodoArbolFechas *nodoActual, NodoArbolFechas *aux);
    NodoArbolFechas *obtenerRaiz();
    NodoArbolFechas *buscarNodo(int dato);
    NodoArbolFechas *buscarPadre(int dato);
    void deforestacion(NodoArbolFechas *nodoPrincipal);
    void limpiarArbol();
    
    void inorden(NodoArbolFechas*);
	void preorden(NodoArbolFechas*);
	void posorden(NodoArbolFechas*);

    void inordenArray(NodoArbolFechas*, int currentIndex, int array[]);

    string getEtiqueta()
    {
        return this->etiqueta;
    }

    void setEtiqueta(string etiqueta)
    {
        this->etiqueta = etiqueta;
    }

    
    int getTamArbol()
    {
        return this->tamArbol;
    }


    void setTamArbol(int tamArbol)
    {
        this->tamArbol = tamArbol;
    }
};

bool ArbolBiOrdFechas::arbolVacio() {
    if (raiz == NULL) {
        return true;
    }
    return false;
}

void ArbolBiOrdFechas::insertarNodo(int dato, Fecha valor_) {
    NodoArbolFechas *aux = new NodoArbolFechas;
    aux -> clave = dato;
    aux -> izquierda = NULL;
    aux -> derecha = NULL;
    aux -> valor = valor_;
    if (raiz == NULL) {
        raiz = aux;
        this->tamArbol++;
    } else {
        NodoArbolFechas *iterador;
        iterador = raiz;

        while (true) {
            string comparacion = esMayorQue(valor_, iterador->valor);

            // Mayor o igual
            if (comparacion=="menor") {
                if (iterador -> izquierda == NULL) {
                    iterador -> izquierda = aux;
                    this->tamArbol++;
                    break;
                } else {
                    iterador = iterador -> izquierda;
                }
            // Menor
            } else {
                if (iterador -> derecha == NULL) {
                    iterador -> derecha = aux;
                    this->tamArbol++;
                    break;
                } else {
                    iterador = iterador -> derecha;
                }
            }
        }

    }
}

bool ArbolBiOrdFechas::eliminarNodo(int dato) {
    NodoArbolFechas *nodoActual, *nodoCambio, *nodoPadre, *aux, *aux2;
    if (raiz == NULL) {
        return false;
    } else {
        nodoActual = buscarNodo(dato);
        if (nodoActual != NULL) {
            if (nodoActual -> clave == raiz -> clave) {
                if (nodoActual -> derecha != NULL) {
                    aux = nodoActual -> derecha;
                    nodoCambio = organizarNodo(nodoActual, aux);
                } else {
                    nodoCambio = raiz -> izquierda;
                }
                raiz = nodoCambio;
            } else {
                nodoPadre = buscarPadre(dato);
                if (nodoActual -> derecha != NULL) {
                    aux = nodoActual -> derecha;

                    nodoCambio = organizarNodo(nodoActual, aux);

                    if (dato <= nodoPadre -> clave) {
                        nodoPadre -> izquierda = nodoCambio;
                    } else {
                        nodoPadre -> derecha = nodoCambio;
                    }
                } else {
                    if (dato <= nodoPadre -> clave) {
                        nodoPadre -> izquierda = nodoActual -> izquierda;
                    } else {
                        nodoPadre -> derecha = nodoActual -> izquierda;
                    }
                }
            }
            this->tamArbol--;
            delete nodoActual;
        } else {
            return false;
        }
    }
    return true;
}

NodoArbolFechas *ArbolBiOrdFechas::organizarNodo(NodoArbolFechas *nodoActual, NodoArbolFechas *aux) {
    NodoArbolFechas *nodoCambio, *aux2, *aux3;
    aux3 = aux -> izquierda;
    if (aux3 != NULL) {
        nodoCambio = aux -> izquierda;
        aux2 = aux;
        while (nodoCambio -> izquierda != NULL) {
            aux2 = nodoCambio;
            nodoCambio = aux -> izquierda;
        }
        if (nodoCambio -> derecha != NULL) {
            aux2 -> izquierda = nodoCambio -> derecha;
        } else {
            aux2 -> izquierda = NULL;
        }
        nodoCambio -> derecha = aux;
    } else {
        nodoCambio = aux;
    }
    nodoCambio -> izquierda = nodoActual -> izquierda;
    return nodoCambio;
}

NodoArbolFechas *ArbolBiOrdFechas::obtenerRaiz() {
    return raiz;
}

Fecha ArbolBiOrdFechas::getInfo(int id) {
    NodoArbolFechas *nodo = buscarNodo(id);

    Fecha fechanula;
    fechanula.anho=0;
    fechanula.mes=0;
    fechanula.dia=0;

    if (nodo != NULL) {
        return nodo->valor;
    }
    return fechanula;
}

NodoArbolFechas *ArbolBiOrdFechas::buscarNodo(int dato) {
    NodoArbolFechas *iterador;
    if (raiz != NULL) {
        iterador = raiz;
        while (dato != iterador -> clave) {
            if (dato <= iterador -> clave) {
                iterador = iterador -> izquierda;
            } else {
                iterador = iterador -> derecha;
            }
            if (iterador == NULL) {
                return NULL;
            }
        }
        return iterador;
    } else {
        return raiz;
    }
}

NodoArbolFechas *ArbolBiOrdFechas::buscarPadre(int dato) {
    NodoArbolFechas *iterador, *aux;
    if (dato == raiz -> clave) {
        return NULL;
    }
    iterador = raiz;
    while (dato != iterador -> clave) {
        aux = iterador;
        if (dato <= iterador -> clave) {
            iterador = iterador -> izquierda;
        } else {
            iterador = iterador -> derecha;
        }
        if (iterador == NULL) {
            return NULL;
        }
    }
    if (iterador == NULL) {
        return NULL;
    }
    return aux;
}

void ArbolBiOrdFechas::deforestacion(NodoArbolFechas *nodoPrincipal) {
    if (nodoPrincipal != NULL) {
        deforestacion(nodoPrincipal -> izquierda);
        deforestacion(nodoPrincipal -> derecha);
        delete nodoPrincipal;
    }
}

void ArbolBiOrdFechas::limpiarArbol() {
    if (raiz != NULL) {
        deforestacion(raiz);
    }
    raiz = NULL;
}

void ArbolBiOrdFechas::inorden(NodoArbolFechas* p){
	if(p != NULL){
		inorden(p->izquierda);
		cout<< p->clave << endl;
		inorden(p->derecha);
	}
}

void inorderComplement(NodoArbolFechas* p, int currentIndex, int orderdArray[], int lenght){
    if(p != NULL){
		inorderComplement(p->izquierda, currentIndex, orderdArray, lenght);
        while (orderdArray[currentIndex]!=0)
        {
            currentIndex++;
            if (currentIndex==lenght)
            {
                break;
            }
            
        }
		orderdArray[currentIndex] = p->clave;
        currentIndex++;
		inorderComplement(p->derecha, currentIndex, orderdArray, lenght);
	}
}

void ArbolBiOrdFechas::inordenArray(NodoArbolFechas* p, int currentIndex, int array[]){
	
    
    const int lenght = this->tamArbol;
    
    for(int i=0;i<lenght;i++){
        array[i] = 0;
    }

    inorderComplement(p, currentIndex, array, lenght);
}



void ArbolBiOrdFechas::preorden(NodoArbolFechas* p){
	if(p != NULL){
		cout<< p->clave << endl;
		preorden(p->izquierda);
		preorden(p->derecha);
	}
}

void ArbolBiOrdFechas::posorden(NodoArbolFechas* p){
	if(p != NULL){
		
		posorden(p->izquierda);
		posorden(p->derecha);
		cout<< p->clave << endl;
	}
}
#endif


