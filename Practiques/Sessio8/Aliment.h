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
        Aliment operator +=(const Aliment& a);
        bool operator <(const Aliment& a);

        //Constructors
        Aliment(string nom = "", int unitats = 0);
        //Pre: --; Post: Aliment creat {nom, unitats}

        //Mètodes consultors
};

#endif // !ALIMENT_H