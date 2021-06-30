#ifndef TERRE_H
#define TERRE_H
#include<iostream>
#include "Vecteur3D.h"
#include<cmath>
class Terre{
	static long double GM;
	static      double RT;
//singleton
private:
	Terre();
	~Terre();
	static Terre *instance;

public :
//singleton
static Terre* getInstance(){
	if( instance == NULL )
		instance = new Terre();
	return instance;
}
Vecteur3D gravite(const Vecteur3D& OM) const;
Vecteur3D vitesseInitiale(double h) const;
Vecteur3D positionInitiale(double h) const;
double tempsParcours(double h) const;

};

#endif