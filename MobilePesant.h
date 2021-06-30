#ifndef MOBILEPESANT_H
#define MOBILEPESANT_H
#include "Mobile.h"
class MobilePesant: public Mobile{
	double masse; 
public:
	MobilePesant(const std::string& _n,double _masse);
	void gravite(double dt);
	double get_masse() const;
	MobilePesant(const MobilePesant& MP);
	 Mobile* copie();
	~MobilePesant();
};
#endif