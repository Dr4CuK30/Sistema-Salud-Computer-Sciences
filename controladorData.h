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
#include "ArbolRojiNegro.h"
#include "ArbolBiOrdFechas.h"
#include "Pila.h"
#include "Cola.h"

#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <string>

using namespace std;

const int CANT_ATRIBUTOS_VACUNA = 2;
const int CANT_ATRIBUTOS_PERSONA = 21;
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
		int cantidadCiudades;
		int cantidadPaises;
		int cantidadLaburos;
		
		//---------------------listas generales-----------------------------------//
		Lista < Casilla<Vacuna> > listaVacunas;
		Lista < Casilla <Persona> > listaPersonas;
		Lista < Casilla<Eps> >listaEPS;
		Lista < Casilla<Ips> > listaIPS;
		Lista < Casilla<Eps_Vacuna> > listaEpsVacuna;
		Lista < Casilla<Ips_Vacuna> > listaIpsVacuna;
		Lista < Casilla <string> > listaCiudades;
		Lista < Casilla<string> > listaPaises;
		Lista < Casilla<string> > listaLaburo;
		Lista<Fecha> listaFechas;

		//---------------------Arboles ordenados----------------------------------//
		
		ArbolBinarioOrdenado pacientesPorEdad;
		ArbolBiOrdFechas pacientesPorFechaPrimeraDosis;
		ArbolBiOrdFechas pacientesPorFechaSegundaDosis;

		//---------------------Arboles Rojinegros--------------------------------//
		ArbolRojiNegro < Casilla<Vacuna> > arbolRJVacunas;
		ArbolRojiNegro < Casilla <Persona> > arbolRJPersonas;
		ArbolRojiNegro < Casilla<Eps> > arbolRJEPS;
		ArbolRojiNegro < Casilla<Eps_Vacuna> > arbolRJEpsVacuna;
		ArbolRojiNegro < Casilla <Ips> > arbolRJIps;
		ArbolRojiNegro < Casilla <Ips_Vacuna> > arbolRJIpsVacuna;
		//---------------------Estructuras multiples-----------------------------//
		//preguntar por arreglos
		Lista < ArbolBinarioOrdenado > listaPacientesPorEps;
		Lista < ArbolBinarioOrdenado > listaPacientesPorIps;
		Lista < ArbolBinarioOrdenado > listaPacientesPorIpsAsignada;
		Lista < ArbolBinarioOrdenado > listaPacientesPorCiudadResidencia;
		Lista < ArbolBinarioOrdenado > listaPacientesPorPais;
		Lista < ArbolBinarioOrdenado > listaPacientesPorSexo;
		Lista < ArbolBinarioOrdenado > listaPacientesPorLaburo;
		Lista < ArbolBinarioOrdenado > listaPacientesPorVacuna;
		Lista < Lista<Persona*> > listaPacientesPorRangosDeEdad;
		
		Lista < Lista< Eps_Vacuna* > > listaVacunasPorEps;
		Lista < Lista< Ips_Vacuna* > > listaVacunasPorIps;
		Lista < Lista< Ips* > > listaIpsPorCiudad; 
		
		Lista < Lista< Ips* > > listaIpsPorEps;
		
		Lista < ArbolBinarioOrdenado > listaPacientesPorEstadoDeVacunacion;
		
		//-------------------Carga de datos--------------------------------------//
		void cargarArchivosLocales();
		void cargarArchivo(string rutaArchivo, int cantAtributos, int modelo);
		
		//------------------- Busquedas ---------------------------------------//
		string idDeVacunaPorNombre(string nombre);
		string idDeCiudadPorNombre(string nombre);
		string idDePaisPorNombre(string nombre);
		string idDeEpsPorNombre(string nombre);
		string idDeIpsPorNombre(string nombre);
		string idDeLaburoPorNombre(string nombre);
		
		//-------------------Guardado de datos-----------------------------------//
		void guardarDatos(string ruta, int modelo);
		
		//-------------------Formacion de estructuras----------------------------//
		
		//multilistas con arboles ordenados por edad
		void organizarPacientesPorEps();//
		void organizarPacientesPorIps();//
		void organizarPacientesPorIpsAsignada();
		void organizarPacientesPorCiudadResidencia();//
		void organizarPacientesPorPais();
		void organizarPacientesPorSexo();//
		void organizarPacientesPorLaburo();//
		void organizarPacientesPorVacuna();//
		
		void organizarPacientesPorRangosDeEdad();//
		void organizarVacunasPorEps();//
		void organizarVacunasPorIps();//
		void organizarIpsPorCiudad();//
		void organizarIpsPorEps();//
		void organizarPacientesPorEstadoVacunacion();
		
		//---------------Mutacion de estructuras--------------------------------//
		//posiblemente a otra clase
		
		// void agregarLaburo(string, int);
		void agregarVacuna(Vacuna, int);
		
		// void agregarEps(Eps, int);
		void agregarIps(Ips, int);
		
		void agregarEpsVacuna(Eps_Vacuna, int);
		void agregarIpsVacuna(Ips_Vacuna, int);
		void agregarPersona(Persona, int);
		
		
		//cambios de datos
		//--------------------------Utils-------------------------------------//
		int validarID(string);
		Cola<Persona*> deArbolACola(ArbolBinarioOrdenado *);
		
		
	public:
		
		ControladorData();
		int ingresarFecha(string);
		
		void agregarEps(Eps, int);
		
		void setPersona(Persona p, int id){
			
			agregarPersona(p, id);
			
			//Organiza por *EPS, *IPS, *Sexo, *Vacuna, *Pais, *Estado de Vac, Residencia

			// Agregar a árboles de EPS:
			for(int i = 1; i<=cantidadEPS; i++){
				ArbolBinarioOrdenado * arbOrd = listaPacientesPorEps.obtenerDato(i);
				if(arbOrd->getEtiqueta()==p.getEpsName()){
					arbOrd->insertarNodo(id, p.getEdad());
				}
				
			}

			// Agregar a árboles De IPS:
			for(int i =1; i<=cantidadIPS; i++){
				ArbolBinarioOrdenado *arbOrd = listaPacientesPorIps.obtenerDato(i);
				if(arbOrd->getEtiqueta()==p.getIpsAsignadaName()){
					arbOrd->insertarNodo(id, p.getEdad());
				}
			}


			// Agregar a árboles de Sexo/Género:
			for(int i=1; i<=2; i++){
				ArbolBinarioOrdenado *arbOrd = listaPacientesPorSexo.obtenerDato(i);
				string sxEtiqueta;
				if(p.getGenero()=="Masculino")sxEtiqueta="Hombres";
				if(p.getGenero()=="Femenino")sxEtiqueta="Mujeres";
				if(arbOrd->getEtiqueta()==sxEtiqueta){
					arbOrd->insertarNodo(id, p.getEdad());
				}
			}

			// Agregar a árboles de Vacuna:
			for(int i=1; i<=cantidadVacunas; i++){
				ArbolBinarioOrdenado *arbOrd = listaPacientesPorVacuna.obtenerDato(i);
				if(arbOrd->getEtiqueta()==p.getVacunaName()){
					arbOrd->insertarNodo(id, p.getEdad());
				}
			}

			// Agregar a arboles de Pais:
			for(int i=1; i<=cantidadPaises; i++){
				ArbolBinarioOrdenado *arbOrd = listaPacientesPorPais.obtenerDato(i);
				string pais = *(p.getPais_nac());
				if(arbOrd->getEtiqueta()==*(p.getPais_nac())){
					arbOrd->insertarNodo(id, p.getEdad());
				}
			}

			// Agregar a árboles por estado de vacuna
			for(int i=1; i<=listaPacientesPorEstadoDeVacunacion.Tam_lista(); i++){
				ArbolBinarioOrdenado *arbOrd = listaPacientesPorEstadoDeVacunacion.obtenerDato(i);
				int valorEtiqueta = 0;
				if(arbOrd->getEtiqueta()=="vacunados"){
					valorEtiqueta = 2;
				}

				if(arbOrd->getEtiqueta()=="semi-vacunados"){
					valorEtiqueta = 1;
				}
				if(valorEtiqueta==p.estadoVacuna()){
					arbOrd->insertarNodo(id, p.getEdad());
				}
			}

			// Agregar a árboles por Residencia:
			for(int i=1; i<=cantidadCiudades; i++){
				ArbolBinarioOrdenado *arbOrd = listaPacientesPorCiudadResidencia.obtenerDato(i);
				if(arbOrd->getEtiqueta()==*(p.getCiudad_resid())){
					arbOrd->insertarNodo(id, p.getEdad());
				}
			}

			// Agregar a árboles por Rango de edad:
			for(int i=1; i<=listaPacientesPorRangosDeEdad.Tam_lista(); i++){
				listaPacientesPorRangosDeEdad.eliminar(i);
			}

			this->organizarPacientesPorRangosDeEdad();
			
		};


		void setIPS(Ips ips, int id){
			this->agregarIps(ips, id);

			// Ips por Ciudad:
			for(int i=1; i<=listaIpsPorCiudad.Tam_lista(); i++){
				listaIpsPorCiudad.eliminar(i);
			}

			this->organizarIpsPorCiudad();

			// Ips por Eps:
			for(int i=1; i<=listaIpsPorEps.Tam_lista(); i++){
				listaIpsPorEps.eliminar(i);
			}

			this->organizarIpsPorEps();

		}

		void setVacuna(Vacuna vacuna, int id){
			agregarVacuna(vacuna, id);

			// Vacuna por IPS:
			for(int i=1; i<=listaVacunasPorIps.Tam_lista(); i++){
				listaVacunasPorIps.eliminar(i);
			}

			this->organizarVacunasPorIps();

			// Vacuna por EPS:
			for(int i=1; i<=listaVacunasPorEps.Tam_lista(); i++){
				listaVacunasPorEps.eliminar(i);
			}

			this->organizarVacunasPorEps();
		}
		void agregarPais(string, int);
		void agregarCiudad(string, int);
		void agregarLaburo(string, int);
		Lista<Fecha> getListaFechas()
		{
			return this->listaFechas;
		}
		
		void terminarPrograma();
		
		//-----------------------------Getters-----------------------------------//
		
		Cola<Persona*> getPersonas();//
		Cola<Vacuna*> getVacunas();//
		Cola<Eps*> getEpss();//
		Cola<Ips*> getIpss();//
		Cola<string*> getCiudades();//
		Cola<string*> getPaises();//
		Cola<string*> getLaburos();//
		Cola<Persona*> getPersonasPorCiudadResidencia(string ciudad);//
		Cola<Persona*> getPersonasPorEps(string eps);//
		Cola<Persona*> getPersonasPorRangoDeEdad(string rango);//
		Cola<Persona*> getPersonasPorTipoVacuna(string vacuna);//
		Cola<Persona*> getPersonasPorIps(string ips, bool asignada);//
		Cola<Persona*> getPersonasPorSexo(string sexo);//
		Cola<Persona*> getPersonasPorPais(string pais);//
		Cola<Ips*> getIpsPorCiudad(string ciudad);//
		Cola<Ips*> getIpsPorEps(string eps);//
	
		
		Cola<Persona*> getVacunadosPorFecha(string fecha, bool);
		Cola<Persona*> getVacunados();
		Cola<Persona*> getSemiVacunados();
		Cola<Persona*> getNoVacunados();
		Cola<Vacuna*> getVacunaPorEps(string);
		Cola<Ips_Vacuna*> getVacunasDisponibles(string ips);
		
		Persona *getPersona(int id);
		Eps *getEps(int id);
		Ips *getIps(int id);
		
		//------------------------Cantidades----------------------------//
		
		int getCantidadPorEps(string eps);//
		int getCantidadPorSexo(string sexo);
		int getCantidadEstadoVacuna(string estado);
		int getCantidadPersonas() {return cantidadPersonas;}
		int getCantidadVacunas() {return cantidadVacunas;}
		int getCantidadEps() {return cantidadEPS;}
		int getCantidadIps() {return cantidadIPS;}
		int getCantidadCiudades(){return cantidadCiudades;}
		int getCantidadPaises(){return cantidadPaises;}
		int getCantidadLaburos(){return cantidadLaburos;}
	
		
};


