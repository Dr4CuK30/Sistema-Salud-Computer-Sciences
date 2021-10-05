#ifndef FECHA_H
#define FECHA_H

#include <string>
#include <stdlib.h>

#include "Lista.h"
#include <ctime>

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


bool esMayorQue(Fecha comparada, Fecha aComparar){
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	float cantDiasCom=0;

	for (int i = 1; i <= (comparada.mes-1); i++)
	{
		if (i==2)
		{
			cantDiasCom = cantDiasCom + 28;
		}

		if(i%2!=0 && i<=7){
			cantDiasCom = cantDiasCom + 31;
		}

		if(i%2==0 && i<7 && i!=2){
			cantDiasCom = cantDiasCom + 30;
		}

		if (i%2==0 && i>=8){
			cantDiasCom = cantDiasCom + 31;
		}

		if(i%2!=0 && i>=9){
			cantDiasCom = cantDiasCom + 30;
		}
	}

	float cantDiasACom=0;

	for (int i = 1; i <= (aComparar.mes-1); i++)
	{
		if (i==2)
		{
			cantDiasACom = cantDiasACom + 28;
		}

		if(i%2!=0 && i<=7){
			cantDiasACom = cantDiasACom + 31;
		}

		if(i%2==0 && i<7 && i!=2){
			cantDiasACom = cantDiasACom + 30;
		}

		if (i%2==0 && i>=8){
			cantDiasACom = cantDiasACom + 31;
		}

		if(i%2!=0 && i>=9){
			cantDiasACom = cantDiasACom + 30;
		}
	}

	float anho_actual = timePtr->tm_year+1900.0 + (timePtr->tm_mon+1.0)/12 + ((timePtr->tm_mday+1.0)/365);
	float fecha_comparada = anho_actual - (comparada.anho + ((comparada.mes)/12.0) + ((cantDiasCom+comparada.dia)/365));
	float fecha_aComparar = anho_actual - (aComparar.anho + ((aComparar.mes)/12.0) + ((cantDiasACom+aComparar.dia)/365));
	cout<<"Comparada 1 : "<<fecha_comparada<<" , A Comparar: "<<fecha_aComparar<<endl;

	if(fecha_comparada>=fecha_aComparar){
		return true;
	}

	return false;

}

#endif
