#include "Hora.h"

Hora::Hora(){
    a_h = 0;
    a_m = 0;
}

Hora::Hora(int h, int m){
    a_h = h;
    a_m = m;
}

//Consultors
void Hora::mostrar() const {
    if(a_h < 10) cout << 0;
    else if(a_h == 0) cout << "00";
    cout << a_h << ":";
    if(a_m < 10) cout << 0;
    else if(a_m == 0) cout << "00";
    cout << a_m;
}


int Hora::durada(const Hora& h) const{
    return (a_h - h.a_h) * 60 + a_m - h.a_m;
}

bool Hora::validar_hora() const{return a_h >= 0 && a_h < 24 && a_m >= 0 && a_m < 60;}

//Modificadors
void Hora::llegir() {
    int format;
    cin >> format;
    a_m = format%100;
    format /= 100;
    a_h = format;
    while(!validar_hora()){
        cin >> format;
        a_m = format%100;
        format /= 100;
        a_h = format;
    }
}

//Operadors
bool Hora::operator <(const Hora& h) const{
    bool es_menor = a_h < h.a_h;
    if(a_h == h.a_h) es_menor = a_m < h.a_m;
    return es_menor;
}

bool Hora::operator ==(const Hora& h) const{return a_h == h.a_h && a_m == h.a_m;}