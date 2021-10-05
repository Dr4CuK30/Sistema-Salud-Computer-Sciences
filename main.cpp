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
     
      
using namespace std;
void empezarPrograma();
void consultarPacientesPor();
void impresionPersonaBasico(Cola<Persona*>);

ControladorData data;

int main(int argc, char *argv[]) {          
	
	
	empezarPrograma();    
	
	
	    
    system("PAUSE");       
    return EXIT_SUCCESS;
}                   

void empezarPrograma(){
	//cargar archivos    
	
	int opcion;
	  
	while(opcion != 8){  
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
		cout<<"8. SALIR"<<endl<<endl;  
		      
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
				
				cout<<"---------------------------Pacientes registrados------------------------------"<<endl;
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
					cout<<setw(15)	<<ips->getCiudad()<<" | ";
					cout<<setw(15)	<<ips->getEpsName()<<" | ";
					cout<<endl;
				}
				
				cout<<endl<<endl<<endl;
				break;
			}
			case 8:
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
	     
	while(opcion != 5){    
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
		cout<<"9. Volver al menu principal"<<endl<<endl;
		        
		cout<<"Opcion: ";
		cin>>opcion;     
		cout<<"---------------------------------"<<endl<<endl;
		  
		switch(opcion){
			case 1:{
				string rangosDeEdad[] = {"-20","20-29","30-39","40-49","50-59","60-69","70-79","+80"};
				
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
