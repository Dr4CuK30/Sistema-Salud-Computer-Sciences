#ifndef FECHA_H
#define FECHA_H

#include <string>
#include <stdlib.h>

#include "Lista.h"

using namespace std;

struct Fecha{
	int dia;
	int mes;
	int anho;
};


Fecha crearFecha(string fechaString){
	string divisiones[] = {"","",""};
	int posicion = 0;
	
	for(int i = 0; i < fechaString.size(); i++){
		if(fechaString[i] == '-'){
			
			posicion++;
			
		}else{
			divisiones[posicion] += fechaString[i];
		}
		
	}
	
	int dia = atoi(divisiones[0].c_str());
	int mes = atoi(divisiones[1].c_str());
	int anho = atoi(divisiones[2].c_str());
	
	Fecha fechaCreada;
	fechaCreada.anho = anho;
	fechaCreada.mes = mes;
	fechaCreada.dia = dia;


	return fechaCreada;
	
}

#endif
