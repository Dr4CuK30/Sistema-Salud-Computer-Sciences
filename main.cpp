#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>

#include "cola_prioridad.h"
#include "controladorData.h"
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"
#include "Vacuna.h"               
#include "Casilla.h"
#include "Fecha.h"
#include "Persona.h"   
#include "ArbolBiOrdFechas.h"
     
      
using namespace std;
void empezarPrograma();
void consultarPacientesPor();
void consultarEstadisticas();
void impresionPersonaBasico(Cola<Persona*>);

ControladorData data;
string rangosDeEdad[] = {"-20","20-29","30-39","40-49","50-59","60-69","70-79","+80"};

int main(int argc, char *argv[]) {          
	
	// Fechas de Prueba
	
//	ArbolBiOrdFechas arbF;
//	Fecha fecha1;
//	Fecha fecha2;
//	Fecha fecha3;
//
//	fecha1.anho = 2001;
//	fecha1.mes = 8;
//	fecha1.dia = 5;
//
//	fecha2.anho = 2001;
//	fecha2.mes = 10;
//	fecha2.dia = 10;
//
//	fecha3.anho = 2000;
//	fecha3.mes = 8;
//	fecha3.dia = 31;
//
//	arbF.insertarNodo(1, fecha1);
//	arbF.insertarNodo(2, fecha2);
//	arbF.insertarNodo(3, fecha3);
//
//	arbF.inorden(arbF.obtenerRaiz());
	
	empezarPrograma();
	
	    
    system("PAUSE");       
    return EXIT_SUCCESS;
}                   

void empezarPrograma(){
	//cargar archivos    
	
	int opcion;
	  
	while(opcion != 9){  
		cout<<"------------------------------------------------------------------------------------------------"<<endl;
		cout<<"-------------------------------BIENVENIDO A SALDAVACUNA APP-------------------------------------"<<endl;
		cout<<"------------------------------------------------------------------------------------------------"<<endl;
		
		cout<<"1. Simular proceso de vacunacion completo"<<endl; 
		cout<<"2. Ingresar nuevo registro"<<endl;
		cout<<"3. Consultar pacientes por..."<<endl;
		cout<<"4. Ver todos los pacientes"<<endl;
		cout<<"5. Ver todos las vacunas registradas"<<endl;
		cout<<"6. Ver todas las EPSs"<<endl;
		cout<<"7. Ver todas las IPSs"<<endl;
		cout<<"8. Consultas estadisticas"<<endl;
		cout<<"9. SALIR"<<endl<<endl;  
		        
		cout<<"Opcion: ";
		cin>>opcion;      
		cout<<" "<<endl<<endl<<endl<<endl;
		   
		switch(opcion){
			case 1:
				break;
			case 2: 
				break;
			case 3:
				consultarPacientesPor();
				break;
			case 4:{
				//Todos los pacientes
				Cola<Persona*> personas = data.getPersonas();
				int cantidad = data.getCantidadPersonas();
				
				impresionPersonaBasico(personas);
				
				cout<<endl<<endl<<endl;
				break;
			}	
			case 5: {
				//Todas las vacunas             
				Cola<Vacuna*> vacunas = data.getVacunas();
				int cantidad = data.getCantidadVacunas();
				
				cout<<"---------------------------Vacunas disponibles------------------------------"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				cout<<"id |   Nombre vacuna      | Cantidad de dosis  |"<<endl;
				cout<<"---|----------------------|--------------------|"<<endl;
				for(int i = 1; i <= cantidad; i++){
					Vacuna *vacuna = vacunas.pop();
					cout<<vacuna->getNombre()<<endl;   
					cout<<i<<"  | ";
					cout<<setw(20)  <<vacuna->getNombre()<<" | ";
					cout<<setw(18)<<vacuna->getCantidadDosis()<<" | ";
					cout<<endl;
				}
				
				cout<<endl<<endl<<endl;
				break;
			}   
			case 6:{
				//Todas las eps
				Cola<Eps*> epss = data.getEpss();
				int cantidad = data.getCantidadEps();
				
				cout<<"---------------------------EPS registradas------------------------------"<<endl;
				cout<<"------------------------------------------------------------------------------"<<endl;
				cout<<"id |   Nombre             |"<<endl;
				cout<<"---|----------------------|"<<endl;
				for(int i = 1; i <= cantidad; i++){
					Eps *eps = epss.pop();
					cout<<i<<"  | ";
					cout<<setw(20)  <<eps->getNombre()<<" | ";
					cout<<endl;
				}
				
				cout<<endl<<endl<<endl;
				break;
			}
			case 7:  {
				//Todas las IPS
				Cola <Ips*> ipss = data.getIpss();  
				int cantidad = data.getCantidadIps();
				
				cout<<"---------------------------Pacientes registrados------------------------------"<<endl;
				cout<<"------------------------------------------------------------------------------"<<endl;
				cout<<"id |        Nombre             |          Direccion             |      Ciudad     |  EPS            |"<<endl;
				cout<<"---|---------------------------|--------------------------------|-----------------|-----------------|"<<endl;
				for(int i = 1; i <= cantidad; i++){
					Ips *ips = ipss.pop();
					cout<<i<<"  | ";
					cout<<setw(25)  <<ips->getNombre()<<" | ";
					cout<<setw(30)	<<ips->getDireccion()<<" | ";
					cout<<setw(15)	<<*(ips->getCiudad())<<" | ";
					cout<<setw(15)	<<ips->getEpsName()<<" | ";
					cout<<endl;
				}
				
				cout<<endl<<endl<<endl;
				break;
			}
			case 8:
				consultarEstadisticas();
				break;
			case 9:
				cout<<"Hasta pronto..."<<endl; 
				break;
			default:	
				cout<<"Opcion no valida"<<endl<<endl;
				break;
		}            
		
		
	}	
	
	//guardar archivos                  
}           
    
