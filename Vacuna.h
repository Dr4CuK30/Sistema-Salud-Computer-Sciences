#ifndef VACUNA_H
#define VACUNA_H
#include <string>
#include <iostream>


using namespace std;

class Vacuna{
	public:
		string nombre;
		int cant;
		Vacuna(){}
		Vacuna(string nombre, int cant){
			cant = cant;
			nombre = nombre;
		}
};

#endif
