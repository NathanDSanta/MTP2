#ifndef PRODUCTE_H
#define PRODUCTE_H
#include "Data.h"
#include "Categoria.h"

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
    Categoria crear_categoria() const;
    void mostrar() const;
    bool ordenar_per(const Producte& p,char criteri) const;

    //Modificadors
    void intercanviar(Producte& p);

    //Operadors (els operadors diferents no son copiats, els he deduït, encara que sembli difícil de creure)
    bool operator <(const Producte& p) const;
    bool operator <<(const Data& d) const;
    bool operator ==(const Producte& p) const;
    void operator +=(const Producte& p);

};

#endif // !PRODUCTE_H
