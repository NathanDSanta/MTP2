#include "Paraula.h"

Paraula::Paraula(){
    valor = "";
    comptador = 0;
}

Paraula::Paraula(ifstream& fin){
    valor = "";
    char c = fin.get();
    while (!fin.eof() && !es_lletra(c)) c = fin.get();
    if(!fin.eof()){
        while(!fin.eof() && es_lletra(c)){
            if(es_majuscula(c)) c = fer_minuscula(c);
            valor += c;
            c = fin.get();
        }
    }
    comptador = 1;
}

void Paraula::mostrar() const{
    cout << valor << ": " << comptador << endl;
}

bool Paraula::operator <(const Paraula& p) const{return valor < p.valor;}
bool Paraula::operator ==(const Paraula& p) const{return valor == p.valor;}

int Paraula::obtenir_comptador() const{return comptador;}

void Paraula::incrementar_comptador(){comptador++;}

bool Paraula::es_lletra(char c){return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';}
bool Paraula::es_majuscula(char c){return c >= 'A' && c <= 'Z';}
char Paraula::fer_minuscula(char c){return c - 'A' + 'a';}