void consultarPacientesPor(){ 
	int opcion;             
	     
	while(opcion != 10){    
		cout<<"---------------------------------"<<endl;
		cout<<"Puede consultar los pacientes por: "<<endl;
    	cout<<"1. Edad"<<endl;
		cout<<"2. Vacunados con un tipo de vacuna"<<endl;
		cout<<"3. Fecha de vacunacion"<<endl;
		cout<<"4. EPS"<<endl;
		cout<<"5. IPS"<<endl;
		cout<<"6. IPS asignada para vacunacion"<<endl;
		cout<<"7. Ciudad de residencia"<<endl;
		cout<<"8. Sexo"<<endl;
		cout<<"----"<<endl;
		cout<<"9. Consultas dobles"<<endl;
		cout<<"10. Volver al menu principal"<<endl<<endl;
		        
		cout<<"Opcion: ";
		cin>>opcion;     
		cout<<"---------------------------------"<<endl<<endl;
		  
		switch(opcion){
			case 1:{
				
				
				int opcion;
				cout<<"Seleccione el rango de edad: "<<endl;
				
				for(int i = 0; i < 8; i++){
					cout<<i+1<<". "<<rangosDeEdad[i]<<endl;
				}
				
				cout<<"Opcion: ";
				cin>>opcion;   
				
				Cola<Persona*> personas = data.getPersonasPorRangoDeEdad(rangosDeEdad[opcion-1]);
				
				impresionPersonaBasico(personas);
				         
				break;
			}
			case 2:{
				Cola<Vacuna*> colaVacuna = data.getVacunas();
				Vacuna *vacunas[data.getCantidadVacunas()];
				
				int opcion;
				cout<<"Seleccione la Vacuna: "<<endl;
				
				for(int i = 0; i < data.getCantidadVacunas(); i++){
					vacunas[i] = colaVacuna.pop();
					
					cout<<i+1<<". "<<vacunas[i]->getNombre()<<endl;
				}
				
				cout<<"Opcion: ";
				cin>>opcion;   
				
				Cola<Persona*> personas = data.getPersonasPorTipoVacuna(vacunas[opcion-1]->getNombre());
				
				impresionPersonaBasico(personas);
				         
				break;
			}
			case 3:
				break;
			case 4:{
				Cola<Eps*> colaEps = data.getEpss();
				Eps *epss[data.getCantidadEps()];
				
				int opcion;
				cout<<"Seleccione la EPS: "<<endl;
				
				for(int i = 0; i < data.getCantidadEps(); i++){
					epss[i] = colaEps.pop();
					
					cout<<i+1<<". "<<epss[i]->getNombre()<<endl;
				}
				
				cout<<"Opcion: ";
				cin>>opcion;   
				
				Cola<Persona*> personas = data.getPersonasPorEps(epss[opcion-1]->getNombre());
				
				impresionPersonaBasico(personas);
				         
				break;
			}
			case 5:{
				Cola<Ips*> colaIps = data.getIpss();
				Ips *ipss[data.getCantidadIps()];
				
				int opcion;
				cout<<"Seleccione la IPS: "<<endl;
				
				for(int i = 0; i < data.getCantidadEps(); i++){
					ipss[i] = colaIps.pop();
					
					cout<<i+1<<". "<<ipss[i]->getNombre()<<endl;
				}
				
				cout<<"Opcion: ";
				cin>>opcion;   
				
				Cola<Persona*> personas = data.getPersonasPorIps(ipss[opcion-1]->getNombre(), false);
				
				impresionPersonaBasico(personas);
				                    
				break;
			}
			case 6:{
				Cola<Ips*> colaIps = data.getIpss();
				Ips *ipss[data.getCantidadIps()];
				
				int opcion;
				cout<<"Seleccione la IPS: "<<endl;
				
				for(int i = 0; i < data.getCantidadEps(); i++){
					ipss[i] = colaIps.pop();
					
					cout<<i+1<<". "<<ipss[i]->getNombre()<<endl;
				}
				
				cout<<"Opcion: ";
				cin>>opcion;   
				
				Cola<Persona*> personas = data.getPersonasPorIps(ipss[opcion-1]->getNombre(), true);
				
				impresionPersonaBasico(personas);
				         
				break;
			}
			case 7:{
				Cola<string*> colaCiudades = data.getCiudades();
				string *ciudades[data.getCantidadCiudades()];
				
				int opcion;
				cout<<"Seleccione la ciudad: "<<endl;
				
				for(int i = 0; i < data.getCantidadEps(); i++){
					ciudades[i] = colaCiudades.pop();
					
					cout<<i+1<<". "<<*ciudades[i]<<endl;
				}
				
				cout<<"Opcion: ";
				cin>>opcion;   
				
				Cola<Persona*> personas = data.getPersonasPorCiudadResidencia(*ciudades[opcion-1]);
				
				impresionPersonaBasico(personas);
				         
				break;
			}
			case 8:{
				int opcion;
				cout<<"Seleccione el sexo: "<<endl;
				
				cout<<1<<". Masculino"<<endl;
				cout<<2<<". Femenino"<<endl;
				
				cout<<"Opcion: ";
				cin>>opcion; 
				
				Cola<Persona*> personas;
				if(opcion == 1) personas = data.getPersonasPorSexo("Hombres");
				else personas = data.getPersonasPorSexo("Mujeres");
				
				impresionPersonaBasico(personas);
				break;
			}        
			default:	
				cout<<"Opcion no valida"<<endl<<endl;
				break;           
		}
		cout<<endl<<endl;
	}
	
  
}
void consultasDobles(){
	int opcion = 0;
	while(opcion != 11){
		cout<<"---------------------------------"<<endl;
		cout<<"Puede consultar los pacientes por: "<<endl;
	   	cout<<"1. Rango de edad y actividad laboral"<<endl;
		cout<<"2. Rango de edad y EPS"<<endl;
		cout<<"3. EPS y tipo de vacuna"<<endl;
		cout<<"----"<<endl;
		cout<<"10. Volver al menu anterior"<<endl;
		cout<<"11. Volver al menu principal"<<endl<<endl;
			        
		cout<<"Opcion: ";
		cin>>opcion;     
		cout<<"---------------------------------"<<endl<<endl;
		  
		Cola<Eps*> colaEps = data.getEpss();
		Eps *epss[data.getCantidadEps()];
		for(int i = 0; i < data.getCantidadEps(); i++) epss[i] = colaEps.pop();  
		
		Cola<Ips*> colaIps = data.getIpss();
		Ips *ipss[data.getCantidadIps()];
		for(int i = 0; i < data.getCantidadIps(); i++) ipss[i] = colaIps.pop();
			 
		Cola<string*> colaLaburos = data.getLaburos();
		string *laburos[data.getCantidadLaburos()];
		for(int i = 0; i < data.getCantidadLaburos(); i++)laburos[i] = colaLaburos.pop(); 
		
		Cola<string*> colaCiudades = data.getCiudades();
		string *ciudades[data.getCantidadCiudades()];
		for(int i = 0; i < data.getCantidadCiudades(); i++) ciudades[i] = colaCiudades.pop();
		
		Cola<Vacuna*> colaVacunas = data.getVacunas();
		Vacuna *vacunas[data.getCantidadVacunas()];
		for(int i = 0; i < data.getCantidadVacunas(); i++) vacunas[i] = colaVacunas.pop(); 
			
		switch(opcion){
			case 1:{
				//lista final con filtro
				string laburo = escogerActividadLaboral();
				string rango = escogerRangoDeEdad();
				
				Cola<Persona*> personas = data.getPersonasPorRangoDeEdad(rango);
				int size = personas.getSize();
				
				Cola<Persona*> personasFiltroLaburo;
				for(int i = 0 ; i < size; i++){
					Persona *persona = personas.pop();
					if(*(persona->getAct_laboral()) == laburo){
						personasFiltroLaburo.push(persona);
					}
				}
				
				size = personasFiltroLaburo.getSize();
				
				//clasificacion
				
				Cola<Persona*> personasPorCiudad[data.getCantidadCiudades()];
				
				for(int i = 0 ; i < size; i++) {
					Persona *persona = personasFiltroLaburo.pop();
					
					for(int j = 0; j < data.getCantidadCiudades(); j++){
						if(*(persona->getCiudad_resid()) == *ciudades[j]){
							personasPorCiudad[j].push(persona);
						}
					}
				}
				
				//impresion
				
				cout<<"-------------"<<laburo<<" ---- rango de edad"<<rango<<"-----------------------"<<endl;
				
				for(int i = 0;    i < data.getCantidadCiudades(); i++){
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					cout<<"| "<<*ciudades[i]<<endl;
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					cout<<"| "; for(int j = 0; j < data.getCantidadEps(); j++) cout<<setw(25)<<epss[j]->getNombre()<<" | ";
					cout<<endl;
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					
					while(personasPorCiudad[i].getSize() > 0){
						cout<<"| ";
						Persona *persona = personasPorCiudad[i].pop();
						for(int j = 0; j < data.getCantidadEps(); j++){
							string dato;	
							if(persona->getEpsName() == epss[j]->getNombre()){
								dato = persona->getNombres() + " " + persona->getApellidos();
									
							}else{
								dato = "";
							}
							
							cout<<setw(25)<<dato<<" | ";
							
						}	
						cout<<endl; 
					}
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					
				}
				
				
				
				break;
			}
			case 2:{
				//lista final con filtro
				string rango = escogerRangoDeEdad();
				string eps = escogerEps();
				
				Cola<Persona*> personas = data.getPersonasPorRangoDeEdad(rango);
				int size = personas.getSize();
				
				Cola<Persona*> personasFiltroEps;
				for(int i = 0 ; i < size; i++){
					Persona *persona = personas.pop();
					if(persona->getEpsName() == eps){
						personasFiltroEps.push(persona);
					}
				}
				
				//clasificacion
				size = personasFiltroEps.getSize();
				
				Cola<Persona*> personasPorCiudad[data.getCantidadCiudades()];
				//filtrado por ciudad
				for(int i = 0 ; i < size; i++) {
					Persona *persona = personasFiltroEps.pop();
					
					for(int j = 0; j < data.getCantidadCiudades(); j++){
						if(*(persona->getCiudad_resid()) == *ciudades[j]){
							personasPorCiudad[j].push(persona);
						} 
					}
				}
				
				Cola<Ips*> colaIpsDisponibles = data.getIpsPorEps(eps);
				int sizeIpsDisponibles = colaIpsDisponibles.getSize();
				Ips *ipsDisponibles[sizeIpsDisponibles];
				for(int i = 0; i < sizeIpsDisponibles; i++) ipsDisponibles[i] = colaIpsDisponibles.pop();
				      
				//impresion
				cout<<"-------------"<<eps<<" ---- rango de edad"<<rango<<"-----------------------"<<endl;
				
				for(int i = 0;    i < data.getCantidadCiudades(); i++){
					string ciudad = *ciudades[i];
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					cout<<"| "<<ciudad<<endl;
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					cout<<"| "; for(int j = 0; j < sizeIpsDisponibles; j++){
						if(*(ipsDisponibles[0]->getCiudad()) == ciudad){
							cout<<setw(25)<<ipsDisponibles[j]->getNombre()<<" | ";
						}
					} 
					cout<<endl;
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					
					while(personasPorCiudad[i].getSize() > 0){
						cout<<"| ";
						Persona *persona = personasPorCiudad[i].pop();
						
						for(int j = 0; j < sizeIpsDisponibles; j++){
							string dato;
							if(*(ipsDisponibles[0]->getCiudad()) == ciudad){
								if(persona->getIpsAsignadaName() == ipsDisponibles[j]->getNombre()){
									dato = persona->getNombres() + " " + persona->getApellidos();	
								}else{
									dato = "";
								}
							}	
							
							cout<<setw(25)<<dato<<" | ";
							
						}	
						cout<<endl; 
					}
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
				
				}
				break;
			}
			case 3:{
				string eps = escogerEps();
				string vacuna = escogerVacuna();
				break;
			}
			default:
				break;
		}
	}
	
}

