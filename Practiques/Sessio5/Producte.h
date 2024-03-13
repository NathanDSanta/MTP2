#ifndef PRODUCTE_H
#define PRODUCTE_H
#include "Data.h"

class Producte{
private:
    //Atributs
    string codi, nom, marca,categoria;
    int unitats;
    Data caducitat;
public:

    //Constructors
    Producte();
    Producte(ifstream& fin);

    //Consultors
    void mostrar() const;

    //Operadors
    bool operator <(const Producte& p) const;
    bool operator <<(const Data& d) const;

};

#endif // !PRODUCTE_H
