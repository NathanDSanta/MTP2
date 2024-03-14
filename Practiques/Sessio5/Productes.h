#ifndef PRODUCTES_H
#define PRODUCTES_H
#include "Producte.h"
#include "Categories.h"

class Productes{
private:
    //Constants
    static const int MAX = 500;
    typedef Producte Vec_Productes[MAX];

    //Atributs
    Vec_Productes t;
    int n;

    //Mètodes privats
    void cerca_dicotomica(const Producte& p, bool& existeix, int& pos) const;
    void inserir(const Producte& p, int pos = -1);
 
public:
    //Constructors
    Productes();


    //Mètodes consultors
    void mostrar() const;

    //Mètodes modificadors
    void afegir_producte(const Producte& p);
    Productes ordenar_per(char criteri);
    void actualitzar_estructures(Productes& llarg, const Data& d);

    //Mètodes de classe
    static void llegir_fitxer(ifstream& fin, Productes& llarg, Productes& curt, Categories& c, const Data& llindar);
};

#endif // !PRODUCTES_H