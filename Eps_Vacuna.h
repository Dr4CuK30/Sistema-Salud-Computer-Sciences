#ifndef EPS_VACUNA_H
#define EPS_VACUNA_H
#include "Eps.h"
#include "Vacuna.h"

class Eps_Vacuna{
	protected:
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
};

#endif