void consultarEstadisticas(){
	int opcion; 
	
	while(opcion != 10){    
		cout<<"---------------------------------"<<endl;
		cout<<"Puede consultar las siguientes estadisticas: "<<endl;
    	cout<<"1. Total de personas por EPS"<<endl;
		cout<<"10. Volver al menu principal"<<endl<<endl;
		        
		cout<<"Opcion: ";
		cin>>opcion;     
		cout<<"---------------------------------"<<endl<<endl;
		
		switch(opcion){
			case 1:{
				Cola<Eps*> colaEps = data.getEpss();
				Eps *epss[data.getCantidadEps()];
				
				int opcion;
				cout<<"Seleccione la EPS: "<<endl;
				
				for(int i = 0; i < data.getCantidadEps(); i++){
					epss[i] = colaEps.pop();
					
					cout<<i+1<<". "<<epss[i]->getNombre()<<endl;
				}
				
				cout<<"Opcion: ";
				cin>>opcion;   
				
				Cola<Persona*> personas = data.getPersonasPorEps(epss[opcion-1]->getNombre());
				int cantidadTotal = personas.getSize();
				
				int cantidadPorEps[] = {0,0,0,0,0,0,0,0};
				
				for(int i = 1; i <= cantidadTotal; i++){
					Persona *persona = personas.pop();
					
					if(persona->getEdad() < 20) cantidadPorEps[0]++;
					else if(persona->getEdad() >= 20 && persona->getEdad() <= 29) cantidadPorEps[1]++;
					else if(persona->getEdad() >= 30 && persona->getEdad() <= 39) cantidadPorEps[2]++;
					else if(persona->getEdad() >= 40 && persona->getEdad() <= 49) cantidadPorEps[3]++;
					else if(persona->getEdad() >= 50 && persona->getEdad() <= 59) cantidadPorEps[4]++;
					else if(persona->getEdad() >= 60 && persona->getEdad() <= 69) cantidadPorEps[5]++;
					else if(persona->getEdad() >= 70 && persona->getEdad() <= 79) cantidadPorEps[6]++;
					else if(persona->getEdad() >= 80) cantidadPorEps[7]++;
				}
				         
				cout<<"|---------------------------------------------------------------|"<<endl;
				cout<<"|EPS   "<<setw(15)<<left<<epss[opcion-1]->getNombre()<<endl;
				cout<<"|---------------------------------------------------------------|"<<endl;
				cout<<"|Cantidad total: "<<cantidadTotal<<endl;
				cout<<"|---------------------------------------------------------------|"<<endl;
				cout<<"|---------------------------------------------------------------|"<<endl;
				cout<<"|---------------------------------------------------------------|"<<endl;
				cout<<"| ";for(int i = 0; i < 8; i++)cout<<setw(5)<<rangosDeEdad[i]<<" | ";
				cout<<endl;
				cout<<"|---------------------------------------------------------------|"<<endl;
				cout<<"| ";for(int i = 0; i < 8; i++)cout<<setw(5)<<cantidadPorEps[i]<<" | ";
				cout<<endl;
				cout<<"|---------------------------------------------------------------|"<<endl;
				break;
			}
			default:
				break;
		}
	}
}


void impresionPersonaBasico(Cola<Persona*> personas){
	int cantidad = personas.getSize();
				
	cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"id |   Nombre completo            |   Edad   | EPS             |   IPS                          | IPS asignada para vacuna       |"<<endl;
	cout<<"---|------------------------------|----------|-----------------|--------------------------------|--------------------------------|"<<endl;
	for(int i = 1; i <= cantidad; i++){
		Persona *persona = personas.pop();
		cout<<i<<"  | ";
		cout<<setw(20)  <<persona->getNombres()<<" "<<persona->getApellidos()<<" | ";
		cout<<persona->getEdad()<<" anhos | ";
		cout<<setw(15)<<persona->getEpsName()<<" | ";
		cout<<setw(30)<<persona->getIpsDefaultName()<<" | ";
		cout<<setw(30)<<persona->getIpsAsignadaName()<<" | ";
		cout<<endl;
	}
				
	cout<<endl;	
}
