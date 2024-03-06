#include <iostream>
#include "Cercle.h"
#include "Punt2D.h"
using namespace std;

Cercle::Cercle(){
    cout << "Entra el radi [r > 0]:" << endl;
    cin >> a_radi; 
}

void Cercle::posicio_relativa_a(const Cercle& c, int& interiors, int& secants, bool& exteriors) const{
    double distancia = a_centre.distancia(c.a_centre);
    if(a_radi+c.a_radi < distancia) {exteriors = true; cout << "Exterior" << endl;}
    else if(a_radi + distancia < c.a_radi || c.a_radi + distancia < a_radi){interiors++; cout << "Interior" << endl;}
    else {secants++; cout << "Secant" << endl;} 
}