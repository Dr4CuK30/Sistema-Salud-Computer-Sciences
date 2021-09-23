#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include "Vacuna.h"
#include "Fecha.h"
#include "Eps.h"

using namespace std;

struct Identificacion{
	long long int numero;
	string tipo;
};

class Persona{
	Identificacion id;
	protected:
		string nombres;
		string apellidos;
		string genero;
		string email;
		string ciudad_nac;
		string pais_nac;
		string ciudad_resid;
		string direccion;
		string barrio;
		string act_laboral;
		long long int telefono_cel;
		long long int telefono_fijo;
		Fecha f_nacimiento;
		Fecha *f_primera_dosis;
		Fecha *f_segunda_dosis;
		Vacuna vacuna;
		Eps eps;
	public:
		Persona(){};
		Persona(long long int numeroId,
				string tipoId,
				string nombres,
				string apellidos,
				string genero,
				string email,
				string ciudad_nac,
				string pais_nac,
				string ciudad_resid,
				string direccion,
				string barrio,
				long long int telefono_cel,
				long long int telefono_fijo,
				Fecha f_nacimiento);
		Identificacion getId(){
			return id;
		}
		bool Vacunar(Vacuna vacuna, Fecha *fecha);
};

//--------- CONSTRUCTORES -----------//
Persona::Persona(long long int numeroId,
				string tipoId,
				string nombres,
				string apellidos,
				string genero,
				string email,
				string ciudad_nac,
				string pais_nac,
				string ciudad_resid,
				string direccion,
				string barrio,
				long long int telefono_cel,
				long long int telefono_fijo,
				Fecha f_nacimiento){
	Identificacion id;
	id.numero = numeroId;
	id.tipo = tipoId;
	this->id = id;
	this->nombres = nombres;
	this->apellidos = apellidos;
	this->genero = genero;
	this->email = email;
	this->ciudad_nac = ciudad_nac;
	this->pais_nac = pais_nac;
	this->ciudad_resid = ciudad_resid;
	this->direccion = direccion;
	this->barrio = barrio;
	this->telefono_cel = telefono_cel;
	this->telefono_fijo = telefono_fijo;
	this->f_nacimiento = f_nacimiento; 
}

//-------------- METODOS -------------------//
bool Persona::Vacunar(Vacuna vacuna, Fecha *fecha){
	if(this->f_segunda_dosis != NULL) return false;
	this->vacuna = vacuna;
	if(this->f_primera_dosis == NULL) this->f_primera_dosis = fecha;
	else this->f_segunda_dosis = fecha;
	return true;
}
#endif
