  
#ifndef VECTEUR3D_H
#define VECTEUR3D_H
class Vecteur3D{
	double x,y,z;

public :
	Vecteur3D(double _x=0,double _y=0,double _z=0):x(_x),y(_y),z(_z){};
	double& operator[] (int val);
	const double& operator[] (int val) const;
	Vecteur3D operator+ (const Vecteur3D& v) const; 
	bool operator!= (const Vecteur3D& v) const; 
	bool operator== (const Vecteur3D& v) const;
	void affichage() const;
	 Vecteur3D operator* (double v);
	double norme() const;
	double distance(const Vecteur3D& B);
	friend Vecteur3D operator* (double _v, const Vecteur3D& v);  
};

#endif