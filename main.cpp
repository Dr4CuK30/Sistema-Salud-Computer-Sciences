#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "cola_prioridad.h"
#include "controladorData.h"
#include "Lista.h"
#include "Vacuna.h"               
#include "Casilla.h"
#include "Fecha.h"
#include "Persona.h"
    
using namespace std;

 
void empezarPrograma();
void consultarPacientesPor();
void usarTablaBasica(int filas, int columnas /*Cola etiquetas, datos*/);

int main(int argc, char *argv[]) {          
     
	
	//empezarPrograma();    
	
	ControladorData data;   
	
	//Pruebas Getters:
	Eps mieps("Eps1");
	Eps * Epspointer = &mieps;
	
	Vacuna mivacuna("Vac2", 2);
	Vacuna * mivacunaPointer = &mivacuna;
	
	
	Eps_Vacuna vacEps(Epspointer, mivacunaPointer, 2);
	cout<<vacEps.getEpsName()<<endl;
	cout<<vacEps.getVacunaName()<<endl;
	
	Ips miips("ips1", "Calle Gei", "Ciudad Gei", Epspointer);
	Ips * ipsPointer = &miips;	
	Ips_Vacuna ipsVac(ipsPointer, mivacunaPointer);
	cout<<ipsVac.getIpsName()<<" , "<<ipsVac.getVacunaName()<<endl;
	
	    
    system("PAUSE");       
    return EXIT_SUCCESS;
}                   

void empezarPrograma(){
	//cargar archivos   
	
	
	int opcion;
	
	while(opcion != 8){  
		cout<<"----------------------------------------------"<<endl;
		cout<<"--------BIENVENIDO A SALDAVACUNA APP----------"<<endl;
		cout<<"----------------------------------------------"<<endl;
		
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
			case 4:
				break;
			case 5:            
				break;
			case 6:
				break;
			case 7:
				break;
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
		cout<<"1. EPS"<<endl;
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
