#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Vacuna{
	public:
		string nombre;
		int cant;
		Vacuna(){}
		Vacuna(string nombre, int cant){
			this.cant = cant;
			this.nombre = nombre;
		}
};

#endif
