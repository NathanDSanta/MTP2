#include "Esdeveniment.h"

Esdeveniment::Esdeveniment(){a_descripcio = "";}

Esdeveniment::Esdeveniment(string descripcio, const Data& data, const Hora& hora_inici, const Hora& hora_fi){
    a_descripcio = descripcio;
    a_data = data;
    a_horainici = hora_inici;
    a_horafi = hora_fi;
}

//Consultors
void Esdeveniment::mostrar() const{
//Pre: --;
//Post: mostra l'esdeveniment
    cout << "DESCRIPCIO: " << a_descripcio << endl << "DATA: ";
    a_data.mostrar(1);
    cout << endl << "HORA: ";
    a_horainici.mostrar();
    cout << " - ";
    a_horafi.mostrar();
    cout << endl;
}

bool Esdeveniment::es_mes_llarg(const Esdeveniment& e) const{
//Pre: --;
//Post: cert si l'esdeveniment és més llarg que e, i fals altrament
    return a_horafi.durada(a_horainici) > e.a_horafi.durada(e.a_horainici);
}

void Esdeveniment::llegir(){
    cout << "DESCRIPCIO: " << endl;
    cin >> a_descripcio;
    cout << "DIA: " << endl;
    a_data.llegir(1);
    cout << "HORA INICI: " << endl;
    a_horainici.llegir();
    cout << "HORA FINAL: " << endl; 
    a_horafi.llegir();
    while(a_horafi.es_menor(a_horainici)) a_horafi.llegir();
}