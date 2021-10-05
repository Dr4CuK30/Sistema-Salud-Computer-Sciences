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

	private:
		Identificacion id;
		string nombres;
		string apellidos;
		string genero;
		string email;
		string *ciudad_nac;
		string *pais_nac;
		string *ciudad_resid;
		string direccion;
		string barrio;
		string *act_laboral;
		long long int telefono_cel;
		long long int telefono_fijo;
		Fecha *f_nacimiento;
		Fecha *f_primera_dosis;
		Fecha *f_segunda_dosis;
		Vacuna *vacuna;
		Eps *eps;
		Ips *ips_default;
		Ips *ips_asignada;


		// void setId(Identificacion id)
		// {
		// 	this.id = id;
		// }

		// void setNombres(string nombres)
		// {
		// 	this.nombres = nombres;
		// }

		// void setApellidos(string apellidos)
		// {
		// 	this.apellidos = apellidos;
		// }

		// void setGenero(string genero)
		// {
		// 	this.genero = genero;
		// }

		// void setEmail(string email)
		// {
		// 	this.email = email;
		// }

		// void set *Ciudad_nac(string *ciudad_nac)
		// {
		// 	this.*ciudad_nac = *ciudad_nac;
		// }

		// void set *Pais_nac(string *pais_nac)
		// {
		// 	this.*pais_nac = *pais_nac;
		// }

		// void set *Ciudad_resid(string *ciudad_resid)
		// {
		// 	this.*ciudad_resid = *ciudad_resid;
		// }

		// void setDireccion(string direccion)
		// {
		// 	this.direccion = direccion;
		// }

		// void setBarrio(string barrio)
		// {
		// 	this.barrio = barrio;
		// }

		// void set *Act_laboral(string *act_laboral)
		// {
		// 	this.*act_laboral = *act_laboral;
		// }

		// void setInt(long int)
		// {
		// 	this.int = int;
		// }


		// void setInt(long int)
		// {
		// 	this.int = int;
		// }

		// void set *F_nacimiento(Fecha *f_nacimiento)
		// {
		// 	this.*f_nacimiento = *f_nacimiento;
		// }

		// void set *F_primera_dosis(Fecha *f_primera_dosis)
		// {
		// 	this.*f_primera_dosis = *f_primera_dosis;
		// }

		// void set *F_segunda_dosis(Fecha *f_segunda_dosis)
		// {
		// 	this.*f_segunda_dosis = *f_segunda_dosis;
		// }

		// void set *Vacuna(Vacuna *vacuna)
		// {
		// 	this.*vacuna = *vacuna;
		// }

		// void set *Eps(Eps *eps)
		// {
		// 	this.*eps = *eps;
		// }

		// void set *Ips_default(Ips *ips_default)
		// {
		// 	this.*ips_default = *ips_default;
		// }

		// void set *Ips_asignada(Ips *ips_asignada)
		// {
		// 	this.*ips_asignada = *ips_asignada;
		// }

	public:
		Persona(){};
		Persona(long long int numeroId,
				string tipoId,
				string nombres,
				string apellidos,
				string genero,
				string email,
				string *ciudad_nac,
				string *pais_nac,
				string *ciudad_resid,
				string direccion,
				string barrio,
				long long int telefono_cel,
				long long int telefono_fijo,
				Fecha *f_nacimiento,
				Fecha *f_primera_dosis,
				Fecha *f_segunda_dosis,
				Vacuna *vacuna,
				Eps *eps,
				Ips *ips_default,
				Ips *ips_asignada,
				string *act_laboral);
		Identificacion getId(){
			return id;
		}
		bool Vacunar(Vacuna *vacuna, Fecha *fecha);
		int getEdad();
		int estadoVacuna();

		string getNombres()
		{
			return this->nombres;
		}

		string getApellidos()
		{
			return this->apellidos;
		}

		string getGenero()
		{
			return this->genero;
		}

		string getEmail()
		{
			return this->email;
		}

		string * getCiudad_nac()
		{
			return this->ciudad_nac;
		}

		string * getPais_nac()
		{
			return this->pais_nac;
		}


		string * getCiudad_resid()
		{
			return this->ciudad_resid;
		}

		string getDireccion()
		{
			return this->direccion;
		}

		string getBarrio()
		{
			return this->barrio;
		}

		string * getAct_laboral()
		{
			return this->act_laboral;
		}

		long getTelefono_cel()
		{
			return this->telefono_cel;
		}

		long getTelefono_fijo()
		{
			return this->telefono_fijo;
		}

		Fecha * getF_nacimiento()
		{
			return this->f_nacimiento;
		}

		Fecha * getF_primera_dosis()
		{
			return this->f_primera_dosis;
		}

		Fecha * getF_segunda_dosis()
		{
			return this->f_segunda_dosis;
		}

		Vacuna * getVacuna()
		{
			return this->vacuna;
		}

		string getVacunaName(){
			Vacuna * vac = this->getVacuna();
			Vacuna vacObtained = *vac;
			return vacObtained.getNombre();
		}

		Eps * getEps()
		{
			return this->eps;
		}

		string getEpsName(){
			
			Eps * eps = this->getEps();
			Eps epsObtained = *eps;
			return epsObtained.getNombre();
		}

		Ips * getIps_default()
		{
			return this->ips_default;
		}

		string getIpsDefaultName(){
			Ips * ips = this->getIps_default();
			Ips ipsObtained = *ips;
			return ipsObtained.getNombre();
		}

		Ips * getIps_asignada()
		{
			return this->ips_asignada;
		}

		string getIpsAsignadaName(){
			if(this->getIps_asignada() == NULL) return "";
			Ips * ips = this->getIps_asignada();
			Ips ipsObtained = *ips;
			return ipsObtained.getNombre();
		}
};