ControladorData::ControladorData(){
	
	this->cantidadEPS = 0;
	this->cantidadEPSVacunas = 0;
	this->cantidadIPSVacunas = 0;
	this->cantidadVacunas = 0;
	this->cantidadPersonas = 0;
	this->cantidadIPS = 0;
	this->cantidadCiudades = 0;
	this->cantidadPaises = 0;
	this->cantidadLaburos = 0;
	
	cargarArchivosLocales();
	
	
	this->organizarPacientesPorEps();
	this->organizarPacientesPorIps();
	this->organizarPacientesPorSexo();
	this->organizarPacientesPorVacuna();
	this->organizarPacientesPorPais();
	this->organizarPacientesPorEstadoVacunacion();
	this->organizarPacientesPorCiudadResidencia();
	this->organizarPacientesPorEstadoVacunacion();
	this->organizarVacunasPorEps();
//	this->organizarVacunasPorIps();
	cout<<"organiza por vac ips"<<endl;
	this->organizarPacientesPorRangosDeEdad();
	cout<<"organiza por edad"<<endl;
	this->organizarIpsPorCiudad();
	cout<<"organiza por ips city"<<endl;
	this->organizarIpsPorEps();
	cout<<"organiza por ips eps"<<endl;
	
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
	cargarArchivo("Archivos/laburos.txt", 2, 9);
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
					int idLaburo = atoi(atributos[21].c_str());
					
					int idFNacimiento = ingresarFecha(atributos[14]);
					int idFPri = ingresarFecha(atributos[15]);
					int idFSeg = ingresarFecha(atributos[16]);
					
					Vacuna *pVacuna;
					string *pCiudadNac;
					string *pPais;
					string *pCiudadRes;
					string *pLaburo;
					Eps *pEps;
					Ips *pIpsDefault;
					Ips *pIpsAsignada;
					Fecha *pFechaNac;
					Fecha *pFechaPri;
					Fecha *pFechaSec;
					
					if(idVacuna == 0) pVacuna = NULL;
					else {
						// pVacuna = &(listaVacunas.obtenerDato(idVacuna)->data);
						// cout<<pVacuna->getNombre()<<" HURTADO 1"<<endl;

						NodoArbolRJ< Casilla<Vacuna> > * raiz = arbolRJVacunas.raiz_arbol();
						pVacuna = &(arbolRJVacunas.buscarNodo(idVacuna, &raiz, NULL)->data->data);
						// cout<<pVacuna->getNombre()<<" HURTADO 2"<<endl;
					}
					
					if(idCiudadNac == 0) pCiudadNac = NULL;
					else pCiudadNac = &(listaCiudades.obtenerDato(idCiudadNac)->data);
					
					if(idPais == 0) pPais = NULL;
					else{
						Casilla<string> *casilla = listaPaises.obtenerDato(idPais);
						pPais = &(casilla->data);
					}
					if(idCiudadRes == 0) pCiudadRes = NULL;
					else{
						Casilla<string> *casilla = listaCiudades.obtenerDato(idCiudadRes);
						pCiudadRes = &(casilla->data);
					}
					if(idLaburo == 0) pLaburo = NULL;
					else{
						Casilla<string> *casilla = listaLaburo.obtenerDato(idLaburo);
						pLaburo = &(casilla->data);
					}
					if(idEps== 0) pEps = NULL;
					else {
						// pEps = &(listaEPS.obtenerDato(idEps)->data);

						NodoArbolRJ< Casilla<Eps> > * raiz = arbolRJEPS.raiz_arbol();
						pEps = &(arbolRJEPS.buscarNodo(idEps, &raiz, NULL)->data->data);
						// cout<<pEps->getNombre()<<" HURTADO 2"<<endl;
					}
					
					if(idIpsDefault == 0) pIpsDefault = NULL;
					else{
						// pIpsDefault = &(listaIPS.obtenerDato(idIpsDefault)->data);

						NodoArbolRJ< Casilla<Ips> > * raiz = arbolRJIps.raiz_arbol();
						pIpsDefault = &(arbolRJIps.buscarNodo(idIpsDefault, &raiz, NULL)->data->data);
						// cout<<pIpsDefault->getNombre()<<" HURTADO 2"<<endl;
						
					}
					
					if(idIpsAsignada == 0) pIpsAsignada = NULL;
					else{
						// pIpsAsignada = &(listaIPS.obtenerDato(idIpsAsignada)->data);

						NodoArbolRJ< Casilla<Ips> > * raiz = arbolRJIps.raiz_arbol();
						pIpsAsignada = &(arbolRJIps.buscarNodo(idIpsAsignada, &raiz, NULL)->data->data);
						// cout<<pIpsAsignada->getNombre()<<" HURTADO 2"<<endl;
					}
					
					if(idFNacimiento == 0) pFechaNac = NULL;
					else pFechaNac =  listaFechas.obtenerDato(idFNacimiento);
					
					if(idFPri == 0) pFechaPri = NULL;
					else pFechaPri =  listaFechas.obtenerDato(idFPri);
					
					if(idFSeg == 0) pFechaSec = NULL;
					else pFechaSec = listaFechas.obtenerDato(idFSeg);
					
					long long numId = strtoll(atributos[1].c_str(),NULL,0);
					long long tel_cel =strtoll(atributos[12].c_str(),NULL,0);
					long long tel_fijo = strtoll(atributos[12].c_str(),NULL,0);
					
					Persona persona = Persona(numId,atributos[2],atributos[3],atributos[4],
												atributos[5],atributos[6],pCiudadNac,pPais,pCiudadRes,atributos[10],
												atributos[11],tel_cel,tel_fijo,
												pFechaNac ,pFechaPri ,pFechaSec ,
												pVacuna,pEps,pIpsDefault,pIpsAsignada, pLaburo);
					
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
					int idCiudad = atoi(atributos[3].c_str());

					Eps *eps = &(listaEPS.obtenerDato(idEps)->data);
					string *ciudad = &(listaCiudades.obtenerDato(idCiudad)->data);
					
//					NodoArbolRJ< Casilla<Eps> > * raiz = arbolRJEPS.raiz_arbol();
//					Eps *eps = &(arbolRJEPS.buscarNodo(idEps, &raiz, NULL)->data->data);
					
					//poner bien la ciudad
					Ips ips = Ips(atributos[1],atributos[2],ciudad,eps);
					agregarIps(ips, id);
					
					break;
				}
				case 5:{
					int idEps = atoi(atributos[1].c_str());
					int idVacuna =  atoi(atributos[2].c_str()); 
					
					cout<<atributos[1]<<endl;
					
					// Eps *eps = &(listaEPS.obtenerDato(idEps)->data);
					Vacuna *vacuna = &(listaVacunas.obtenerDato(idVacuna)->data);

					NodoArbolRJ< Casilla<Eps> > * raiz = arbolRJEPS.raiz_arbol();
					Eps *eps = &(arbolRJEPS.buscarNodo(idEps, &raiz, NULL)->data->data);

					// NodoArbolRJ< Casilla<Vacuna> > * raizVacuna = arbolRJVacunas.raiz_arbol();
					// Vacuna *vacuna = &(arbolRJVacunas.buscarNodo(idVacuna, &raizVacuna, NULL)->data->data);
					
					Eps_Vacuna epsVacuna = Eps_Vacuna(eps, vacuna, atoi(atributos[2].c_str()));
					agregarEpsVacuna(epsVacuna, id);
					break;
				}
				case 6:{
					int idIps = atoi(atributos[1].c_str());
					int idVacuna = atoi(atributos[2].c_str());
					
					Ips *ips = &(listaIPS.obtenerDato(idIps)->data);
					Vacuna *vacuna = &(listaVacunas.obtenerDato(idVacuna)->data);
					
					Ips_Vacuna ips_vacuna = Ips_Vacuna(ips, vacuna);
					
					agregarIpsVacuna(ips_vacuna, id);
					
					break;
				}
				case 7:
					agregarCiudad(atributos[1], id);
					break;
				case 8:
					agregarPais(atributos[1], id);
					break;
				case 9:
					agregarLaburo(atributos[1], id);
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

