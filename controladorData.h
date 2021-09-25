#ifndef CONTROLADOR_DATA_H
#define CONTROLADOR_DATA_H

#include "Lista.h"
#include "Persona.h"
#include "Vacuna.h"
#include "Eps.h"
#include "Eps_Ips.h"
#include "Eps_Vacuna.h"
#include "Ips.h"
#include "Ips_Vacuna.h"

#include "ArbolBinarioOrdenado.h"

#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <string>



using namespace std;

const int CANT_ATRIBUTOS_VACUNA = 2;
const int CANT_ATRIBUTOS_PERSONA = 14;
const int CANT_ATRIBUTOS_EPS = 1;
const int CANT_ATRIBUTOS_IPS = 3;
const int CANT_ATRIBUTOS_EPS_VACUNA = 1;
const int CANT_ATRIBUTOS_EPS_IPS = 1;
const int CANT_ATRIBUTOS_IPS_VACUNA = 1;


class ControladorData{
	
	private:
		
		int cantidadPersonas;
		int cantidadVacunas;
		int cantidadEPS;
		int cantidadIPS;
		int cantidadEPSVacunas;
		int cantidadIPSVacunas;
		int cantidadEPS_IPS;
		
		//---------------------listas generales-----------------------------------//
		Lista <Vacuna> listaVacunas;
		Lista <Persona> listaPersonas;
		Lista <Eps> listaEPS;
		Lista <Ips> listaIPS;
		Lista <Eps_Vacuna> listaEpsVacuna;
		Lista <Ips_Vacuna> listaIpsVacuna;
		Lista <Eps_Ips> listaEpsIps;
		Lista <string> listaCiudades;
		Lista <string> listaPaises;
		
		
		//---------------------Arboles ordenados----------------------------------//
		
		ArbolBinarioOrdenado pacientesPorEdad;
		ArbolBinarioOrdenado pacientesPorFechaPrimeraDosis;
		ArbolBinarioOrdenado pacientesPorFechaSegundaDosis;
		
		//---------------------Estructuras multiples-----------------------------//
		//preguntar por arreglos
		Lista <ArbolBinarioOrdenado> listaPacientesPorEps;
		Lista <ArbolBinarioOrdenado> listaPacientesPorCiudadResidencia;
		Lista <ArbolBinarioOrdenado> listaPacientesPorSexo;
		Lista <ArbolBinarioOrdenado> listaPacientesPorLaburo;
		Lista <ArbolBinarioOrdenado> listaPacientesPorVacuna;
		
		//-------------------Carga de datos--------------------------------------//
		void cargarArchivosLocales();
		void guardarDatos();
		void cargarArchivo(string rutaArchivo, int cantAtributos, int modelo);
		
		void cargarPacientes();
		void cargarVacunas();
		void cargarEps();
		void cargarIps();
		void cargarLugares();
		void cargarVacunasPorIps();
		void cargarVacunasPorEps();
		
	
		
		//-------------------Formacion de estructuras----------------------------//
		
		void organizarPacientesPorEps();
		void organizarPacientesPorCiudadResidencia();
		void organizarPacientesPorSexo();
		void organizarPacientesPorLaburo();
		void organizarPacientesPorVacuna();
		
		//---------------Mutacion de estructuras--------------------------------//
		//posiblemente a otra clase
		void agregarPersona(Persona);
		void agregarCiudad(string);
		void agregarLaburo(string);
		void agregarVacuna(Vacuna);
		void agregarEps(Eps);
		void agregarIps(Ips);
		void agregarPais(string);
		
		//cambios de datos
		
	public:
		ControladorData();
};


ControladorData::ControladorData(){
	
	this->cantidadEPS = 0;
	this->cantidadEPSVacunas = 0;
	this->cantidadEPS_IPS = 0;
	this->cantidadIPSVacunas = 0;
	this->cantidadVacunas = 0;
	this->cantidadPersonas = 0;
	this->cantidadIPS = 0;
	
	this->cargarArchivosLocales();
	
}

void ControladorData::cargarArchivosLocales(){
	//1 persona
	//2 vacuna
	//3 EPS
	//4 IPS
	//5 EPS Vacuna
	//6 IPS Vacuna
	//7 EPS IPS
	//8 ciudad
	//9 Pais
	
	cargarArchivo("Archivos/personas.txt", CANT_ATRIBUTOS_PERSONA, 1);
	cargarArchivo("Archivos/vacunas.txt", CANT_ATRIBUTOS_VACUNA, 2);
	cargarArchivo("Archivos/eps.txt", CANT_ATRIBUTOS_EPS, 3);
	cargarArchivo("Archivos/ips.txt", CANT_ATRIBUTOS_IPS, 4);
	cargarArchivo("Archivos/eps_vacuna.txt", CANT_ATRIBUTOS_EPS_VACUNA, 5);
	cargarArchivo("Archivos/ips_vacuna.txt", CANT_ATRIBUTOS_IPS_VACUNA, 6);
	cargarArchivo("Archivos/eps_ips.txt", CANT_ATRIBUTOS_EPS_IPS, 7);
	cargarArchivo("Archivos/ciudades.txt", 1, 8);
	cargarArchivo("Archivos/paises.txt", 1, 9);
	
}

void ControladorData::cargarArchivo(string rutaArchivo, int cantAtributos, int modelo){
	cout<<"entra al metodo "<<modelo<<endl<<endl;
	
	fstream archivo;
	string linea, *atributos;
	
	archivo.open(rutaArchivo.c_str());
	
	if(archivo.is_open()){
		while(getline(archivo, linea)){
			atributos = new string[cantAtributos];
			int pos = 0;
			
			for(int i = 0; i < linea.size(); i++){
				if(linea[i] == ';' && linea[i + 1] == ';'){
					pos++;
					i++;
				}else{
					atributos[pos] += linea[i];
				}
				
			}
			
			for(int i = 0; i < cantAtributos; i++)cout<<atributos[i]<<"-";
			cout<<endl;
			
			switch(modelo){
				case 1:
					break;
				case 2:{
					Vacuna vacuna = Vacuna(atributos[0], atoi(atributos[1].c_str())); 
//					agregarVacuna(vacuna);
					break;
				}
				case 3:{
					Eps eps = Eps(atributos[0]);
//					agregarEps(eps);
					break;
				}
				case 4:{
					Ips ips = Ips(atributos[0],atributos[1],atributos[2]);
//					agregarIps(ips)
				}
				case 5:{
					Eps eps;//buscar eps referente a atributos[0]
					Vacuna vacuna;//buscar vacuna referente a atributos[1]
					Eps_Vacuna epsVacuna = Eps_Vacuna(eps, vacuna, atoi(atributos[2].c_str()));
//					agregarEpsVacuna();
					break;
				}
				case 6:{
					Ips ips;//buscar ips referente a atributos[0]
					Vacuna vacuna;//buscar vacuna referente a atributos[1]
					
					Ips_Vacuna ips_vacuna = Ips_Vacuna(ips, vacuna);
					break;
				}
				case 7:{
					Eps eps;//buscar eps referente a atributos[0]
					Ips ips;//buscar ips referente a atributos[1]
					
					Eps_Ips eps_ips =  Eps_Ips(eps, ips);
					break;
				}
				case 8:
//					agregarCiudad(atributos[0]);
					break;
				case 9:
//					agregarPais(atributos[0]);
					break;
				default:
					break; 
			}
				
		}
		delete []atributos;
		
	}else{
		cout<<"Archivo de "<<modelo<<" no disponible"<<endl;
	}
}


#endif
