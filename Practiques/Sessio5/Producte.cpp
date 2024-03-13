#include "Producte.h"

Producte::Producte(){codi = ""; nom = ""; marca = ""; categoria = ""; unitats = 0;}

Producte::Producte(ifstream& fin){
    fin >> codi;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(fin, nom);
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(fin, marca);
    caducitat = Data(fin);
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(fin, categoria);
    unitats = 1;
}

void Producte::mostrar() const{
    cout << "c:" << codi << " - " << nom
         << "(" << marca << ") - n: " << unitats
         << ", cad:";
    caducitat.mostrar();
    cout << " [" << categoria << "]" << endl;
}

bool Producte::operator <(const Producte& p) const{return codi < p.codi;}
bool Producte::operator <<(const Data& d) const{return caducitat < d;}
