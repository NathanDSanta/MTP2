#include "Baralla.h"


//Constructors -- destructor
Baralla::Baralla(){
//Pre: --; Post: Baralla buida
    a_n = 0;
    a_max = 13;
    a_t = new Carta[a_max];
}

Baralla::Baralla(unsigned llavor){
//Pre: --; Post: Baralla barrejada
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
//Pre: --; Post: Baralla és una còpia de b
    copia(b);
}

Baralla::~Baralla(){
//Pre: --; Post: Memòria alliberada
    delete [] a_t;
}


//Mètodes
void Baralla::copia(const Baralla& b){
//Pre: memòria alliberada; Post: aquesta baralla és còpia de la baralla b
    a_n = b.a_n;
    a_max = b.a_max;
    a_t = new Carta[a_max];
    for(int i = 0; i < a_n; i++) a_t[i] = b.a_t[i];
}

void Baralla::expandeix_contrau(bool contrau){
//Pre: --; Post: la memòria reservada s'amplia en 13.
    Carta *aux = a_t;
    if(contrau) a_max -= 13;
    else a_max += 13;
    a_t = new Carta[a_max];
    for(int i=0; i < a_n; i++) a_t[i] = aux[i];
    delete[] aux;
}

int Baralla::aleatori(int valor){
//Pre: --; Post: retorna un valor aleatori entre 0 i valor-1
    a_llavor = a_llavor*1103515245 + 12345;
    return ((a_llavor/32)%32768)%valor;
}

void Baralla::barrejar(){
//Pre: --; Post: baralla barrejada
    for(int i = a_n - 1; i > 0; i--){
        int pos = aleatori(i+1);
        Carta::intercanviar(a_t[pos], a_t[i]);
    }
}

bool Baralla::buit() const{
//Pre: --; Post: retorna true si la baralla és buida
    return a_n == 0;
}


//OPERADORS

Baralla& Baralla::operator=(const Baralla& b){
//Pre --; Post: Baralla és còpia de b
    if(this != &b){
        delete [] a_t;
        copia(b);
    }
    return *this;
}


void Baralla::operator +=(const Carta& c){
//Pre: --; Post: C afegida al final de la baralla.
    if (a_n == a_max) expandeix_contrau();
    a_t[a_n] = c;
    a_n++;
}

Carta Baralla::operator--(int){
//Pre: --; Post: retorna l'últim element i l'elimina del vector simultàniament
    Carta aux = a_t[a_n - 1];
    a_n--;
    if(a_max - a_n >= 13) expandeix_contrau(true);
    return aux;
}


// IOSTREAM

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