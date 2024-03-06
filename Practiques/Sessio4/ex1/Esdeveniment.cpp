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
    cout << "[";
    a_data.mostrar(1);
    cout << ", ";
    a_horainici.mostrar();
    cout << " - ";
    a_horafi.mostrar();
    cout << "] " << a_descripcio << endl;
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
    while(a_horafi < a_horainici) a_horafi.llegir();
}

Data Esdeveniment::data() const{return a_data;} //Pre: cert; Post: retorna la data de l'esdeveniment
int Esdeveniment::durada() const{return a_horafi.durada(a_horainici);}

bool Esdeveniment::operator < (const Esdeveniment& e) const{
    bool mes_petit = a_data < e.a_data;
    if(a_data == e.a_data){
        mes_petit = a_horainici < e.a_horainici;
        if(a_horainici == e.a_horainici){
            mes_petit = a_horafi < e.a_horafi;
            if(a_horafi == e.a_horafi) mes_petit = a_descripcio < e.a_descripcio;
        }
    }
    return mes_petit;
}

bool Esdeveniment::operator ==(const Esdeveniment& e) const{return a_data == e.a_data && a_descripcio == e.a_descripcio && a_horafi == e.a_horafi && a_horainici == e.a_horainici;}