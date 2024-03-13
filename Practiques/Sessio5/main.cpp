#include "Categories.h"
#include "Productes.h"

string demanar_string(string missatge){
    cout << missatge << endl;
    string aux;
    cin >> aux;
    return aux;
}

char demanar_char(string missatge){
    cout << missatge << endl;
    char aux;
    cin >> aux;
    return aux;
}

void opcions(){
    cout << "OPCIONS: " << endl
         << "N -> Ordenar pe nom" << endl
         << "D -> Ordenar per data" << endl
         << "A -> Actualitzar" << endl
         << "C -> Comanda" << endl
         << "M -> Menu" << endl
         << "S -> Sortir" << endl;
}

int main(){
    Data llindar(true);
    ifstream fitxer(demanar_string("Entra el nom del fitxer: ").c_str());
    if(!fitxer.is_open()) cout << "Fitxer no trobat" << endl;
    else{
        Productes llarg, curt;
        Productes::llegir_fitxer(fitxer, llarg, curt, llindar);
        llarg.mostrar();
        opcions();
        curt.mostrar();
    }
    return 0;
}