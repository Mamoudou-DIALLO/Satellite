  
#include "IntegrateurRungeKutta.h"
void IntegrateurRungeKutta::avance(Vecteur3D& _x,Vecteur3D& _v,Vecteur3D (*f)(Vecteur3D&,Vecteur3D&),double dt ){
		
	         
	Vecteur3D k1;
	Vecteur3D k2;
	Vecteur3D inter1;
	k1=(*f)(_x,_v)*(dt/2.0);	
	inter1=_x+(dt/2.0)*k1;
	k2=(*f)(inter1,_v)*(dt/2.0);
	_x=_x+((dt/2.0)*k2);
	


		
}