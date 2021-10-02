#ifndef IPS_H
#define IPS_H
#include <string>
#include <iostream>
#include "Eps.h"

using namespace std;

class Ips{
	private:
		string nombre;
		string direccion;
		string ciudad;
		Eps *eps;

	public:

		Ips(){
		}
		Ips(string nombre, string direccion, string ciudad, Eps *eps){
			this->nombre = nombre;
			this->direccion = direccion;
			this->ciudad = ciudad;
			this->eps = eps;
		}

		string getNombre()
		{
			return this->nombre;
		}

		string getDireccion()
		{
			return this->direccion;
		}

		string getCiudad()
		{
			return this->ciudad;
		}

		Eps * getEps()
		{
			return this->eps;
		}

		string getEpsName(){
			Eps * eps = this->getEps();
			Eps obtained = *eps;
			return obtained.getNombre();
		}
		
};

#endif
