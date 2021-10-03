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
const int CANT_ATRIBUTOS_IPS = 4;
const int CANT_ATRIBUTOS_EPS_VACUNA = 3;
const int CANT_ATRIBUTOS_IPS_VACUNA = 2;
 
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
		Lista <Fecha> listaFechas;
		
		 
		//---------------------Arboles ordenados----------------------------------//
		
		ArbolBinarioOrdenado pacientesPorEdad;
		ArbolBinarioOrdenado pacientesPorFechaPrimeraDosis;
		ArbolBinarioOrdenado pacientesPorFechaSegundaDosis;
		
		//---------------------Estructuras multiples-----------------------------//
		//preguntar por arreglos
		Lista < ArbolBinarioOrdenado > listaPacientesPorEps;
		Lista < ArbolBinarioOrdenado > listaPacientesPorCiudadResidencia;
		Lista < ArbolBinarioOrdenado > listaPacientesPorSexo;
		Lista < ArbolBinarioOrdenado > listaPacientesPorLaburo;
		Lista < ArbolBinarioOrdenado > listaPacientesPorVacuna;
		
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
		
		//multilistas con arboles ordenados por edad
		void organizarPacientesPorEps();
		void organizarPacientesPorCiudadResidencia();
		void organizarPacientesPorSexo();
		void organizarPacientesPorLaburo();
		void organizarPacientesPorVacuna();
		
		//---------------Mutacion de estructuras--------------------------------//
		//posiblemente a otra clase
		void agregarPersona(Persona, int);
		void agregarCiudad(string, int);
		void agregarLaburo(string, int);
		void agregarVacuna(Vacuna, int);
		void agregarEps(Eps, int);
		void agregarIps(Ips, int);
		void agregarPais(string, int);
		
		void agregarEpsVacuna(Eps_Vacuna, int);
		void agregarIpsVacuna(Ips_Vacuna, int);
		
		int ingresarFecha(string);
		//cambios de datos
		//--------------------------Utils-------------------------------------//
		int validarID(string);
		
		
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
	
	cargarArchivosLocales();
	
	
	
	Casilla<Persona> casilla = listaPersonas.obtenerDato(1);
		Persona persona = casilla.data;
		
		cout<<"Persona "<<1<<" con el nombre ";
		cout<<persona.getNombres()<<endl;
		cout<<persona.getEps()->getNombre()<<endl;
	
	
	organizarPacientesPorEps();
	
	cout<<"impresion arboles"<<endl;
	pacientesPorEdad.inorden(pacientesPorEdad.obtenerRaiz());
	cout<<"----"<<endl;
	pacientesPorEdad.preorden(pacientesPorEdad.obtenerRaiz());
	cout<<"----"<<endl;
	pacientesPorEdad.posorden(pacientesPorEdad.obtenerRaiz());
	
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
	//9 Laburo
	
	//Este orden es importante
	cargarArchivo("Archivos/ciudades.txt", 2, 7);
	cargarArchivo("Archivos/paises.txt", 2, 8);
	
	cargarArchivo("Archivos/vacunas.txt", CANT_ATRIBUTOS_VACUNA + 1, 2);
	cargarArchivo("Archivos/eps.txt", CANT_ATRIBUTOS_EPS + 1, 3);
	cargarArchivo("Archivos/ips.txt", CANT_ATRIBUTOS_IPS + 1, 4);
	
	cargarArchivo("Archivos/personas.txt", CANT_ATRIBUTOS_PERSONA + 1, 1);
	
	cargarArchivo("Archivos/eps_vacuna.txt", CANT_ATRIBUTOS_EPS_VACUNA + 1, 5);
	cargarArchivo("Archivos/ips_vacuna.txt", CANT_ATRIBUTOS_IPS_VACUNA + 1, 6);
	
}

