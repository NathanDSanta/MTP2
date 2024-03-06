#ifndef AGENDA_H
#define AGENDA_H
#include "Esdeveniment.h"

class Agenda{

private:

    //Constants
    static const int MAX = 100;
    static const int NO_TROBAT = -1;
    typedef Esdeveniment Vec_Esdeveniments[MAX];
    
    //Atributs
    Vec_Esdeveniments t;
    int n;

    //Mètodes privats
    int cercar_esdeveniment(const Esdeveniment& e) const;
    //Pre: -- ; Post: retorna la posició de l'esdeveniment o NO_TROBAT
public:
    //Constructors
    Agenda();
    //Pre: -- ; Post: L'agenda no té esdeveniments


    //Mètodes consultors
    void mostrar() const;
    //Pre: -- ; Post: mostra els esdeveniments de l'agenda
    int temps_ocupat(const Data& d) const;
    //Pre: -- ; Post: retorna la durada total (en minuts dels esdeveniments d'un dia)

    //Mètodes modificadors
    void afegir_esdeveniment(const Esdeveniment& e);
    //Pre: --; Post: afegir ordenadament un esdeveniment a l'agenda

};

#endif // !AGENDA_H
