#ifndef PRODUCTE_H
#define PRODUCTE_H
#include <iostream>
#include <fstream>
#include "Data.h"
using namespace std;

class Producte{
private:
    string codi, nom, marca, categoria;
    Data caducitat;
    int unitats;
public:
    Producte(); //
    Producte(string c, string n, string m, string cat, Data cad, int u);
    //Consultors

    string obtenir_codi() const;
    //
    string obtenir_nom() const;
    //
    string obtenir_marca() const; 
    //
    string obtenir_categoria() const; 
    //
    Data obtenir_caducitat() const;
    //
    int obtenir_unitats() const;
    //
    bool es_mes_petit(Producte p, char criteri) const;
    //

};

#endif