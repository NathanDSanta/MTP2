#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
using namespace std;

class Data{
private:
    int any, mes, dia;
public:
    //Constructors
    Data(); //
    Data(int any, int mes, int dia); //

    //Consultors
    int obtenir_any() const;
    //
    int obtenir_mes() const;
    //
    int obtenir_dia() const;
    //

};

#endif