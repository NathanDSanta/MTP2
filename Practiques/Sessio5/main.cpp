#include "Productes.h"

Data demanar_data(string missatge){
    cout << missatge << endl;
    return Data(true);
}

string demanar_string(string missatge){
    cout << missatge << endl;
    string aux;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, aux);
    return aux;
}

char demanar_char(string missatge){
    cout << missatge << endl;
    char aux;
    cin >> aux;
    return aux;
}

int demanar_int(string missatge){
    cout << missatge << endl;
    int aux;
    cin >> aux;
    return aux;
}

void opcions(){
    cout << "OPCIONS: " << endl
         << "N -> Ordenar per nom" << endl
         << "D -> Ordenar per data" << endl
         << "A -> Actualitzar" << endl
         << "C -> Comanda" << endl
         << "M -> Menu" << endl
         << "S -> Sortir" << endl;
}

int main(){
    Data llindar = demanar_data("Entra una data (any mes dia): ");
    ifstream fitxer(demanar_string("Entra el nom del fitxer: ").c_str());
    if(!fitxer.is_open()) cout << "Fitxer no trobat" << endl;
    else{
        Productes llarg, curt;
        Categories cat;
        Productes::llegir_fitxer(fitxer, llarg, curt, cat, llindar);
        opcions();
        bool sortir = false;
        while(!sortir){
            char opcio = demanar_char("Opcio:");
            switch (opcio){
            case 'N':
            case 'D':
                Productes(curt).ordenar_per(opcio).mostrar();
                break;
            case 'A':
                curt.actualitzar_estructures(llarg, demanar_data("Entra la nova data (any mes dia):"));
                break;
            case 'C': 
                cat.mostrar_es_pot_satisfer(demanar_int("Quantitat:"), demanar_string("Categoria:"));
                break;
            case 'M':
                opcions();
                break;
            case 'S':
                sortir = true;
                break;
            }
        }
    }
    return 0;
}