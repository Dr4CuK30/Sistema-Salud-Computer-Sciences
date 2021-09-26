#ifndef VACUNA_H
#define VACUNA_H
#include <string>
#include <iostream>


using namespace std;

class Vacuna{
	public:
		string nombre;
		int cantidadDosis;
		Vacuna(){}
		Vacuna(string nombre, int cantidadDosis){
			this->cantidadDosis = cantidadDosis;
			this->nombre = nombre;
		}
};

#endif
