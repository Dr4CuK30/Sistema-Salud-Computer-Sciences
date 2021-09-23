#ifndef CONTROLADOR_DATA_H
#define CONTROLADOR_DATA_H

#include "Lista.h"
//#include "Persona.h"
#include "Vacuna.h"

#include "ArbolBinarioOrdenado.h"
#include <iostream>


using namespace std;

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
		//Lista <Persona> listaPersonas;
		//Lista <EPS> listaEPS;
		//Lista <IPS> listaIPS;
		//Lista <EPSVacuna>;
		//Lista <IPSVacuna>;
		//Lista <EPS_IPS>;
		
		//---------------------Arboles ordenados----------------------------------//
		
		
		
		
	
};


#endif
