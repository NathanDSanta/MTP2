#ifndef VEC_PARAULES_H
#define VEC_PARAULES_H
#include "Paraula.h"

class Vec_paraules{
private:
    //Constants
    static const int MAX = 25000;
    typedef Paraula Vector_paraules[MAX];

    //Atributs
    Vector_paraules t;
    int n;

    //Metodes privats
    void cerca_dicotomica(const Paraula& p, bool& trobat, int& pos) const;
    //Pre: --; Post: trobat = true --> pos = posició on es troba, trobat = false --> pos = posició d'inserció;

public:
    //Constructors
    Vec_paraules(); //Pre: --; Post: n = 0 i t[0..MAX - 1] = {"" , 0} (valor, comptador)

    //Metodes consultors
    void mostrar_minim_aparcions(int num_ap) const;
    //Pre: num-ap > 0; Post: mostra el llistat de paraules amb un numero d'aparicions igual o més alt que num_ap

    //Metodes modificadors
    void inserir_paraula(const Paraula& p);
    //Pre: --; Post: p inserit a t[0..n-1]
};

#endif // !VEC_PARAULES_H