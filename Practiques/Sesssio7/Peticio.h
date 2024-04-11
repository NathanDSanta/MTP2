#ifndef PETICIO_H
#define PETICIO_H
#include <iostream>
using namespace std;

class Peticio{
    private:
        //Atributs
        string nom, id;
        int hora;

    public:
        //Constructor
        Peticio();
        //Pre: --; Post: Peticio buida;
        Peticio(const string& nom,const string& id, const int& hora);
        //Pre: --; Post: Peticio {nom, id, hora}

        //Mètodes consultors
        void mostrar();
        //Pre: --; Post: mostra la peticio per pantalla
        void recollida();
        //Pre: --; Post: mostra de recollida;


};

#endif // !PETICIO_H