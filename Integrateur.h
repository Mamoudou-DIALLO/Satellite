#ifndef INTEGRATEUR_H
#define INTEGRATEUR_H
#include "Vecteur3D.h"
class Integrateur{

public:
virtual void avance(Vecteur3D& _x,Vecteur3D& _v,Vecteur3D (*f)(Vecteur3D&,Vecteur3D&),double dt )=0;

};
#endif