#ifndef PRODUCTES_H
#define PRODUCTES_H
#include "Producte.h"

class Productes{
private:
    //Constants
    static const int MAX = 1000;
    typedef Producte Vec_Productes[MAX];

    //Atributs
    Vec_Productes t;
    int n;

public:
    //Constructors
    Productes();


    //Mètodes consultors
    void mostrar() const;

    //Mètodes modificadors
    void inserir(const Producte& p);


    //Mètodes de classe
    static void llegir_fitxer(ifstream& fin, Productes& llarg, Productes& curt, const Data& llindar);
};

#endif // !PRODUCTES_H