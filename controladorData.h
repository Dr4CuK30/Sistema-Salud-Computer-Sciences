#ifndef CONTROLADOR_DATA_H
#define CONTROLADOR_DATA_H

#include "Lista.h"
//#include "Persona.h"
#include "Vacuna.h"
#include <iostream>


using namespace std;

class ControladorData{
	
	private:
		
		int cantidadPersonas;
		int cantidadVacunas;
		int cantidadEPS;
		int cantidadIPS;
		int cantidadEPSVacuna;
		int cantidadIPSVacuna;
		int cantidadEPS_IPS;
		
		//---------------------listas generales-----------------------------------//
		Lista <Vacuna> listaVacunas;
		
		
	
};


#endif
