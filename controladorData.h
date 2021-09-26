#ifndef CONTROLADOR_DATA_H
#define CONTROLADOR_DATA_H

#include "Lista.h"
#include "Persona.h"
#include "Vacuna.h"
#include "Eps.h"
#include "Eps_Vacuna.h"
#include "Ips.h"
#include "Ips_Vacuna.h"
#include "Casilla.h"

#include "ArbolBinarioOrdenado.h"

#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <string>


using namespace std;

const int CANT_ATRIBUTOS_VACUNA = 2;
const int CANT_ATRIBUTOS_PERSONA = 20;
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
		Lista < Casilla<Vacuna> > listaVacunas;
		Lista < Casilla <Persona> > listaPersonas;
		Lista < Casilla<Eps> >listaEPS;
		Lista < Casilla<Ips> > listaIPS;
		Lista < Casilla<Eps_Vacuna> > listaEpsVacuna;
		Lista < Casilla<Ips_Vacuna> > listaIpsVacuna;
		Lista < Casilla <string> > listaCiudades;
		Lista < Casilla<string> > listaPaises;
		
		
		//---------------------Arboles ordenados----------------------------------//
		
		ArbolBinarioOrdenado pacientesPorEdad;
		ArbolBinarioOrdenado pacientesPorFechaPrimeraDosis;
		ArbolBinarioOrdenado pacientesPorFechaSegundaDosis;
		
		//---------------------Estructuras multiples-----------------------------//
		//preguntar por arreglos
		Lista < Casilla<ArbolBinarioOrdenado> > listaPacientesPorEps;
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
		void agregarCiudad(string, int);
		void agregarLaburo(string);
		void agregarVacuna(Vacuna, int);
		void agregarEps(Eps, int);
		void agregarIps(Ips);
		void agregarPais(string, int);
		
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
	//7 ciudad
	//8 Pais
	
	
	cargarArchivo("Archivos/ciudades.txt", 2, 7);
	cargarArchivo("Archivos/paises.txt", 2, 8);
	
//	cargarArchivo("Archivos/personas.txt", CANT_ATRIBUTOS_PERSONA + 1, 1);
	cargarArchivo("Archivos/vacunas.txt", CANT_ATRIBUTOS_VACUNA + 1, 2);
	cargarArchivo("Archivos/eps.txt", CANT_ATRIBUTOS_EPS + 1, 3);
	cargarArchivo("Archivos/ips.txt", CANT_ATRIBUTOS_IPS + 1, 4);
	cargarArchivo("Archivos/eps_vacuna.txt", CANT_ATRIBUTOS_EPS_VACUNA + 1, 5);
	cargarArchivo("Archivos/ips_vacuna.txt", CANT_ATRIBUTOS_IPS_VACUNA + 1, 6);
	
}

void ControladorData::cargarArchivo(string rutaArchivo, int cantAtributos, int modelo){
//	cout<<modelo<<endl;
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
			
//			for(int i = 0; i < cantAtributos; i++)cout<<atributos[i]<<"-";
//			cout<<endl;
			int id = atoi(atributos[0].c_str());
			
			if(atributos[pos] == "--") atributos[pos] = "";
			
			switch(modelo){
				case 1:{
					//metodo de validacion para todos
					int idVacuna;
					int idCiudad;
					int idPais;
					int idEps;
					int idIpsDefault;
					int idIpsAsignada;
					//cuidado aca con las direcciones en memoria
					Vacuna vacuna = listaVacunas.obtenerDato(idVacuna).data;
					string ciudad = listaCiudades.obtenerDato(idCiudad).data;
					string pais = listaPaises.obtenerDato(idPais).data;
					Eps eps = listaEPS.obtenerDato(idEps).data;
					Ips ipsDefault = listaIPS.obtenerDato(idIpsDefault).data;
					Ips ipsAsignada = listaIPS.obtenerDato(idIpsAsignada).data;
					
					//pilas con el long long
//					Persona persona = Persona(strtoll(atributos[1].c_str(),NULL,0),atributos[2],atributos[3],atributos[4],
//												atributos[5],atributos[6],atributos[7],atributos[8],atributos[9],atributos[10],
//												atributos[11],strtoll(atributos[12].c_str(),NULL,0),strtoll(atributos[13].c_str(),NULL,0),
//												atributos[14],atributos[15],atributos[16],
//												&vacuna,&eps,&ipsDefault,&ipsAsignada) 
					
					//CREACION DE OBJETO NO TERMINADA EL ERROR ESTA ACA
					break;
				}
				case 2:{
					Vacuna vacuna = Vacuna(atributos[1], atoi(atributos[2].c_str())); 
					
					agregarVacuna(vacuna, id);
					/* prueba de obtencion de datos
					Vacuna prueba= listaVacunas.obtenerDato(1).data;
					cout<<prueba.nombre<<endl;
					*/
					break;
				}
				case 3:{
					Eps eps = Eps(atributos[0]);
//					agregarEps(eps);
					break;
				}
				case 4:{
					Eps eps;//buscar eps
					Ips ips = Ips(atributos[1],atributos[2],atributos[3],&eps);
//					agregarIps(ips) 
				}
				case 5:{
					Eps *eps;//buscar eps referente a atributos[0]
					Vacuna *vacuna;//buscar vacuna referente a atributos[1]
					Eps_Vacuna epsVacuna = Eps_Vacuna(eps, vacuna, atoi(atributos[2].c_str()));
//					agregarEpsVacuna();
					break;
				}
				case 6:{
					Ips ips;//buscar ips referente a atributos[0]
					Vacuna vacuna;//buscar vacuna referente a atributos[1]
					
					Ips_Vacuna ips_vacuna = Ips_Vacuna(&ips, &vacuna);
					break;
				}
				case 7:
//					agregarCiudad(atributos[0]);
					break;
				case 8:
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


void ControladorData::agregarVacuna(Vacuna vacuna, int id){
//	int posicion = listaVacunas.Tam_lista(); podria ser util para verificacion de pos de ser necesario
	Casilla<Vacuna> casilla;
	casilla.data = vacuna;
	casilla.id = id;
	
	listaVacunas.intertar_final(casilla);
}

void ControladorData::agregarEps(Eps eps, int id){
	Casilla<Eps> casilla;
	casilla.data = eps;
	casilla.id = id;
	
	listaEPS.intertar_final(casilla);
}

void ControladorData::agregarCiudad(string ciudad, int id){
	Casilla<string> casilla;
	casilla.data = ciudad;
	casilla.id = id;
	
	listaCiudades.intertar_final(casilla);
}

void ControladorData::agregarPais(string pais, int id){
	Casilla<string> casilla;
	casilla.data = pais;
	casilla.id = id;
	
	listaPaises.intertar_final(casilla);
}
#endif
