#ifndef INTEGRATEURRUNGEKUTTA_H
#define INTEGRATEURRUNGEKUTTA_H
#include "Integrateur.h"
#include "Vecteur3D.h"
class IntegrateurRungeKutta: public Integrateur{
public :
void avance(Vecteur3D& _x,Vecteur3D& _v,Vecteur3D (*f)(Vecteur3D&,Vecteur3D&),double dt );

};
#endif