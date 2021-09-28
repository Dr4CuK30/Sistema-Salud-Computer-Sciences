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


Lista<Fecha> listaFechas;

Fecha *crearFecha(string fechaString){
	if(fechaString == "--") return NULL;
	
	string *divisiones = new string[3];
	int posicion = 0;
	
	for(int i = 0; i < fechaString.size(); i++){
		if(fechaString[i] == '-'){
			i++;
			posicion++;
		}else{
			divisiones[posicion] += fechaString;
		}
	}
	
	int dia = atoi(divisiones[0].c_str());
	int mes = atoi(divisiones[1].c_str());
	int anho = atoi(divisiones[2].c_str());
	
	Fecha fecha;
	fecha.anho = anho;
	fecha.mes = mes;
	fecha.dia = dia;
	
	listaFechas.intertar_final(fecha);
	
	fecha = listaFechas.obtenerDato(listaFechas.Tam_lista());
	
	return &fecha;
	
}

#endif
