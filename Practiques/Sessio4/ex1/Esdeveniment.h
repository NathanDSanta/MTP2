#ifndef ESDEVENIMENT_H
#define ESDEVENIMENT_H
#include "Data.h"
#include "Hora.h"

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
    Data data() const;
    //Pre: -- ; Post: retorna la data de l'esdeveniment
    int durada() const;
    //Pre: --; Post: retorna la durada entre l'hora inicial i l'hora final (en minuts)
    void mostrar() const;
    //Pre: --; Post: mostra l'esdeveniment
    bool es_mes_llarg(const Esdeveniment& e) const;
    //Pre: --; Post: retorna cert si l'esdeveniment es més llarg que e, i fals altrament.

    //Modificadors
    void llegir();
    //Pre: -- ; Post: llegeix un Esdeveniment de teclat.

    //Operadors
    bool operator < (const Esdeveniment& e) const;
    bool operator == (const Esdeveniment& e) const;
};

#endif // !ESDEVENIMENT_H