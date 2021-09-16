#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

struct Fecha{
	int dia;
	int mes;
	int anho;
};

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
		Fecha f_primera_dosis;
		Fecha f_segunda_dosis;
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

#endif