void ControladorData::guardarDatos(string ruta, int modelo){
	fstream archivo;
	string linea, *atributos;
	archivo.open(ruta.c_str(), ofstream::out | ofstream::trunc);
	if(archivo.is_open()){
		switch (modelo) {
			case 1:
				//PERSONA
				for(int i = 1; i <= listaPersonas.getSize(); i++){
					Casilla<Persona> *casilla = listaPersonas.obtenerDato(i);
					Persona persona = casilla->data;
					
					string idVacuna =  "--";
					string idCiudadNac = "--"; //atoi(atributos[7].c_str());
					string idPais = "--"; //atoi(atributos[8].c_str());
					string idCiudadRes = "--"; //atoi(atributos[9].c_str());
					string FNacimiento = "--"; //fechaToString(persona.getF_nacimiento());	
					string FPri = "--"; //ingresarFecha(atributos[15]);
					string FSeg = "--"; //ingresarFecha(atributos[16]);
					string idEps = "--"; //atoi(atributos[18].c_str());
					string idIpsDefault = "--"; // atoi(atributos[19].c_str());
					string idIpsAsignada = "--"; // atoi(atributos[20].c_str());
					string idLaburo = "--"; // atoi(atributos[21].c_str());
					if(persona.getVacuna() != NULL){
						idVacuna = idDeVacunaPorNombre(persona.getVacuna()->getNombre());
					}
					if(persona.getCiudad_nac() != NULL){
						idCiudadNac = idDeCiudadPorNombre(*persona.getCiudad_nac());
					}
					if(persona.getPais_nac() != NULL){
						idPais = idDePaisPorNombre(*persona.getPais_nac());
					}
					if(persona.getCiudad_resid() != NULL){
						idCiudadRes = idDeCiudadPorNombre(*persona.getCiudad_resid());
					}
					if(persona.getF_nacimiento() != NULL){
						FNacimiento = fechaToString(*persona.getF_nacimiento());	
					}
					if(persona.getF_primera_dosis() != NULL){
						FPri = fechaToString(*persona.getF_primera_dosis());	
					}
					if(persona.getF_segunda_dosis() != NULL){
						FSeg = fechaToString(*persona.getF_segunda_dosis());	
					}
					if(persona.getVacuna() != NULL){
						idVacuna = idDeVacunaPorNombre(persona.getVacunaName());
					}
					if(persona.getEps() != NULL){
						idEps = idDeEpsPorNombre(persona.getEpsName());
					}
					if(persona.getIps_default() != NULL){
						idIpsDefault = idDeIpsPorNombre(persona.getIpsDefaultName());
					}
					if(persona.getIps_asignada() != NULL){
						idIpsAsignada = idDeIpsPorNombre(persona.getIpsAsignadaName());
					}
					if(persona.getAct_laboral() != NULL){
						idLaburo = idDeLaburoPorNombre(*persona.getAct_laboral());
					}
					archivo
						<<casilla->id<<";;"
						<<persona.getId().numero<<";;"
						<<persona.getId().tipo<<";;"
						<<persona.getNombres()<<";;"
						<<persona.getApellidos()<<";;"
						<<persona.getGenero()<<";;"
						<<persona.getEmail()<<";;"
						<<idCiudadNac<<";;"
						<<idPais<<";;"
						<<idCiudadRes<<";;"
						<<persona.getDireccion()<<";;"
						<<persona.getBarrio()<<";;"
						<<persona.getTelefono_cel()<<";;"
						<<persona.getTelefono_fijo()<<";;"
						<<FNacimiento<<";;"
						<<FPri<<";;"
						<<FSeg<<";;"
						<<idVacuna<<";;"
						<<idEps<<";;"
						<<idIpsDefault<<";;"
						<<idIpsAsignada<<";;"
						<<idLaburo<<endl
						;
				}
				break;
			case 2:
				//VACUNAS
				for(int i = 1; i <= listaVacunas.getSize(); i++){
					Casilla<Vacuna> *casilla = listaVacunas.obtenerDato(i);
					Vacuna vacuna = casilla->data;
					archivo
						<<casilla->id<<";;"
						<<vacuna.getNombre()<<";;"
						<<vacuna.getCantidadDosis()<<endl;
				}
				break;
			case 3:
				//EPS
				for(int i = 1; i <= listaEPS.getSize(); i++){
					Casilla<Eps> *casilla = listaEPS.obtenerDato(i);
					Eps eps = casilla->data;
					archivo
						<<casilla->id<<";;"
						<<eps.getNombre()<<endl;
				}
				break;
			case 4:
				//IPS
				for(int i = 1; i <= listaIPS.getSize(); i++){
					Casilla<Ips> *casilla = listaIPS.obtenerDato(i);
					Ips ips = casilla->data;
					
					string idCiudad = "--";
					string idEps = "--";
					
					if(ips.getEps() != NULL){
						idEps = idDeEpsPorNombre(ips.getEpsName());
					}
					if(ips.getCiudad() != NULL){
						idCiudad = idDeCiudadPorNombre(*ips.getCiudad());
					}
					
					archivo
						<<casilla->id<<";;"
						<<ips.getNombre()<<";;"
						<<ips.getDireccion()<<";;"
						<<idCiudad<<";;"
						<<idEps<<endl;
				}
				break;
			case 5:
				//EPS_VACUNA
				for(int i = 1; i <= listaEpsVacuna.getSize(); i++){
					Casilla<Eps_Vacuna> *casilla = listaEpsVacuna.obtenerDato(i);
					Eps_Vacuna epsv = casilla->data;
					
					string idVacuna = "--";
					string idEps = "--";
					
					if(epsv.getEps() != NULL){
						idEps = idDeEpsPorNombre(epsv.getEpsName());
					}
					if(epsv.getVacuna() != NULL){
						idVacuna = idDeVacunaPorNombre(epsv.getVacunaName());
					}
					archivo
						<<casilla->id<<";;"
						<<idEps<<";;"
						<<idVacuna<<";;"
						<<epsv.getStock()<<endl;
				}
				break;
			case 6:
				//IPS_VACUNA
				for(int i = 1; i <= listaIpsVacuna.getSize(); i++){
					Casilla<Ips_Vacuna> *casilla = listaIpsVacuna.obtenerDato(i);
					Ips_Vacuna ipsv = casilla->data;
					
					string idVacuna = "--";
					string idIps = "--";
					
					if(ipsv.getIps() != NULL){
						idIps = idDeIpsPorNombre(ipsv.getIpsName());
					}
					if(ipsv.getVacuna() != NULL){
						idVacuna = idDeVacunaPorNombre(ipsv.getVacunaName());
					}
					archivo
						<<casilla->id<<";;"
						<<idIps<<";;"
						<<idVacuna<<endl;
				}
				break;
			case 7:
				//CIUDADES
				for(int i = 1; i <= listaCiudades.getSize(); i++){
					Casilla<string> *casilla = listaCiudades.obtenerDato(i);
					archivo
						<<casilla->id<<";;"
						<<casilla->data<<endl;
				}
				break;
			case 8:
				//PAISES
				for(int i = 1; i <= listaPaises.getSize(); i++){
					Casilla<string> *casilla = listaPaises.obtenerDato(i);
					archivo
						<<casilla->id<<";;"
						<<casilla->data<<endl;
				}
				break;
			case 9:
				//LABUROS
				for(int i = 1; i <= listaLaburo.getSize(); i++){
					Casilla<string> *casilla = listaLaburo.obtenerDato(i);
					archivo
						<<casilla->id<<";;"
						<<casilla->data<<endl;
				}
				break;
			default:
				break;
		}
	} else {
		cout<<"No abre pa: "<<modelo<<endl;
	}
}

