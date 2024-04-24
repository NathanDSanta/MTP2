#include "Baralla.h"


//Constructors -- destructor
Baralla::Baralla(){
    a_n = 0;
    a_max = 13;
    a_t = new Carta[a_max];
}

Baralla::Baralla(int llavor){
    a_n = 0;
    a_max = 13;
    a_t = new Carta[a_max];
    while(a_n != BARALLA_COMPLETA){
        *this += Carta(Carta::PALS[a_n/13],a_n%13);
    }
    a_llavor = llavor;
    barrejar();
}

Baralla::Baralla(const Baralla& b){
    copia(b);
}

Baralla::~Baralla(){
    delete [] a_t;
}


//Mètodes
void Baralla::copia(const Baralla& b){
    a_n = b.a_n;
    a_max = b.a_max;
    a_t = new Carta[a_max];
    for(int i = 0; i < a_n; i++) a_t[i] = b.a_t[i];
}

void Baralla::expandeix(){
    Carta *aux = a_t;
    a_max += 13;
    a_t = new Carta[a_max];
    for(int i=0; i < a_n; i++) a_t[i] = aux[i];
    delete[] aux;
}

int Baralla::aleatori(int valor){
    int a = 1103515245, c= 12345, m=32768;
    a_llavor = a*a_llavor + c;
    return ((a_llavor/32)%m)%valor;
}

void Baralla::barrejar(){
    for(int i = a_n - 1; i > 0; i--){
        int pos = aleatori(i+1);
        Carta::intercanviar(a_t[pos], a_t[i]);
    }
}

//Operadors
Baralla& Baralla::operator=(const Baralla& b){
    if(this != &b){
        delete [] a_t;
        copia(b);
    }
    return *this;
}


void Baralla::operator +=(const Carta& c){
    if (a_n == a_max) expandeix();
    a_t[a_n] = c;
    a_n++;
}

istream& operator>>(istream& i, Baralla& b){
    while(b.a_n != Baralla::BARALLA_COMPLETA){
        i >> b.a_t[b.a_n];
        b.a_n++;
    }
    return i;
}

ostream& operator<<(ostream& o, const Baralla& b){
    o << "BARALLA" << endl;
    int i = 0;
    while(i < b.a_n){
        o << b.a_t[i] << " ";
        i++;
    }
    return o;
}