#ifndef CATEGORIA_H
#define CATEGORIA_H
#include "Data.h"

class Categoria{
private:
    //Atributs
    string nom;
    int unitats;

public:
    //Constructors
    Categoria(string nom = "", int unitats = 1);

    //Mètodes consultors
    // void mostrar() const;
    bool satisfer_demanda(int quantitat) const;

    //Mètodes modificadors

    //Operadors
    bool operator ==(const Categoria& c) const;
    bool operator <(const Categoria& c) const;
    void operator +=(const Categoria& c);
};

#endif // !CATEGORIA_H