void ControladorData::cargarArchivo(string rutaArchivo, int cantAtributos, int modelo){
	cout<<"modelo "<<modelo<<" con "<<cantAtributos<<" atributos"<<endl;
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
					int idVacuna =  atoi(atributos[17].c_str());
					int idCiudadNac =  atoi(atributos[7].c_str());
					int idCiudadRes =  atoi(atributos[9].c_str());
					int idPais = atoi(atributos[8].c_str()) ;
					int idEps = atoi(atributos[18].c_str());
					int idIpsDefault =  atoi(atributos[19].c_str());
					int idIpsAsignada =  atoi(atributos[20].c_str());
					
					int idFNacimiento = ingresarFecha(atributos[14]);
					int idFPri = ingresarFecha(atributos[15]);
					int idFSeg = ingresarFecha(atributos[16]);
					
					Vacuna *pVacuna;
					string *pCiudadNac;
					string *pPais;
					string *pCiudadRes;
					Eps *pEps;
					Ips *pIpsDefault;
					Ips *pIpsAsignada;
					Fecha *pFechaNac;
					Fecha *pFechaPri;
					Fecha *pFechaSec;
					
					if(idVacuna == 0) pVacuna = NULL;
					else{
						Vacuna vacuna = listaVacunas.obtenerDato(idVacuna).data;
						pVacuna = &vacuna;
					}
					if(idCiudadNac == 0) pCiudadNac = NULL;
					else{
						string ciudad = listaCiudades.obtenerDato(idCiudadNac).data;
						pCiudadNac = &ciudad;
					}
					if(idPais == 0) pPais = NULL;
					else{
						string pais = listaCiudades.obtenerDato(idPais).data;
						pPais = &pais;
					}
					if(idCiudadRes == 0) pCiudadRes = NULL;
					else{
						string ciudad = listaCiudades.obtenerDato(idCiudadRes).data;
						pCiudadRes = &ciudad;
					}
					if(idEps== 0) pEps = NULL;
					else{
						Eps eps = listaEPS.obtenerDato(idEps).data;
						pEps = &eps;
					}
					if(idIpsDefault == 0) pIpsDefault = NULL;
					else{
						Ips ipsDefault = listaIPS.obtenerDato(idIpsDefault).data;
						pIpsDefault = &ipsDefault;
					}
					if(idIpsAsignada == 0) pIpsAsignada = NULL;
					else{
						Ips ipsAsignada = listaIPS.obtenerDato(idIpsAsignada).data;
						pIpsAsignada = &ipsAsignada;
					}
					if(idFNacimiento == 0) pFechaNac = NULL;
					else{
						Fecha fecha = listaFechas.obtenerDato(idFNacimiento);
						pFechaNac = &fecha;
					}
					if(idFPri == 0) pFechaPri = NULL;
					else{
						Fecha fecha = listaFechas.obtenerDato(idFPri);
						pFechaPri = &fecha;
					}
					if(idFSeg == 0) pFechaSec = NULL;
					else{
						Fecha fecha = listaFechas.obtenerDato(idFSeg);
						pFechaSec = &fecha;
					}
					
					long long numId = strtoll(atributos[1].c_str(),NULL,0);
					long long tel_cel =strtoll(atributos[12].c_str(),NULL,0);
					long long tel_fijo = strtoll(atributos[12].c_str(),NULL,0);
					
					cout<<"prueba de la insercion de la eps"<<endl;
					cout<<pEps->getNombre()<<endl;
					
					Persona persona = Persona(numId,atributos[2],atributos[3],atributos[4],
												atributos[5],atributos[6],pCiudadNac,pPais,pCiudadRes,atributos[10],
												atributos[11],tel_cel,tel_fijo,
												pFechaNac ,pFechaPri ,pFechaSec ,
												pVacuna,pEps,pIpsDefault,pIpsAsignada); 
					
					
					agregarPersona(persona, id);
//					if(persona.ips_asignada == NULL)cout<<"es nula mk"<<endl;
//					cout<<persona.nombres<<" "<<idIpsAsignada<<" "<<persona.ips_asignada<<endl;
//					cout<<listaIPS.obtenerDato(1).data.nombre<<" "<<listaIPS.obtenerDato(2).data.nombre;
					break;
				}
				case 2:{
					Vacuna vacuna = Vacuna(atributos[1], atoi(atributos[2].c_str())); 
					
					agregarVacuna(vacuna, id);
					break;
				}
				case 3:{
					Eps eps = Eps(atributos[1]);
					agregarEps(eps, id);
					break;
				}
				case 4:{
					int idEps = atoi(atributos[4].c_str());
					Eps eps = listaEPS.obtenerDato(idEps).data;
					
					Ips ips = Ips(atributos[1],atributos[2],atributos[3],&eps);
					agregarIps(ips, id);
				}
				case 5:{
					int idEps = atoi(atributos[1].c_str());
					int idVacuna =  atoi(atributos[2].c_str()); 
					
					Eps eps = listaEPS.obtenerDato(idEps).data;
					Vacuna vacuna = listaVacunas.obtenerDato(idVacuna).data;
					
					Eps_Vacuna epsVacuna = Eps_Vacuna(&eps, &vacuna, atoi(atributos[2].c_str()));
					agregarEpsVacuna(epsVacuna, id);
					break;
				}
				case 6:{
					int idIps = atoi(atributos[1].c_str());
					int idVacuna = atoi(atributos[2].c_str());
					
					Ips ips = listaIPS.obtenerDato( idIps).data;
					Vacuna vacuna = listaVacunas.obtenerDato(idVacuna).data;
					
					Ips_Vacuna ips_vacuna = Ips_Vacuna(&ips, &vacuna);
					
					agregarIpsVacuna(ips_vacuna, id);
					
					break;
				}
				case 7:
					agregarCiudad(atributos[1], id);
					break;
				case 8:
					agregarPais(atributos[1], id);
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