void ControladorData::terminarPrograma(){
	guardarDatos("Archivos/laburos.txt", 9);
	guardarDatos("Archivos/ciudades.txt", 7);
	guardarDatos("Archivos/paises.txt", 8);
	guardarDatos("Archivos/vacunas.txt", 2);
	guardarDatos("Archivos/eps.txt", 3);
	guardarDatos("Archivos/ips.txt", 4);
	guardarDatos("Archivos/personas.txt", 1);
	guardarDatos("Archivos/eps_vacuna.txt", 5);
	guardarDatos("Archivos/ips_vacuna.txt", 6);
}

void ControladorData::agregarVacuna(Vacuna vacuna, int id){
//	int posicion = listaVacunas.Tam_lista(); podria ser util para verificacion de pos de ser necesario
	Casilla<Vacuna> casilla;
	casilla.data = vacuna;
	casilla.id = id;
	listaVacunas.intertar_final(casilla);
	
	Casilla< Vacuna > * vacunaDir = listaVacunas.obtenerDato(id);
	arbolRJVacunas.insertar(vacunaDir);

	cantidadVacunas++;
}

void ControladorData::agregarPersona(Persona persona, int id){
	Casilla<Persona> casilla;
	casilla.data = persona;
	casilla.id = id;
	
	pacientesPorEdad.insertarNodo(id, persona.getEdad());
	if(persona.getF_primera_dosis() != NULL)
		 pacientesPorFechaPrimeraDosis.insertarNodo(id, *(persona.getF_primera_dosis()));
	if(persona.getF_segunda_dosis() != NULL)
		 pacientesPorFechaSegundaDosis.insertarNodo(id, *(persona.getF_segunda_dosis()));
		 
	listaPersonas.intertar_final(casilla);
	
	if(persona.getF_primera_dosis() != NULL)
		 pacientesPorFechaPrimeraDosis.insertarNodo(id, *(persona.getF_primera_dosis()));
	if(persona.getF_segunda_dosis() != NULL)
		 pacientesPorFechaSegundaDosis.insertarNodo(id, *(persona.getF_segunda_dosis()));

	Casilla< Persona > * personaDir = listaPersonas.obtenerDato(id);
	arbolRJPersonas.insertar(personaDir);

	cantidadPersonas++;
	
}

void ControladorData::agregarEps(Eps eps, int id){
	Casilla<Eps> casilla;
	casilla.data = eps;
	casilla.id = id;
	
	listaEPS.intertar_final(casilla);

	Casilla< Eps > * epsDir = listaEPS.obtenerDato(id);
	arbolRJEPS.insertar(epsDir);
	cantidadEPS++;
}

