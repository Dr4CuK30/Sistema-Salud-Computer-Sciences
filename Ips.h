#ifndef IPS_H
#define IPS_H
#include <string>
#include <iostream>
#include "Eps.h"

using namespace std;

class Ips{
	public:
		string nombre;
		string direccion;
		string ciudad;
		Eps *eps;
	
		Ips(){
		}
		Ips(string nombre, string direccion, string ciudad, Eps *eps){
			this->nombre = nombre;
			this->direccion = direccion;
			this->ciudad = ciudad;
			this->eps = eps;
		}
		
};

#endif
