#include <conio.h>
#include <iostream>
#ifndef ARBOLROJINEGRO_H
#define ARBOLROJINEGRO_H
using namespace std;

template <class T>
struct NodoArbolRJ {
	//Clave para ordenar el árbole
	int clave;

	// Apuntador a tipo de dato (facilitar búsquedas usando árboles on deck)
	T * data;

	bool color = true;
	//TRUE - ROJO
	//FALSE - NEGRO
	NodoArbolRJ<T> *izq, *der, *padre;
};

template <class T>
class ArbolRojiNegro {
private:
	NodoArbolRJ<T> *raiz;
	void destruir(NodoArbolRJ<T>*);
		
public:
	ArbolRojiNegro() {
		raiz = NULL;
	}

	NodoArbolRJ<T>* raiz_arbol() { return raiz; }
	bool insertar(T * campo);

	NodoArbolRJ<T>* buscar_arbol(int, NodoArbolRJ<T>*, NodoArbolRJ<T>*);
	NodoArbolRJ<T>* rotacion_sencilla_izq(NodoArbolRJ<T>*);
	NodoArbolRJ<T>* rotacion_sencilla_der(NodoArbolRJ<T>*);

	bool eliminar(int);

	NodoArbolRJ<T>* buscarNodo(int, NodoArbolRJ<T>**, NodoArbolRJ<T>*);
	
	void inorden(NodoArbolRJ<T>*);
	void preorden(NodoArbolRJ<T>*);
	void posorden(NodoArbolRJ<T>*);

	void ajustar_supresion(NodoArbolRJ<T>*);
	
	//Destructor del árbol
	~ArbolRojiNegro(){
		destruir(raiz);
	}
};


template <class T>
bool ArbolRojiNegro<T>::insertar(T * campo) {
	int clave = campo->id;
	NodoArbolRJ<T> *padre;
	if (raiz == NULL) {
		raiz = new NodoArbolRJ<T>;
		raiz->data = campo;
		raiz->clave = clave;
		
		raiz->color = false;
		raiz->izq = raiz->der = raiz->padre = NULL;
		return 0;
	}
	padre = buscar_arbol(clave, raiz, NULL);
	if (padre == NULL) return false;

	NodoArbolRJ<T>* x;
	x = new NodoArbolRJ<T>;
	x->clave = clave;
	x->padre = padre;
	x->izq = x->der = NULL;
	x->data = campo;

	if (clave < padre->clave) {
		padre->izq = x;
	}
	else {
		padre->der = x;
	}

	NodoArbolRJ<T>* abuelo, *tio;

	while (padre->color && x->color) {

		abuelo = padre->padre;
		if (abuelo->izq == padre) tio = abuelo->der;
		else					  tio = abuelo->izq;

		if (tio != NULL && tio->color && padre->color) {
			//El padre y el tio del nuevo nodo son rojos - caso 1
			padre->color = !padre->color;
			tio->color = !tio->color;
			abuelo->color = !abuelo->color;
		}
		else {
			if (abuelo->izq == padre && padre->der == x) {
				rotacion_sencilla_izq(padre);
				x = padre;
				padre = abuelo->izq;
			}
			else if (abuelo->der == padre && padre->izq == x){
				rotacion_sencilla_der(padre);
				x = padre;
				padre = abuelo->der;
			}

			if (abuelo->izq == padre && padre->izq == x) {
				padre->color = !padre->color;
				abuelo->color = !abuelo->color;
				rotacion_sencilla_der(abuelo);
				abuelo = padre->padre;
				
			}
			else if (abuelo->der == padre && padre->der == x) {
				padre->color = !padre->color;
				abuelo->color = !abuelo->color;
				rotacion_sencilla_izq(abuelo);	
				abuelo = padre->padre;
				
				
			}

			if (padre->padre == NULL) {
				raiz = padre;
			}
		}		
		if (abuelo == NULL || abuelo->padre == NULL) {
			break;
		}
		x = abuelo;
		padre = abuelo->padre;
		
	}
	if (raiz->color) raiz->color = false;
	return true;

}

template <class T>
NodoArbolRJ<T>* ArbolRojiNegro<T>::buscar_arbol(int n, NodoArbolRJ<T>* p, NodoArbolRJ<T>* q) {
	if (p == NULL) return q;
	if (n < p->clave) {
		q = p;
		q = buscar_arbol(n, p->izq, q);
		return q;
	}
	else if (n > p->clave) {
		q = p;
		q = buscar_arbol(n, p->der, q);
		return q;
	}
	else
	return NULL;
}

template <class T>
NodoArbolRJ<T>* ArbolRojiNegro<T>::rotacion_sencilla_izq(NodoArbolRJ<T>* padre) {
	NodoArbolRJ<T>* aux = padre->der;
	aux->padre = padre->padre;
	padre->der = aux->izq;
	if (aux->izq != NULL) {
		aux->izq->padre = padre;
	}
	aux->izq = padre;
	if (padre->padre != NULL) {
		if (padre->padre->der == padre) {
			padre->padre->der = aux;
		}
		else {
			padre->padre->izq = aux;
		}
	}
	else {
		raiz = aux;
	}
	padre->padre = aux;

	return aux;	
}

