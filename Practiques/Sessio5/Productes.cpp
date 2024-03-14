#include "Productes.h"

Productes::Productes(){n = 0;}

void Productes::inserir(const Producte& p, int pos){
    int i = n;
    if(pos > 0){
        for(i; i > pos; i--) t[i] = t[i-1];
    } else{
        while(i > 0 && p < t[i - 1]){
            t[i] = t[i - 1];
            i--;
        }
    }
    t[i] = p;
    n++;
}

void Productes::afegir_producte(const Producte& p){
    bool existeix; int pos;
    cerca_dicotomica(p, existeix, pos);
    if(existeix) t[pos] += p;
    else inserir(p, pos);
}

void Productes::llegir_fitxer(ifstream& fin, Productes& llarg, Productes& curt, Categories& c, const Data& llindar){
    Producte p(fin);
    while(!fin.eof()){    
        if(p << llindar) curt.afegir_producte(p);
        else llarg.afegir_producte(p);
        c.afegir_categoria(p.crear_categoria());
        p = Producte(fin);
    }
}

void Productes::mostrar() const{
    cout << "Llistat de productes de caducitat curta: " << endl;
    for(int i = 0; i < n; i++){
        t[i].mostrar();
    }
}

void Productes::cerca_dicotomica(const Producte& p, bool& existeix, int& pos) const{
    existeix = false;
    int esq = 0, drt = n - 1, mig = 0;
    while(!existeix && drt >= esq){
        mig = (esq + drt) / 2;
        if(t[mig] == p) existeix = true;
        else if (p < t[mig]) drt = mig - 1;
        else esq = mig + 1;
    }
    if(existeix) pos = mig;
    else pos = esq;
}

Productes Productes::ordenar_per(char criteri){
    for(int i = 0; i < n; i++){
        int pos_menor = i;
        for(int j = i + 1; j < n; j++){
            if(t[j].ordenar_per(t[pos_menor],criteri)) pos_menor = j;
        }
        t[i].intercanviar(t[pos_menor]);
    }
    return *this;
}

void Productes::actualitzar_estructures(Productes& llarg, const Data& d){
    int n_bons = 0;
    for(int i = 0; i < llarg.n; i++){
        if(llarg.t[i] << d) inserir(llarg.t[i]);
        else{
            llarg.t[n_bons] = llarg.t[i];
            n_bons++;
        } 
    }
}