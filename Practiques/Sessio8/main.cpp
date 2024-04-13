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
        
        case 1:{
            cout << "[ AFEGIR ALIMENT: ]" << endl;
            Aliment ins; cin >> ins;
            banc += ins;
            break;
        }
        
        case 2:
            cout << "[ SERVIR ALIMENT: ]" << endl;
            banc.servir_aliment();
            break;

        case 3:
            cout << "[ LLISTAR ALIMENTS: ]" << endl;
            cout << banc;
            break;

        case 4:
            cout << "[ CONSULTAR ALIMENT: ]" << endl;
            banc.consultar_aliment();
            break;
        }
    }
    return 0;
}