#include "Productes.h"

Productes::Productes(){n = 0;}

void Productes::inserir(const Producte& p){
    int i = n - 1;
    while(i > 0 && t[i - 1] < p){
        t[i] = t[i - 1];
        i--;
    }
    t[i] = p;
    n++;
}

void Productes::llegir_fitxer(ifstream& fin, Productes& llarg, Productes& curt, const Data& llindar){
    Producte p(fin);
    while(!fin.eof()){    
        if(p << llindar) curt.inserir(p);
        else llarg.inserir(p);
        p = Producte(fin);
    }
}

void Productes::mostrar() const{
    for(int i = 0; i < n; i++){
        cout << "Llistat de productes de caducitat curta: " << endl;
        t[i].mostrar();
    }
}