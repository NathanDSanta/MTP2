#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"

class Baralla
{
private:
    //Constants i mètodes amics
    friend istream& operator>>(istream& i, Baralla& b);
    friend ostream& operator<<(ostream& o, const Baralla& b);
    static const int BARALLA_COMPLETA = 52;

    //Atributs
    Carta *a_t;
    int a_n;
    int a_max;
    unsigned a_llavor;

    //Mètodes privats
    void reserva();
    //Pre: --; Post: memòria reservada per a_max Carta
    void copia(const Baralla& b);
    //Pre: memòria alliberada; Post: aquesta baralla és còpia de la baralla b
    void expandeix();
    //Pre: --; Post: la memòria reservada s'amplia en 13.
    int aleatori(int valor);
    //Pre: --; Post: retorna un valor aleatori entre 0 i valor-1

    

public:
    //Constr - Destr
    Baralla();
    Baralla(int llavor);
    Baralla(const Baralla& b);
    ~Baralla();

    //Mètodes modificadors
    void barrejar();
    //Pre: --; Post: barreja

    //Operadors
    Baralla& operator =(const Baralla& b);
    void operator += (const Carta& c);
};

#endif // !BARALLA_H