#include "Peticio.h"

Peticio::Peticio(){
    a_nom = "";
    a_id = "";
    a_hora = 0;
}

Peticio::Peticio(const string& nom, const string& id, const int& hora){
    a_nom = nom;
    a_id = id;
    a_hora = hora;
}

void Peticio::mostrar(){
    cout << "[";
    if(a_hora == 9) cout << "0";
    cout << a_hora << ":00]: " << a_nom << ": " << a_id << endl;
}

void Peticio::recollida(){
    cout << "LA RESERVA D'ALIMENTS REALITZADA PER " << a_nom << " HA ESTAT RECOLLIDA." << endl;
}