//--------- CONSTRUCTORES -----------//
Persona::Persona(long long int numeroId,
				string tipoId,
				string nombres,
				string apellidos,
				string genero,
				string email,
				string *ciudad_nac,
				string *pais_nac,
				string *ciudad_resid,
				string direccion,
				string barrio,
				long long int telefono_cel,
				long long int telefono_fijo,
				Fecha *f_nacimiento,
				Fecha *f_primera_dosis,
				Fecha *f_segunda_dosis,
				Vacuna *vacuna,
				Eps *eps,
				Ips *ips_default,
				Ips *ips_asignada,
				string *act_laboral){
					
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
	this->act_laboral = act_laboral;
}

//-------------- METODOS -------------------//
bool Persona::Vacunar(Vacuna *vacuna, Fecha *fecha){
	int etapa =  this->estadoVacuna();
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

	float cantDias=0;

	for (int i = 1; i <= (this->f_nacimiento->mes-1); i++)
	{
		if (i==2)
		{
			cantDias = cantDias + 28;
		}

		if(i%2!=0 && i<=7){
			cantDias = cantDias + 31;
		}

		if(i%2==0 && i<7 && i!=2){
			cantDias = cantDias + 30;
		}

		if (i%2==0 && i>=8){
			cantDias = cantDias + 31;
		}

		if(i%2!=0 && i>=9){
			cantDias = cantDias + 30;
		}
	}
	
	float anho_nacimiento = this->f_nacimiento->anho + ((this->f_nacimiento->mes)/12.0) + ((cantDias + this->f_nacimiento->dia)/365);
	float anho_actual = timePtr->tm_year+1900.0 + (timePtr->tm_mon+1.0)/12 + ((timePtr->tm_mday+1.0)/365);
	return floor(anho_actual-anho_nacimiento);
}

int Persona::estadoVacuna(){
	if(this->f_segunda_dosis != NULL) return 2;
	if(this->f_primera_dosis != NULL) {
		if(this->vacuna->getCantidadDosis() == 1){
			return 2;
		}
		return 1;
	}
	return 0;
}
#endif
