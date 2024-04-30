#ifndef PILA_CARTES_H
#define PILA_CARTES_H
#include "Carta.h"

class Pila_Cartes
{
private:

    //Def
    friend ostream& operator <<(ostream& o, const Pila_Cartes& p);


    struct Node{
        Carta valor;
        Node* ant;
    };

    Node* a_cim;


public:
    // Constr -- Destr
    Pila_Cartes();
    Pila_Cartes(const Pila_Cartes &p);
    ~Pila_Cartes();

    // Operadors
    Pila_Cartes& operator =(const Pila_Cartes& p);
    void operator +=(const Carta& c);
    void operator -=(const Carta& c);

};

#endif // !PILA_CARTES_H