template <class T>
NodoArbolRJ<T>* ArbolRojiNegro<T>::rotacion_sencilla_der(NodoArbolRJ<T>* padre) {
	NodoArbolRJ<T>* aux = padre->izq;
	aux->padre = padre->padre;
	padre->izq = aux->der;
	if (aux->der != NULL) {
		aux->der->padre = padre;
	}
	aux->der = padre;
	if (padre->padre != NULL) {
		if (padre->padre->der == padre) {
			padre->padre->der = aux;
		}
		else {
			padre->padre->izq = aux;
		}
	}
	else {
		raiz = aux;
	}
	padre->padre = aux;
	return aux;
}

template <class T>
void ArbolRojiNegro<T>::inorden(NodoArbolRJ<T>* p) {
	if (p != NULL) {
		inorden(p->izq);
		if (p->color) cout << "ROJO => ";
		else cout << "NEGRO => ";
		cout << p->data->data.getNombre() << endl;
		inorden(p->der);
	}
}

template <class T>
void ArbolRojiNegro<T>::preorden(NodoArbolRJ<T>* p) {
	if (p != NULL) {
		if (p->color) cout << "ROJO => ";
		else cout << "NEGRO => ";
		cout << p->data->data.getNombre() << endl;
		preorden(p->izq);
		preorden(p->der);
	}
}

template <class T>
void ArbolRojiNegro<T>::posorden(NodoArbolRJ<T>* p) {
	if (p != NULL) {
		posorden(p->izq);
		posorden(p->der);
		if (p->color) cout << "ROJO => ";
		else cout << "NEGRO => ";
		cout << p->data->data.getNombre() << endl;
	}
}


template <class T>
bool ArbolRojiNegro<T>::eliminar(int clave) {
	NodoArbolRJ<T> *q, *p = raiz, *x;
	q = buscarNodo(clave, &p, NULL);
	if (q == NULL) return false;

	//Verificar # de hijos
	if (q->der != NULL && q->izq != NULL) {
		//Dos Hijos Buscar el de la derecha mas a la izq
		x = q->der;
		while (x->izq != NULL) {
			x = x->izq;
		}
		q->clave = x->clave;
		if (x->der != NULL) {
			x->clave = x->der->clave;
			x = x->der;
		}
	}
	else if (q->der != NULL){
		//Solo hijo derecho
		q->clave = q->der->clave;
		x = q->der;
	}
	else if (q->izq != NULL) {
		//Solo hijo izq
		q->clave = q->izq->clave;
		x = q->izq;
	}
	else{
		//Sin hijos
		x = q;
	}

	ajustar_supresion(x);
	if (x->padre->der == x) {
		x->padre->der = NULL;
	}
	else if (x->padre->izq == x) {
		x->padre->izq = NULL;
	}
	delete x;

	return true;
}

template <class T>
// claveBus = clave a buscar
NodoArbolRJ<T>* ArbolRojiNegro<T>::buscarNodo(int claveBus, NodoArbolRJ<T>** p, NodoArbolRJ<T>*q) {
	if ((*p) == NULL) return NULL;

	//Búsqueda hacia la izquierda
	if (claveBus < (*p)->clave) {
		q = *p;
		*p = (*p)->izq;
		q = buscarNodo(claveBus, p, q);
		return q;
	}
	//Búsqueda hacia la derecha
	else if (claveBus > (*p)->clave) {
		q = *p;
		*p = (*p)->der;
		q = buscarNodo(claveBus, p, q);
		return q;
	}
	//Nodo Encontrado!
	else if (claveBus == (*p)->clave) {
		return *p;
	}
	else return q;
}


template <class T>
void ArbolRojiNegro<T>::ajustar_supresion(NodoArbolRJ<T>* x) {
	NodoArbolRJ<T>* w;
	while (x != raiz && !x->color) {
		if (x = x->padre->izq) {
			w = x->padre->der;
			if (w != NULL && w->color) {
				w->color = false;
				x->padre->color = true;
				rotacion_sencilla_izq(x->padre);
				w = x->padre->der;
			}

			if ((w->der == NULL || !w->der->color) && (w->izq == NULL || !w->izq->color)) {
				w->color = true;
				x = x->padre;
			}
			else {
				if (w->der == NULL || !w->der->color) {
					if (w->izq != NULL) w->izq->color = false;
					w->color = true;
					rotacion_sencilla_der(w);
					w = x->padre->der;
				}
				w->color = x->padre->color;
				x->padre->color = false;
				if (w->der != NULL) w->der->color = false;
				rotacion_sencilla_izq(x->padre);
				x = raiz;
			}
		}
		else {
			w = x->padre->izq;
			if (w != NULL && w->color) {
				w->color = false;
				x->padre->color = true;
				rotacion_sencilla_der(x->padre);
				w = x->padre->izq;
			}

			if ((w->izq == NULL || !w->izq->color) && (w->der == NULL || !w->der->color)) {
				w->color = true;
				x = x->padre;
			}
			else {
				if (w->izq == NULL || !w->izq->color) {
					if (w->der != NULL) w->der->color = false;
					w->color = true;
					rotacion_sencilla_izq(w);
					w = x->padre->izq;
				}
				w->color = x->padre->color;
				x->padre->color = false;
				if (w->izq != NULL) w->izq->color = false;
				rotacion_sencilla_der(x->padre);
				x = raiz;
			}
		}
	}
	x->color = false;
}

template <class T>
void ArbolRojiNegro<T>::destruir(NodoArbolRJ<T>* x) {
	if(x->izq != NULL){
		destruir(x->izq);
	}
	if(x->der != NULL){
		destruir(x->der);
	}
	delete x;
}

#endif 

