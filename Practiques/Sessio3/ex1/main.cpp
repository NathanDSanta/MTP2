#include <iostream>
#include "Data.h"
#include "Hora.h"
#include "Esdeveniment.h"
using namespace std;

void mostrar_final(const Esdeveniment& e, int n){
    cout << "HAS ENTRAT " << n << " ESDEVENIMENTS" << endl << "L'ESDEVENIMENT MES LLARG ES: " << endl;
    e.mostrar();
}

bool demanar_esdeveniment(){
    cout << "VOLS ENTRAR UN ALTRE ESDEVENIMENT? (S/N): " << endl;
    char aux;
    bool si = false;
    cin >> aux;
    if(aux == 'S') si = true;
    else si = false;
    return si;
}

int main(){
    cout << "ENTRA ELS ESDEVENIMENTS: " << endl;
    Esdeveniment llarg;
    llarg.llegir();
    int n_esdeveniments = 1;
    while(demanar_esdeveniment()){
        Esdeveniment nou;
        nou.llegir();
        if(nou.es_mes_llarg(llarg)) llarg = nou;
        n_esdeveniments++;
    }
    mostrar_final(llarg,n_esdeveniments);
    return 0;
}