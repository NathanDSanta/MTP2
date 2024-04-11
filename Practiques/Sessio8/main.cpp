#include "Magatzem.h"

int menu(){
    cout << "[ MENU ] " << endl
         << "[ 1: AFEGIR ALIMENT ]" << endl
         << "[ 2: SERVIR ALIMENT ]" << endl
         << "[ 3: LLISTAR ALIMENTS ] " << endl
         << "[ 4: CONSULTAR ALIMENT ]" << endl
         << "[ 0: SORTIR ]" << endl
         << "[ OPCIO: ]" << endl;
    int aux;
    cin >> aux;
    return aux;
}

int main(){
    cout << "[ BANC DELS ALIMENTS ]" << endl;
    Magatzem banc;
    bool sortir = false;
    while(!sortir){
        int opcio = menu();
        switch (opcio){
        case 0:
            sortir = true;
            break;
        
        case 1:
            banc.afegir_aliment();
            break;
        
        case 2:
            banc.servir_aliment();
            break;

        case 3:
            cout << banc;
            break;

        case 4:
            banc.consultar_aliment();
            break;
        }
    }
    return 0;
}