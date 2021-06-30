#include "Terre.h"
long double Terre::GM=398600000000000.0;
double Terre::RT=6378000.0;

Vecteur3D Terre::gravite(const Vecteur3D& OM) const{

	double norm = OM.norme();
	double val=(-GM)/(norm*norm*norm);
return val*OM;
}
// vitesse initiale du satellite par rapport à la terre à une hauteur h
Vecteur3D Terre::vitesseInitiale(double h) const{
	Vecteur3D _v(0,sqrt(GM/(RT+h)),0);
return _v;
}
// position initiale du satellite par rapport à la terre à une hauteur h
Vecteur3D Terre::positionInitiale(double h) const{
	Vecteur3D _v(RT+h);// contructeur par defaut (val, y=0, z=0)
return _v;
}
// temps necessaire pour faire le tour de la terre à partir d'une hauteur h
double Terre::tempsParcours(double h) const{

return  (2*M_PI)*sqrt( ( ((RT+h)*(RT+h)*(RT+h)) ) / GM );
}

// singleton
Terre* Terre::instance=NULL;
Terre::Terre(){

}
Terre::~Terre(){

}