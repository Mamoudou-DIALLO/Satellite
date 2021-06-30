#ifndef MOBILE_H
#define MOBILE_H
#include<iostream>
#include<string>
#include "Vecteur3D.h"
class Mobile{
	std::string nom;
	Vecteur3D position;
	Vecteur3D vitesse;
	
public:	
	Mobile(const std::string& _n);
	void avance(double dt);
	std::string& get_nom();
	void set_nom(std::string& _n);
	Vecteur3D& get_position();
	void set_position(Vecteur3D& _p);
	Vecteur3D& get_vitesse();
	void set_vitesse(Vecteur3D& _v);
	void affichage();
	static Vecteur3D get_G(Vecteur3D& x,Vecteur3D& v);
	virtual Mobile* copie();
	Mobile(const Mobile& m);
	~Mobile();
	template <class T>
        void advance(double dt){
	T integrale;
	integrale.avance(get_position(),get_vitesse(),&Mobile::get_G,dt);
	
       }
};

#endif