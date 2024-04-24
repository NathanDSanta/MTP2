#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class Carta{


    private:
        //Mètodes amics
        friend istream& operator>>(istream& i, Carta& c);
        friend ostream& operator<<(ostream& o, const Carta& c);

        //Atributs
        char a_pal;
        int a_valor;
        bool a_visible;

        //Mètodes privats
        bool pal_menor(const Carta& c) const;
        //Pre: --; Post: retorna true si el pal és menor
        static int cerca_valor(char valor);
        //Pre: --; Post: número del valor en funció del char;

    public:
        static const char PALS[4];
        static const char VALORS[13];

        //Constr
        Carta(char pal = 'a', int valor = 0, bool visible = true);
        //Pre: --; Post: Carta creada amb valors predeterminats modificables  {' ', 0, true}

        //Operadors
        bool operator <(const Carta& c) const;
        //Pre: --; Post: retorna si aquesta carta és menor que c, segons l'ordre de pals i valors respectivament.
        

        //Mètodes modificadors
        static void intercanviar(Carta& a, Carta& c);
        //Pre: a = A, c = C; post: a = C, c = A;

        

};

#endif // !CARTA_H