#include "Aliment.h"

//Constructors
Aliment::Aliment(string nom, int unitats){
    a_nom = nom;
    a_unitats = unitats;
}


//Mètodes consultors



//Mètodes modificadors



//Mètodes privats



//Operadors
istream& operator>>(istream& i, Aliment& a){
    cout << "[ Nom ]" << endl;
    i >> a.a_nom;
    cout << "[ Quantitat ]" << endl;
    i >> a.a_unitats;
    return i;
}

ostream& operator<<(ostream& o, const Aliment& a){
    cout << "[ Tenim " << a.a_unitats << " unitats de " << a.a_nom << " al magatzem. ]" << endl;
}