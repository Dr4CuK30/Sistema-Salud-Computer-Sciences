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
		void agregarPaciente();
		void agregarCiudad();
		void agregarLaburo();
		void agregarVacuna(Vacuna vacuna);
		void agregarEps();
		void agregarIps();
		
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
	
	this->cargarVacunas();
	//this->cargarArchivosLocales();
}

void ControladorData::cargarArchivosLocales(){
	
	fstream archivoPacientes;
	string linea, *datos;
	
	datos = new string[5];
	
	archivoPacientes.open("Archivos/pacientes.txt", ios::in);
	
	if(archivoPacientes.is_open()){
		int i = 0;
		while(getline(archivoPacientes, linea)){
			datos[i] = linea;
			i++;
		}
		archivoPacientes.close();
	}else{
		cout<< "Archivo de pacientes no abre"<<endl;
	}
	cout<<datos[0];
	
}

void ControladorData::cargarPacientes(){
}

void ControladorData::cargarVacunas(){
	
	fstream archivoVacunas;
	string linea, *atributosVacuna;
	
	
	archivoVacunas.open("archivos/vacunas.txt");
	
	if(archivoVacunas.is_open()){
		while(getline(archivoVacunas, linea)){
			atributosVacuna = new string[CANT_ATRIBUTOS_VACUNA];
			int pos = 0;
			
			for(int i = 0; i < linea.size(); i++){
				if(linea[i] == ';' && linea[i+1] == ';'){
					pos++;
					i++;
				}else{
					atributosVacuna[pos] += linea[i];
				}
			}
			
			Vacuna vacuna = Vacuna(atributosVacuna[0], atoi(atributosVacuna[1].c_str())); 
			agregarVacuna(vacuna);
			
			delete []atributosVacuna;
		}
		
		archivoVacunas.close();
	}else{
		cout<<"Archivo de vacunas no disponible"<<endl;
	}
	
}

void ControladorData::cargarEps(){
}

void ControladorData::cargarIps(){
}

void ControladorData::cargarLugares(){
}

void ControladorData::cargarVacunasPorIps(){
}
		
void ControladorData::cargarVacunasPorEps(){
}

void ControladorData::agregarVacuna(Vacuna vacuna){
	
}

#endif
