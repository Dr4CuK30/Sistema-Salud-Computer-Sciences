#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <string>

using namespace std;


struct NodoArbol {
    NodoArbol *izquierda;
    NodoArbol *derecha;
    int clave;
    int valor;
};

class ArbolBinarioOrdenado {
    NodoArbol *raiz;
public:
	string etiqueta;
    ArbolBinarioOrdenado() {
        raiz = NULL;
//        this->etiqueta = etiqueta;
    }
    bool arbolVacio();
    void insertarNodo(int dato, int valor);
    bool eliminarNodo(int dato);
    int getInfo(int id);
    NodoArbol *organizarNodo(NodoArbol *nodoActual, NodoArbol *aux);
    NodoArbol *obtenerRaiz();
    NodoArbol *buscarNodo(int dato);
    NodoArbol *buscarPadre(int dato);
    void deforestacion(NodoArbol *nodoPrincipal);
    void limpiarArbol();
    
    void inorden(NodoArbol*);
	void preorden(NodoArbol*);
	void posorden(NodoArbol*);
};

bool ArbolBinarioOrdenado::arbolVacio() {
    if (raiz == NULL) {
        return true;
    }
    return false;
}

void ArbolBinarioOrdenado::insertarNodo(int dato, int valor_) {
    NodoArbol *aux = new NodoArbol;
    aux -> clave = dato;
    aux -> izquierda = NULL;
    aux -> derecha = NULL;
    aux -> valor = valor_;
    if (raiz == NULL) {
        raiz = aux;
    } else {
        NodoArbol *iterador;
        iterador = raiz;
        while (true) {
            if (valor_ <= iterador -> valor) {//aca hubo cambio
                if (iterador -> izquierda == NULL) {
                    iterador -> izquierda = aux;
                    break;
                } else {
                    iterador = iterador -> izquierda;
                }
            } else {
                if (iterador -> derecha == NULL) {
                    iterador -> derecha = aux;
                    break;
                } else {
                    iterador = iterador -> derecha;
                }
            }
        }
    }
}

bool ArbolBinarioOrdenado::eliminarNodo(int dato) {
    NodoArbol *nodoActual, *nodoCambio, *nodoPadre, *aux, *aux2;
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
            delete nodoActual;
        } else {
            return false;
        }
    }
    return true;
}

NodoArbol *ArbolBinarioOrdenado::organizarNodo(NodoArbol *nodoActual, NodoArbol *aux) {
    NodoArbol *nodoCambio, *aux2, *aux3;
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

NodoArbol *ArbolBinarioOrdenado::obtenerRaiz() {
    return raiz;
}

int ArbolBinarioOrdenado::getInfo(int id) {
    NodoArbol *nodo = buscarNodo(id);
    if (nodo != NULL) {
        return nodo->valor;
    }
    return 0;
}

NodoArbol *ArbolBinarioOrdenado::buscarNodo(int dato) {
    NodoArbol *iterador;
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

NodoArbol *ArbolBinarioOrdenado::buscarPadre(int dato) {
    NodoArbol *iterador, *aux;
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

void ArbolBinarioOrdenado::deforestacion(NodoArbol *nodoPrincipal) {
    if (nodoPrincipal != NULL) {
        deforestacion(nodoPrincipal -> izquierda);
        deforestacion(nodoPrincipal -> derecha);
        delete nodoPrincipal;
    }
}

void ArbolBinarioOrdenado::limpiarArbol() {
    if (raiz != NULL) {
        deforestacion(raiz);
    }
    raiz = NULL;
}

void ArbolBinarioOrdenado::inorden(NodoArbol* p){
	if(p != NULL){
		inorden(p->izquierda);
		cout<< p->clave << endl;
		inorden(p->derecha);
	}
}

void ArbolBinarioOrdenado::preorden(NodoArbol* p){
	if(p != NULL){
		cout<< p->clave << endl;
		preorden(p->izquierda);
		preorden(p->derecha);
	}
}

void ArbolBinarioOrdenado::posorden(NodoArbol* p){
	if(p != NULL){
		
		posorden(p->izquierda);
		posorden(p->derecha);
		cout<< p->clave << endl;
	}
}
#endif

