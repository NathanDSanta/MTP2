#include "Carta.h"

const char Carta::PALS[4] = {'P','c','d','T'};
const char Carta::VALORS[13] = {'A','2','3','4','5','6','7','8','9','D','J','Q','K'};

//Constr
Carta::Carta(char pal, int valor, bool visible){
    a_pal = pal;
    a_valor = valor;
    a_visible = visible;
}

//Operadors
bool Carta::operator <(const Carta& c) const{
    bool es_menor = pal_menor(c);
    if(a_pal == c.a_pal) es_menor = a_valor < c.a_valor;
    return es_menor;
}

//Mètodes modificadors
void Carta::intercanviar(Carta& a, Carta& c){
    Carta aux = a;
    a = c;
    c = aux;
}

//Mètodes privats
bool Carta::pal_menor(const Carta& c) const{
    int i = 0;
    while(i < 4 && PALS[i] != a_pal && PALS[i] != c.a_pal){
        i++;
    }
    bool es_menor = a_pal == PALS[i];
    return es_menor;
}

int Carta::cerca_valor(char valor){
    int i = 0;
    while(i < 13 && VALORS[i] != valor) i++;
    return i;
}

istream& operator>>(istream& i, Carta& c){
    char valor = ' ';
    i >> valor >> c.a_pal;
    c.a_valor = Carta::cerca_valor(valor);
    return i;
}

ostream& operator<<(ostream& o,const Carta& c){
    o << Carta::VALORS[c.a_valor] << c.a_pal << " ";
    return o;
}