#include "Mobile.h"
#include "Terre.h"

Mobile::Mobile(const std::string& _n):nom(_n){
}

 void Mobile::avance(double dt){
	//avance(get_position(),get_vitesse(),&Mobile::get_G,dt);
	//position = position + dt * vitesse;
}

void  Mobile::affichage(){
 
	std::cout<<" AFFICHAGE MOBILE \n";
	std::cout<<" Nom du mobile "<< nom <<"\n";
 	std::cout<< "Position x = " << position[0] <<"\n";
 	std::cout<< "Position y = " << position[1] <<"\n";
	std::cout<< "Position z = " << position[2] <<"\n";
	std::cout<< "Vitesse x = " << vitesse[0] <<"\n";
	std::cout<< "Vitesse y = " << vitesse[1] <<"\n";
	std::cout<< "Vitesse z = " << vitesse[2] <<"\n";
}

std::string& Mobile::get_nom(){
	
	return nom;
}

void Mobile::set_nom(std::string& _n){
	
	nom=_n;
}

Vecteur3D& Mobile::get_position(){
	
	return position;
}

void Mobile::set_position(Vecteur3D& _p){

	position=_p;
}

Vecteur3D& Mobile::get_vitesse(){

	return vitesse;
}
void Mobile::set_vitesse(Vecteur3D& _v){

	vitesse=_v;
}

Vecteur3D Mobile::get_G(Vecteur3D& x,Vecteur3D& v){
	
	Terre *T=Terre::getInstance();
return T->gravite(x);
}

Mobile::Mobile(const Mobile& m){
	
	if(this != &m) // l'objet ne doit pas ce copier dans lui même
	{
		nom = m.nom;
		position = m.position;
		vitesse = m.vitesse;
		
	}
}

Mobile* Mobile::copie(){
	
	Mobile *m=new Mobile(*this); //on transmet l'objet a copier au constructeur par copie

return m;
}

Mobile::~Mobile(){

}