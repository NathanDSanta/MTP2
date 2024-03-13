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
};

#endif // !CATEGORIA_H