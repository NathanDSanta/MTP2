#ifndef ALIMENT_H
#define ALIMENT_H
#include <iostream>
using namespace std;

class Aliment{
    private:
        //Atributs
        string nom;
        int unitats;

    public:
        //Operadors
        friend istream& operator>>(istream& i, Aliment& a);
        friend ostream& operator<<(ostream& i, const Aliment& a);
        Aliment operator +=(const Aliment& a);
        bool operator <(const Aliment& a);

        //Constructors
        Aliment(string nom = "", int unitats = 0);
        //Pre: --; Post: Aliment creat {nom, unitats}

        //Mètodes consultors
        string unitats() const;
        //Pre: --; Post: mostra un missatge amb les unitats del producte
};

#endif // !ALIMENT_H