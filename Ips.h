#ifndef IPS_H
#define IPS_H
#include <string>
#include <iostream>

using namespace std;

class Ips{
	protected:
		string nombre;
		string direccion;
		string ciudad;
	public:
		Ips(){
		}
		Ips(string nombre, string direccion, string ciudad){
			this->nombre = nombre;
			this->direccion = direccion;
			this->ciudad = ciudad;
		}
		
};

#endif
