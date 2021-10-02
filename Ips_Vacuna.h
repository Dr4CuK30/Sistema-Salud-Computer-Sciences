#ifndef IPS_VACUNA_H
#define IPS_VACUNA_H
#include "Ips.h"
#include "Vacuna.h"

class Ips_Vacuna{
	private:
		Ips *ips;
		Vacuna *vacuna;
	public:
		Ips_Vacuna(){}
		Ips_Vacuna(Ips *ips, Vacuna *vacuna){
			this->ips = ips;
			this->vacuna = vacuna;
		}
		
		Ips * getIps()
		{
			return this->ips;
		}

		Vacuna * getVacuna()
		{
			return this->vacuna;
		}

		// Obtener Nombres:
		string getIpsName(){
			Ips * ips = this->getIps();
			Ips obtained = *ips;
			return obtained.getNombre();
		}

		string getVacunaName(){
			Vacuna * vacuna = this->getVacuna();
			Vacuna obtained = *vacuna;
			return obtained.getNombre();
		}
};

#endif
