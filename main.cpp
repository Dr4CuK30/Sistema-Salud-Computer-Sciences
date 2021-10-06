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
void consultasDobles();
void consultarEstadisticas();


// Menu Hurtado /Inserciones:
// Principal:
void crearRegistrosMenu();
//Persona:
void registrarPersonaMenu();

string escogerRangoDeEdad();
string escogerEps();
string escogerVacuna();
string escogerActividadLaboral();
void impresionPersonaBasico(Cola<Persona*>);


ControladorData data;
string rangosDeEdad[] = {"-20","20-29","30-39","40-49","50-59","60-69","70-79","+80"};

int main(int argc, char *argv[]) {          
	
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
				crearRegistrosMenu();
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
	               
	while(opcion != 11){    
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
		cout<<"9. Pais de nacimiento"<<endl;
		cout<<"----"<<endl;
		cout<<"10. Consultas dobles"<<endl;
		cout<<"11. Volver al menu principal"<<endl<<endl;
		        
		cout<<"Opcion: ";
		cin>>opcion;     
		cout<<"---------------------------------"<<endl<<endl;
		  
		switch(opcion){
			case 1:{
			
				string rango = escogerRangoDeEdad(); 
				Cola<Persona*> personas = data.getPersonasPorRangoDeEdad(rango);
				impresionPersonaBasico(personas);       
				break;
			}
			case 2:{
				string vacuna = escogerVacuna(); 
				Cola<Persona*> personas = data.getPersonasPorTipoVacuna(vacuna);
				impresionPersonaBasico(personas);
				         
				break;
			}
			case 3:{
				cout<<"-----------------------------"<<endl;
				cout<<"Ingrese la fecha: "<<endl;
				string fecha;
				cin>>fecha;
				cout<<endl;
				//preguntar por dosis
				Cola<Persona*> personas = data.getVacunadosPorFecha(fecha, true);
				cout<<"obtiene bien "<<endl;
				cout<<personas.getSize()<<endl;  
				
				impresionPersonaBasico(personas);
				
				
				break;
			}			
			case 4:{
				string eps = escogerEps(); 
				Cola<Persona*> personas = data.getPersonasPorEps(eps);
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
				//Seleccion de ciudad
				Cola<string*> colaCiudades = data.getCiudades();
				string *ciudades[data.getCantidadCiudades()];
				
				int opcion;
				cout<<"Seleccione la ciudad: "<<endl;
				
				for(int i = 0; i < data.getCantidadCiudades(); i++){
					ciudades[i] = colaCiudades.pop();
					
					cout<<i+1<<". "<<*ciudades[i]<<endl;
				}
				
				cout<<"Opcion: ";
				cin>>opcion;   
				
				string ciudadSeleccionada = *ciudades[opcion-1];
				
				Cola<Persona*> personas = data.getPersonasPorCiudadResidencia(*ciudades[opcion-1]);
				//otrs datos
				
				Cola<Eps*> colaEps = data.getEpss();
				Eps *epss[data.getCantidadEps()];

				for(int i = 0; i < data.getCantidadEps(); i++) epss[i] = colaEps.pop();
				
				Cola<string*> colaLaburos = data.getLaburos();
				string *laburos[data.getCantidadLaburos()];
				Cola<Persona*> personasPorLaburo[data.getCantidadLaburos()];
				
				for(int i = 0; i < data.getCantidadLaburos(); i++){
					laburos[i] = colaLaburos.pop();
					
					Cola<Persona*> cola;
					
					personasPorLaburo[i] = cola;
				} 
				int size = personas.getSize();
				for(int j = 0; j <  size; j++){
					Persona *persona = personas.pop();
					 
					for(int i = 0; i < data.getCantidadLaburos(); i++){
						if(*(persona->getAct_laboral()) == *laburos[i]){
							personasPorLaburo[i].push(persona);
						}
					}
				}
			
				
				//impresion
				cout<<"------------------"<<ciudadSeleccionada<<"-----------------------"<<endl;
				
				for(int i = 0;    i < data.getCantidadLaburos(); i++){
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					cout<<"| "<<*laburos[i]<<endl;
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					cout<<"| "; for(int j = 0; j < data.getCantidadEps(); j++) cout<<setw(25)<<epss[j]->getNombre()<<" | ";
					cout<<endl;
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					
					while(personasPorLaburo[i].getSize() > 0){
						cout<<"| ";
						Persona *persona = personasPorLaburo[i].pop();
						
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
			case 9:{
				//lectura pais
				Cola<string*> colaPaises = data.getPaises();
				string *paises[data.getCantidadPaises()];
				
				int opcion;
				cout<<"Seleccione el pais: "<<endl;
				
				for(int i = 0; i < data.getCantidadPaises(); i++){
					paises[i] = colaPaises.pop();
					
					cout<<i+1<<". "<<*paises[i]<<endl;
				}
				
				cout<<"Opcion: ";
				cin>>opcion;   
				
				string paisSeleccionado = *paises[opcion-1];
				
				//estructuracion
				Cola<string*> colaCiudades = data.getCiudades();
				string *ciudades[data.getCantidadCiudades()];
				Cola<Persona*> arregloPersonasPorCiudad[data.getCantidadCiudades()];
				
				Cola<Eps*> colaEps = data.getEpss();
				Eps *epss[data.getCantidadEps()];
				
				
				for(int i = 0; i < data.getCantidadEps(); i++) epss[i] = colaEps.pop();
				
				
				for(int i = 0; i < data.getCantidadCiudades(); i++){
					ciudades[i] = colaCiudades.pop();
					
					Cola<Persona*> personas = data.getPersonasPorCiudadResidencia(*ciudades[i]);
					arregloPersonasPorCiudad[i] = personas;
				}
				
				//impresion y verificacion por pais
				cout<<"------------------"<<paisSeleccionado<<"-----------------------"<<endl;
				
				for(int i = 0;    i < data.getCantidadCiudades(); i++){
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					cout<<"| "<<*ciudades[i]<<endl;
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					cout<<"| "; for(int j = 0; j < data.getCantidadEps(); j++) cout<<setw(25)<<epss[j]->getNombre()<<" | ";
					cout<<endl;
					cout<<"|-----------------------------------------------------------------------------------|"<<endl;
					
					while(arregloPersonasPorCiudad[i].getSize() > 0){
						cout<<"| ";
						Persona *persona = arregloPersonasPorCiudad[i].pop();
						for(int j = 0; j < data.getCantidadEps(); j++){
							
							string dato;
							if(*(persona->getPais_nac()) == paisSeleccionado){
								
								if(persona->getEpsName() == epss[j]->getNombre()){
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
			case 10:{
				consultasDobles();
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
	while(opcion != 4){
		cout<<"---------------------------------"<<endl;
		cout<<"Puede consultar los pacientes por: "<<endl;
	   	cout<<"1. Rango de edad y actividad laboral"<<endl;
		cout<<"2. Rango de edad y EPS"<<endl;
		cout<<"3. EPS y tipo de vacuna"<<endl;
		cout<<"----"<<endl;
		cout<<"4. Volver al menu anterior"<<endl;
			        
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
				
				Cola<Persona*> personas = data.getPersonasPorTipoVacuna(vacuna);
				int size = personas.getSize();
				
				Cola<Persona*> personasFiltroEps;
				for(int i = 0; i < size; i++){
					Persona *persona = personas.pop();
					if(persona->getEpsName() == eps){
						personasFiltroEps.push(persona);
					}
				}
				
				size = personasFiltroEps.getSize();
				//clasificacion
				
				
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
				cout<<"-------------"<<eps<<" ---- vacuna"<<vacuna<<"-----------------------"<<endl;
				
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
			default:
				break;
		}
	}
	
}

void consultarEstadisticas(){
	int opcion; 
	
	while(opcion != 5){    
		cout<<"---------------------------------"<<endl;
		cout<<"Puede consultar las siguientes estadisticas: "<<endl;
    	cout<<"1. Total de personas por EPS"<<endl;
    	cout<<"2. Hombres y mujeres vacunados por eps"<<endl;
    	cout<<"3. EPSs con una cantidad minima de afiliados"<<endl;
    	cout<<"4. Vacunados en una fecha"<<endl;
		cout<<"5. Volver al menu principal"<<endl<<endl;
		        
		cout<<"Opcion: ";
		cin>>opcion;     
		cout<<"---------------------------------"<<endl<<endl;
		
		Cola<Eps*> colaEps = data.getEpss();
		Eps *epss[data.getCantidadEps()];
		for(int i = 0; i < data.getCantidadEps(); i++) epss[i] = colaEps.pop();
		
		Cola<Vacuna*> colaVacunas = data.getVacunas();
		Vacuna *vacunas[data.getCantidadVacunas()];
		for(int i = 0; i < data.getCantidadVacunas(); i++) vacunas[i] = colaVacunas.pop(); 
		
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
			case 2:{
				Cola<Persona*> hombres = data.getPersonasPorSexo("Hombres");
				Cola<Persona*> mujeres = data.getPersonasPorSexo("Mujeres");
				
				int sizeHombres = hombres.getSize();
				int sizeMujeres = mujeres.getSize();
				
				Cola<Persona*> mujeresVacunadasEps[data.getCantidadEps()];
				Cola<Persona*> hombresVacunadosEps[data.getCantidadEps()];
				
				for(int i = 0; i < sizeHombres+sizeMujeres; i++){
					Persona *persona;
					
					cout<<hombres.getSize()<<endl;
					if(hombres.getSize() != 0) persona = hombres.pop();
					else persona = mujeres.pop();
					
					
					if(persona->estadoVacuna() == 1 || persona->estadoVacuna() == 2){
						for(int i = 0; i < data.getCantidadEps(); i++){
							if(persona->getEpsName() == epss[i]->getNombre()){
								if(persona->getGenero() == "masculino"){
									hombresVacunadosEps[i].push(persona);
								}else{
									mujeresVacunadasEps[i].push(persona);
								}
								
							}
						}
					}
				}
				cout<<"el error es en la impresion"<<endl;
				//impresion
				cout<<"|-----------------------------------------------------|"<<endl;
				for(int i = 0; i < data.getCantidadEps(); i++){
					cout<<"|-------------------|"<<endl;
					cout<<"|- "<<epss[i]->getNombre()<<endl;
					cout<<"|-------------------|"<<endl;
					cout<<"| Hombres | Mujeres |"<<endl;
					cout<<"|-------------------|"<<endl;
					cout<<"| "<<setw(5)<<hombresVacunadosEps[i].getSize()<<" | "<<setw(5)<<mujeresVacunadasEps[i].getSize()<<" |"<<endl;
					cout<<"|-------------------|"<<endl<<endl;
				}
				
				
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				cout<<"-----------------------------"<<endl;
				cout<<"Ingrese la fecha: "<<endl;
				string fecha;
				cin>>fecha;
				cout<<endl;
				
				Cola<Persona*> personasPrimeraDosis = data.getVacunadosPorFecha(fecha, true);
				Cola<Persona*> personasSegundaDosis = data.getVacunadosPorFecha(fecha, false);
				int size = personasPrimeraDosis.getSize() + personasSegundaDosis.getSize();
				
				cout<<"las obtiene bien"<<endl;
				
				int vacunadosPorEps[data.getCantidadEps()];
				for(int i = 0; i < data.getCantidadEps(); i++) vacunadosPorEps[i] = 0;
				
				for(int j = 0; j < size;j++){
					cout<<"recorre personas"<<endl;
					Persona *persona;
					if(personasPrimeraDosis.getSize() != 0) persona = personasPrimeraDosis.pop();
					else persona = personasSegundaDosis.pop();
					
					for(int i = 0; i < data.getCantidadEps(); i++){
						if(epss[i]->getNombre() == persona->getEpsName()){
							vacunadosPorEps[i]++;
						}
					} 
				}
				
				//impresion
				cout<<"|-------------------------------------------------------------------------------|"<<endl;
				cout<<"|------Fecha: "<<fecha<<endl;
				cout<<"|-------------------------------------------------------------------------------|"<<endl;
				cout<<"| "; for(int i = 0; i < data.getCantidadEps(); i++) cout<<setw(20)<<epss[i]->getNombre()<<" | ";
				cout<<endl<<"| "; for(int i = 0; i < data.getCantidadEps(); i++) cout<<setw(20)<<vacunadosPorEps[i]<<" | ";
				cout<<endl;
			
				
				break;
			}
			default:
				break;
		}
	}
}

string escogerRangoDeEdad(){
	int opcion;
	cout<<"Seleccione el rango de edad: "<<endl;
				
	for(int i = 0; i < 8; i++){
		cout<<i+1<<". "<<rangosDeEdad[i]<<endl;
	}
				
	cout<<"Opcion: ";
	cin>>opcion; 
	
	return rangosDeEdad[opcion-1];
}

string escogerVacuna(){
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
	
	return vacunas[opcion-1]->getNombre();
}

string escogerEps(){
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
	
	return epss[opcion-1]->getNombre();
}

string escogerCiudad(){
	Cola<string*> colaCiudad = data.getCiudades();
	string *ciudad[data.getCantidadCiudades()];
				
	int opcion;
	cout<<"Seleccione la ciudad: "<<endl;
				
	for(int i = 0; i < data.getCantidadCiudades(); i++){
		ciudad[i] = colaCiudad.pop();		
		cout<<i+1<<". "<<*(ciudad[i])<<endl;
	}
				  
	cout<<"Opcion: ";
	cin>>opcion;

	if(opcion<1 || opcion>data.getCantidadCiudades())
	return "";
	
	return *(ciudad[opcion-1]);
}

string escogerPais(){
	Cola<string*> colaPais = data.getPaises();
	string *pais[data.getCantidadPaises()];
				
	int opcion;
	cout<<"Seleccione el País: "<<endl;
				
	for(int i = 0; i < data.getCantidadPaises(); i++){
		pais[i] = colaPais.pop();		
		cout<<i+1<<". "<<*(pais[i])<<endl;
	}
				  
	cout<<"Opcion: ";
	cin>>opcion;

	if(opcion<1 || opcion>data.getCantidadPaises())
	return "";
	
	return *(pais[opcion-1]);
}

string escogerActividadLaboral(){
	
	Cola<string*> colaLaburo = data.getLaburos();
	string *laburos[data.getCantidadLaburos()];
	
	int opcion;
	cout<<"Seleccione la actividad laboral: "<<endl;
	
	for(int i = 0; i < data.getCantidadLaburos(); i++){
		laburos[i] = colaLaburo.pop();
		cout<<i+1<<". "<<*laburos[i]<<endl;
	}
	
	cout<<"Opcion: ";
	cin>>opcion;
	
	return *laburos[opcion-1];
}

void impresionPersonaBasico(Cola<Persona*> personas){
	int cantidad = personas.getSize();
				
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"id |   Nombre completo            |   Edad   | EPS             |   IPS                          | IPS asignada para vacuna       |     Vacuna   |"<<endl;
	cout<<"---|------------------------------|----------|-----------------|--------------------------------|--------------------------------|--------------|"<<endl;
	for(int i = 1; i <= cantidad; i++){
		Persona *persona = personas.pop();
		cout<<i<<"  | ";
		cout<<setw(20)  <<persona->getNombres()<<" "<<persona->getApellidos()<<" | ";
		cout<<persona->getEdad()<<" anhos | ";
		cout<<setw(15)<<persona->getEpsName()<<" | ";
		cout<<setw(30)<<persona->getIpsDefaultName()<<" | ";
		cout<<setw(30)<<persona->getIpsAsignadaName()<<" | ";
		cout<<setw(12)<<persona->getVacunaName()<<" | "; 
		cout<<endl;
	}
				
	cout<<endl;	
}

void crearRegistrosMenu(){
	int opcion; 
	while (opcion!=11)
	{
		cout<<"---------------------------------"<<endl;
		cout<<"Ingrese el tipo de registro que desea insertar: "<<endl;
    	cout<<"1. Persona"<<endl;
		// cout<<"2. Vacunados con un tipo de vacuna"<<endl;
		// cout<<"3. Fecha de vacunacion"<<endl;
		// cout<<"4. EPS"<<endl;
		// cout<<"5. IPS"<<endl;
		// cout<<"6. IPS asignada para vacunacion"<<endl;
		// cout<<"7. Ciudad de residencia"<<endl; 
		// cout<<"8. Sexo"<<endl;
		// cout<<"9. Pais de nacimiento"<<endl;
		cout<<"11. Volver al menu principal"<<endl<<endl;
		        
		cout<<"Opcion: ";
		cin>>opcion;     
		cout<<"---------------------------------"<<endl<<endl;

		switch (opcion){
		case 1:
			registrarPersonaMenu();
			break;
		
		default:
			break;
		}
	}
	
}

void registrarPersonaMenu(){

	Identificacion personaId;
	long long int numId = 0;
	int tipoId;

	// Identificación
	while (numId==0 && tipoId!=4)
	{
		cout<<"Ingrese el tipo de documento de la persona a ingresar: "<<endl;
		cout<<"1. CC"<<endl;
		cout<<"2. TI"<<endl;
		cout<<"3. CE"<<endl;
		cout<<"4. Salir"<<endl;

		cout<<"Tipo De Documento: ";
		cin>>tipoId;

		switch (tipoId){
		case 1:
			personaId.tipo = "CC";
			break;
		case 2:
			personaId.tipo = "TI";
			break;
		case 3:
			personaId.tipo = "CE";
			break;
		case 4:
			break;		
		default:
			cout<<"Opcion invalida"<<endl;
			break;
		}

		cout<<"Ingrese el numero de identificacion"<<endl;
		cin>>numId;

		if(numId<=0) {
			cout<<"Valor invalido, revise su entrada"<<endl;
			numId = 0;
		}
		else{
			personaId.numero = numId;
		}
	}

	// Nombre
	string nombrePersona = "";
	while (nombrePersona == "")
	{
		cout<<"Inserte el nombre de la persona que desea registrar"<<endl;
		cin>>nombrePersona;
	}

	// Apellido
	string apelPersona = "";
	while (apelPersona == "")
	{
		cout<<"Inserte el apellido de la persona que desea registrar"<<endl;
		cin>>apelPersona;
	}

	// Genero
	
	string genero = "";
	int generoOpcion;
	while (genero == "" && generoOpcion!=4)
	{
		cout<<"Seleccione el genero de la persona que desea registrar"<<endl;
		cout<<"1. Masculino"<<endl;
		cout<<"2. Femenino"<<endl;
		cout<<"3. No Especifica"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Genero: ";
		cin>>generoOpcion;

		switch (generoOpcion){
		case 1:
			genero = "Masculino";
			break;
		case 2:
			genero = "Femenino";
			break;
		case 3:
			genero = "No especifica";
			break;
		case 4:
			break;		
		default:
			cout<<"Opcion invalida"<<endl;
			break;
		}
	}

	// Email:
	string email = "";
	while(email == ""){
		cout<<"Ingrese el correo de la persona a ingresar"<<endl;
		cin>>email;

		if(email==""){
			cout<<"Revise la informacion registrada e intentelo nuevamente"<<endl;
		}
	}

	//Ciudad de nacimiento:
	string * ciudadNacimiento=NULL;
	while (ciudadNacimiento==NULL){
		cout<<"CIUDAD DE NACIMIENTO"<<endl;
		Cola<string*> colaCiudad = data.getCiudades();
		string *ciudad[data.getCantidadCiudades()];
					
		int opcionCiudad;
		cout<<"Seleccione la ciudad: "<<endl;
					
		for(int i = 0; i < data.getCantidadCiudades(); i++){
			ciudad[i] = colaCiudad.pop();		
			cout<<i+1<<". "<<*(ciudad[i])<<endl;
		}
					
		cout<<"Opcion: ";
		cin>>opcionCiudad;

		if(opcionCiudad>0 && (opcionCiudad-1)<data.getCantidadCiudades())
		ciudadNacimiento = ciudad[(opcionCiudad-1)];
		else
		ciudadNacimiento = NULL;
	}

	//Pais de nacimiento:
	string * paisNacimiento=NULL;
	while (paisNacimiento==NULL){
		cout<<"PAIS DE NACIMIENTO"<<endl;
		Cola<string*> colaPais = data.getPaises();
		string *pais[data.getCantidadPaises()];
					
		int opcionPais;
		cout<<"Seleccione el Pais: "<<endl;
					
		for(int i = 0; i < data.getCantidadPaises(); i++){
			pais[i] = colaPais.pop();		
			cout<<i+1<<". "<<*(pais[i])<<endl;
		}
					
		cout<<"Opcion: ";
		cin>>opcionPais;

		if(opcionPais>0 && (opcionPais-1)<data.getCantidadPaises())
		paisNacimiento = pais[opcionPais-1];
		else
		paisNacimiento = NULL;
	}

	//Ciudad de Residencia:
	string * ciudadResi=NULL;
	while (ciudadResi==NULL){
		cout<<"CIUDAD DE RESIDENCIA"<<endl;
		Cola<string*> colaCiudad = data.getCiudades();
		string *ciudad[data.getCantidadCiudades()];
					
		int opcionCiudad2;
		cout<<"Seleccione la ciudad: "<<endl;
					
		for(int i = 0; i < data.getCantidadCiudades(); i++){
			ciudad[i] = colaCiudad.pop();		
			cout<<i+1<<". "<<*(ciudad[i])<<endl;
		}
					
		cout<<"Opcion: ";
		cin>>opcionCiudad2;

		if(opcionCiudad2>0 && (opcionCiudad2-1)<data.getCantidadCiudades())
		ciudadResi = ciudad[opcionCiudad2-1];
		else
		ciudadResi = NULL;
	}

	//Direccion
	string direccion="";
	while (direccion==""){
		cout<<"Ingrese la direccion : "<<endl;
		cin>>direccion;
	}

	//Barrio
	string barrio="";
	while (barrio==""){
		cout<<"Ingrese el barrio : "<<endl;
		cin>>barrio;
	}

	//Telefono Celular:
	long long int telefono_cel=0;
	while (telefono_cel==0){
		cout<<"Ingrese su telefono celular : "<<endl;
		cin>>telefono_cel;
	}

	//Telefono Fijo:
	long long int telefono_fijo=0;
	while (telefono_fijo==0){
		cout<<"Ingrese su telefono fijo : "<<endl;
		cin>>telefono_fijo;
	}

	//Fecha de nacimiento:

	Lista<Fecha> listaFechas = data.getListaFechas();


	string f_nacimientoString="";
	Fecha * f_nacimiento=NULL;
	while (f_nacimiento==NULL){
		cout<<"Ingrese su fecha de nacimiento con el siguiente formato DD-MM-AAA: "<<endl;
		cin>>f_nacimientoString;
		if(f_nacimientoString!=""){
			int tam = data.ingresarFecha(f_nacimientoString);
			f_nacimiento = data.getListaFechas().obtenerDato(tam);
		}
		cout<<f_nacimiento->anho<<", "<<f_nacimiento->mes<<", "<<f_nacimiento->dia<<endl;
	}

	//Fecha de Primera Dosis:
	string f_primera_dosisString="";
	Fecha * f_primera_dosis=NULL;
	
	
	while (f_primera_dosis==NULL){
		cout<<"Ingrese la fecha en la que fue aplicada su primera dosis con el siguiente formato DD-MM-AAA: "<<endl;
		cout<<"En caso de no tener aplicadad dicha dosis, ingrese --: "<<endl;
		cin>>f_primera_dosisString;
		if(f_primera_dosisString!="") {
			int tam = data.ingresarFecha(f_primera_dosisString);
			f_primera_dosis = data.getListaFechas().obtenerDato(tam);
		}
		cout<<f_primera_dosis->anho<<", "<<f_primera_dosis->mes<<", "<<f_primera_dosis->dia<<endl;

	}

	//Fecha de Segunda Dosis:
	string f_segunda_dosisString="";
	Fecha * f_segunda_dosis=NULL;
	while (f_segunda_dosis==NULL){
		cout<<"Ingrese la fecha en la que fue aplicada su segunda dosis con el siguiente formato DD-MM-AAA: "<<endl;
		cout<<"En caso de no tener aplicadad dicha dosis, ingrese --: "<<endl;
		cin>>f_segunda_dosisString;
		if(f_segunda_dosisString!=""){
			int tam = data.ingresarFecha(f_segunda_dosisString);
			f_segunda_dosis = data.getListaFechas().obtenerDato(tam);
		}
		cout<<f_segunda_dosis->anho<<", "<<f_segunda_dosis->mes<<", "<<f_segunda_dosis->dia<<endl;
	}


	//Vacuna
	Vacuna *vacunaPersona;
	int vacunaOpcion=0;
	while(vacunaOpcion<=0){
		Cola<Vacuna*> colaVacuna = data.getVacunas();
		Vacuna *vacunas[data.getCantidadVacunas()];
					
		cout<<"Seleccione la Vacuna que le fue aplicada (Si no se le aplico ninguna vacuna, ingrese el valor 0): "<<endl;
					
		for(int i = 0; i < data.getCantidadVacunas(); i++){
			vacunas[i] = colaVacuna.pop();		
			cout<<i+1<<". "<<vacunas[i]->getNombre()<<endl;
		}
					
		cout<<"Opcion: ";
		cin>>vacunaOpcion;  
		
		if(vacunaOpcion>0 && (vacunaOpcion-1)<data.getCantidadVacunas()){
			vacunaPersona = vacunas[vacunaOpcion-1];
		} else {
			vacunaPersona = NULL;
		}
		cout<<vacunaPersona->getNombre()<<endl;
	}

	//Eps
	Eps *epsPersona;
	int epsOpcion=0;
	while(epsOpcion<=0){
		Cola<Eps*> colaEps = data.getEpss();
		Eps *epss[data.getCantidadEps()];
					
		cout<<"Seleccione la Eps a la que esta registrado: "<<endl;
					
		for(int i = 0; i < data.getCantidadEps(); i++){
			epss[i] = colaEps.pop();		
			cout<<i+1<<". "<<epss[i]->getNombre()<<endl;
		}
					
		cout<<"Opcion: ";
		cin>>epsOpcion;  
		
		if(epsOpcion>0 && (epsOpcion-1)<data.getCantidadEps()){
			epsPersona = epss[epsOpcion-1];
		} else {
			epsPersona = NULL;
		}
		
	}


	//Ips Asignada
	Ips *ipsAsignada=NULL;
	Ips *ipsDefault=NULL;
	int ipsOpcion=0;
	while(ipsOpcion<=0){
		
		Cola<Ips*> colaIps = data.getIpsPorEps(epsPersona->getNombre());
		int lenghtIps = colaIps.getSize();
		Ips *ipss[lenghtIps];
		
		cout<<"Seleccione la Ips a la que esta registrado: "<<endl;
					
		for(int i = 0; i < lenghtIps; i++){
			ipss[i] = colaIps.pop();		
			cout<<i+1<<". "<<ipss[i]->getNombre()<<endl;
		}
					
					
		cout<<"Opcion: ";
		cin>>ipsOpcion;  
		
		
		ipsDefault = ipss[0];
		if(ipsOpcion>0 && (ipsOpcion-1)<lenghtIps){
			ipsAsignada = ipss[ipsOpcion-1];
		} else {
			ipsAsignada = NULL;
		}
	}
	
	//Actividad Laboral:
	string * actLaboral=NULL;
	while (actLaboral == NULL)
	{
		Cola<string*> colaLaburo = data.getLaburos();
		string *laburos[data.getCantidadLaburos()];
		
		int opcionAct;
		cout<<"Seleccione la actividad laboral: "<<endl;
		
		for(int i = 0; i < data.getCantidadLaburos(); i++){
			laburos[i] = colaLaburo.pop();
			cout<<i+1<<". "<<*laburos[i]<<endl;
		}
		
		
		cout<<"Opcion: ";
		cin>>opcionAct;

		if(opcionAct>0 && (opcionAct-1)<data.getCantidadLaburos())
		actLaboral = laburos[opcionAct-1];
	}
	

	Persona persona = Persona(personaId.numero,personaId.tipo,nombrePersona,apelPersona,
											    genero,email,ciudadNacimiento,paisNacimiento,ciudadResi,direccion,
												barrio,telefono_cel,telefono_fijo,
												f_nacimiento ,f_primera_dosis ,f_segunda_dosis ,
												vacunaPersona,epsPersona,ipsDefault,ipsAsignada, actLaboral);


	data.setPersona(persona, data.getCantidadPersonas()+1);
	
}
