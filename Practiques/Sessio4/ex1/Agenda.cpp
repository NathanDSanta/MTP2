#include "Agenda.h"

Agenda::Agenda(){n= 0;} //Pre: -- ; Post: l'agenda no té esdeveniments

void Agenda::mostrar() const{
//Pre: --; Post: mostra els esdeveniments de l'agenda
cout << "ESDEVENIMENTS DE L'AGENDA: " << endl;
    for(int i = 0; i < n; i++){
        t[i].mostrar();
    }
}

void Agenda::afegir_esdeveniment(const Esdeveniment& e){
    if(cercar_esdeveniment(e) == NO_TROBAT){
        int i = n;
        bool inserit = false;
        while(i > 0 && e < t[i-1]){
            t[i] = t[i-1]; 
            i--;
        }
        t[i] = e;
        n++;
    }
}

int Agenda::temps_ocupat(const Data& d) const{
    int minuts = 0;
    for(int i = 0; i < n; i++){
        if(t[i].data() == d) minuts += t[i].durada(); 
    }
    return minuts;
}

int Agenda::cercar_esdeveniment(const Esdeveniment& e) const{
    int esq = 0, drt = n - 1, mig = 0;
    bool trobat = false; int pos = 0;
    while ((!trobat && drt >= esq)){
        mig = (drt + esq) / 2;
        if(e == t[mig]) trobat = true;
        else if(e < t[mig]) drt = mig - 1;
        else esq = mig + 1;
    }
    if(trobat) pos = mig;
    else {pos = NO_TROBAT;}
    return pos;
}