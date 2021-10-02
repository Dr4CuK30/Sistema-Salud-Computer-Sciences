
#ifndef EPS_H
#define EPS_H
#include <string>
#include <iostream>

using namespace std;

class Eps{
	private:
		string nombre;
		
	public:
		Eps(){}
		Eps(string nombre){
			this->nombre = nombre;
		}

		string getNombre()
		{
			return this->nombre;
		}

};

#endif
