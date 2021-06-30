#ifndef SIMULATION_H
#define SIMULATION_H
#include<list>
#include "Mobile.h"
class Simulation{
	double temps;
	std::list<Mobile*> listeMobile; 
public:
	Simulation(double _tps);
	void Add_Mobile( Mobile* m);
	void Delete_Mobile(Mobile* m);
	void Show_Liste();
	void simuler(double dt);
	double get_temps() const;
	std::list<Mobile*>& get_listemobile();
	Simulation(const Simulation&);
	~Simulation();
};
#endif