#ifndef CATEGORIES_H
#define CATEGORIES_H
#include "Categoria.h"

class Categories{
private:
    //Constants
    static const int MAX = 100;
    typedef Categoria Vec_Categories[MAX];

    //Atributs
    Vec_Categories t;
    int n;

    //Mètodes privats
    void cerca_dicotomica(const Categoria& c, bool& existeix, int& pos) const;
    void inserir(const Categoria& c, int pos = -1);

public:

    //Constructors
    Categories();

    //Mètodes consultors
    void mostrar_es_pot_satisfer(int quantitat, string categoria) const;
    // void mostrar() const;


    //Mètodes modificadors
    void afegir_categoria(const Categoria& c);

};

#endif // !CATEGORIES_H