void ControladorData::agregarIps(Ips ips, int id){
	Casilla<Ips> casilla;
	casilla.data = ips;
	casilla.id = id;

	listaIPS.intertar_final(casilla);

	Casilla< Ips > * ipsDir = listaIPS.obtenerDato(id);
	arbolRJIps.insertar(ipsDir);
	
	
	cantidadIPS++;
}

void ControladorData::agregarCiudad(string ciudad, int id){
	Casilla<string> casilla;
	casilla.data = ciudad;
	casilla.id = id;
	
	listaCiudades.intertar_final(casilla);
	cantidadCiudades++;
}

void ControladorData::agregarPais(string pais, int id){
	Casilla<string> casilla;
	casilla.data = pais;
	casilla.id = id;
	
	listaPaises.intertar_final(casilla);
	cantidadPaises++;
}

void ControladorData::agregarLaburo(string labor, int id){
	Casilla<string> casilla;
	casilla.data = labor;
	casilla.id = id;
	
	listaLaburo.intertar_final(casilla);
	cantidadLaburos++;
}

void ControladorData::agregarEpsVacuna(Eps_Vacuna epsVacuna, int id){
	Casilla<Eps_Vacuna> casilla;
	casilla.data = epsVacuna;
	casilla.id = id;
	
	listaEpsVacuna.intertar_final(casilla);

	Casilla< Eps_Vacuna > * epsVacunaDir = listaEpsVacuna.obtenerDato(id);
	arbolRJEpsVacuna.insertar(epsVacunaDir);

	cantidadEPSVacunas++;
}

