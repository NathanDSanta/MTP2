#ifndef TAULELL_H
#define TAULELL_H
#include "Pila_Cartes.h"

class Taulell
{
private:
    Carta **mat;
    int nf, nc;

public:

    
    Taulell();
    Taulell(const Taulell& t);
    ~Taulell();


};

#endif // !TAULELL_H