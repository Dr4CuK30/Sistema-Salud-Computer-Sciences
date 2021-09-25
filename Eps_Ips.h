#ifndef EPS_IPS_H
#define EPS_IPS_H
#include "Ips.h"
#include "Eps.h"

class Eps_Ips{
	protected:
		Ips *ips;
		Eps *eps;
	public:
		Eps_Ips(){
		}
		Eps_Ips(Eps *eps, Ips *ips){
			this->ips = ips;
			this->eps = eps;
		}
};

#endif
