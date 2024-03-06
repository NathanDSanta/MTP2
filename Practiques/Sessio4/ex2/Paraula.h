#ifndef PARAULA_H
#define PARAULA_H   
#include <iostream>
#include <fstream>
using namespace std;

class Paraula{
private:
    //Atributs
    string valor;
    int comptador;

    //Metodes auxiliars de classe
    static bool es_lletra(char c);
    static bool es_majuscula(char c);
    static char fer_minuscula(char c);
    
public:
    //Constructors
    Paraula(); //Pre: -- ; Post: Paraula incialitzada a {"" , 0} (valor, comptador)
    Paraula(ifstream& fin); //Pre: -- ; Post: Paraula llegida de fitxer

    //Metodes consultors
    int obtenir_comptador() const;
    //Pre: --; Post: retorna el comptador
    void mostrar() const;
    //Pre: --; Post: mostra la paraula

    //Metodes modificadors
    void incrementar_comptador();
    //Pre: --; Post: incrementa el comptador de la paraula en 1;

    //Operadors
    bool operator <(const Paraula& p) const;
    bool operator ==(const Paraula& p) const;

};
#endif // !PARAULA_H