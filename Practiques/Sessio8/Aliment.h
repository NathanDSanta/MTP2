#ifndef ALIMENT_H
#define ALIMENT_H
#include <iostream>
using namespace std;

class Aliment{
    private:
        //Atributs
        string a_nom;
        int a_unitats;

    public:
        //Operadors
        friend istream& operator>>(istream& i, Aliment& a);
        friend ostream& operator<<(ostream& i, const Aliment& a);
        void operator +=(const Aliment& a);
        void operator -=(const Aliment& a);
        Aliment operator -(const Aliment& a) const;
        bool operator <=(const Aliment& a) const;
        bool operator <=(const int& unitats) const;
        bool operator ==(const Aliment& a) const;
        bool operator ==(const int& unitats) const;

        //Constructors
        Aliment(string nom = "", int unitats = 0);
        //Pre: --; Post: Aliment creat {nom, unitats}

        //Mètodes consultors
        void descripcio() const;
        //Pre: --; Post: mostra la descripcio del producte
        void no_existeix() const;
        //Pre: --; Post: mostra el missatge que no existeix 
        void insuficients() const;
        //Pre: --; Post: mostra el missatge que no hi han suficents
};

#endif // !ALIMENT_H