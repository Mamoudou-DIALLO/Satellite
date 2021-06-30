#include "MobilePesant.h"
#include "IntegrateurEuler.h"
#include "IntegrateurRungeKutta.h"
#include "Terre.h"
MobilePesant::MobilePesant(const std::string& _n,double _masse):Mobile(_n),masse(_masse){
	
}
void MobilePesant::gravite(double dt){
	
	Vecteur3D _vitesse=get_vitesse();
	Terre *T=Terre::getInstance();
	advance<IntegrateurEuler>(dt);
	_vitesse=_vitesse + (dt*T->gravite(get_position()));
	set_vitesse(_vitesse);
}
double MobilePesant::get_masse() const{

	return masse;
}
Mobile* MobilePesant::copie(){
	
	Mobile *m=new MobilePesant(*this);// on transmet l'objet à copier au constructeur par copie		
return m;
}
MobilePesant::MobilePesant(const MobilePesant& MP):Mobile(MP),masse(MP.masse){

}
MobilePesant::~MobilePesant(){

}