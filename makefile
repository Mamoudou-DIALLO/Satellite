all : simulation                                                               
                                                                               
clear :                                                                        
	rm -f *.o                                                                     
                                                                               
simulation : Mobile.o Tests.o Simulation.o MobilePesant.o Vecteur3D.o Terre.o IntegrateurRungeKutta.o Integrateur.o IntegrateurEuler.o main.cpp                                         
	g++ -Wall Mobile.o Tests.o Simulation.o MobilePesant.o Vecteur3D.o Terre.o IntegrateurRungeKutta.o Integrateur.o IntegrateurEuler.o main.cpp -o simulation                             
                                                                               
Mobile.o : Mobile.cpp                                                          
	g++ -Wall -c Mobile.cpp                                                       
                                                                               
Tests.o : Tests.cpp                                                            
	g++ -Wall -c Tests.cpp                                                        

Simulation.o : Simulation.cpp
	g++ -Wall -c Simulation.cpp   

MobilePesant.o : MobilePesant.cpp
	g++ -Wall -c MobilePesant.cpp

Vecteur3D.o : Vecteur3D.cpp
	g++ -Wall -c Vecteur3D.cpp

Terre.o : Terre.cpp
	g++ -Wall -c Terre.cpp

Integrateur.o : Integrateur.cpp
		g++ -Wall -c Integrateur.cpp

IntegrateurEuler.o : IntegrateurEuler.cpp
		g++ -Wall -c IntegrateurEuler.cpp

IntegrateurRungeKutta.o: IntegrateurRungeKutta.cpp
		g++ -Wall -c IntegrateurRungeKutta.cpp



