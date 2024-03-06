#include <iostream>
#include "Jugador.h"
using namespace std;

const int Jugador::ORDRE_PUNTS[Jugador::N_PUNTS] = {0,15,30,40,0};

Jugador::Jugador(){
    cout << "Entra el nom del jugador: " << endl;
    cin >> nom;
    punts = 0;
    jocs = 0;
    guanyat = false;
}

void Jugador::augmentar_punts(Jugador& j){
    int i = 0;
    bool trobat = false;
    while(!trobat && i < N_PUNTS){
        trobat = punts == ORDRE_PUNTS[i];
        if(trobat)punts = ORDRE_PUNTS[i+1];
        i++;
    }
    if(i == 4) augmentar_joc(j);
    else{
        cout << nom << " ha guanyat el punt" << endl;
    }        
}

void Jugador::augmentar_joc(Jugador& j){
    jocs++;
    j.punts = 0;
    cout << nom << " ha guanyat el punt i el joc" << endl;
    if(jocs >= 2) guanyat = true;
}

void Jugador::mostrar_jugador() const{
    cout << nom << ", punts: " << punts << ", jocs: " << jocs << endl;
}

string Jugador::obtenir_nom() const{return nom;}
bool Jugador::obtenir_guanyat() const{return guanyat;}

void Jugador::mostrar_jugadors(Jugador A, Jugador B){
    A.mostrar_jugador();
    B.mostrar_jugador();
    cout << endl;
}