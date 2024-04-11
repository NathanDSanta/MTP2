#include "CuaPeticions.h"

void opcions(){
    cout << "OPCIONS:" << endl;
    cout << "1: ENTRAR UNA PETICIO" << endl
         << "2: PROCESSAR UNA RECOLLIDA" << endl
         << "3: MOSTRAR EL MENU D'OPCIONS" << endl
         << "0: FINALITZAR" << endl;
}

int demanar_opcio(){
    cout << "OPCIO: " << endl;
    int opcio;
    cin >> opcio;
    while(opcio < 0 || opcio > 3){cout << "OPCIO: " << endl; cin >> opcio;}
    return opcio;
}

int main(){
    cout << "BANC DELS ALIMENTS" << endl;
    CuaPeticions llistat;
    bool sortir = false;
    while(!sortir && !llistat.dia_acabat()){
        opcions();
        int opcio = demanar_opcio();
        switch (opcio){
        case 0:
            sortir = true;
            llistat.mostrar();
            break;
        
        case 1:
            llistat.nova_peticio();
            break;
        case 2:
            llistat.processar_recollida();
            break;
        case 3:
            opcions();
            break;
        }
        cout << endl;
    }
    return 0;
}