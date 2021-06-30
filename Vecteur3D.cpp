#include"Vecteur3D.h"
#include<cmath>
#include<iostream>
double& Vecteur3D::operator[] (int val){
	
	if( val == 0 )
		return x;
			else if ( val == 1 )
				return y;
					else if ( val == 2 )
						return z;
	throw ("Out of bounds");
}

const double& Vecteur3D::operator[] (int val) const{
	
	if( val == 0 )
		return x;
			else if ( val == 1 )
				return y;
					else if ( val == 2 )
						return z;
	throw ("Out of bounds");
}


Vecteur3D Vecteur3D::operator+ (const Vecteur3D& v) const{

return Vecteur3D((*this)[0]+v[0],(*this)[1]+v[1],(*this)[2]+v[2]);
}

double Vecteur3D::norme() const
{
	return sqrt(( (*this)[0] * (*this)[0] ) + ( (*this)[1] * (*this)[1] ) + ( (*this)[2] * (*this)[2] ));
}

// vecteur * double
Vecteur3D Vecteur3D::operator* (double v){
return Vecteur3D((*this)[0]*v,(*this)[1]*v,(*this)[2]*v);
}

// double * vecteur fonction amie car la classe double ne nous appartient pas( impossible de faire this sur double) 
Vecteur3D operator* (double _v,const Vecteur3D& v){
return Vecteur3D(_v*v[0],_v*v[1],_v*v[2]);	
}

// si Vecteur != Vecteur1
bool Vecteur3D::operator!= (const Vecteur3D& v) const{
	
	return  ( ( (*this)[0] != v[0] ) ||  ( (*this)[1] != v[1] ) || ( (*this)[2] != v[2] ) ) ? true : false; 
} 

// si Vecteur == Vecteur1
bool Vecteur3D::operator== (const Vecteur3D& v) const{

	return  ( ( (*this)[0] == v[0] ) &&  ( (*this)[1] == v[1] ) && ( (*this)[2] == v[2] ) ) ? true : false; 
}
// distance entre 2 vecteur
double Vecteur3D::distance(const Vecteur3D& B){
	
	return sqrt( (B[0]-(*this)[0])*(B[0]-(*this)[0]) + (B[1]-(*this)[1])*(B[1]-(*this)[1]) + (B[2]-(*this)[2])*(B[2]-(*this)[2]) );
}
void Vecteur3D::affichage() const{
	std::cout<<" AFFICHAGE VECTEUR \n";
 	std::cout<< " x = " << (*this)[0] <<"\n";
 	std::cout<< " y = " << (*this)[1] <<"\n";
	std::cout<< " z = " << (*this)[2] <<"\n";
	std::cout<< " Norme = " << this->norme()<<"\n";

}