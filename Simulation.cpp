#include"Simulation.h"
#include "IntegrateurEuler.h"
#include "IntegrateurRungeKutta.h"
Simulation::Simulation(double _tps):temps(_tps){

}
void Simulation::Add_Mobile(Mobile* m){
	listeMobile.push_back(m);
}	
void Simulation::Delete_Mobile(Mobile* m){
	listeMobile.remove(m);
	//delete m;
}	
void Simulation::Show_Liste(){
	std::list<Mobile*>::iterator it;
	it = listeMobile.begin();
	while( it != listeMobile.end() )
	{
		(*it)->affichage();
		it++;
	}
}
void Simulation::simuler(double dt){
	temps+=dt;// modifie le temps courant
	std::list<Mobile*>::iterator it;
	it = listeMobile.begin();
	while( it != listeMobile.end() )
	{
		(*it)->advance<IntegrateurEuler>(dt);
		it++;
	}
}
double Simulation::get_temps() const{
	
	return temps;

}
std::list<Mobile*>& Simulation::get_listemobile(){

	return listeMobile;
}
Simulation::Simulation(const Simulation& _s){

	if(this != &_s)
	{
		temps = _s.temps;
		std::list<Mobile*> tmp=_s.listeMobile;
		std::list<Mobile*>::iterator it;
		it = tmp.begin();
		while( it != tmp.end() )
		{
			Add_Mobile((*it)->copie());// on appel copie qui renvoie un pointeur de Mobile
			it++;
		}
	}
	
}
Simulation::~Simulation(){
	std::list<Mobile*>::iterator it;
	it = listeMobile.begin();
	while( it != listeMobile.end() )
	{
			delete (*it);
		it++;
	}
	listeMobile.clear();
}