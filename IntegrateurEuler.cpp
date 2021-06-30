
#include "IntegrateurEuler.h"

void IntegrateurEuler::avance(Vecteur3D& _x,Vecteur3D& _v,Vecteur3D (*f)(Vecteur3D&,Vecteur3D&),double dt ){
		_x=_x+(dt*_v);
		_v=_v+(dt*((*f)(_x,_v)));
		
}