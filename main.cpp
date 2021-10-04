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
void empezarPrograma(ControladorData);
void consultarPacientesPor();
void usarTablaBasica(int filas, int columnas /*Cola etiquetas, datos*/);

int main(int argc, char *argv[]) {       
	  
	      
	      
	      
//	Cola<string> cola;   
//	
//	cola.push("hola");   
//	cout<<"se crea bien"<<endl;
//	cola.push("2");
//	cola.push(" 3 ");  
//	 
//	cout<<"ingresa piola"<<endl;
//	for(int i = 0; i < 3; i++) {
//		cout<<"antes de nada"<<endl;
////		cout<<i<<" "<<cola.pop(); 
//	}     
//	
//	cout<<"--"<<endl;
	ControladorData data;   
	
	
	empezarPrograma(data);    
	
	
	    
    system("PAUSE");       
    return EXIT_SUCCESS;
}                   

void empezarPrograma(ControladorData data){
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
				Pila<Persona*> personas = data.getPersonas();
				int cantidad = data.getCantidadPersonas();
				
				cout<<"---------------------------Pacientes registrados------------------------------"<<endl;
				cout<<"------------------------------------------------------------------------------"<<endl;
				cout<<"id |   Nombre completo            |   Edad   | EPS             |"<<endl;
				cout<<"---|------------------------------|----------|-----------------|"<<endl;
				for(int i = 1; i <= cantidad; i++){
					Persona *persona = personas.pop();
					cout<<i<<"  | ";
					cout<<setw(20)  <<persona->getNombres()<<" "<<persona->getApellidos()<<" | ";
					cout<<persona->getEdad()<<" anhos | ";
					cout<<setw(15)<<persona->getEpsName()<<" | ";
					cout<<endl;
				}
				
				cout<<endl<<endl<<endl;
				break;
			}	
			case 5: {
				//Todas las vacunas
				Pila<Vacuna*> vacunas = data.getVacunas();
				int cantidad = data.getCantidadVacunas();
				
				cout<<"---------------------------Vacunas disponibles------------------------------"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				cout<<"id |   Nombre vacuna      | Cantidad de dosis  |"<<endl;
				cout<<"---|----------------------|--------------------|"<<endl;
				for(int i = 1; i <= cantidad; i++){
					Vacuna *vacuna = vacunas.pop();
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
				Pila<Eps*> epss = data.getEpss();
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
				Pila<Ips*> ipss = data.getIpss();
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
    	cout<<"2. Edad"<<endl;
		cout<<"3. Vacunados con un tipo de vacuna"<<endl;
		cout<<"4. Fecha de vacunacion"<<endl;
		cout<<"5. Volver al menu principal"<<endl<<endl;
		        
		cout<<"Opcion: ";
		cin>>opcion;     
		cout<<"---------------------------------"<<endl;
		  
		switch(opcion){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;         
			default:	
				cout<<"Opcion no valida"<<endl<<endl;
				break;          
		}
	}
	

}
