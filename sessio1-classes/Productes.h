#ifndef VEC_PRODUCTES.H
#define VEC_PRODUCTES.H
#include <iostream>
#include <fstream>
#include "Producte.h"
#include "Data.h"
using namespace std;
const int MAX = 10000;
typedef Producte vec_productes[MAX];

class Productes{
private:
    vec_productes t;
    int n;
public:
    //Constructors
    Productes();

    //Consultors

    //Modificadors
    void isnerir_producte(Producte p);
    //
    void ordenar(char criteri);
    //
    void mostrar();
    //
    void eliminar_productes(Data d);

};
#endif