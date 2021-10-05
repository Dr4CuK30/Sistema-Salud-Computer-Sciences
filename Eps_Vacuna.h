#ifndef EPS_VACUNA_H
#define EPS_VACUNA_H
#include "Eps.h"
#include "Vacuna.h"

class Eps_Vacuna{
	private:
		Eps *eps;
		Vacuna *vacuna;
		int stock;	

	public:
		Eps_Vacuna(){}
		Eps_Vacuna(Eps *eps, Vacuna *vacuna, int stock){
			this->eps = eps;
			this->vacuna = vacuna;
			this->stock = stock;
		}

		Eps * getEps(){
			return this->eps;
		}

		Vacuna * getVacuna(){
			return this->vacuna;
		}

		int getStock(){
			return this->stock;
		}

		// Obtener Nombres:
		string getVacunaName(){
			Vacuna * vacuna = this->getVacuna();
			Vacuna obtained = *vacuna;
			return obtained.getNombre();
		}

		string getEpsName(){
			Eps * eps = this->getEps();
			Eps obtained = *eps;
			return obtained.getNombre();
		}

		string getNombre(){
			return this->getVacunaName() + this->getEpsName();
		}
};

#endif
