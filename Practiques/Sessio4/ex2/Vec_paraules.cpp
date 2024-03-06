#include "Vec_paraules.h"

Vec_paraules::Vec_paraules(){
    n = 0;
}

void Vec_paraules::mostrar_minim_aparcions(int num_ap) const{
    cout << "RECOMPTE DE PARAULES: " << endl; 
    for(int i = 0; i < n; i++){
        if(t[i].obtenir_comptador() >= num_ap) t[i].mostrar();
    }
    cout << "HI HA " << n << " PARAULES DIFERENTS" << endl;
}

void Vec_paraules::inserir_paraula(const Paraula& p){
    bool trobat = false; int pos;
    cerca_dicotomica(p, trobat, pos);
    if(trobat) t[pos].incrementar_comptador();
    else{
        for(int i = n; i > pos; i--) t[i] = t[i - 1];
        t[pos] = p;
        n++;
    }
}

void Vec_paraules::cerca_dicotomica(const Paraula& p, bool& trobat, int& pos) const{
    int esq = 0, drt = n - 1, mig = 0;
    trobat = false;
    while(!trobat && drt >= esq){
        mig = (esq + drt) / 2;
        if(t[mig] == p) trobat = true;
        else if(t[mig] < p) esq = mig + 1;
        else drt = mig - 1;
    }
    if(trobat) pos = mig;
    else pos = esq;
}