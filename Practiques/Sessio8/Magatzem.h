#ifndef MAGATZEM_H
#define MAGATZEM_H
#include <iostream>
#include "Aliment.h"
using namespace std;

class Magatzem{

    struct Node{
        Aliment valor;
        Node* seg;
    };

    private:
        //Constants

        //Atributs
        Node* a_inici;

        //Mètodes privats
        void cerca_aliment(const Aliment& a, Node** aux, bool& existeix) const;
        //Pre: --; Post: retorn un punter a la posicio del aliment nom, retorna NULL si no existeix;

    public:
        //Operadors
        friend ostream& operator <<(ostream& o, const Magatzem& m);
        Magatzem& operator =(const Magatzem& m);
        Magatzem& operator +=(const Magatzem& m);
        Magatzem& operator +=(const Aliment& a);
        Magatzem& operator +(const Magatzem& m);
        Magatzem& operator +(const Aliment& a);

        //Constructors -- Destructors
        Magatzem();
        //Pre: --; Post: Magatzem creat i buit.
        Magatzem(const Magatzem& m); 
        //Pre: --; Post: Magatzem copia de m.
        ~Magatzem();
        //Pre: --; Post: Magatzem destruit correctament.

        //Mètodes consultors
        void consultar_aliment() const;
        //Pre: --; Post: busca un aliment i el mostra si existeix, si no, ens informarà que no existeix.

        //Mètodes modificadors
        void servir_aliment();
        //Pre: --; Post: serveix un aliment de la llista
};


#endif // !MAGATZEM_H
