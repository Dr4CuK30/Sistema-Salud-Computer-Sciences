#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <ctime>
#include <math.h>
#include "Vacuna.h"
#include "Fecha.h"
#include "Eps.h"
#include "Ips.h"

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
		Vacuna *vacuna;
		Eps *eps;
		Ips *ips_default;
		Ips *ips_asignada;
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
				Fecha f_nacimiento,
				Fecha *f_primera_dosis,
				Fecha *f_segunda_dosis,
				Vacuna *vacuna,
				Eps *eps,
				Ips *ips_default,
				Ips *ips_asignada);
		Identificacion getId(){
			return id;
		}
		bool Vacunar(Vacuna *vacuna, Fecha *fecha);
		int getEdad();
		int faltaVacunar();
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
				Fecha f_nacimiento,
				Fecha *f_primera_dosis,
				Fecha *f_segunda_dosis,
				Vacuna *vacuna,
				Eps *eps,
				Ips *ips_default,
				Ips *ips_asignada){
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
	this->f_primera_dosis = f_primera_dosis;
	this->f_segunda_dosis = f_segunda_dosis;
	this->vacuna = vacuna;
	this->eps = eps;
	this->ips_default = ips_default;
	this->ips_asignada = ips_asignada;
}

//-------------- METODOS -------------------//
bool Persona::Vacunar(Vacuna *vacuna, Fecha *fecha){
	int etapa =  this->faltaVacunar();
	if(etapa == 0){
		this->vacuna = vacuna;
		this->f_primera_dosis = fecha;
		return true;	
	}else if(etapa == 1){
		if(this->vacuna != vacuna) return false;
		else {
			this->f_segunda_dosis = fecha;
			return true;
		}
	} else{
		return false;
	}
}

int Persona::getEdad(){
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	float anho_nacimiento = this->f_nacimiento.anho + ((this->f_nacimiento.mes+1)/12) + (this->f_nacimiento.anho/365);
	float anho_actual = timePtr->tm_year+1900 + (timePtr->tm_mon+1/12) + (timePtr->tm_mday/365);
	return floor(anho_actual-anho_nacimiento);
}

int Persona::faltaVacunar(){
	if(this->f_segunda_dosis != NULL) return 2;
	if(this->f_primera_dosis != NULL) return 1;
	return 0;
}
#endif
