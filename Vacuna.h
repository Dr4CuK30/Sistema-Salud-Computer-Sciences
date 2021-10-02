#ifndef VACUNA_H
#define VACUNA_H
#include <string>
#include <iostream>


using namespace std;

class Vacuna{
	private:
		string nombre;
		int cantidadDosis;
		
	public:		
		Vacuna(){}
		Vacuna(string nombre, int cantidadDosis){
			this->cantidadDosis = cantidadDosis;
			this->nombre = nombre;
		}

		string getNombre(){
			return this->nombre;
		}

		int getCantidadDosis()
		{
			return this->cantidadDosis;
		}

};

#endif
