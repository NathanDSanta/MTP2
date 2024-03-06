#include "Agenda.h"

bool demanar_esdeveniment(){
    cout << "VOLS AFEGIR UN ALTRE ESDEVENIMENT? (S/N): " << endl;
    char aux;
    bool si = false;
    cin >> aux;
    if(aux == 'S') si = true;
    else si = false;
    return si;
}

int main(){
    Agenda ag;
    cout << "AFEGEIX ELS ESDEVENIMENTS: " << endl;
    Esdeveniment e;
    e.llegir();
    ag.afegir_esdeveniment(e);
    while(demanar_esdeveniment()){
        e.llegir();
        ag.afegir_esdeveniment(e);
    }
    ag.mostrar();
    cout << "ENTRA UNA DATA: " << endl;
    Data d;
    d.llegir(1);
    cout << "EL TEMPS OCUPAT DEL DIA "; 
    d.mostrar(1);
    cout << " ES DE " << ag.temps_ocupat(d) << " MINUTS" << endl;
    return 0;
}