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
#include "Pila.h"
#include "Cola.h"

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
		int cantidadCiudades;
		int cantidadPaises;
		
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
		Lista < ArbolBinarioOrdenado > listaPacientesPorCiudadResidencia;
		Lista < ArbolBinarioOrdenado > listaPacientesPorSexo;
		Lista < ArbolBinarioOrdenado > listaPacientesPorLaburo;
		Lista < ArbolBinarioOrdenado > listaPacientesPorVacuna;
		Lista < ArbolBinarioOrdenado > listaPacientesPorRangosDeEdad;
		
		Lista < Lista< Eps_Vacuna* > > listaVacunasPorEps;
		Lista < Lista< Ips_Vacuna* > > listaVacunasPorIps;
		Lista < Lista< Ips* > > listaIpsPorCiudad; 
		
		Lista < ArbolBinarioOrdenado > listaPacientesPorEstadoDeVacunacion;
		
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
		void organizarPacientesPorEps();//
		void organizarPacientesPorCiudadResidencia();//
		void organizarPacientesPorSexo();//
		void organizarPacientesPorLaburo();
		void organizarPacientesPorVacuna();//
		
		void organizarPacientesPorRangosDeEdad();
		void organizarVacunasPorEps();//
		void organizarVacunasPorIps();//
		void organizarIpsPorCiudad();//
		void organizarPacientesPorEstadoVacunacion();
		
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
		
		//-----------------------------Getters-----------------------------------//
		
		Cola<Persona*> getPersonas();
		Cola<Vacuna*> getVacunas();
		Cola<Eps*> getEpss();
		Cola<Ips*> getIpss();
		void getPersonasPorCiudad(string ciudad);
		Cola<Persona*> getPersonasPorEps(string eps);
		void getVacunadosPorFecha(string fecha);
		void getVacunados();
		void getSemiVacunados();
		void getNoVacunados();
		void getVacunasDisponibles(string ips);
		
		Persona *getPersona(int id);
		Eps *getEps(int id);
		Ips *getIps(int id);
		
		//------------------------Cantidades----------------------------//
		
		int getCantidadPorEps(string eps);
		int getCantidadPorSexo(string sexo);
		int getCantidadEstadoVacuna(string estado);
		int getCantidadPersonas() {return cantidadPersonas;}
		int getCantidadVacunas() {return cantidadVacunas;}
		int getCantidadEps() {return cantidadEPS;}
		int getCantidadIps() {return cantidadIPS;}
	
		
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
	
	cargarArchivosLocales();
	
	this->organizarPacientesPorEps();
	this->organizarPacientesPorSexo();
	this->organizarPacientesPorVacuna();
	this->organizarPacientesPorCiudadResidencia();
	this->organizarVacunasPorEps();
	this->organizarVacunasPorIps();
	
	//EJEMPLO RE UTIL PANA
	
//	int array[pacientesPorEdad.getTamArbol()];
//	pacientesPorEdad.inordenArray(pacientesPorEdad.obtenerRaiz(),0, array);
//	
//	for(int i = 0; i < pacientesPorEdad.getTamArbol(); i++) cout<<array[i]<<endl;
	
//	cout<<"----"<<endl;
//	cout<<"impresion arboles por EPS"<<endl;
//	for(int i = 1;i <= cantidadEPS; i++){
//		ArbolBinarioOrdenado *arbol = listaPacientesPorEps.obtenerDato(i);
//		cout<<arbol->getEtiqueta()<<endl;
//		arbol->inorden(arbol->obtenerRaiz());
//	}
//	
//	cout<<"impresion arboles por vacuna"<<endl;
//	for(int i = 1;i <= cantidadVacunas; i++){
//		ArbolBinarioOrdenado *arbol = listaPacientesPorVacuna.obtenerDato(i);
//		cout<<arbol->getEtiqueta()<<endl;
//		arbol->inorden(arbol->obtenerRaiz());
//	}
//	
//	cout<<"impresion arboles por SEXO GRATIS"<<endl;
//	for(int i = 1;i <= 2; i++){
//		ArbolBinarioOrdenado *arbol = listaPacientesPorSexo.obtenerDato(i);
//		cout<<arbol->getEtiqueta()<<endl;
//		arbol->inorden(arbol->obtenerRaiz());
//	}
//	
//	cout<<"impresion arboles por ciudad de nacimiento"<<endl;
//	for(int i = 1;i <= cantidadCiudades; i++){
//		ArbolBinarioOrdenado *arbol = listaPacientesPorCiudadResidencia.obtenerDato(i);
//		cout<<arbol->getEtiqueta()<<endl;
//		arbol->inorden(arbol->obtenerRaiz());
//	}
//	cout<<"----"<<endl;
	
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
//	cout<<"modelo "<<modelo<<" con "<<cantAtributos<<" atributos"<<endl;
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
						Casilla<string> *casilla = listaCiudades.obtenerDato(idPais);
						pPais = &(casilla->data);
					}
					if(idCiudadRes == 0) pCiudadRes = NULL;
					else{
						Casilla<string> *casilla = listaCiudades.obtenerDato(idCiudadRes);
						pCiudadRes = &(casilla->data);
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
					Eps *eps = &(listaEPS.obtenerDato(idEps)->data);
					
					Ips ips = Ips(atributos[1],atributos[2],atributos[3],eps);
					agregarIps(ips, id);
				}
				case 5:{
					int idEps = atoi(atributos[1].c_str());
					int idVacuna =  atoi(atributos[2].c_str()); 
					
					Eps *eps = &(listaEPS.obtenerDato(idEps)->data);
					Vacuna *vacuna = &(listaVacunas.obtenerDato(idVacuna)->data);
					
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
	
	Casilla< Vacuna > * vacunaDir = listaVacunas.obtenerDato(id);
	arbolRJVacunas.insertar(vacunaDir);

	cantidadVacunas++;
}

void ControladorData::agregarPersona(Persona persona, int id){
	Casilla<Persona> casilla;
	casilla.data = persona;
	casilla.id = id;
	
	pacientesPorEdad.insertarNodo(id, persona.getEdad());
	listaPersonas.intertar_final(casilla);

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

void ControladorData::organizarPacientesPorRangosDeEdad(){
	
//	pacientesPorEdad
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
			if(ips->getCiudad() == ciudadesDisponibles[j]){
				Lista<Ips*> *lista = listaIpsPorCiudad.obtenerDato(j+1);
				lista->intertar_final(ips);
				break;
			}
			
		} 
	}
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

Cola<Persona*> ControladorData::getPersonasPorEps(string eps){
	Cola<Persona*> personas;
	ArbolBinarioOrdenado *arbolPersonas;
	for(int i = 1 ; i <= cantidadEPS; i++){
		ArbolBinarioOrdenado *pacientesEnEps = listaPacientesPorEps.obtenerDato(i);
		if(eps == pacientesEnEps->getEtiqueta()){
			arbolPersonas = pacientesEnEps;
		}
	}
	int cantidadPersonas = arbolPersonas->getTamArbol();
	
	int idPersonasOrdenadas[cantidadPersonas];
	pacientesPorEdad.inordenArray(cantidadPersonas,0, idPersonasOrdenadas);
	
	for(int i = 0; i < cantidadPersonas; i++){
		int idBusqueda = idPersonasOrdenadas[i];
		Casilla *casilla = arbolRJPersonas.buscarNodo();
		Persona *persona = arbolRJPersonas.buscarNodo();
	}
	
	return personas;
	
}



#endif
