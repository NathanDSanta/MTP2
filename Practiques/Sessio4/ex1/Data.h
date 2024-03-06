#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;

class Data{
private:
    //Constants
    static const int MESOS_ANY = 12;
    static const int DIES_MES[MESOS_ANY];

    //Atributs
    int a_dia, a_mes, a_any;

    //Consultors
    bool validar_data() const;
    //Pre: -- ; Post: cert si data vàlida, i fals altrament

public:
    //Constructors
    Data();
    //Pre: -- ; Post: és la data 1/1/2001 (data per defecte)
    Data(int d, int m, int a);
    //Pre: -- ; Post: és la data d/m/a si és correcta o 1/1/2001 en cas contrari

    //Consultors
    void mostrar(int format) const;
    //Pre: format 1 o 2; Post: mostra la data actual en format d/m/a o d-mes-a

    //Modificadors
    void llegir(int format);
    //Pre: format 1 o 2; Post: llegeix dates en format AAAAMMDD o d m a, fins a llegir-ne una de correcta

    //Operadors
    bool operator <(const Data& d) const;
    bool operator ==(const Data& d) const;
};

#endif // !DATA_H