#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class Data{
private:
    //Atributs
    int a_dia, a_mes, a_any;

public:
    //Constructors
    Data(ifstream& fin);
    Data(bool cin = false, int any = 2001, int mes = 1, int dia = 1);

    //Mètodes Consultors
    void mostrar() const;

    //Operadors
    bool operator <(const Data& d) const;
    bool operator ==(const Data& d) const;
};


#endif // !DATA_H