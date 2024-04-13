#include "Aliment.h"

//Constructors
Aliment::Aliment(string nom, int unitats){
    a_nom = nom;
    a_unitats = unitats;
}


//Mètodes consultors
void Aliment::descripcio() const{
    cout << "[ Tenim " << a_unitats << " unitats de " <<  a_nom  << " al magatzem. ]" << endl;
}

void Aliment::no_existeix() const{
    cout << "[ " << a_nom << " no existeix! ]" << endl;
}

void Aliment::insuficients() const{
    cout << "[ No hem pogut servir tots els aliments. ]" << endl << "[ Nomes en tenim " << a_unitats <<". ]" << endl;
}

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
    o << a.a_nom << ": " << a.a_unitats << endl;
    return o;
}

void Aliment::operator +=(const Aliment& a){a_unitats += a.a_unitats;}

void Aliment::operator -=(const Aliment& a){a_unitats -= a.a_unitats;}

Aliment Aliment::operator -(const Aliment& a) const{
    return Aliment(a_nom,a_unitats - a.a_unitats);
}

bool Aliment::operator <=(const Aliment& a) const{
    return a_nom <= a.a_nom;
}

bool Aliment::operator <=(const int& unitats) const{
    return a_unitats <= unitats;
}

bool Aliment::operator ==(const Aliment& a) const{
    return a_nom == a.a_nom;
}

bool Aliment::operator ==(const int& unitats) const{
    return a_unitats == unitats;
}