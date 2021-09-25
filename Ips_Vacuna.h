#ifndef IPS_VACUNA_H
#define IPS_VACUNA_H
#include "Ips.h"
#include "Vacuna.h"

class Ips_Vacuna{
	protected:
		Ips *ips;
		Vacuna *vacuna;
	public:
		Ips_Vacuna(){}
		Ips_Vacuna(Ips *ips, Vacuna *vacuna){
			this->ips = ips;
			this->vacuna = vacuna;
		}
};

#endif
