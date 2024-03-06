#ifndef ESDEVENIMENT_H
#define ESDEVENIMENT_H
#include <iostream>
#include "Data.h"
#include "Hora.h"
using namespace std;

class Esdeveniment{
private:
    //Atributs
    string a_descripcio;
    Data a_data;
    Hora a_horainici;
    Hora a_horafi;

public:
    //Constructors
    Esdeveniment();
    Esdeveniment(string descripcio, const Data& data, const Hora& hora_inici, const Hora& hora_fi);

    //Consultors
    void mostrar() const;
    //Pre: --; Post: mostra l'esdeveniment
    bool es_mes_llarg(const Esdeveniment& e) const;
    //Pre: cert; Post: cert si l'esdeveniment es més llarg que e, i fals altrament.

    //Modificadors
    void llegir();
    //Pre: -- ; Post: llegeix un Esdeveniment de teclat.
};

#endif // !ESDEVENIMENT_H