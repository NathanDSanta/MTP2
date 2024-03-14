#include "Categories.h"

Categories::Categories(){n = 0;}

void Categories::afegir_categoria(const Categoria& c){
    bool existeix; int pos;
    cerca_dicotomica(c, existeix, pos);
    if(existeix) t[pos] += c;
    else inserir(c, pos);
}

void Categories::inserir(const Categoria& c, int pos){
    int i = n;
    if(pos > 0){
        for(i; i > pos; i--) t[i] = t[i-1];
    } else{
        while(i > 0 && c < t[i - 1]){
            t[i] = t[i - 1];
            i--;
        }
    }
    t[i] = c;
    n++;
}

void Categories::cerca_dicotomica(const Categoria& c, bool& existeix, int& pos) const{
    existeix = false;
    int esq = 0, drt = n - 1, mig = 0;
    while(!existeix && drt >= esq){
        mig = (esq + drt) / 2;
        if(t[mig] == c) existeix = true;
        else if (c < t[mig]) drt = mig - 1;
        else esq = mig + 1;
    }
    if(existeix) pos = mig;
    else pos = esq;
}

void Categories::mostrar_es_pot_satisfer(int quantitat, string categoria) const{
    bool existeix; int pos;
    cerca_dicotomica(categoria, existeix, pos);
    string missatge = "-- ";
    if(!existeix || !t[pos].satisfer_demanda(quantitat)) missatge += " No e";
    else missatge += "E";
    cout << missatge + "s pot satisfer --" << endl;
}

/* void Categories::mostrar() const{
    for(int i = 0; i < n; i++){
        t[i].mostrar();
    }
} */