void ControladorData::agregarPersona(Persona persona, int id){
	Casilla<Persona> casilla;
	casilla.data = persona;
	casilla.id = id;
	
	pacientesPorEdad.insertarNodo(id, persona.getEdad());
	listaPersonas.intertar_final(casilla);
	
}

void ControladorData::agregarEps(Eps eps, int id){
	Casilla<Eps> casilla;
	casilla.data = eps;
	casilla.id = id;
	
	listaEPS.intertar_final(casilla);
}

void ControladorData::agregarIps(Ips ips, int id){
	Casilla<Ips> casilla;
	casilla.data = ips;
	casilla.id = id;
	
	listaIPS.intertar_final(casilla);
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

void ControladorData::agregarEpsVacuna(Eps_Vacuna epsVacuna, int id){
	Casilla<Eps_Vacuna> casilla;
	casilla.data = epsVacuna;
	casilla.id = id;
	
	listaEpsVacuna.intertar_final(casilla);
}

void ControladorData::agregarIpsVacuna(Ips_Vacuna ipsVacuna,int id){
	Casilla<Ips_Vacuna> casilla;
	casilla.data = ipsVacuna;
	casilla.id = id;
	
	listaIpsVacuna.intertar_final(casilla);
}


int ControladorData::validarID(string idString){
	if(idString == "--"){
		return 0;
	}
	return atoi(idString.c_str());
}

int ControladorData::ingresarFecha(string plano){
	if(plano == "--") return 0;
	
	Fecha fecha = crearFecha(plano);
	listaFechas.intertar_final(fecha);
	
	return listaFechas.Tam_lista(); 
}

void ControladorData::organizarPacientesPorSexo(){
	
	ArbolBinarioOrdenado arbolMujeres;
	ArbolBinarioOrdenado arbolHombres;
	
	
	for(int i = 0; i < listaPersonas.Tam_lista(); i++){
		Casilla<Persona> casilla = listaPersonas.obtenerDato(i);
		Persona persona = casilla.data;
		int id = casilla.id;
		
		if(persona.getGenero() == "masculino"){
			arbolHombres.insertarNodo(id, persona.getEdad());
		}else if(persona.getGenero() == "femenino"){
			arbolMujeres.insertarNodo(id, persona.getEdad());
		}
	}
	 
	listaPacientesPorSexo.intertar_final(arbolMujeres);
	listaPacientesPorSexo.intertar_final(arbolHombres);
}

void ControladorData::organizarPacientesPorEps(){
	Casilla<Persona> casilla = listaPersonas.obtenerDato(1);
		Persona persona = casilla.data;
		
		cout<<"Persona "<<1<<" con el nombre ";
		cout<<persona.getNombres()<<endl;
		cout<<persona.getEps()->getNombre()<<endl;
		
	int size = listaEPS.Tam_lista();
	string epsDisponibles[size];
	
	for(int i = 1;i <= size; i++){
		ArbolBinarioOrdenado arbol;
		Eps eps = listaEPS.obtenerDato(i).data;
		listaPacientesPorEps.intertar_final(arbol);
		
		epsDisponibles[i-1] = eps.getNombre();
	}
	
	cout<<"se crean las eps"<<endl;
	
	
	for(int i = 1;i <=  listaPersonas.Tam_lista(); i++){
		Casilla<Persona> casilla = listaPersonas.obtenerDato(i);
		Persona persona = casilla.data;
		
		cout<<"Persona "<<i<<" con el nombre ";
		cout<<persona.getNombres()<<endl;
		cout<<persona.getEps()->getNombre()<<endl;
		
		for(int j = 0; j < size; j++){
			
			
			
			if(persona.getEpsName() == epsDisponibles[j]){
				ArbolBinarioOrdenado arbol = listaPacientesPorEps.obtenerDato(j+1);
				arbol.insertarNodo(casilla.id, persona.getEdad());
				
				break;
			}
		}
	}
	cout<<"fin"<<endl;
}



#endif
