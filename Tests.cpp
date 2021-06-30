#include "Tests.h"
#include "Mobile.h"
#include "Vecteur3D.h"
#include "Simulation.h"
#include "MobilePesant.h"
#include "Terre.h"
#include "IntegrateurRungeKutta.h"
#include "IntegrateurEuler.h"
#include <string.h>
#include<iostream>
bool testMobile1(){
	
     Mobile *m= new Mobile("c++");
	std::string testNom;
	       testNom="java";
	    m->set_nom(testNom);
	if( testNom != m->get_nom() )
		return false;
	
	Vecteur3D _posi;
	_posi[0]=14;
	_posi[1]=15;
	_posi[2]=16;
	m->set_position(_posi);
	if( _posi[0] != m->get_position()[0] || _posi[1] != m->get_position()[1] || _posi[2] != m->get_position()[2] )
		return false;
	
	Vecteur3D _vit;
	_vit[0]=1;
	_vit[1]=2;
	_vit[2]=3;
	m->set_vitesse(_vit);
	if( _vit[0] != m->get_vitesse()[0] || _vit[1] != m->get_vitesse()[1] || _vit[2] != m->get_vitesse()[2] )
		return false;

	double dt=20;
	_posi[0]+=dt*m->get_vitesse()[0];
	_posi[1]+=dt*m->get_vitesse()[1];
	_posi[2]+=dt*m->get_vitesse()[2];

	m->avance(dt);
	if( _posi[0] != m->get_position()[0] || _posi[1] != m->get_position()[1] || _posi[2] != m->get_position()[2] )	
		return false;

	if( _vit[0] != m->get_vitesse()[0] || _vit[1] != m->get_vitesse()[1] || _vit[2] != m->get_vitesse()[2] )
		return false;

	m->affichage();
	delete m;
return true;
}
bool testSimulation1()
{	
	// instanciation de 2 mobiles normale
	double dt=20;
	Mobile *m1= new Mobile("c++");
	Mobile *m2= new Mobile("java");	
	// on calcul le resultat attendu après la  simulation de m1
	Vecteur3D _posi=m1->get_position();
	_posi[0]+=dt*m1->get_vitesse()[0];
	_posi[1]+=dt*m1->get_vitesse()[1];
	_posi[2]+=dt*m1->get_vitesse()[2];
	Vecteur3D _vit=m1->get_vitesse();
	// on calcul le resultat attendu après la  simulation de m2
	Vecteur3D _posi2=m2->get_position();
	_posi2[0]+=dt*m2->get_vitesse()[0];
	_posi2[1]+=dt*m2->get_vitesse()[1];
	_posi2[2]+=dt*m2->get_vitesse()[2];
	Vecteur3D _vit2=m2->get_vitesse();
	// instanciation de la simulation
	Simulation s(0);
	// ajout des mobiles à la liste de  simulation
	s.Add_Mobile(m1);
	s.Add_Mobile(m2);
	// affiche les mobiles de la liste de simulation
	s.Show_Liste();
	// Avancer les mobiles de la simulation de 20
	s.simuler(dt);
	if( s.get_temps() != dt )
		return false;
	// on verifie les valeurs après simulation avec les valeurs attendus
	if( _posi[0] != m1->get_position()[0] || _posi[1] != m1->get_position()[1] || _posi[2] != m1->get_position()[2] )	
		return false;

	if( _vit[0] != m1->get_vitesse()[0] || _vit[1] != m1->get_vitesse()[1] || _vit[2] != m1->get_vitesse()[2] )
		return false;

	if( _posi2[0] != m2->get_position()[0] || _posi2[1] != m2->get_position()[1] || _posi2[2] != m2->get_position()[2] )	
		return false;

	if( _vit2[0] != m2->get_vitesse()[0] || _vit2[1] != m2->get_vitesse()[1] || _vit2[2] != m2->get_vitesse()[2] )
		return false;
	// supprime le mobile 2 de la liste de simulation
	s.Delete_Mobile(m2);
	// affiche les mobiles de la liste de simulation
	s.Show_Liste();
delete m2;
	
return true;
}
bool testSimulation2()
{
	// instanciation de 3 mobiles avec 0 pour normale et 1 pour allocation dynamique
	Mobile *m1= new Mobile("mysql");
	Mobile *m2 = new Mobile("oracle");	
	Mobile *m3= new Mobile("sqllite");
	/*std::cout<<" TAILLES 1\n ";
	std::cout<<sizeof(m1);
	std::cout<<" \n ";
	std::cout<<" TAILLES 2\n ";
	std::cout<<sizeof(m2);
	std::cout<<" \n ";*/
	// instanciation de la simulation
	Simulation s(6);
	// ajout des mobiles à la liste de  simulation
	s.Add_Mobile(m1);
	s.Add_Mobile(m2);
	s.Add_Mobile(m3);
	// affiche les mobiles de la liste de simulation
	s.Show_Liste();
	// Avancer les mobiles de la simulation de 10
	s.simuler(10);
	// supprime le mobile 1 de la liste de simulation
	s.Delete_Mobile(m1);
	// affiche les mobiles de la liste de simulation
	s.Show_Liste();
delete m1;
return true;
}
bool testMobile2(){
	// pour une hauteur de 10m le mobile doit mettre 1.427s pour atteindre le sol
	int j=1427;
	Vecteur3D posi(0,0,10);	
	Vecteur3D vit(0,0,0);
	MobilePesant P("moto",12.5);
	P.set_vitesse(vit);
	P.set_position(posi);
	while( j != 0 )
	{	
		std::cout<<"\n";
		P.gravite(0.001);
		j=j-1;	
		std::cout<<" VALEUR DE Z DE X\n";
		std::cout<< P.get_position()[2];	
		
		
	}
	
	

return true;
}
bool testSimulation3(){
	int i=1;
// instanciation de 3 mobiles avec 0 pour normale et 1 pour allocation dynamique
	Mobile *m1= new Mobile("velo");
	Mobile *m2 = new Mobile("personne");	
	MobilePesant *P1 = new MobilePesant("bus",12.5);
	Vecteur3D _p1=m1->get_position();
	Vecteur3D _p2=m2->get_position();
	Vecteur3D _p3=P1->get_position();
	// instanciation de la simulation
	Simulation _s(0);
	// ajout des mobiles à la liste de  simulation
	_s.Add_Mobile(m1);
	_s.Add_Mobile(m2);
	_s.Add_Mobile(P1);
	// Avancer les mobiles de la simulation de 10
	while( i <= 10 )
	{
		_s.simuler(i);
		i++;

	}
	// affiche les mobiles de la liste de simulation
	_s.Show_Liste();
	// on verifi que le temps soit égale aà la somme de 1+2....10
	if( _s.get_temps() != 55 )
		return false;
	// on verie que les positions on changé
	if(_p1[0] == m1->get_position()[0] || _p1[1] == m1->get_position()[1]  || _p1[2] == m1->get_position()[2] )
		return false;
	
	if(_p2[0] == m2->get_position()[0] || _p2[1] == m2->get_position()[1]  || _p2[2] == m2->get_position()[2] )
		return false;

	if(_p3[0] == P1->get_position()[0] || _p3[1] == P1->get_position()[1]  || _p3[2] == P1->get_position()[2] )
		return false;

return true;
}
bool testSimulation4(){

	Mobile *m1= new Mobile("bic");
	Mobile *m2 = new Mobile("gomme");	
	MobilePesant *P1= new MobilePesant("ampule",12.5);
	// instanciation de la simulation
	Simulation _s(6);
	// ajout des mobiles à la liste de  simulation
	_s.Add_Mobile(m1);
	_s.Add_Mobile(m2);
	_s.Add_Mobile(P1);
	// affichage des mobile de la simulation
	_s.Show_Liste();
	// instanciation d'une nouvelle simulation
	Simulation _ss(_s);// appel du constructeur de recopie de la class simulation
	// affichage des mobile copier
	_ss.Show_Liste();

	if(_ss.get_temps() != _s.get_temps() )
		return false;

 	std::list<Mobile*> listeMobile1=_s.get_listemobile(); 
	std::list<Mobile*> listeMobile2=_ss.get_listemobile();
	std::list<Mobile*>::iterator it1;
		it1 = listeMobile1.begin();
	std::list<Mobile*>::iterator it2;
		it2 = listeMobile2.begin();
	// on verifie que les objets copier on la meme vitesse, position et nom pour les mobiles et masse pour les mobilepesants 
	while( ( it1 != listeMobile1.end() ) || ( it2 != listeMobile2.end() ) )
	{
		// on verife que la position est identique
		if( (*it1)->get_position()[2] != (*it2)->get_position()[2] || (*it1)->get_position()[1] != (*it2)->get_position()[1] || (*it1)->get_position()[0] != (*it2)->get_position()[0] )
			return false;
		// on verifie que la vitesse est identique
		if( (*it1)->get_vitesse()[2] != (*it2)->get_vitesse()[2] || (*it1)->get_vitesse()[1] != (*it2)->get_vitesse()[1] || 
(*it1)->get_vitesse()[0] != (*it2)->get_vitesse()[0] )
			return false;
		//on verifie que le nom est identique
		if( (*it1)->get_nom().compare( (*it2)->get_nom() ) != 0 )
			return false;
		
		it1++;
		it2++;

	}
return true;

}
bool testVecteur3D(){
	double dt=10;
	Vecteur3D v1(1,2,3);
	Vecteur3D v2;
	// test operateur []
	if( v1[0] != 1 || v1[1] != 2 || v1[2] != 3 )
		return false;
		v1.affichage();

	// test double * vecteur
	v2=dt*v1;
	if( v2[0] != 10 || v2[1] != 20 || v2[2] != 30 )
		return false;
		v2.affichage();

	// test somme de 2 vecteurs
	Vecteur3D v3=v1+v2;
	if( v3[0] != 11 || v3[1] != 22 || v3[2] != 33 )
		return false;
		v3.affichage();
	// test norme
	Vecteur3D v4(2,1,2);
	if( v4.norme() != 3.0 )
		return false;
		v4.affichage();


return true;
}
bool testTerre(){
	
	// test singleton Terre
	Terre* T=Terre::getInstance();
	Terre* T2=Terre::getInstance();
	if( T != T2 )
		return false;
	// test gravité
	Vecteur3D v1(2,1,2);
	/*if( T->gravite(v1) != T2->gravite(v1) )
		return false;*/
	//T->gravite(v1).affichage();
	Vecteur3D v(-7,-4,3);
	Vecteur3D v3(17,6,2.5);
	std::cout<<v.distance(v3);

	
return true;
}
bool testSatellite1(){
	

	

	// après simulation le satellite doit revenir à peu près à sa position initiale 
	// et la distance entre la position initiale et la position final doit être de quelque km
	MobilePesant P("Satellite",4000.58);
	Terre *t=Terre::getInstance();
	double tempsDeSimulation = t->tempsParcours(200000.0);
	std::cout << " T vaut : " << (tempsDeSimulation/60) << "s (attendu : 88,45)"  << std::endl;
	std::cout << " Vitesse avant simulation : "  << std::endl;
	 t->vitesseInitiale(200000.0).affichage();
	std::cout<<"------------------------------------ \n";
	std::cout << " Position avant simulation : "  << std::endl;
	 t->positionInitiale(200000.0).affichage();
	std::cout<<"------------------------------------ \n";
	Vecteur3D posi=t->positionInitiale(200000.0);	
	Vecteur3D vit=t->vitesseInitiale(200000.0);
	P.set_vitesse(vit);
	P.set_position(posi);
	std::cout << " Gravite : "  << std::endl;
	 t->gravite(posi).affichage();
	std::cout<<"------------------------------------ \n";
	double pasDeSimulation = 0.1; 
	for(double i= 0 ; i<= tempsDeSimulation ; i+=pasDeSimulation)
	P.gravite(pasDeSimulation);
	std::cout << " Après simulation : "  << std::endl;
	P.affichage();
	std::cout<<"Distance entre Depart et Arriver = "<<P.get_position().distance(posi)/1000 <<" Km " << std::endl;
	std::cout<<"------------------------------------ \n";
return true;
}
bool testIntegrateur2(){
	Mobile m("bic");
	Terre *t=Terre::getInstance();
	double tempsDeSimulation = t->tempsParcours(200000.0);
	double pasDeSimulation = 0.1; 
	std::cout << " T vaut : " << (tempsDeSimulation/60) << "s (attendu : 88,45)"  << std::endl;
	std::cout << " Vitesse avant simulation : "  << std::endl;
	 t->vitesseInitiale(200000.0).affichage();
	std::cout<<"------------------------------------ \n";
	std::cout << " Position avant simulation : "  << std::endl;
	 t->positionInitiale(200000.0).affichage();
	std::cout<<"------------------------------------ \n";
	Vecteur3D posi=t->positionInitiale(200000.0);	
	Vecteur3D vit=t->vitesseInitiale(200000.0);
	m.set_vitesse(vit);
	m.set_position(posi);
	/*std::cout << " Gravite : "  << std::endl;
	 t->gravite(posi).affichage();
	std::cout<<"------------------------------------ \n";
	std::cout<<"         IntegrateurEuler            \n";
	std::cout<<"------------------------------------ \n";
	
	for(double i= 0 ; i<= tempsDeSimulation ; i+=pasDeSimulation)
	 {
		  
		  m.advance<IntegrateurEuler>(pasDeSimulation);
	}
	std::cout << " Après simulation : "  << std::endl;
	m.affichage();
	std::cout<<"Distance entre Depart et Arriver = "<<m.get_position().distance(posi)/1000 <<" Km " << std::endl;*/
	std::cout<<"------------------------------------ \n";
	std::cout<<"         IntegrateurRungeKutta            \n";
	std::cout<<"------------------------------------ \n";
	/*posi=t->positionInitiale(200000.0);
	posi=posi+(pasDeSimulation/2.0)*vit;
	m.set_position(posi);*/
	for(double i= 0 ; i<= tempsDeSimulation ; i+=pasDeSimulation)
	 {
		  m.advance<IntegrateurRungeKutta>(pasDeSimulation);
	}
	std::cout << " Après simulation : "  << std::endl;
	m.affichage();
	std::cout<<"Distance entre Depart et Arriver = "<<m.get_position().distance(posi)/1000 <<" Km " << std::endl;
	
std::cout<<"------------------------------------ \n";
	
return true;
}