void ControladorData::agregarIpsVacuna(Ips_Vacuna ipsVacuna,int id){
	Casilla<Ips_Vacuna> casilla;
	casilla.data = ipsVacuna;
	casilla.id = id;
	
	listaIpsVacuna.intertar_final(casilla);

	Casilla< Ips_Vacuna > * ipsVacunaDir = listaIpsVacuna.obtenerDato(id);
	arbolRJIpsVacuna.insertar(ipsVacunaDir);

	cantidadIPSVacunas++;
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
	
	arbolHombres.setEtiqueta("Hombres");
	arbolMujeres.setEtiqueta("Mujeres");
	
	for(int i = 1; i <= listaPersonas.Tam_lista(); i++){
		Casilla<Persona> *casilla = listaPersonas.obtenerDato(i);
		Persona persona = casilla->data;
		int id = casilla->id;
		
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
		
	string epsDisponibles[cantidadEPS];
	
	for(int i = 1;i <= cantidadEPS; i++){
		ArbolBinarioOrdenado arbol;
		Eps eps = listaEPS.obtenerDato(i)->data;
		
		arbol.setEtiqueta(eps.getNombre());
		listaPacientesPorEps.intertar_final(arbol);
		
		epsDisponibles[i-1] = eps.getNombre();
	}
	
	for(int i = 1;i <= cantidadPersonas ; i++){
		Casilla<Persona> *casilla = listaPersonas.obtenerDato(i);
		Persona persona = casilla->data;
		
		for(int j = 0; j < cantidadEPS; j++){
			
			if(persona.getEpsName() == epsDisponibles[j]){
				ArbolBinarioOrdenado *arbol = listaPacientesPorEps.obtenerDato(j+1);
				arbol->insertarNodo(casilla->id, persona.getEdad());
				break;
			}
		}
	}
}

void ControladorData::organizarPacientesPorIps(){
	string ipsDisponibles[cantidadIPS];
	
	for(int i = 1;i <= cantidadIPS; i++){
		ArbolBinarioOrdenado arbol1;
		ArbolBinarioOrdenado arbol2;
		Ips ips = listaIPS.obtenerDato(i)->data;
		
		arbol1.setEtiqueta(ips.getNombre());
		arbol2.setEtiqueta(ips.getNombre());
		listaPacientesPorIps.intertar_final(arbol1);
		listaPacientesPorIpsAsignada.intertar_final(arbol2);
		
		ipsDisponibles[i-1] = ips.getNombre();
	}
	
	
	for(int i = 1;i <= cantidadPersonas ; i++){
		Casilla<Persona> *casilla = listaPersonas.obtenerDato(i);
		Persona persona = casilla->data;
		for(int j = 0; j < cantidadIPS; j++){
			
			if(persona.getIpsDefaultName() == ipsDisponibles[j]){
				ArbolBinarioOrdenado *arbol = listaPacientesPorIps.obtenerDato(j+1);
				arbol->insertarNodo(casilla->id, persona.getEdad());
			}
			
			if(persona.getIpsAsignadaName() == ipsDisponibles[j]){
				ArbolBinarioOrdenado *arbol = listaPacientesPorIpsAsignada.obtenerDato(j+1);
				arbol->insertarNodo(casilla->id, persona.getEdad());
			}
		}
	}
}

void ControladorData::organizarPacientesPorVacuna(){
	
	string vacunasDisponibles[cantidadVacunas];
	
	for(int i = 1; i <= cantidadVacunas; i++){
		ArbolBinarioOrdenado arbol;
		Vacuna vacuna = listaVacunas.obtenerDato(i)->data;
		arbol.setEtiqueta(vacuna.getNombre());
		
		listaPacientesPorVacuna.intertar_final(arbol);
		
		vacunasDisponibles[i-1] = vacuna.getNombre();
	}
	
	for(int i = 1; i <= cantidadPersonas; i++){
		Casilla<Persona> *casilla = listaPersonas.obtenerDato(i);
		Persona persona = casilla->data;
		for(int j = 0; j < cantidadVacunas; j++){
			if(persona.getVacuna() != NULL){
				if(persona.getVacunaName() == vacunasDisponibles[j]){
					ArbolBinarioOrdenado *arbol = listaPacientesPorVacuna.obtenerDato(j+1);
					arbol->insertarNodo(casilla->id, persona.getEdad());
					break;
				}
			}
		} 
	}
}

void ControladorData::organizarPacientesPorCiudadResidencia(){
	
	string ciudadesDisponibles[cantidadCiudades];
	
	for(int i = 1; i <= cantidadCiudades; i++){
		ArbolBinarioOrdenado arbol;
		string ciudad = listaCiudades.obtenerDato(i)->data;
		arbol.setEtiqueta(ciudad); 
		listaPacientesPorCiudadResidencia.intertar_final(arbol);
		ciudadesDisponibles[i-1] = ciudad;
	}
	
	for(int i = 1;i <= cantidadPersonas; i++){
		Casilla<Persona> *casilla = listaPersonas.obtenerDato(i);
		Persona persona = casilla->data;
		for(int j = 0; j < cantidadCiudades; j++){
			if(*(persona.getCiudad_resid()) == ciudadesDisponibles[j]){
				ArbolBinarioOrdenado *arbol = listaPacientesPorCiudadResidencia.obtenerDato(j+1);
				arbol->insertarNodo(casilla->id, persona.getEdad());
				break;
			}
			
		} 
	}
	
}

void ControladorData::organizarPacientesPorPais(){
	
	string paisesDisponibles[cantidadPaises];
	
	for(int i = 1; i <= cantidadPaises; i++){
		ArbolBinarioOrdenado arbol;
		string pais = listaPaises.obtenerDato(i)->data;
		arbol.setEtiqueta(pais); 
		listaPacientesPorPais.intertar_final(arbol);
		paisesDisponibles[i-1] = pais;
		
	}
	for(int i = 1;i <= cantidadPersonas; i++){
		Casilla<Persona> *casilla = listaPersonas.obtenerDato(i);
		Persona persona = casilla->data;
		
		for(int j = 0; j < cantidadCiudades; j++){
			if(*(persona.getPais_nac()) == paisesDisponibles[j]){
				ArbolBinarioOrdenado *arbol = listaPacientesPorPais.obtenerDato(j+1);
				arbol->insertarNodo(casilla->id, persona.getEdad());
				break;
			}
			
		} 
	}
}

void ControladorData::organizarPacientesPorRangosDeEdad(){
	
	string rangosDeEdad[] = {"-20","20-29","30-39","40-49","50-59","60-69","70-79","+80"};
	int cantRangos = 8;
	
	for(int i = 1; i <= cantRangos;i++){
		Lista<Persona*> lista;
		lista.setEtiqueta(rangosDeEdad[i-1]);
		listaPacientesPorRangosDeEdad.intertar_final(lista);
	}
	
	int idPersonasOrdenadas[cantidadPersonas];
	pacientesPorEdad.inordenArray(pacientesPorEdad.obtenerRaiz(),0, idPersonasOrdenadas);
	
	for(int i = 0; i < cantidadPersonas; i++){
		int idBusqueda = idPersonasOrdenadas[i];
		
		NodoArbolRJ< Casilla<Persona> > * raiz = arbolRJPersonas.raiz_arbol();
		Casilla<Persona> *casilla = arbolRJPersonas.buscarNodo(idBusqueda, &raiz, NULL)->data;
		Persona *persona = &(casilla->data);
		
		if(persona->getEdad() < 20){
			Lista<Persona*> *lista = listaPacientesPorRangosDeEdad.obtenerDato(1);
			lista->intertar_final(persona);
		}else if(persona->getEdad() >= 20 && persona->getEdad() <= 29){
			Lista<Persona*> *lista = listaPacientesPorRangosDeEdad.obtenerDato(2);
			lista->intertar_final(persona);
		}else if(persona->getEdad() >= 30 && persona->getEdad() <= 39){
			Lista<Persona*> *lista = listaPacientesPorRangosDeEdad.obtenerDato(3);
			lista->intertar_final(persona);
		}else if(persona->getEdad() >= 40 && persona->getEdad() <= 49){
			Lista<Persona*> *lista = listaPacientesPorRangosDeEdad.obtenerDato(4);
			lista->intertar_final(persona);
		}else if(persona->getEdad() >= 50 && persona->getEdad() <= 59){
			Lista<Persona*> *lista = listaPacientesPorRangosDeEdad.obtenerDato(5);
			lista->intertar_final(persona);
		}else if(persona->getEdad() >= 60 && persona->getEdad() <= 69){
			Lista<Persona*> *lista = listaPacientesPorRangosDeEdad.obtenerDato(6);
			lista->intertar_final(persona);
		}else if(persona->getEdad() >= 70 && persona->getEdad() <= 79){
			Lista<Persona*> *lista = listaPacientesPorRangosDeEdad.obtenerDato(7);
			lista->intertar_final(persona);
		}else if(persona->getEdad() >= 80){
			Lista<Persona*> *lista = listaPacientesPorRangosDeEdad.obtenerDato(8);
			lista->intertar_final(persona);
		}
	}
}

void ControladorData::organizarVacunasPorEps(){
	
	string epsDisponibles[cantidadEPS];
	
	for(int i = 1; i <= cantidadEPS; i++){
		Lista<Eps_Vacuna*> lista;
		Eps eps = listaEPS.obtenerDato(i)->data;
		lista.setEtiqueta(eps.getNombre());
		
		epsDisponibles[i-1] = eps.getNombre();
		listaVacunasPorEps.intertar_final(lista);
	}
	
	for(int i = 1; i <= cantidadEPSVacunas; i++){
		Casilla<Eps_Vacuna> *casilla = listaEpsVacuna.obtenerDato(i);
		Eps_Vacuna *epsVacuna = &(casilla->data);
		
		for(int j = 0; j < cantidadEPS; j++){
			
			if(epsVacuna->getEpsName() == epsDisponibles[j]){
				Lista<Eps_Vacuna*> *lista = listaVacunasPorEps.obtenerDato(j+1);
				lista->intertar_final(epsVacuna);
				break;
			}
		}
	}
}

void ControladorData::organizarVacunasPorIps(){
	
	string ipsDisponibles[cantidadIPS];
	
	for(int i = 1; i <= cantidadIPS; i++){
		Lista<Ips_Vacuna*> lista;
		Ips ips = listaIPS.obtenerDato(i)->data;
		lista.setEtiqueta(ips.getNombre());
		
		ipsDisponibles[i-1] = ips.getNombre();
		listaVacunasPorIps.intertar_final(lista);
	}
	cout<<"obtiene las ips"<<endl;
	for(int i = 1; i <= cantidadEPSVacunas; i++){
		Casilla<Ips_Vacuna> *casilla = listaIpsVacuna.obtenerDato(i);
		Ips_Vacuna *ipsVacuna = &(casilla->data);
		
		for(int j = 0; j < cantidadIPS; j++){
			
			if(ipsVacuna->getIpsName() == ipsDisponibles[j]){
				Lista<Ips_Vacuna*> *lista = listaVacunasPorIps.obtenerDato(j+1);
				lista->intertar_final(ipsVacuna);
				break;
			}
		}
	}
	cout<<"cierra piola"<<endl;
}

void ControladorData::organizarIpsPorCiudad(){
	
	string ciudadesDisponibles[cantidadCiudades];
	
	for(int i = 1; i <= cantidadCiudades; i++){
		Lista<Ips*> lista;
		string ciudad = listaCiudades.obtenerDato(i)->data;
		lista.setEtiqueta(ciudad); 
		listaIpsPorCiudad.intertar_final(lista);
		ciudadesDisponibles[i-1] = ciudad;
	}
	
	for(int i = 1;i <= cantidadIPS ; i++){
		Casilla<Ips> *casilla = listaIPS.obtenerDato(i);
		Ips *ips = &(casilla->data);
		
		for(int j = 0; j < cantidadCiudades; j++){
			if(*(ips->getCiudad()) == ciudadesDisponibles[j]){
				Lista<Ips*> *lista = listaIpsPorCiudad.obtenerDato(j+1);
				lista->intertar_final(ips);
				break;
			}
			
		} 
	}
}

void ControladorData::organizarIpsPorEps(){
	string epsDisponibles[cantidadEPS];

	for(int i = 1; i <= cantidadEPS; i++){
		Lista<Ips*> lista;
		Eps eps = listaEPS.obtenerDato(i)->data;
		lista.setEtiqueta(eps.getNombre());

		epsDisponibles[i-1] = eps.getNombre();
		listaIpsPorEps.intertar_final(lista);
	}

	for(int i = 1;i <= cantidadIPS ; i++){
		Casilla<Ips> *casilla = listaIPS.obtenerDato(i);
		Ips *ips = &(casilla->data);

		for(int j = 0; j < cantidadEPS; j++){
			if(ips->getEpsName() == epsDisponibles[j]){
				Lista<Ips*> *lista = listaIpsPorEps.obtenerDato(j+1);
				lista->intertar_final(ips);
				break;
			}

		} 
	}
}

void ControladorData::organizarPacientesPorEstadoVacunacion(){
	ArbolBinarioOrdenado vacunados;
	vacunados.setEtiqueta("vacunados");
	ArbolBinarioOrdenado semivacunados;
	semivacunados.setEtiqueta("semi-vacunados");
	ArbolBinarioOrdenado novacunados;
	novacunados.setEtiqueta("no-vacunados");

	for(int i = 1; i <= listaPersonas.Tam_lista(); i++){

		NodoArbolRJ< Casilla<Persona> > * raiz = arbolRJPersonas.raiz_arbol();
		Persona *persona = &(arbolRJPersonas.buscarNodo(i, &raiz, NULL)->data->data);

		int id = i;

		if(persona->estadoVacuna() == 2){
			vacunados.insertarNodo(id, persona->getEdad());
		}else if(persona->estadoVacuna() == 1){
			semivacunados.insertarNodo(id, persona->getEdad());
		}else if(persona->estadoVacuna() == 0){
			novacunados.insertarNodo(id, persona->getEdad());
		}
	}

	listaPacientesPorEstadoDeVacunacion.intertar_final(vacunados);
	listaPacientesPorEstadoDeVacunacion.intertar_final(semivacunados);
	listaPacientesPorEstadoDeVacunacion.intertar_final(novacunados);
}

//---------------------------Busquedas-----------------------------------//
string ControladorData::idDeVacunaPorNombre(string nombre){
	stringstream ss;
	Casilla<Vacuna> *aux_vacuna;
	for(int i = 1; i<=listaVacunas.getSize(); i++){
		aux_vacuna = listaVacunas.obtenerDato(i);
		if(aux_vacuna->data.getNombre() == nombre){
			ss<<aux_vacuna->id;
			return ss.str();
		}
	}
}
string ControladorData::idDeCiudadPorNombre(string nombre){
	stringstream ss;
	Casilla<string> *aux_ciudad;
	for(int i = 1; i<=listaCiudades.getSize(); i++){
		aux_ciudad = listaCiudades.obtenerDato(i);
		if(aux_ciudad->data == nombre){
			ss<<aux_ciudad->id;
			return ss.str();
		}
	}
}
string ControladorData::idDePaisPorNombre(string nombre){
	stringstream ss;
	Casilla<string> *aux_pais;
	for(int i = 1; i<=listaPaises.getSize(); i++){
		aux_pais = listaPaises.obtenerDato(i);
		if(aux_pais->data == nombre){
			ss<<aux_pais->id;
			return ss.str();
		}
	}
}
string ControladorData::idDeEpsPorNombre(string nombre){
	stringstream ss;
	Casilla<Eps> *aux_eps;
	for(int i = 1; i<=listaEPS.getSize(); i++){
		aux_eps = listaEPS.obtenerDato(i);
		if(aux_eps->data.getNombre() == nombre){
			ss<<aux_eps->id;
			return ss.str();
		}
	}
}
string ControladorData::idDeIpsPorNombre(string nombre){
	stringstream ss;
	Casilla<Ips> *aux_ips;
	for(int i = 1; i<=listaIPS.getSize(); i++){
		aux_ips = listaIPS.obtenerDato(i);
		if(aux_ips->data.getNombre() == nombre){
			ss<<aux_ips->id;
			return ss.str();
		}
	}
}
string ControladorData::idDeLaburoPorNombre(string nombre){
	stringstream ss;
	Casilla<string> *aux_laburo;
	for(int i = 1; i<=listaLaburo.getSize(); i++){
		aux_laburo = listaLaburo.obtenerDato(i);
		if(aux_laburo->data == nombre){
			ss<<aux_laburo->id;
			return ss.str();
		}
	}
}

Cola<Persona*> ControladorData::deArbolACola(ArbolBinarioOrdenado *arbolPersonas){
	Cola<Persona*> colaPersonas;
	int cantidadPersonasLocal = arbolPersonas->getTamArbol();
	
	int idPersonasOrdenadas[cantidadPersonasLocal];
	pacientesPorEdad.inordenArray(arbolPersonas->obtenerRaiz(),0, idPersonasOrdenadas);
	
	for(int i = 0; i < cantidadPersonasLocal; i++){
		int idBusqueda = idPersonasOrdenadas[i];
		
		NodoArbolRJ< Casilla<Persona> > * raiz = arbolRJPersonas.raiz_arbol();
		
		Casilla<Persona> *casilla = arbolRJPersonas.buscarNodo(idBusqueda, &raiz, NULL)->data;
		Persona *persona = &(casilla->data);
		cout<<persona->getNombres()<<endl;
		colaPersonas.push(persona);
	}
	cout<<"tamanio "<<colaPersonas.getSize()<<endl;
	return colaPersonas;
}

//-------------------------metodos publicos----------------------------//
//aca son importantes los rojinegros
Cola<Persona*> ControladorData::getPersonas(){
	
	Cola<Persona*> cola;
	
	for(int i = 1; i <= cantidadPersonas; i++){
		Persona *persona = &(listaPersonas.obtenerDato(i)->data);
		cola.push(persona);
	}
	
	return cola;
}

Cola<Vacuna*> ControladorData::getVacunas(){
	Cola<Vacuna*> cola;
	
	for(int i = 1; i <= cantidadVacunas; i++){
		Vacuna *vacuna = &(listaVacunas.obtenerDato(i)->data);
		cola.push(vacuna);
	}
	
	return cola;
}

Cola<Eps*> ControladorData::getEpss(){
	Cola<Eps*> cola;
	
	for(int i = 1; i <= cantidadEPS; i++){
		Eps *eps = &(listaEPS.obtenerDato(i)->data);
		cola.push(eps);
	}
	
	return cola;
}

Cola<Ips*> ControladorData::getIpss(){
	Cola<Ips*> cola;
	
	for(int i = 1; i <= cantidadIPS; i++){
		Ips *ips = &(listaIPS.obtenerDato(i)->data);
		cola.push(ips);
	}
	
	return cola;
}

Cola<string*> ControladorData::getCiudades(){
	Cola<string*> cola;
	
	for(int i = 1; i <= cantidadCiudades; i++){
		string *ciudad = &(listaCiudades.obtenerDato(i)->data);
		cola.push(ciudad);
	}
	
	return cola;
}

Cola<string*> ControladorData::getPaises(){
	Cola<string*> cola;
	
	for(int i = 1; i <= cantidadPaises; i++){
		string *pais = &(listaPaises.obtenerDato(i)->data);
		cola.push(pais);
	}
	
	return cola;
}

Cola<string*> ControladorData::getLaburos(){
	Cola<string*> cola;
	
	for(int i = 1; i <= cantidadLaburos; i++){
		string *laburo = &(listaLaburo.obtenerDato(i)->data);
		cola.push(laburo);
	}
	
	return cola;
}

Cola<Persona*> ControladorData::getVacunadosPorFecha(string fecha, bool praDosis){
	Cola<Persona*> colaPersonas;
	Fecha fechaVacuna = crearFecha(fecha);
	int size;
	if(praDosis) size = pacientesPorFechaPrimeraDosis.getTamArbol();
	else size = pacientesPorFechaSegundaDosis.getTamArbol();
	
	int idPersonas[size];
	
	if(praDosis){
		pacientesPorFechaPrimeraDosis.inordenArrayFechas(pacientesPorFechaPrimeraDosis.obtenerRaiz(), 0, idPersonas);
	}else{
		pacientesPorFechaSegundaDosis.inordenArrayFechas(pacientesPorFechaSegundaDosis.obtenerRaiz(), 0, idPersonas);
	}
	
	for(int i = 0; i < size; i++){
		Persona *persona = &(listaPersonas.obtenerDato(idPersonas[i])->data);
		Fecha fecha;
		if(praDosis) fecha = *persona->getF_primera_dosis();
		else fecha = *persona->getF_segunda_dosis();
		
		if(esMayorQue(fechaVacuna, fecha) == "igual") colaPersonas.push(persona);
	}
	return colaPersonas;
		
}

Cola<Persona*> ControladorData::getVacunados(){
	ArbolBinarioOrdenado *arbolPersonas;
	
	for(int i = 1 ; i <= 3; i++){
		ArbolBinarioOrdenado *pacientes = listaPacientesPorEstadoDeVacunacion.obtenerDato(i);
		if("vacunados" == pacientes->getEtiqueta()){
			arbolPersonas = pacientes;
		}
	}
	return deArbolACola(arbolPersonas);	
}

Cola<Persona*> ControladorData::getSemiVacunados(){
	ArbolBinarioOrdenado *arbolPersonas;
	
	for(int i = 1 ; i <= 3; i++){
		ArbolBinarioOrdenado *pacientes = listaPacientesPorEstadoDeVacunacion.obtenerDato(i);
		if("semi-vacunados" == pacientes->getEtiqueta()){
			arbolPersonas = pacientes;
		}
	}
	return deArbolACola(arbolPersonas);
}

Cola<Persona*> ControladorData::getNoVacunados(){
	ArbolBinarioOrdenado *arbolPersonas;
	
	for(int i = 1 ; i <= 3; i++){
		ArbolBinarioOrdenado *pacientes = listaPacientesPorEstadoDeVacunacion.obtenerDato(i);
		if("no-vacunados" == pacientes->getEtiqueta()){
			arbolPersonas = pacientes;
		}
	}
	return deArbolACola(arbolPersonas);
}

Cola<Persona*> ControladorData::getPersonasPorEps(string eps){
	
	ArbolBinarioOrdenado *arbolPersonas;
	for(int i = 1 ; i <= cantidadEPS; i++){
		ArbolBinarioOrdenado *pacientesEnEps = listaPacientesPorEps.obtenerDato(i);
		if(eps == pacientesEnEps->getEtiqueta()){
			arbolPersonas = pacientesEnEps;
		}
	}
	return deArbolACola(arbolPersonas);
	
}

Cola<Persona*> ControladorData::getPersonasPorRangoDeEdad(string rango){
	Cola<Persona*> colaPersonas;
	Lista<Persona*> *listaFinal;
	
	for(int i = 1 ; i < 8 ; i++){
		Lista<Persona*> *lista = listaPacientesPorRangosDeEdad.obtenerDato(i);
		if(rango == lista->getEtiqueta()){
			listaFinal = lista;
		}
	}
	
	int cantidadPersonasLocal = listaFinal->getSize();
	
	for(int i = 1; i <= cantidadPersonasLocal; i++){
		Persona *persona = *listaFinal->obtenerDato(i);
		colaPersonas.push(persona);
	}
	
	return colaPersonas;
}

Cola<Persona*> ControladorData::getPersonasPorTipoVacuna(string vacuna){
	ArbolBinarioOrdenado *arbolPersonas;
	
	for(int i = 1 ; i <= cantidadVacunas; i++){
		ArbolBinarioOrdenado *pacientes = listaPacientesPorVacuna.obtenerDato(i);
		if(vacuna == pacientes->getEtiqueta()){
			arbolPersonas = pacientes;
		}
	}

	
	return deArbolACola(arbolPersonas);
}

Cola<Persona*> ControladorData::getPersonasPorIps(string ips, bool asignada){
	ArbolBinarioOrdenado *arbolPersonas;
	
	for(int i = 1 ; i <= cantidadIPS; i++){
		ArbolBinarioOrdenado *pacientes; 
		if(asignada) pacientes = listaPacientesPorIpsAsignada.obtenerDato(i);
		else pacientes = listaPacientesPorIps.obtenerDato(i);
		
		if(ips == pacientes->getEtiqueta()){
			arbolPersonas = pacientes;
		}
	}
	
	return deArbolACola(arbolPersonas);
}


Cola<Persona*> ControladorData::getPersonasPorSexo(string sexo){
	ArbolBinarioOrdenado *arbolPersonas;
	
	for(int i = 1 ; i <= 2; i++){
		ArbolBinarioOrdenado *pacientes = listaPacientesPorSexo.obtenerDato(i);
		if(sexo == pacientes->getEtiqueta()){
			
			arbolPersonas = pacientes;
		}
	}
	return deArbolACola(arbolPersonas);
}

Cola<Persona*> ControladorData::getPersonasPorCiudadResidencia(string ciudad){
	ArbolBinarioOrdenado *arbolPersonas;
	
	for(int i = 1 ; i <= cantidadCiudades; i++){
		ArbolBinarioOrdenado *pacientes = listaPacientesPorCiudadResidencia.obtenerDato(i);
		
		if(ciudad == pacientes->getEtiqueta()){
			arbolPersonas = pacientes;
		}
	}
	
	
	
	return deArbolACola(arbolPersonas);	
}

Cola<Persona*> ControladorData::getPersonasPorPais(string pais){
	
	ArbolBinarioOrdenado *arbolPersonas;
	
	for(int i = 1 ; i <= cantidadPaises; i++){
		ArbolBinarioOrdenado *pacientes = listaPacientesPorPais.obtenerDato(i);
		
		
		if(pais == pacientes->getEtiqueta()){
			
			arbolPersonas = pacientes;
		}
	}
	
	return deArbolACola(arbolPersonas);	
}

Cola<Ips*> ControladorData::getIpsPorCiudad(string ciudad){
	Cola<Ips*> colaIps;
	Lista<Ips*> *listaIpss;

	for(int i = 1 ; i <= cantidadCiudades; i++){
		Lista<Ips*> *ipss = listaIpsPorCiudad.obtenerDato(i);

		if(ciudad == ipss->getEtiqueta()){
			listaIpss = ipss;
		}
	}

	for(int i = 1 ; i <= listaIpss->getSize(); i++) colaIps.push(*(listaIpss->obtenerDato(i)));

	return colaIps;
}

Cola<Ips*> ControladorData::getIpsPorEps(string eps){
	Cola<Ips*> colaIps;
	Lista<Ips*> *listaIpss;

	for(int i = 1 ; i <= cantidadEPS ; i++){
		Lista<Ips*> *ipss = listaIpsPorEps.obtenerDato(i);

		if(eps == ipss->getEtiqueta()){
			listaIpss = ipss;
		}
	}

	for(int i = 1 ; i <= listaIpss->getSize(); i++) colaIps.push(*(listaIpss->obtenerDato(i)));

	return colaIps;
}

Cola<Vacuna*> ControladorData::getVacunaPorEps(string eps){
	Cola<Vacuna*> colaVacunas;
	Lista<Eps_Vacuna*> *vacunasDisponibles;
	
	for(int i = 1; i <= cantidadEPS; i++){
		Lista<Eps_Vacuna*> *vacunas = listaVacunasPorEps.obtenerDato(i);
		
		if(vacunas->getEtiqueta() == eps){
			vacunasDisponibles = vacunas;
			break;
		}
	}
	
	for(int i = 1; i <= vacunasDisponibles->getSize(); i++){
		Eps_Vacuna *epsVacuna = *vacunasDisponibles->obtenerDato(i);
		colaVacunas.push(epsVacuna->getVacuna());
	} 
	
	return colaVacunas;
}

Cola<Ips_Vacuna*> ControladorData::getVacunasDisponibles(string ips){
	Cola<Ips_Vacuna*> colaVacunas;
	Lista<Ips_Vacuna*> *vacunasDisponibles;
	
	for(int i = 1; i <= cantidadEPS; i++){
		Lista<Ips_Vacuna*> *vacunas = listaVacunasPorIps.obtenerDato(i);
		
		if(vacunas->getEtiqueta() == ips){
			vacunasDisponibles = vacunas;
			break;
		}
	}
	
	for(int i = 1; i <= vacunasDisponibles->getSize(); i++){
		Ips_Vacuna *ipsVacuna = *vacunasDisponibles->obtenerDato(i);
		colaVacunas.push(ipsVacuna);
	} 
	
	return colaVacunas;
}
#endif
