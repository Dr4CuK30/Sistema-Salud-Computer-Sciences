#ifndef IPS_H
#define IPS_H
#include <string>
#include <iostream>
#include "Ips.h"

using namespace std;

class Ips{
	protected:
		string nombre;
		string direccion;
		string ciudad;
		Ips *ips;
	public:
		Ips(){
		}
		Ips(string nombre, string direccion, string ciudad, Ips *ips){
			this->nombre = nombre;
			this->direccion = direccion;
			this->ciudad = ciudad;
		}
		
};

#endif
